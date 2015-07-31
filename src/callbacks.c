
/* THIS FILE GETS GENERATED, DO NOT EDIT DIRECTLY! */

#include "ei.h"
#include "rts/ExternalAI/Interface/SSkirmishAICallback.h"

int handle_command(int skirmishAIId, const struct SSkirmishAICallback* callback, char* command, char* recvbuff, int index){
        if (strcmp(command, "fetch_getTeamUnits") == 0) {
            long unitIds_sizeMax;
            ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
            int unitIds[unitIds_sizeMax];
            int result = callback->getTeamUnits(skirmishAIId, unitIds, unitIds_sizeMax);
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 2);
            ei_x_encode_atom(&sendbuff, "result_getTeamUnits");
            int i = 0;
            for (; i < result; i++) {
                ei_x_encode_list_header(&sendbuff, 1);
                ei_x_encode_long(&sendbuff, unitIds[i]);
            }
            return send_to_hq(skirmishAIId, sendbuff);
        }
        return -1;
    }
