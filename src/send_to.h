#ifndef _SENDTO_H
#define _SENDTO_H

#include "ei.h"

EXPORT(int) send_to_hq(int team_id, ei_x_buff buff);
EXPORT(int) send_to_pid(int team_id, erlang_pid* pid, ei_x_buff buff);

EXPORT(int) answer(int team_id, erlang_pid* pid, char* what);
EXPORT(int) answer_ok(int team_id, erlang_pid* pid);
EXPORT(int) answer_error(int team_id, erlang_pid* pid);

#endif // _SENDTO_H
