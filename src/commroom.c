#include "commroom.h"

#include "ExternalAI/Interface/SSkirmishAICallback.h"
//#include "ExternalAI/Interface/AISCommands.h"
#include "send_to.h"
#include "events.h"
#include "callbacks.h"
#include "commands.h"


#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "erl_interface.h"
#include "ei.h"

#define BUFSIZE 1000
#define COMM_TMO 10

#define NODE_NAME_PREFIX "erlang_ai"
#define COOKIE_PREFIX "erlang_ai"
#define PORT 7766

#define MAX_TEAM_COUNT 4


int frame = -1;
char node_names[MAX_TEAM_COUNT][100];
char cookies[MAX_TEAM_COUNT][100];

ei_cnode ecs[MAX_TEAM_COUNT];
erlang_pid hq[MAX_TEAM_COUNT];
int listen_fd[MAX_TEAM_COUNT];
ErlConnect conns[MAX_TEAM_COUNT];
int uplinks[MAX_TEAM_COUNT];
const struct SSkirmishAICallback* callbacks[MAX_TEAM_COUNT];


int my_listen(int port) {
    int listen_fd;
    struct sockaddr_in addr;
    int on = 1;

    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return (-1);

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    memset((void*) &addr, 0, (size_t) sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_fd, (struct sockaddr*) &addr, sizeof(addr)) < 0)
        return (-1);

    listen(listen_fd, 5);
    return listen_fd;
}


EXPORT(int) init(int team_id, const struct SSkirmishAICallback* new_callback) {
    callbacks[team_id] = new_callback;

    fprintf(stdout, "sync version: %s\n", callbacks[team_id]->Engine_Version_getFull(team_id));

    fprintf(stdout, "\n\n\t\tStarting up Erlang CNode, Team %i\n\n", team_id);

    sprintf(node_names[team_id], "%s%i", NODE_NAME_PREFIX, team_id);
    sprintf(cookies[team_id], "%s%i", COOKIE_PREFIX, team_id);

    if (ei_connect_init(&ecs[team_id], node_names[team_id], cookies[team_id], team_id) < 0) {
        fprintf(stderr, "ERROR when initializing: %d", erl_errno);
        exit(-1);
    }

    fprintf(stdout, "this node: %s\n", ei_thisnodename(&ecs[team_id]));
    fprintf(stdout, "   cookie: %s\n", cookies[team_id]);

    int i=0;
    for (; i < MAX_TEAM_COUNT; i++) {
        uplinks[i] = -1;
    }

    if ((listen_fd[team_id] = my_listen(PORT)) <= 0) {
        fprintf(stderr, "cannot open listen port on %i\n", PORT);
        exit(-1);
    }

    if (ei_publish(&ecs[team_id], PORT) == -1) {
        fprintf(stderr, "cannot reach epmd\n");
        exit(1);
    }

    return 0;
}


EXPORT(int) send_to_hq(int team_id, ei_x_buff buff) {
    printf("send_to_hq\n");
    int result = 0;
    int uplink = uplinks[team_id];
    if (uplink > 0) {
        if (ei_send_tmo(uplink, &hq[team_id], buff.buff, buff.index, COMM_TMO) < 0) {
            fprintf(stderr, "\tsend failed: %i\n", erl_errno);
            result = -1;
        }
    } else {
        printf("no uplink?!\n");
    }
    ei_x_free(&buff);
    return result;
}

EXPORT(int) send_to_pid(int team_id, erlang_pid* pid, ei_x_buff buff) {
    int result = 0;
    int uplink = uplinks[team_id];
    if (uplink > 0) {
        if (ei_send_tmo(uplink, pid, buff.buff, buff.index, COMM_TMO) < 0) {
            fprintf(stderr, "\tsend failed: %i\n", erl_errno);
            result = -1;
        }
    } else {
        printf("no uplink?!\n");
    }
    ei_x_free(&buff);
    return result;
}

int send_event(int team_id, int topic, const void* data) {
    int uplink = uplinks[team_id];
    if (uplink < 0) {
        fprintf(stderr, "cannot send event, dropping it...\n");
        return 0;
    }
    fprintf(stdout, "[%s] topic %i --[%i]--> hq\n", cookies[team_id], topic, uplink);

    erl_errno = 0;
    ei_x_buff sendbuf;
    ei_x_new_with_version(&sendbuf);
    ei_x_encode_tuple_header(&sendbuf, 3);
    ei_x_encode_atom(&sendbuf, "event");

    if (add_event_data(&sendbuf, topic, data) < 0) {
        printf("cannot add event data?!\n");
        ei_x_free(&sendbuf);
        return 1;
    }

    return send_to_pid(team_id, &hq[team_id], sendbuf);
}


int send_pong(int team_id, erlang_pid pid) {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_atom(&buff, "pong");
    return send_to_pid(team_id, &pid, buff);
}


int send_tick(int team_id, int frame) {
    ei_cnode ec = ecs[team_id];
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_tuple_header(&buff, 3);
    ei_x_encode_atom(&buff, "tick");
    ei_x_encode_long(&buff, frame);
    ei_x_encode_pid(&buff, ei_self(&ec));
    return send_to_hq(team_id, buff);
}


int check_for_message_from_hq(int team_id) {
    int uplink = uplinks[team_id];
    if (uplink < 0) {
        uplinks[team_id] = ei_accept_tmo(&ecs[team_id], listen_fd[team_id], &conns[team_id], 1000);
        if (uplinks[team_id] < 0) {
            fprintf(stderr, "no one tried to connect, yielding...\n");
            return 0;
        }
        printf("connected to %s\n", conns[team_id].nodename);
    }

    erl_errno = 0;
    erlang_msg msg;
    ei_x_buff recvbuf;
    ei_x_new(&recvbuf);

    int got = ei_xreceive_msg_tmo(uplink, &msg, &recvbuf, COMM_TMO);
    char message[24] = "";
    int version, arity;

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
                uplinks[team_id] = -1;
                break;
            case ETIMEDOUT:
                break;
        }
    } else {
        recvbuf.index = 0;
        ei_decode_version(recvbuf.buff, &recvbuf.index, &version);
        ei_decode_tuple_header(recvbuf.buff, &recvbuf.index, &arity);
        ei_decode_atom(recvbuf.buff, &recvbuf.index, message);

        printf("received: %s <--[%i]-- /%i, 0:'%s'\n", msg.toname, uplink, arity, message);
    }
//    if (strcmp(message, "ping") == 0) {
//        erlang_pid from;
//        ei_decode_pid(recvbuf.buff, &recvbuf.index, &from);
//        send_pong(team_id, from);
//    }
    if (strcmp(message, "register") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuf.buff, &recvbuf.index, &from);
        hq[team_id] = from;
        ei_x_buff sendbuf;
        ei_x_new_with_version(&sendbuf);
        ei_x_encode_tuple_header(&sendbuf, 2);
        ei_x_encode_atom(&sendbuf, "ok");
        ei_x_encode_pid(&sendbuf, ei_self(&ecs[team_id]));
        return send_to_pid(team_id, &hq[team_id], sendbuf);
    }
    if (strcmp(message, "callback") == 0) {
        return handle_callback(team_id, callbacks[team_id], recvbuf);
    }
    if (strcmp(message, "command") == 0) {
        return handle_command(team_id, callbacks[team_id], recvbuf);
    }

    return 0;
}


EXPORT(int) handleEvent(int team_id, int topic, const void* data) {
    if (topic == 3) {
        frame = *((int*)data);  // I 'love' pointers :o)
        if (frame == 1) {
            fprintf(stdout, "\n                LET THE WAR BEGIN!\n\n");
        }
        //if (frame % 600 == 0) {
            //return send_tick(team_id, frame);
        //}
        if (frame % 10 == 0) {
            return check_for_message_from_hq(team_id);
        }
        return 0;
    }

    return send_event(team_id, topic, data);
}
