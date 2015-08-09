#ifndef NULL_ERLANG_AI_COMMANDS_H
#define NULL_ERLANG_AI_COMMANDS_H

#include "rts/ExternalAI/Interface/SSkirmishAICallback.h"
#include "ei.h"

int handle_command(int team_id, const struct SSkirmishAICallback* callback, ei_x_buff buff);

#endif
