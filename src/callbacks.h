#ifndef NULL_ERLANG_AI_CALLBACKS_H
#define NULL_ERLANG_AI_CALLBACKS_H

#include "ExternalAI/Interface/SSkirmishAICallback.h"

int handle_callback(int skirmishAIId, const struct SSkirmishAICallback* callback, char* recvbuff, int index);

#endif
