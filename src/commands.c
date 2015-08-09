
/* GENERATED FILE, DO NOT EDIT DIRECTLY */

#include "commands.h"

#include <string.h>
#include "ei.h"

#include "rts/ExternalAI/Interface/AISCommands.h"

#include "send_to.h"

int handle_command(int team_id, const struct SSkirmishAICallback* callback, ei_x_buff buff) {
    char command[64] = "";
    ei_decode_atom(recvbuff, &index, command);

    char command[64] = "";
    {
        int result = ei_decode_atom(buff.buff, &buff.index, command);
        if (result != 0) {
            fprintf(stderr, "[ERROR] cannot decode 'command' as 'char*', error code %i\n", result);
            ei_x_free(&buff);
            return result;
        }
    }
    if (strcmp(command, "COMMAND_CHEATS_GIVE_ME_NEW_UNIT") == 0) {
        long unitDefId_tmp;
        ei_decode_long(recvbuff, &index, &unitDefId_tmp);
        int unitDefId = (int)unitDefId_tmp;
        float pos_posF3[3];
        double pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[0] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[1] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[2] = (float)pos_posF3_tmp;
        int ret_newUnitId;
        struct SGiveMeNewUnitCheatCommand command = {
            unitDefId,
            pos_posF3,
            ret_newUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_CHEATS_GIVE_ME_NEW_UNIT, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_newUnitId");
            ei_x_encode_long(&sendbuff, command.ret_newUnitId);
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_CHEATS_GIVE_ME_RESOURCE") == 0) {
        long resourceId_tmp;
        ei_decode_long(recvbuff, &index, &resourceId_tmp);
        int resourceId = (int)resourceId_tmp;
        double amount_tmp;
        ei_decode_double(recvbuff, &index, &amount_tmp);
        float amount = (float)amount_tmp;
        struct SGiveMeResourceCheatCommand command = {
            resourceId,
            amount,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_CHEATS_GIVE_ME_RESOURCE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_CHEATS_SET_MY_INCOME_MULTIPLIER") == 0) {
        double factor_tmp;
        ei_decode_double(recvbuff, &index, &factor_tmp);
        float factor = (float)factor_tmp;
        struct SSetMyIncomeMultiplierCheatCommand command = {
            factor,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_CHEATS_SET_MY_INCOME_MULTIPLIER, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_LINE_ADD_POINT") == 0) {
        long lineId_tmp;
        ei_decode_long(recvbuff, &index, &lineId_tmp);
        int lineId = (int)lineId_tmp;
        double x_tmp;
        ei_decode_double(recvbuff, &index, &x_tmp);
        float x = (float)x_tmp;
        double y_tmp;
        ei_decode_double(recvbuff, &index, &y_tmp);
        float y = (float)y_tmp;
        struct SAddPointLineGraphDrawerDebugCommand command = {
            lineId,
            x,
            y,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_LINE_ADD_POINT, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_LINE_DELETE_POINTS") == 0) {
        long lineId_tmp;
        ei_decode_long(recvbuff, &index, &lineId_tmp);
        int lineId = (int)lineId_tmp;
        long numPoints_tmp;
        ei_decode_long(recvbuff, &index, &numPoints_tmp);
        int numPoints = (int)numPoints_tmp;
        struct SDeletePointsLineGraphDrawerDebugCommand command = {
            lineId,
            numPoints,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_LINE_DELETE_POINTS, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_SET_POS") == 0) {
        double x_tmp;
        ei_decode_double(recvbuff, &index, &x_tmp);
        float x = (float)x_tmp;
        double y_tmp;
        ei_decode_double(recvbuff, &index, &y_tmp);
        float y = (float)y_tmp;
        struct SSetPositionGraphDrawerDebugCommand command = {
            x,
            y,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_SET_POS, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_SET_SIZE") == 0) {
        double w_tmp;
        ei_decode_double(recvbuff, &index, &w_tmp);
        float w = (float)w_tmp;
        double h_tmp;
        ei_decode_double(recvbuff, &index, &h_tmp);
        float h = (float)h_tmp;
        struct SSetSizeGraphDrawerDebugCommand command = {
            w,
            h,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_SET_SIZE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_DELETE") == 0) {
        long overlayTextureId_tmp;
        ei_decode_long(recvbuff, &index, &overlayTextureId_tmp);
        int overlayTextureId = (int)overlayTextureId_tmp;
        struct SDeleteOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_DELETE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_POS") == 0) {
        long overlayTextureId_tmp;
        ei_decode_long(recvbuff, &index, &overlayTextureId_tmp);
        int overlayTextureId = (int)overlayTextureId_tmp;
        double x_tmp;
        ei_decode_double(recvbuff, &index, &x_tmp);
        float x = (float)x_tmp;
        double y_tmp;
        ei_decode_double(recvbuff, &index, &y_tmp);
        float y = (float)y_tmp;
        struct SSetPositionOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
            x,
            y,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_POS, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_SIZE") == 0) {
        long overlayTextureId_tmp;
        ei_decode_long(recvbuff, &index, &overlayTextureId_tmp);
        int overlayTextureId = (int)overlayTextureId_tmp;
        double w_tmp;
        ei_decode_double(recvbuff, &index, &w_tmp);
        float w = (float)w_tmp;
        double h_tmp;
        ei_decode_double(recvbuff, &index, &h_tmp);
        float h = (float)h_tmp;
        struct SSetSizeOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
            w,
            h,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_SIZE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DRAWER_FIGURE_DELETE") == 0) {
        long figureGroupId_tmp;
        ei_decode_long(recvbuff, &index, &figureGroupId_tmp);
        int figureGroupId = (int)figureGroupId_tmp;
        struct SDeleteFigureDrawerCommand command = {
            figureGroupId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_FIGURE_DELETE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DRAWER_LINE_ADD") == 0) {
        float posFrom_posF3[3];
        double posFrom_posF3_tmp;
        ei_decode_double(recvbuff, &index, &posFrom_posF3_tmp);
        posFrom_posF3[0] = (float)posFrom_posF3_tmp;
        ei_decode_double(recvbuff, &index, &posFrom_posF3_tmp);
        posFrom_posF3[1] = (float)posFrom_posF3_tmp;
        ei_decode_double(recvbuff, &index, &posFrom_posF3_tmp);
        posFrom_posF3[2] = (float)posFrom_posF3_tmp;
        float posTo_posF3[3];
        double posTo_posF3_tmp;
        ei_decode_double(recvbuff, &index, &posTo_posF3_tmp);
        posTo_posF3[0] = (float)posTo_posF3_tmp;
        ei_decode_double(recvbuff, &index, &posTo_posF3_tmp);
        posTo_posF3[1] = (float)posTo_posF3_tmp;
        ei_decode_double(recvbuff, &index, &posTo_posF3_tmp);
        posTo_posF3[2] = (float)posTo_posF3_tmp;
        struct SAddLineDrawCommand command = {
            posFrom_posF3,
            posTo_posF3,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_LINE_ADD, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DRAWER_PATH_DRAW_ICON_AT_LAST_POS") == 0) {
        long cmdId_tmp;
        ei_decode_long(recvbuff, &index, &cmdId_tmp);
        int cmdId = (int)cmdId_tmp;
        struct SDrawIconAtLastPosPathDrawerCommand command = {
            cmdId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_PATH_DRAW_ICON_AT_LAST_POS, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DRAWER_POINT_REMOVE") == 0) {
        float pos_posF3[3];
        double pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[0] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[1] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[2] = (float)pos_posF3_tmp;
        struct SRemovePointDrawCommand command = {
            pos_posF3,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_POINT_REMOVE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_GROUP_CREATE") == 0) {
        int ret_groupId;
        struct SCreateGroupCommand command = {
            ret_groupId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_GROUP_CREATE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_groupId");
            ei_x_encode_long(&sendbuff, command.ret_groupId);
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_GROUP_ERASE") == 0) {
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        struct SEraseGroupCommand command = {
            groupId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_GROUP_ERASE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_PATH_FREE") == 0) {
        long pathId_tmp;
        ei_decode_long(recvbuff, &index, &pathId_tmp);
        int pathId = (int)pathId_tmp;
        struct SFreePathCommand command = {
            pathId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_PATH_FREE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_PATH_INIT") == 0) {
        float start_posF3[3];
        double start_posF3_tmp;
        ei_decode_double(recvbuff, &index, &start_posF3_tmp);
        start_posF3[0] = (float)start_posF3_tmp;
        ei_decode_double(recvbuff, &index, &start_posF3_tmp);
        start_posF3[1] = (float)start_posF3_tmp;
        ei_decode_double(recvbuff, &index, &start_posF3_tmp);
        start_posF3[2] = (float)start_posF3_tmp;
        float end_posF3[3];
        double end_posF3_tmp;
        ei_decode_double(recvbuff, &index, &end_posF3_tmp);
        end_posF3[0] = (float)end_posF3_tmp;
        ei_decode_double(recvbuff, &index, &end_posF3_tmp);
        end_posF3[1] = (float)end_posF3_tmp;
        ei_decode_double(recvbuff, &index, &end_posF3_tmp);
        end_posF3[2] = (float)end_posF3_tmp;
        long pathType_tmp;
        ei_decode_long(recvbuff, &index, &pathType_tmp);
        int pathType = (int)pathType_tmp;
        double goalRadius_tmp;
        ei_decode_double(recvbuff, &index, &goalRadius_tmp);
        float goalRadius = (float)goalRadius_tmp;
        int ret_pathId;
        struct SInitPathCommand command = {
            start_posF3,
            end_posF3,
            pathType,
            goalRadius,
            ret_pathId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_PATH_INIT, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_pathId");
            ei_x_encode_long(&sendbuff, command.ret_pathId);
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_SET_LAST_POS_MESSAGE") == 0) {
        float pos_posF3[3];
        double pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[0] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[1] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[2] = (float)pos_posF3_tmp;
        struct SSetLastPosMessageCommand command = {
            pos_posF3,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_SET_LAST_POS_MESSAGE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_TRACE_RAY") == 0) {
        float rayPos_posF3[3];
        double rayPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayPos_posF3_tmp);
        rayPos_posF3[0] = (float)rayPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayPos_posF3_tmp);
        rayPos_posF3[1] = (float)rayPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayPos_posF3_tmp);
        rayPos_posF3[2] = (float)rayPos_posF3_tmp;
        float rayDir_posF3[3];
        double rayDir_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayDir_posF3_tmp);
        rayDir_posF3[0] = (float)rayDir_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayDir_posF3_tmp);
        rayDir_posF3[1] = (float)rayDir_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayDir_posF3_tmp);
        rayDir_posF3[2] = (float)rayDir_posF3_tmp;
        long srcUnitId_tmp;
        ei_decode_long(recvbuff, &index, &srcUnitId_tmp);
        int srcUnitId = (int)srcUnitId_tmp;
        int ret_hitUnitId;
        long flags_tmp;
        ei_decode_long(recvbuff, &index, &flags_tmp);
        int flags = (int)flags_tmp;
        struct STraceRayCommand command = {
            rayPos_posF3,
            rayDir_posF3,
            srcUnitId,
            ret_hitUnitId,
            flags,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_TRACE_RAY, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_hitUnitId");
            ei_x_encode_long(&sendbuff, command.ret_hitUnitId);
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_TRACE_RAY_FEATURE") == 0) {
        float rayPos_posF3[3];
        double rayPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayPos_posF3_tmp);
        rayPos_posF3[0] = (float)rayPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayPos_posF3_tmp);
        rayPos_posF3[1] = (float)rayPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayPos_posF3_tmp);
        rayPos_posF3[2] = (float)rayPos_posF3_tmp;
        float rayDir_posF3[3];
        double rayDir_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayDir_posF3_tmp);
        rayDir_posF3[0] = (float)rayDir_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayDir_posF3_tmp);
        rayDir_posF3[1] = (float)rayDir_posF3_tmp;
        ei_decode_double(recvbuff, &index, &rayDir_posF3_tmp);
        rayDir_posF3[2] = (float)rayDir_posF3_tmp;
        long srcUnitId_tmp;
        ei_decode_long(recvbuff, &index, &srcUnitId_tmp);
        int srcUnitId = (int)srcUnitId_tmp;
        int ret_hitFeatureId;
        long flags_tmp;
        ei_decode_long(recvbuff, &index, &flags_tmp);
        int flags = (int)flags_tmp;
        struct SFeatureTraceRayCommand command = {
            rayPos_posF3,
            rayDir_posF3,
            srcUnitId,
            ret_hitFeatureId,
            flags,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_TRACE_RAY_FEATURE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_hitFeatureId");
            ei_x_encode_long(&sendbuff, command.ret_hitFeatureId);
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_AI_SELECT") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        struct SAiSelectUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_AI_SELECT, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_ATTACK") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toAttackUnitId_tmp;
        ei_decode_long(recvbuff, &index, &toAttackUnitId_tmp);
        int toAttackUnitId = (int)toAttackUnitId_tmp;
        struct SAttackUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toAttackUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_ATTACK, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_ATTACK_AREA") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float toAttackPos_posF3[3];
        double toAttackPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toAttackPos_posF3_tmp);
        toAttackPos_posF3[0] = (float)toAttackPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toAttackPos_posF3_tmp);
        toAttackPos_posF3[1] = (float)toAttackPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toAttackPos_posF3_tmp);
        toAttackPos_posF3[2] = (float)toAttackPos_posF3_tmp;
        double radius_tmp;
        ei_decode_double(recvbuff, &index, &radius_tmp);
        float radius = (float)radius_tmp;
        struct SAttackAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toAttackPos_posF3,
            radius,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_ATTACK_AREA, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_BUILD") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toBuildUnitDefId_tmp;
        ei_decode_long(recvbuff, &index, &toBuildUnitDefId_tmp);
        int toBuildUnitDefId = (int)toBuildUnitDefId_tmp;
        float buildPos_posF3[3];
        double buildPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &buildPos_posF3_tmp);
        buildPos_posF3[0] = (float)buildPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &buildPos_posF3_tmp);
        buildPos_posF3[1] = (float)buildPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &buildPos_posF3_tmp);
        buildPos_posF3[2] = (float)buildPos_posF3_tmp;
        long facing_tmp;
        ei_decode_long(recvbuff, &index, &facing_tmp);
        int facing = (int)facing_tmp;
        struct SBuildUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toBuildUnitDefId,
            buildPos_posF3,
            facing,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_BUILD, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_CAPTURE") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toCaptureUnitId_tmp;
        ei_decode_long(recvbuff, &index, &toCaptureUnitId_tmp);
        int toCaptureUnitId = (int)toCaptureUnitId_tmp;
        struct SCaptureUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toCaptureUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_CAPTURE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_CAPTURE_AREA") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float pos_posF3[3];
        double pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[0] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[1] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[2] = (float)pos_posF3_tmp;
        double radius_tmp;
        ei_decode_double(recvbuff, &index, &radius_tmp);
        float radius = (float)radius_tmp;
        struct SCaptureAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_CAPTURE_AREA, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_CUSTOM") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long cmdId_tmp;
        ei_decode_long(recvbuff, &index, &cmdId_tmp);
        int cmdId = (int)cmdId_tmp;
        float params[3];
        double params_tmp;
        ei_decode_double(recvbuff, &index, &params_tmp);
        params[0] = (float)params_tmp;
        ei_decode_double(recvbuff, &index, &params_tmp);
        params[1] = (float)params_tmp;
        ei_decode_double(recvbuff, &index, &params_tmp);
        params[2] = (float)params_tmp;
        long params_size_tmp;
        ei_decode_long(recvbuff, &index, &params_size_tmp);
        int params_size = (int)params_size_tmp;
        struct SCustomUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            cmdId,
            params,
            params_size,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_CUSTOM, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_D_GUN") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toAttackUnitId_tmp;
        ei_decode_long(recvbuff, &index, &toAttackUnitId_tmp);
        int toAttackUnitId = (int)toAttackUnitId_tmp;
        struct SDGunUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toAttackUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_D_GUN, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_D_GUN_POS") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float pos_posF3[3];
        double pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[0] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[1] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[2] = (float)pos_posF3_tmp;
        struct SDGunPosUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_D_GUN_POS, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_FIGHT") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float toPos_posF3[3];
        double toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[0] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[1] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[2] = (float)toPos_posF3_tmp;
        struct SFightUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_FIGHT, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_GROUP_ADD") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toGroupId_tmp;
        ei_decode_long(recvbuff, &index, &toGroupId_tmp);
        int toGroupId = (int)toGroupId_tmp;
        struct SGroupAddUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toGroupId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_GROUP_ADD, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_GROUP_CLEAR") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        struct SGroupClearUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_GROUP_CLEAR, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_GUARD") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toGuardUnitId_tmp;
        ei_decode_long(recvbuff, &index, &toGuardUnitId_tmp);
        int toGuardUnitId = (int)toGuardUnitId_tmp;
        struct SGuardUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toGuardUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_GUARD, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_LOAD_ONTO") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long transporterUnitId_tmp;
        ei_decode_long(recvbuff, &index, &transporterUnitId_tmp);
        int transporterUnitId = (int)transporterUnitId_tmp;
        struct SLoadOntoUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            transporterUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_LOAD_ONTO, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_LOAD_UNITS_AREA") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float pos_posF3[3];
        double pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[0] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[1] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[2] = (float)pos_posF3_tmp;
        double radius_tmp;
        ei_decode_double(recvbuff, &index, &radius_tmp);
        float radius = (float)radius_tmp;
        struct SLoadUnitsAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_LOAD_UNITS_AREA, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_MOVE") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float toPos_posF3[3];
        double toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[0] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[1] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[2] = (float)toPos_posF3_tmp;
        struct SMoveUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_MOVE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_PATROL") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float toPos_posF3[3];
        double toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[0] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[1] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[2] = (float)toPos_posF3_tmp;
        struct SPatrolUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_PATROL, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RECLAIM_AREA") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float pos_posF3[3];
        double pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[0] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[1] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[2] = (float)pos_posF3_tmp;
        double radius_tmp;
        ei_decode_double(recvbuff, &index, &radius_tmp);
        float radius = (float)radius_tmp;
        struct SReclaimAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RECLAIM_AREA, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RECLAIM_FEATURE") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toReclaimFeatureId_tmp;
        ei_decode_long(recvbuff, &index, &toReclaimFeatureId_tmp);
        int toReclaimFeatureId = (int)toReclaimFeatureId_tmp;
        struct SReclaimFeatureUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toReclaimFeatureId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RECLAIM_FEATURE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RECLAIM_UNIT") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toReclaimUnitId_tmp;
        ei_decode_long(recvbuff, &index, &toReclaimUnitId_tmp);
        int toReclaimUnitId = (int)toReclaimUnitId_tmp;
        struct SReclaimUnitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toReclaimUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RECLAIM_UNIT, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_REPAIR") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toRepairUnitId_tmp;
        ei_decode_long(recvbuff, &index, &toRepairUnitId_tmp);
        int toRepairUnitId = (int)toRepairUnitId_tmp;
        struct SRepairUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toRepairUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_REPAIR, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RESTORE_AREA") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float pos_posF3[3];
        double pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[0] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[1] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[2] = (float)pos_posF3_tmp;
        double radius_tmp;
        ei_decode_double(recvbuff, &index, &radius_tmp);
        float radius = (float)radius_tmp;
        struct SRestoreAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RESTORE_AREA, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RESURRECT") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toResurrectFeatureId_tmp;
        ei_decode_long(recvbuff, &index, &toResurrectFeatureId_tmp);
        int toResurrectFeatureId = (int)toResurrectFeatureId_tmp;
        struct SResurrectUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toResurrectFeatureId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RESURRECT, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RESURRECT_AREA") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float pos_posF3[3];
        double pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[0] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[1] = (float)pos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &pos_posF3_tmp);
        pos_posF3[2] = (float)pos_posF3_tmp;
        double radius_tmp;
        ei_decode_double(recvbuff, &index, &radius_tmp);
        float radius = (float)radius_tmp;
        struct SResurrectAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RESURRECT_AREA, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SELF_DESTROY") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        struct SSelfDestroyUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SELF_DESTROY, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_AUTO_REPAIR_LEVEL") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long autoRepairLevel_tmp;
        ei_decode_long(recvbuff, &index, &autoRepairLevel_tmp);
        int autoRepairLevel = (int)autoRepairLevel_tmp;
        struct SSetAutoRepairLevelUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            autoRepairLevel,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_AUTO_REPAIR_LEVEL, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_BASE") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float basePos_posF3[3];
        double basePos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &basePos_posF3_tmp);
        basePos_posF3[0] = (float)basePos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &basePos_posF3_tmp);
        basePos_posF3[1] = (float)basePos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &basePos_posF3_tmp);
        basePos_posF3[2] = (float)basePos_posF3_tmp;
        struct SSetBaseUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            basePos_posF3,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_BASE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_FIRE_STATE") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long fireState_tmp;
        ei_decode_long(recvbuff, &index, &fireState_tmp);
        int fireState = (int)fireState_tmp;
        struct SSetFireStateUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            fireState,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_FIRE_STATE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_IDLE_MODE") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long idleMode_tmp;
        ei_decode_long(recvbuff, &index, &idleMode_tmp);
        int idleMode = (int)idleMode_tmp;
        struct SSetIdleModeUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            idleMode,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_IDLE_MODE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_MOVE_STATE") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long moveState_tmp;
        ei_decode_long(recvbuff, &index, &moveState_tmp);
        int moveState = (int)moveState_tmp;
        struct SSetMoveStateUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            moveState,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_MOVE_STATE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_TRAJECTORY") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long trajectory_tmp;
        ei_decode_long(recvbuff, &index, &trajectory_tmp);
        int trajectory = (int)trajectory_tmp;
        struct SSetTrajectoryUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            trajectory,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_TRAJECTORY, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_WANTED_MAX_SPEED") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        double wantedMaxSpeed_tmp;
        ei_decode_double(recvbuff, &index, &wantedMaxSpeed_tmp);
        float wantedMaxSpeed = (float)wantedMaxSpeed_tmp;
        struct SSetWantedMaxSpeedUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            wantedMaxSpeed,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_WANTED_MAX_SPEED, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_STOCKPILE") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        struct SStockpileUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_STOCKPILE, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_STOP") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        struct SStopUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_STOP, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_UNLOAD_UNIT") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float toPos_posF3[3];
        double toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[0] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[1] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[2] = (float)toPos_posF3_tmp;
        long toUnloadUnitId_tmp;
        ei_decode_long(recvbuff, &index, &toUnloadUnitId_tmp);
        int toUnloadUnitId = (int)toUnloadUnitId_tmp;
        struct SUnloadUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
            toUnloadUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_UNLOAD_UNIT, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_UNLOAD_UNITS_AREA") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        float toPos_posF3[3];
        double toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[0] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[1] = (float)toPos_posF3_tmp;
        ei_decode_double(recvbuff, &index, &toPos_posF3_tmp);
        toPos_posF3[2] = (float)toPos_posF3_tmp;
        double radius_tmp;
        ei_decode_double(recvbuff, &index, &radius_tmp);
        float radius = (float)radius_tmp;
        struct SUnloadUnitsAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
            radius,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_UNLOAD_UNITS_AREA, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        struct SWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_DEATH") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long toDieUnitId_tmp;
        ei_decode_long(recvbuff, &index, &toDieUnitId_tmp);
        int toDieUnitId = (int)toDieUnitId_tmp;
        struct SDeathWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toDieUnitId,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT_DEATH, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_GATHER") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        struct SGatherWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT_GATHER, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_SQUAD") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long numUnits_tmp;
        ei_decode_long(recvbuff, &index, &numUnits_tmp);
        int numUnits = (int)numUnits_tmp;
        struct SSquadWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            numUnits,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT_SQUAD, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_TIME") == 0) {
        long unitId_tmp;
        ei_decode_long(recvbuff, &index, &unitId_tmp);
        int unitId = (int)unitId_tmp;
        long groupId_tmp;
        ei_decode_long(recvbuff, &index, &groupId_tmp);
        int groupId = (int)groupId_tmp;
        long options_tmp;
        ei_decode_long(recvbuff, &index, &options_tmp);
        short options = (short)options_tmp;
        long timeOut_tmp;
        ei_decode_long(recvbuff, &index, &timeOut_tmp);
        int timeOut = (int)timeOut_tmp;
        long time_tmp;
        ei_decode_long(recvbuff, &index, &time_tmp);
        int time = (int)time_tmp;
        struct STimeWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            time,
        };
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        if (callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT_TIME, &command) < 0) {;
            answer_error(team_id, &from);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            send_to_pid(team_id, &from, sendbuff);
        }
    }
}