#include "AIExport.h"
#include "ExternalAI/Interface/SSkirmishAICallback.h"
#include "ExternalAI/Interface/AISCommands.h"
#include "events.h"
#include "callbacks.h"


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

#define HQ_NODE "hq"
#define COMMROOM "commroom"
#define NODE_NAME_PREFIX "erlang_ai"
#define COOKIE_PREFIX "erlang_ai"

#define MAX_TEAM_COUNT 4


int frame = -1;
char node_names[MAX_TEAM_COUNT][100];

char cookies[MAX_TEAM_COUNT][100];

ei_cnode ecs[MAX_TEAM_COUNT];
char hq_nodes[MAX_TEAM_COUNT][100];
int uplinks[MAX_TEAM_COUNT];
const struct SSkirmishAICallback* callbacks[MAX_TEAM_COUNT];


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

    sprintf(hq_nodes[team_id], "%s%i@%s", HQ_NODE, team_id, ei_thishostname(&ecs[team_id]));

    fprintf(stdout, "this node: %s\n", ei_thisnodename(&ecs[team_id]));
    // fprintf(stdout, "host: %s\n", ei_thishostname(&ec));
    fprintf(stdout, "  hq node: %s\n", hq_nodes[team_id]);
    fprintf(stdout, "   cookie: %s\n", cookies[team_id]);

    return 0;
}


int check_uplink(int team_id) {
    int uplink = uplinks[team_id];
    ei_cnode ec = ecs[team_id];
    char* hq_node = hq_nodes[team_id];
    if (uplink <= 0) {
        uplink = ei_connect_tmo(&ec, hq_node, COMM_TMO);
        if (uplink <= 0) {
            if (frame % 600 == 0) {
                fprintf(stderr, "uplink still not available\n");
            }
            return -1;
        } else {
            fprintf(stdout, "uplink established on channel %i\n", uplink);
        }
        uplinks[team_id] = uplink;
    }
    return 0;
}


int send_to_hq(int team_id, ei_x_buff buff) {
    int result = 0;
    if (check_uplink(team_id) >= 0) {
        //fprintf(stdout, "[%s] --[%i]--> hq\n", ei_thishostname(&ec), uplink);
        int uplink = uplinks[team_id];
        ei_cnode ec = ecs[team_id];
        if (ei_reg_send_tmo(&ec, uplink, COMMROOM, buff.buff, buff.index, COMM_TMO) < 0) {
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
    fprintf(stdout, "[%s] topic %i --[%i]--> %s\n", cookies[team_id], topic, uplink, hq_nodes[team_id]);

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

    return send_to_hq(team_id, sendbuf);
}


int send_pong(int team_id) {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_atom(&buff, "pong");
    return send_to_hq(team_id, buff);
}


int send_tick(int team_id, int frame) {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_atom(&buff, "tick");
    ei_x_encode_long(&buff, frame);
    return send_to_hq(team_id, buff);
}


int send_atom_intlist_to_hq(int team_id, const char* atom, int* ls, int size) {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_tuple_header(&buff, 2);
    ei_x_encode_atom(&buff, atom);
    int i = 0;
    for (; i < size; i++) {
        ei_x_encode_list_header(&buff, 1);
        ei_x_encode_ulong(&buff, ls[i]);
    }
    ei_x_encode_empty_list(&buff);
    return send_to_hq(team_id, buff);
}


int send_atom_long_atom_string_to_hq(int team_id, const char* atom1, long l, const char* atom2, const char* s) {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_tuple_header(&buff, 4);
    ei_x_encode_atom(&buff, atom1);
    ei_x_encode_ulong(&buff, l);
    ei_x_encode_atom(&buff, atom2);
    ei_x_encode_string(&buff, s);
    return send_to_hq(team_id, buff);
}


int send_atom_int_atom_float3_to_hq(int team_id, const char* atom1, int i, const char* atom2, const float* pos) {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_tuple_header(&buff, 6);
    ei_x_encode_atom(&buff, atom1);
    ei_x_encode_ulong(&buff, i);
    ei_x_encode_atom(&buff, atom2);
    ei_x_encode_double(&buff, pos[0]);
    ei_x_encode_double(&buff, pos[1]);
    ei_x_encode_double(&buff, pos[2]);
    return send_to_hq(team_id, buff);
}

int send_all_unit_ids(int team_id) {
    int ids[100];
    int result = callbacks[team_id]->getTeamUnits(team_id, ids, 100);
    fprintf(stdout, "result: %i\n", result);
    return send_atom_intlist_to_hq(team_id, "teamunits", ids, result);
}


int send_unit_name(int team_id, int unit_id) {
    int unit_def_id = callbacks[team_id]->Unit_getDef(team_id, unit_id);
    const char* name = callbacks[team_id]->UnitDef_getHumanName(team_id, unit_def_id);
    return send_atom_long_atom_string_to_hq(team_id, "unit", unit_id, "name", name);
}


int unit_pos(int team_id, int unit_id) {
    float pos[3];
    callbacks[team_id]->Unit_getPos(team_id, unit_id, pos);
    return send_atom_int_atom_float3_to_hq(team_id, "unit", unit_id, "pos", pos);
}


int move_unit(int team_id, int unit_id, float* pos) {
    struct SMoveUnitCommand move_command = {
        unit_id,
        -1,
        0,
        INT_MAX,
        pos
    };
    callbacks[team_id]->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_MOVE, &move_command);
}


int check_for_command_from_hq(int team_id) {
    if (check_uplink(team_id) < 0) {
        return 0;
    }

    int uplink = uplinks[team_id];

    erl_errno = 0;
    erlang_msg msg;
    ei_x_buff recvbuf;
    ei_x_new(&recvbuf);

    int got = ei_xreceive_msg_tmo(uplink, &msg, &recvbuf, COMM_TMO);
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
                uplinks[team_id] = -1;
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
        send_pong(team_id);
    } else if (strcmp(command, "send_all_unit_ids") == 0) {
        send_all_unit_ids(team_id);
    } else if (strcmp(command, "send_unit_name") == 0) {
        long id;
        ei_decode_long(recvbuf.buff, &index, &id);
        send_unit_name(team_id, id);
    } else if (strcmp(command, "unit_pos") == 0) {
        long id;
        ei_decode_long(recvbuf.buff, &index, &id);
        unit_pos(team_id, id);
    } else if (strcmp(command, "move") == 0) {
        long id;
        ei_decode_long(recvbuf.buff, &index, &id);
        double x, y, z;
        ei_decode_double(recvbuf.buff, &index, &x);
        ei_decode_double(recvbuf.buff, &index, &y);
        ei_decode_double(recvbuf.buff, &index, &z);
        float pos[3] = {(float)x, (float)y, (float)z};
        fprintf(stdout, "move %li to %f/%f\n", id, pos[0], pos[2]);
        move_unit(team_id, id, pos);
    } else {
        handle_command(team_id, callbacks[team_id], command, recvbuf.buff, index);
    }

    return 0;
}


EXPORT(int) handleEvent(int team_id, int topic, const void* data) {
    if (topic == 3) {
        frame = *((int*)data);  // I 'love' pointers :o)
        if (frame == 1) {
            fprintf(stdout, "\n                LET THE WAR BEGIN!\n\n");
        }
        if (frame % 6000 == 0) {
            send_tick(team_id, frame);
        }
        if (frame % 60 == 0) {
            return check_for_command_from_hq(team_id);
        }
        return 0;
    }

    return send_event(team_id, topic, data);
}
