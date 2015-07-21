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

ei_x_buff sendbuf;
ei_x_buff recvbuf;



EXPORT(int) init(int skirmishAIId, const struct SSkirmishAICallback* callback) {
    fprintf(stdout, "Starting up Erlang CNode %i\n", skirmishAIId);

    if (ei_connect_init(&ec, "springai", "springai", skirmishAIId) < 0) {
        fprintf(stderr, "ERROR when initializing: %d", erl_errno);
        exit(-1);
    }

    fprintf(stdout, "node: %s\n", ei_thisnodename(&ec));
    fprintf(stdout, "host: %s\n", ei_thishostname(&ec));

    ei_x_new(&recvbuf);

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

    erlang_msg msg;

    erl_errno = 0;
    int got = ei_xreceive_msg_tmo(fd, &msg, &recvbuf, 10);

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
                break;
            case ETIMEDOUT:
                break;
        }
    } else {
        hq = msg.from;

        char command[24];
        int index, version, arity;

        index = 0;
        ei_decode_version(recvbuf.buff, &index, &version);
        ei_decode_tuple_header(recvbuf.buff, &index, &arity);
        ei_decode_atom(recvbuf.buff, &index, command);

        fprintf(stdout, "\t%s <--[%i]-- /%i, 0:'%s'\n", msg.toname, fd, arity, command);
        if (strcmp(command, "ping") == 0) {
            send_event_to_hq(42, "pong");
        }

    }
    return 0;
}

int send_event_to_hq(int topic, const void* data) {
    if (ensure_connection_to_hq() < 0) {
        fprintf(stderr, "\thq unreachable, dropping topic %i\n", topic);
        return 0;
    }
    fprintf(stdout, "\t%i, data:'%s' --[%i]--> %s\n", topic, (char*)data, fd, hq.node);

    ei_x_new_with_version(&sendbuf);
    ei_x_encode_tuple_header(&sendbuf, 3);
    ei_x_encode_atom(&sendbuf, "event");
    ei_x_encode_long(&sendbuf, topic);

    //char* argh = "heureka again again";
    char argh[10] = "wtf";
    //ei_x_encode_string(&sendbuf, argh);
    ei_x_encode_string(&sendbuf, "heureka again");
    //ei_x_encode_string(&sendbuf, data);
    //ei_x_encode_binary(&sendbuf, data, sizeof(data));
    if (ei_send_tmo(fd, &hq, sendbuf.buff, sendbuf.index, 100) < 0) {
        fprintf(stdout, "\tsend_event_to_hq failed: %i\n", erl_errno);
    }
    ei_x_free(&sendbuf);

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
            send_event_to_hq(42, "tick");
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
