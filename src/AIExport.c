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
#define CONNECT_TMO 10


#define HQ_NODE "hq@localhost"
#define GENERAL "general"


int ai_id = -1;
int frame = -1;

ei_cnode ec;
int uplink = -1;




EXPORT(int) init(int skirmishAIId, const struct SSkirmishAICallback* callback) {
    fprintf(stdout, "Starting up Erlang CNode %i\n", skirmishAIId);

    ai_id = skirmishAIId;

    if (ei_connect_init(&ec, "springai", "springai", ai_id) < 0) {
        fprintf(stderr, "ERROR when initializing: %d", erl_errno);
        exit(-1);
    }

    fprintf(stdout, "node: %s\n", ei_thisnodename(&ec));
    fprintf(stdout, "host: %s\n", ei_thishostname(&ec));

    return 0;
}


int check_uplink() {
    if (uplink < 0) {
        uplink = ei_connect_tmo(&ec, HQ_NODE, CONNECT_TMO);
        if (uplink < 0) {
            if (frame % 600 == 0) {
                fprintf(stderr, "uplink still not available\n");
            }
        } else {
            fprintf(stdout, "uplink established on channel %i\n", uplink);
        }
    }
    return uplink;
}


int send_to_hq(ei_x_buff buff) {
    if (check_uplink() < 0) {
        ei_x_free(&buff);
        return -1;
    }
    if (ei_reg_send(&ec, uplink, GENERAL, buff.buff, buff.index) < 0) {
        fprintf(stderr, "\tsend_tick failed: %i\n", erl_errno);
    }
    ei_x_free(&buff);
    return 0;
}


int receive_command_from_hq() {
    check_uplink();
    if (uplink < 0) {
        return 0;
    }

    erl_errno = 0;
    erlang_msg msg;
    ei_x_buff recvbuf;
    ei_x_new(&recvbuf);

    int got = ei_xreceive_msg_tmo(uplink, &msg, &recvbuf, 10);
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
                uplink = -1;
                break;
            case ETIMEDOUT:
                break;
        }
    } else {
        index = 0;
        ei_decode_version(recvbuf.buff, &index, &version);
        ei_decode_tuple_header(recvbuf.buff, &index, &arity);
        ei_decode_atom(recvbuf.buff, &index, command);

        fprintf(stdout, "\treceive: %s <--[%i]-- /%i, 0:'%s'\n", msg.toname, uplink, arity, command);
    }
    if (strcmp(command, "ping") == 0) {
        send_pong();
    }

    return 0;
}

int send_event_to_hq(int topic, const void* data) {
    fprintf(stdout, "\n\tsend: %i, data:'%s' --[%i]--> hq\n", topic, (char*)data, uplink);

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
    fprintf(stdout, "\t\tpayload size: %i bytes\n", sendbuf.index);

    return send_to_hq(sendbuf);
}

int send_pong() {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_atom(&buff, "pong");
    return send_to_hq(buff);
}

int send_tick() {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_atom(&buff, "tick");
    return send_to_hq(buff);
}

EXPORT(int) handleEvent(int skirmishAIId, int topic, const void* data) {
    if (topic == 3) {
        frame = *((int*)data);  // I 'love' pointers :o)
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
