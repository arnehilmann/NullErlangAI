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

ei_cnode ec;
int fd = -1;

EXPORT(int) init(int skirmishAIId, const struct SSkirmishAICallback* callback) {
    fprintf(stdout, "Starting up Erlang CNode %i\n", skirmishAIId);

    if (ei_connect_init(&ec, "springai", "springai", skirmishAIId) < 0) {
        fprintf(stderr, "ERROR when initializing: %d", erl_errno);
        exit(-1);
    }

    fprintf(stdout, "node: %s\n", ei_thisnodename(&ec));
    fprintf(stdout, "host: %s\n", ei_thishostname(&ec));

    return 0;
}


int receive_command_from_hq() {
    int hq = ensure_connection_to_hq();
    if (hq < 0) {
        return 0;
    }

    erl_errno = 0;

    // unsigned char buf[BUFSIZE];
    // int got = ei_receive_tmo(hq, buf, BUFSIZE, 10);

    erlang_msg msg;
    ei_x_buff recvbuf;
    ei_x_new(&recvbuf);

    int got = ei_xreceive_msg_tmo(hq, &msg, &recvbuf, 10);

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
                break;
            case ETIMEDOUT:
                break;
        }
    } else {
        fprintf(stdout, "message received\n");
        fprintf(stdout, "type: %li\n", msg.msgtype);
        fprintf(stdout, "toname: %s\n", msg.toname);
        fprintf(stdout, "buffer: %s\n", recvbuf.buff);
        fprintf(stdout, "buffer size: %i\n", recvbuf.buffsz);
        fprintf(stdout, "buffer index: %i\n", recvbuf.index);

        char command[24];
        int index, version, arity;

        index = 0;
        ei_decode_version(recvbuf.buff, &index, &version);
        fprintf(stdout, "version: %i\n", version);
        fprintf(stdout, "index: %i\n", index);

        ei_decode_tuple_header(recvbuf.buff, &index, &arity);
        fprintf(stdout, "arity: %i\n", arity);
        fprintf(stdout, "index: %i\n", index);

        ei_decode_atom(recvbuf.buff, &index, command);
        fprintf(stdout, "command: %s\n", command);
        fprintf(stdout, "index: %i\n", index);

        /*
        if (emsg.type == ERL_REG_SEND) {
            fromp = erl_element(2, emsg.msg);
            resp = erl_format("{cnode, test}");
            fprintf(stdout, "sending %s to %s\n", "{cnode, test}", "HQ");
            erl_send(hq, fromp, resp);
            erl_free_term(fromp);
            erl_free_term(resp);
        }
        */
    }
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

int send_event_to_hq(int aiid, int topic, const void* data) {
    fprintf(stdout, "sending event to hq\n");

    int hq;
    if ((hq = ensure_connection_to_hq()) < 0) {
        return 0;
    }
    fprintf(stdout, "hq %i connected\n", hq);


    /*
    ErlConnect conn;

    int loop = 1;
    int got;
    unsigned char buf[BUFSIZE];
    ErlMessage emsg;

    ETERM *fromp, *tuplep, *fnp, *argp, *resp;
    int res;

    if (fd < 0) {
        if ((fd = erl_connect("foo@elk")) < 0) {
            //erl_err_quit("connect");
            printf("no connect?\n");
            return 0;
        }
        printf("connected to foo@elk\n");
    }
    if (fd < 0) {
        return 0;
    }

    // ei_receive_msg_tmo
    got = erl_receive_msg(fd, buf, BUFSIZE, &emsg);
    if (got == ERL_TICK) {
        // ignore
    } else if (got == ERL_ERROR) {
        loop = 0;
    } else {
        if (emsg.type == ERL_REG_SEND) {
            fromp = erl_element(2, emsg.msg);
            resp = erl_format("{cnode, test}");
            fprintf(stdout, "sending %s to %s\n", "{cnode, test}", "foo@elk");
            erl_send(fd, fromp, resp);
            erl_free_term(fromp);
            erl_free_term(resp);
        }
    }

    / *
    //if ((fd = erl_accept(listen_socket, &conn)) == ERL_ERROR)
    int n;
//    fd_set *rfds, *wfds;
//    struct timeval tv = {0, 0};
//    n = select(listen_sockeud, rfds, wfds, NULL, &tv);

    n = 1;
    switch (n) {
        case 0:
            // printf("timeout\n");
            break;
        case -1:
            erl_err_quit("error in erl_accept");
            break;
        default:
            printf("waiting\n");
            fd = erl_accept(listen_socket, &conn);
            printf("TADAHHHH\n");
            got = erl_receive_msg(fd, buf, BUFSIZE, &emsg);
            if (got == ERL_TICK) {
                // ignore
            } else if (got == ERL_ERROR) {
                loop = 0;
            } else {
                if (emsg.type == ERL_REG_SEND) {
                    fromp = erl_element(2, emsg.msg);
                    tuplep = erl_element(3, emsg.msg);
                    fnp = erl_element(1, tuplep);
                    argp = erl_element(2, tuplep);

                    fprintf(stderr, "%s\n", fromp);

                    if (strncmp(ERL_ATOM_PTR(fnp), "foo", 3) == 0) {
                        res = foo(ERL_INT_VALUE(argp));
                    } else if (strncmp(ERL_ATOM_PTR(fnp), "bar", 3) == 0) {
                        res = bar(ERL_INT_VALUE(argp));
                    }

                    resp = erl_format("{cnode, ~i}", res);
                    erl_send(fd, fromp, resp);

                    erl_free_term(emsg.from); erl_free_term(emsg.msg);
                    erl_free_term(fromp); erl_free_term(tuplep);
                    erl_free_term(fnp); erl_free_term(argp);
                    erl_free_term(resp);
                }
            }
    }
    //fprintf(stderr, "Connected to %s\n\r", conn.nodename);
    */


    /*
    if ((fd = erl_accept(listen_socket, &conn)) == ERL_ERROR)
        erl_err_quit("erl_accept");
    printf("ACCEPTED!!!!!!!!!!!!!!\n");

    loop = 1;
    while (loop--) {
        printf(".");

        got = erl_receive_msg(fd, buf, BUFSIZE, &emsg);
        if (got == ERL_TICK) {
        } else if (got == ERL_ERROR) {
            loop = 0;
        } else {

            if (emsg.type == ERL_REG_SEND) {
                fromp = erl_element(2, emsg.msg);
                tuplep = erl_element(3, emsg.msg);
                fnp = erl_element(1, tuplep);
                argp = erl_element(2, tuplep);

                if (strncmp(ERL_ATOM_PTR(fnp), "foo", 3) == 0) {
                    res = foo(ERL_INT_VALUE(argp));
                } else if (strncmp(ERL_ATOM_PTR(fnp), "bar", 3) == 0) {
                    res = bar(ERL_INT_VALUE(argp));
                }

                resp = erl_format("{cnode, ~i}", res);
                erl_send(fd, fromp, resp);

                erl_free_term(emsg.from); erl_free_term(emsg.msg);
                erl_free_term(fromp); erl_free_term(tuplep);
                erl_free_term(fnp); erl_free_term(argp);
                erl_free_term(resp);
            }
        }
    }
    */

    // signal: ok
    return 0;
}


EXPORT(int) handleEvent(int skirmishAIId, int topic, const void* data) {
    if (topic == 3) {
        int frame = *((int*)data);  // I 'love' pointers :o)
        if (frame == 1) {
            fprintf(stdout, "\n                LET THE WAR BEGIN!\n\n");
        }
        if (frame % 6000 == 0) {
            fprintf(stdout, "frame: %i\n", frame);
        }
        if (frame % 600 == 0) {
            return receive_command_from_hq();
        }
        return 0;
    }

    fprintf(stdout, "ai id: %i\n", skirmishAIId);
    fprintf(stdout, "topic: %i\n", topic);
    fprintf(stdout, "data : %s\n", data);

    return send_event_to_hq(skirmishAIId, topic, data);
}
