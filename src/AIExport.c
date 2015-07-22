#include "AIExport.h"
#include "ExternalAI/Interface/SSkirmishAICallback.h"



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "erl_interface.h"
#include "ei.h"

#define BUFSIZE 1000



int ai = -1;
ei_cnode ec;
int fd = -1;
erlang_pid hq;




EXPORT(int) init(int skirmishAIId, const struct SSkirmishAICallback* callback) {
    fprintf(stdout, "Starting up Erlang CNode %i\n", skirmishAIId);

    ai = skirmishAIId;

    if (ei_connect_init(&ec, "springai", "springai", ai) < 0) {
        fprintf(stderr, "ERROR when initializing: %d", erl_errno);
        exit(-1);
    }

    fprintf(stdout, "node: %s\n", ei_thisnodename(&ec));
    fprintf(stdout, "host: %s\n", ei_thishostname(&ec));

    return 0;
}


int ensure_connection_to_hq() {
    if (fd < 0) {
        fd = ei_connect_tmo(&ec, "hq@localhost", 100);
        if (fd < 0) {
            printf("hq did not answer within 1 sec\n");
        } else {
            fprintf(stdout, "hq reached: %i\n", fd);
        }
    }
    return fd;
}


int receive_command_from_hq() {
    ensure_connection_to_hq();
    if (fd < 0) {
        return 0;
    }

    erl_errno = 0;
    erlang_msg msg;
    ei_x_buff recvbuf;
    ei_x_new(&recvbuf);

    int got = ei_xreceive_msg_tmo(fd, &msg, &recvbuf, 10);
    char command[24] = "";
    int index, version, arity;


    if (got == ERL_TICK) {
        // ignore
    } else if (got == ERL_ERROR) {
        switch (erl_errno) {
            case EAGAIN:
                break;
            case EMSGSIZE:
                erl_err_quit("msgsize!");
                break;
            case EIO:
                fprintf(stderr, "IO-Error?!\n");
                fd = -1;
                hq.node[0] = 0;
                break;
            case ETIMEDOUT:
                break;
        }
    } else {
        hq = msg.from;

        index = 0;
        ei_decode_version(recvbuf.buff, &index, &version);
        ei_decode_tuple_header(recvbuf.buff, &index, &arity);
        ei_decode_atom(recvbuf.buff, &index, command);

        fprintf(stdout, "\treceive: %s <--[%i]-- /%i, 0:'%s'\n", msg.toname, fd, arity, command);
    }
    if (strcmp(command, "ping") == 0) {
        erlang_pid pid;
        printf("\tping encountered\n");
        ei_decode_pid(recvbuf.buff, &index, &pid);
        fprintf(stdout, "\tpid from ping payload: %s %i,%i,%i\n", pid.node, pid.num, pid.serial, pid.creation);
        send_event_to_hq(41, "pong");
        send_event_to_hq(43, "pong");
    }

    return 0;
}

int send_event_to_hq(int topic, const void* data) {
    if (ensure_connection_to_hq() < 0) {
        fprintf(stderr, "\thq unreachable, dropping topic %i\n", topic);
        return 0;
    }
    if (!hq.node) {
        fprintf(stdout, "\tsend: %i, data:'%s' --[%i]-|  no hq yet\n", topic, (char*)data, fd);
        return 0;
    }
    fprintf(stdout, "\tsend: %i, data:'%s' --[%i]--> %s %i,%i,%i\n", topic, (char*)data, fd, hq.node, hq.num, hq.serial, hq.creation);

    erl_errno = 0;
    ei_x_buff sendbuf;
    if (ei_x_new_with_version(&sendbuf) < 0) {
        fprintf(stderr, "\tei_x_new_with_version failed: %i\n", erl_errno);
    }
    if (ei_x_encode_tuple_header(&sendbuf, 3) < 0) {
        fprintf(stderr, "\tei_x_encode_tuple_header failed: %i\n", erl_errno);
    }
    if (ei_x_encode_atom(&sendbuf, "event") < 0){
        fprintf(stderr, "\tei_x_encode_atom failed: %i\n", erl_errno);
    }
    if (ei_x_encode_long(&sendbuf, topic) < 0){
        fprintf(stderr, "\tei_x_encode_long failed: %i\n", erl_errno);
    }
    if (ei_x_encode_string(&sendbuf, data) < 0) {
        fprintf(stderr, "\tei_x_encode_string failed: %i\n", erl_errno);
    }

    fprintf(stdout, "\tpayload size: %i bytes\n", sendbuf.index);
    if (ei_send_tmo(fd, &hq, sendbuf.buff, sendbuf.index, 1000) < 0) {
        fprintf(stderr, "\tsend_event_to_hq failed: %i\n", erl_errno);
    }
    ei_x_free(&sendbuf);
    printf("\n");

    return 0;
}


int send_tick() {
    if (ensure_connection_to_hq()  < 0) {
        fprintf(stderr, "\tno connection established\n");
        return 0;
    }
    erl_errno = 0;
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_atom(&buff, "tick");
    fprintf(stdout, "\tsend: 'tick' %i bytes --[%i]--> %s %i,%i,%i\n", buff.index, fd, hq.node, hq.num, hq.serial, hq.creation);
    ei_send_tmo(fd, &hq, buff.buff, buff.index, 1000);
    ei_x_free(&buff);
    return 0;
}


EXPORT(int) handleEvent(int skirmishAIId, int topic, const void* data) {
    ai = skirmishAIId;
    if (topic == 3) {
        int frame = *((int*)data);  // I 'love' pointers :o)
        if (frame == 1) {
            fprintf(stdout, "\n                LET THE WAR BEGIN!\n\n");
        }
        if (frame % 6000 == 0) {
            fprintf(stdout, "frame: %i\n", frame);
            send_tick();
        }
        if (frame % 60 == 0) {
            return receive_command_from_hq();
        }
        return 0;
    }

    // fprintf(stdout, "ai id: %i\n", skirmishAIId);
    // fprintf(stdout, "topic: %i\n", topic);
    // fprintf(stdout, "data : %s\n", (char*)data);

    return send_event_to_hq(topic, data);
}
