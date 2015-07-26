#include "AIExport.h"
#include "ExternalAI/Interface/SSkirmishAICallback.h"
#include "ExternalAI/Interface/AISCommands.h"


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
#define GENERAL "general"
#define NODE_NAME "springai"
#define COOKIE "springai"


int team_id = -1;
int frame = -1;

ei_cnode ec;
char hq_node[100];
int uplink = -1;
const struct SSkirmishAICallback* callback;


EXPORT(int) init(int new_team_id, const struct SSkirmishAICallback* new_callback) {
    team_id = new_team_id;
    callback = new_callback;

    fprintf(stdout, "sync version: %s\n", callback->Engine_Version_getFull(team_id));

    fprintf(stdout, "\n\n\t\tStarting up Erlang CNode, Team %i\n\n", team_id);

    if (ei_connect_init(&ec, NODE_NAME, COOKIE, team_id) < 0) {
        fprintf(stderr, "ERROR when initializing: %d", erl_errno);
        exit(-1);
    }

    sprintf(hq_node, "%s@%s", HQ_NODE, ei_thishostname(&ec));

    fprintf(stdout, "this node: %s\n", ei_thisnodename(&ec));
    // fprintf(stdout, "host: %s\n", ei_thishostname(&ec));
    fprintf(stdout, "  hq node: %s\n", hq_node);
    fprintf(stdout, "   cookie: %s\n", COOKIE);

    return 0;
}


int check_uplink() {
    if (uplink < 0) {
        uplink = ei_connect_tmo(&ec, hq_node, COMM_TMO);
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
    int result = 0;
    if (check_uplink() >= 0) {
        fprintf(stdout, "\tsend: ... --[%i]--> hq\n", uplink);
        if (ei_reg_send_tmo(&ec, uplink, GENERAL, buff.buff, buff.index, COMM_TMO) < 0) {
            fprintf(stderr, "\tsend failed: %i\n", erl_errno);
            result = -1;
        }
    } else {
        printf("no uplink?!\n");
    }
    ei_x_free(&buff);
    return result;
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
    if (ei_x_encode_binary(&sendbuf, data, sizeof(data)) < 0) {
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


int send_atom_intlist_to_hq(const char* atom, int* ls, int size) {
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
    return send_to_hq(buff);
}


int send_atom_long_atom_string_to_hq(const char* atom1, long l, const char* atom2, const char* s) {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_tuple_header(&buff, 4);
    ei_x_encode_atom(&buff, atom1);
    ei_x_encode_ulong(&buff, l);
    ei_x_encode_atom(&buff, atom2);
    ei_x_encode_string(&buff, s);
    return send_to_hq(buff);
}


int send_atom_int_atom_float3_to_hq(const char* atom1, int i, const char* atom2, const float* pos) {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_tuple_header(&buff, 6);
    ei_x_encode_atom(&buff, atom1);
    ei_x_encode_ulong(&buff, i);
    ei_x_encode_atom(&buff, atom2);
    ei_x_encode_double(&buff, pos[0]);
    ei_x_encode_double(&buff, pos[1]);
    ei_x_encode_double(&buff, pos[2]);
    return send_to_hq(buff);
}

int send_all_unit_ids() {
    int ids[100];
    int result = callback->getTeamUnits(team_id, ids, 100);
    fprintf(stdout, "result: %i\n", result);
    return send_atom_intlist_to_hq("teamunits", ids, result);
}


int send_unit_name(int unit_id) {
    int unit_def_id = callback->Unit_getDef(team_id, unit_id);
    const char* name = callback->UnitDef_getHumanName(team_id, unit_def_id);
    return send_atom_long_atom_string_to_hq("unit", unit_id, "name", name);
}


int unit_pos(int unit_id) {
    float pos[3];
    callback->Unit_getPos(team_id, unit_id, pos);
    return send_atom_int_atom_float3_to_hq("unit", unit_id, "pos", pos);
}


int move_unit(int unit_id, float* pos) {
    struct SMoveUnitCommand move_command = {
        unit_id,
        -1,
        0,
        INT_MAX,
        pos
    };
    callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_MOVE, &move_command);
}


int receive_command_from_hq() {
    if (check_uplink() < 0) {
        return 0;
    }

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
    } else if (strcmp(command, "send_all_unit_ids") == 0) {
        send_all_unit_ids();
    } else if (strcmp(command, "send_unit_name") == 0) {
        long id;
        ei_decode_long(recvbuf.buff, &index, &id);
        send_unit_name(id);
    } else if (strcmp(command, "unit_pos") == 0) {
        long id;
        ei_decode_long(recvbuf.buff, &index, &id);
        unit_pos(id);
    } else if (strcmp(command, "move") == 0) {
        long id;
        ei_decode_long(recvbuf.buff, &index, &id);
        double x, y, z;
        ei_decode_double(recvbuf.buff, &index, &x);
        ei_decode_double(recvbuf.buff, &index, &y);
        ei_decode_double(recvbuf.buff, &index, &z);
        float pos[3] = {(float)x, (float)y, (float)z};
        fprintf(stdout, "move %i to %f/%f\n", id, pos[0], pos[2]);
        move_unit(id, pos);
    }

    return 0;
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

    return send_event_to_hq(topic, data);
}
