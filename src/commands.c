
/* GENERATED FILE, DO NOT EDIT DIRECTLY */

#include <string.h>
#include "ei.h"
#include "rts/ExternalAI/Interface/SSkirmishAICallback.h"
#include "rts/ExternalAI/Interface/AISCommands.h"

int handle_command(int team_id, const struct SSkirmishAICallback* callback, char* recvbuff, int index) {
    char command[64] = "";
    ei_decode_atom(recvbuff, &index, command);

    if (strcmp(command, "COMMAND_CALL_LUA_RULES") == 0) {
        const char* inData;
        int inSize;
        char* ret_outData;
        struct SCallLuaRulesCommand command = {
            inData,
            inSize,
            ret_outData,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_CALL_LUA_RULES, &command);
    }
    if (strcmp(command, "COMMAND_CALL_LUA_UI") == 0) {
        const char* inData;
        int inSize;
        char* ret_outData;
        struct SCallLuaUICommand command = {
            inData,
            inSize,
            ret_outData,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_CALL_LUA_UI, &command);
    }
    if (strcmp(command, "COMMAND_CHEATS_GIVE_ME_NEW_UNIT") == 0) {
        int unitDefId;
        float* pos_posF3;
        int ret_newUnitId;
        struct SGiveMeNewUnitCheatCommand command = {
            unitDefId,
            pos_posF3,
            ret_newUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_CHEATS_GIVE_ME_NEW_UNIT, &command);
    }
    if (strcmp(command, "COMMAND_CHEATS_GIVE_ME_RESOURCE") == 0) {
        int resourceId;
        float amount;
        struct SGiveMeResourceCheatCommand command = {
            resourceId,
            amount,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_CHEATS_GIVE_ME_RESOURCE, &command);
    }
    if (strcmp(command, "COMMAND_CHEATS_SET_MY_INCOME_MULTIPLIER") == 0) {
        float factor;
        struct SSetMyIncomeMultiplierCheatCommand command = {
            factor,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_CHEATS_SET_MY_INCOME_MULTIPLIER, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_LINE_ADD_POINT") == 0) {
        int lineId;
        float x;
        float y;
        struct SAddPointLineGraphDrawerDebugCommand command = {
            lineId,
            x,
            y,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_LINE_ADD_POINT, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_LINE_DELETE_POINTS") == 0) {
        int lineId;
        int numPoints;
        struct SDeletePointsLineGraphDrawerDebugCommand command = {
            lineId,
            numPoints,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_LINE_DELETE_POINTS, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_LINE_SET_COLOR") == 0) {
        int lineId;
        short* color_colorS3;
        struct SSetColorLineGraphDrawerDebugCommand command = {
            lineId,
            color_colorS3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_LINE_SET_COLOR, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_LINE_SET_LABEL") == 0) {
        int lineId;
        const char* label;
        struct SSetLabelLineGraphDrawerDebugCommand command = {
            lineId,
            label,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_LINE_SET_LABEL, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_SET_POS") == 0) {
        float x;
        float y;
        struct SSetPositionGraphDrawerDebugCommand command = {
            x,
            y,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_SET_POS, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_SET_SIZE") == 0) {
        float w;
        float h;
        struct SSetSizeGraphDrawerDebugCommand command = {
            w,
            h,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_GRAPH_SET_SIZE, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_ADD") == 0) {
        int ret_overlayTextureId;
        const float* texData;
        int w;
        int h;
        struct SAddOverlayTextureDrawerDebugCommand command = {
            ret_overlayTextureId,
            texData,
            w,
            h,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_ADD, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_DELETE") == 0) {
        int overlayTextureId;
        struct SDeleteOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_DELETE, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_LABEL") == 0) {
        int overlayTextureId;
        const char* label;
        struct SSetLabelOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
            label,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_LABEL, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_POS") == 0) {
        int overlayTextureId;
        float x;
        float y;
        struct SSetPositionOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
            x,
            y,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_POS, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_SIZE") == 0) {
        int overlayTextureId;
        float w;
        float h;
        struct SSetSizeOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
            w,
            h,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_SIZE, &command);
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_UPDATE") == 0) {
        int overlayTextureId;
        const float* texData;
        int x;
        int y;
        int w;
        int h;
        struct SUpdateOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
            texData,
            x,
            y,
            w,
            h,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_UPDATE, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_ADD_NOTIFICATION") == 0) {
        float* pos_posF3;
        short* color_colorS3;
        short alpha;
        struct SAddNotificationDrawerCommand command = {
            pos_posF3,
            color_colorS3,
            alpha,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_ADD_NOTIFICATION, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_DRAW_UNIT") == 0) {
        int toDrawUnitDefId;
        float* pos_posF3;
        float rotation;
        int lifeTime;
        int teamId;
        bool transparent;
        bool drawBorder;
        int facing;
        struct SDrawUnitDrawerCommand command = {
            toDrawUnitDefId,
            pos_posF3,
            rotation,
            lifeTime,
            teamId,
            transparent,
            drawBorder,
            facing,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_DRAW_UNIT, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_FIGURE_CREATE_LINE") == 0) {
        float* pos1_posF3;
        float* pos2_posF3;
        float width;
        bool arrow;
        int lifeTime;
        int figureGroupId;
        int ret_newFigureGroupId;
        struct SCreateLineFigureDrawerCommand command = {
            pos1_posF3,
            pos2_posF3,
            width,
            arrow,
            lifeTime,
            figureGroupId,
            ret_newFigureGroupId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_FIGURE_CREATE_LINE, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_FIGURE_CREATE_SPLINE") == 0) {
        float* pos1_posF3;
        float* pos2_posF3;
        float* pos3_posF3;
        float* pos4_posF3;
        float width;
        bool arrow;
        int lifeTime;
        int figureGroupId;
        int ret_newFigureGroupId;
        struct SCreateSplineFigureDrawerCommand command = {
            pos1_posF3,
            pos2_posF3,
            pos3_posF3,
            pos4_posF3,
            width,
            arrow,
            lifeTime,
            figureGroupId,
            ret_newFigureGroupId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_FIGURE_CREATE_SPLINE, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_FIGURE_DELETE") == 0) {
        int figureGroupId;
        struct SDeleteFigureDrawerCommand command = {
            figureGroupId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_FIGURE_DELETE, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_FIGURE_SET_COLOR") == 0) {
        int figureGroupId;
        short* color_colorS3;
        short alpha;
        struct SSetColorFigureDrawerCommand command = {
            figureGroupId,
            color_colorS3,
            alpha,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_FIGURE_SET_COLOR, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_LINE_ADD") == 0) {
        float* posFrom_posF3;
        float* posTo_posF3;
        struct SAddLineDrawCommand command = {
            posFrom_posF3,
            posTo_posF3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_LINE_ADD, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_PATH_BREAK") == 0) {
        float* endPos_posF3;
        short* color_colorS3;
        short alpha;
        struct SBreakPathDrawerCommand command = {
            endPos_posF3,
            color_colorS3,
            alpha,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_PATH_BREAK, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_PATH_DRAW_ICON_AT_LAST_POS") == 0) {
        int cmdId;
        struct SDrawIconAtLastPosPathDrawerCommand command = {
            cmdId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_PATH_DRAW_ICON_AT_LAST_POS, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_PATH_DRAW_LINE") == 0) {
        float* endPos_posF3;
        short* color_colorS3;
        short alpha;
        struct SDrawLinePathDrawerCommand command = {
            endPos_posF3,
            color_colorS3,
            alpha,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_PATH_DRAW_LINE, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_PATH_DRAW_LINE_AND_ICON") == 0) {
        int cmdId;
        float* endPos_posF3;
        short* color_colorS3;
        short alpha;
        struct SDrawLineAndIconPathDrawerCommand command = {
            cmdId,
            endPos_posF3,
            color_colorS3,
            alpha,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_PATH_DRAW_LINE_AND_ICON, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_PATH_FINISH") == 0) {
        bool iAmUseless;
        struct SFinishPathDrawerCommand command = {
            iAmUseless,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_PATH_FINISH, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_PATH_RESTART") == 0) {
        bool sameColor;
        struct SRestartPathDrawerCommand command = {
            sameColor,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_PATH_RESTART, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_PATH_START") == 0) {
        float* pos_posF3;
        short* color_colorS3;
        short alpha;
        struct SStartPathDrawerCommand command = {
            pos_posF3,
            color_colorS3,
            alpha,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_PATH_START, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_POINT_ADD") == 0) {
        float* pos_posF3;
        const char* label;
        struct SAddPointDrawCommand command = {
            pos_posF3,
            label,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_POINT_ADD, &command);
    }
    if (strcmp(command, "COMMAND_DRAWER_POINT_REMOVE") == 0) {
        float* pos_posF3;
        struct SRemovePointDrawCommand command = {
            pos_posF3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_DRAWER_POINT_REMOVE, &command);
    }
    if (strcmp(command, "COMMAND_GROUP_CREATE") == 0) {
        int ret_groupId;
        struct SCreateGroupCommand command = {
            ret_groupId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_GROUP_CREATE, &command);
    }
    if (strcmp(command, "COMMAND_GROUP_ERASE") == 0) {
        int groupId;
        struct SEraseGroupCommand command = {
            groupId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_GROUP_ERASE, &command);
    }
    if (strcmp(command, "COMMAND_PATH_FREE") == 0) {
        int pathId;
        struct SFreePathCommand command = {
            pathId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_PATH_FREE, &command);
    }
    if (strcmp(command, "COMMAND_PATH_GET_APPROXIMATE_LENGTH") == 0) {
        float* start_posF3;
        float* end_posF3;
        int pathType;
        float goalRadius;
        float ret_approximatePathLength;
        struct SGetApproximateLengthPathCommand command = {
            start_posF3,
            end_posF3,
            pathType,
            goalRadius,
            ret_approximatePathLength,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_PATH_GET_APPROXIMATE_LENGTH, &command);
    }
    if (strcmp(command, "COMMAND_PATH_GET_NEXT_WAYPOINT") == 0) {
        int pathId;
        float* ret_nextWaypoint_posF3_out;
        struct SGetNextWaypointPathCommand command = {
            pathId,
            ret_nextWaypoint_posF3_out,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_PATH_GET_NEXT_WAYPOINT, &command);
    }
    if (strcmp(command, "COMMAND_PATH_INIT") == 0) {
        float* start_posF3;
        float* end_posF3;
        int pathType;
        float goalRadius;
        int ret_pathId;
        struct SInitPathCommand command = {
            start_posF3,
            end_posF3,
            pathType,
            goalRadius,
            ret_pathId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_PATH_INIT, &command);
    }
    if (strcmp(command, "COMMAND_PAUSE") == 0) {
        bool enable;
        const char* reason;
        struct SPauseCommand command = {
            enable,
            reason,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_PAUSE, &command);
    }
    if (strcmp(command, "COMMAND_SEND_RESOURCES") == 0) {
        int resourceId;
        float amount;
        int receivingTeamId;
        bool ret_isExecuted;
        struct SSendResourcesCommand command = {
            resourceId,
            amount,
            receivingTeamId,
            ret_isExecuted,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_SEND_RESOURCES, &command);
    }
    if (strcmp(command, "COMMAND_SEND_START_POS") == 0) {
        bool ready;
        float* pos_posF3;
        struct SSendStartPosCommand command = {
            ready,
            pos_posF3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_SEND_START_POS, &command);
    }
    if (strcmp(command, "COMMAND_SEND_TEXT_MESSAGE") == 0) {
        const char* text;
        int zone;
        struct SSendTextMessageCommand command = {
            text,
            zone,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_SEND_TEXT_MESSAGE, &command);
    }
    if (strcmp(command, "COMMAND_SEND_UNITS") == 0) {
        int* unitIds;
        int unitIds_size;
        int receivingTeamId;
        int ret_sentUnits;
        struct SSendUnitsCommand command = {
            unitIds,
            unitIds_size,
            receivingTeamId,
            ret_sentUnits,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_SEND_UNITS, &command);
    }
    if (strcmp(command, "COMMAND_SET_LAST_POS_MESSAGE") == 0) {
        float* pos_posF3;
        struct SSetLastPosMessageCommand command = {
            pos_posF3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_SET_LAST_POS_MESSAGE, &command);
    }
    if (strcmp(command, "COMMAND_TRACE_RAY") == 0) {
        float* rayPos_posF3;
        float* rayDir_posF3;
        int srcUnitId;
        int ret_hitUnitId;
        int flags;
        struct STraceRayCommand command = {
            rayPos_posF3,
            rayDir_posF3,
            srcUnitId,
            ret_hitUnitId,
            flags,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_TRACE_RAY, &command);
    }
    if (strcmp(command, "COMMAND_TRACE_RAY_FEATURE") == 0) {
        float* rayPos_posF3;
        float* rayDir_posF3;
        int srcUnitId;
        int ret_hitFeatureId;
        int flags;
        struct SFeatureTraceRayCommand command = {
            rayPos_posF3,
            rayDir_posF3,
            srcUnitId,
            ret_hitFeatureId,
            flags,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_TRACE_RAY_FEATURE, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_AI_SELECT") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        struct SAiSelectUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_AI_SELECT, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_ATTACK") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toAttackUnitId;
        struct SAttackUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toAttackUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_ATTACK, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_ATTACK_AREA") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* toAttackPos_posF3;
        float radius;
        struct SAttackAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toAttackPos_posF3,
            radius,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_ATTACK_AREA, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_BUILD") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toBuildUnitDefId;
        float* buildPos_posF3;
        int facing;
        struct SBuildUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toBuildUnitDefId,
            buildPos_posF3,
            facing,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_BUILD, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_CAPTURE") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toCaptureUnitId;
        struct SCaptureUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toCaptureUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_CAPTURE, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_CAPTURE_AREA") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* pos_posF3;
        float radius;
        struct SCaptureAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_CAPTURE_AREA, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_CLOAK") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        bool cloak;
        struct SCloakUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            cloak,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_CLOAK, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_CUSTOM") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int cmdId;
        float* params;
        int params_size;
        struct SCustomUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            cmdId,
            params,
            params_size,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_CUSTOM, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_D_GUN") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toAttackUnitId;
        struct SDGunUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toAttackUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_D_GUN, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_D_GUN_POS") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* pos_posF3;
        struct SDGunPosUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_D_GUN_POS, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_FIGHT") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* toPos_posF3;
        struct SFightUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_FIGHT, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_GROUP_ADD") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toGroupId;
        struct SGroupAddUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toGroupId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_GROUP_ADD, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_GROUP_CLEAR") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        struct SGroupClearUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_GROUP_CLEAR, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_GUARD") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toGuardUnitId;
        struct SGuardUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toGuardUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_GUARD, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_LOAD_ONTO") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int transporterUnitId;
        struct SLoadOntoUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            transporterUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_LOAD_ONTO, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_LOAD_UNITS") == 0) {
        int unitId;
        int groupId;
        short options;
        int* toLoadUnitIds;
        int toLoadUnitIds_size;
        struct SLoadUnitsUnitCommand command = {
            unitId,
            groupId,
            options,
            toLoadUnitIds,
            toLoadUnitIds_size,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_LOAD_UNITS, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_LOAD_UNITS_AREA") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* pos_posF3;
        float radius;
        struct SLoadUnitsAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_LOAD_UNITS_AREA, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_MOVE") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* toPos_posF3;
        struct SMoveUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_MOVE, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_PATROL") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* toPos_posF3;
        struct SPatrolUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_PATROL, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_RECLAIM_AREA") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* pos_posF3;
        float radius;
        struct SReclaimAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RECLAIM_AREA, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_RECLAIM_FEATURE") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toReclaimFeatureId;
        struct SReclaimFeatureUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toReclaimFeatureId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RECLAIM_FEATURE, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_RECLAIM_UNIT") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toReclaimUnitId;
        struct SReclaimUnitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toReclaimUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RECLAIM_UNIT, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_REPAIR") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toRepairUnitId;
        struct SRepairUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toRepairUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_REPAIR, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_RESTORE_AREA") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* pos_posF3;
        float radius;
        struct SRestoreAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RESTORE_AREA, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_RESURRECT") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toResurrectFeatureId;
        struct SResurrectUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toResurrectFeatureId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RESURRECT, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_RESURRECT_AREA") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* pos_posF3;
        float radius;
        struct SResurrectAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_RESURRECT_AREA, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SELF_DESTROY") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        struct SSelfDestroyUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SELF_DESTROY, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SET_AUTO_REPAIR_LEVEL") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int autoRepairLevel;
        struct SSetAutoRepairLevelUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            autoRepairLevel,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_AUTO_REPAIR_LEVEL, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SET_BASE") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* basePos_posF3;
        struct SSetBaseUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            basePos_posF3,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_BASE, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SET_FIRE_STATE") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int fireState;
        struct SSetFireStateUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            fireState,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_FIRE_STATE, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SET_IDLE_MODE") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int idleMode;
        struct SSetIdleModeUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            idleMode,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_IDLE_MODE, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SET_MOVE_STATE") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int moveState;
        struct SSetMoveStateUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            moveState,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_MOVE_STATE, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SET_ON_OFF") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        bool on;
        struct SSetOnOffUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            on,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_ON_OFF, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SET_REPEAT") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        bool repeat;
        struct SSetRepeatUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            repeat,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_REPEAT, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SET_TRAJECTORY") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int trajectory;
        struct SSetTrajectoryUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            trajectory,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_TRAJECTORY, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_SET_WANTED_MAX_SPEED") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float wantedMaxSpeed;
        struct SSetWantedMaxSpeedUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            wantedMaxSpeed,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_SET_WANTED_MAX_SPEED, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_STOCKPILE") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        struct SStockpileUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_STOCKPILE, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_STOP") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        struct SStopUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_STOP, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_UNLOAD_UNIT") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* toPos_posF3;
        int toUnloadUnitId;
        struct SUnloadUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
            toUnloadUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_UNLOAD_UNIT, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_UNLOAD_UNITS_AREA") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        float* toPos_posF3;
        float radius;
        struct SUnloadUnitsAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
            radius,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_UNLOAD_UNITS_AREA, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        struct SWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_DEATH") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int toDieUnitId;
        struct SDeathWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toDieUnitId,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT_DEATH, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_GATHER") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        struct SGatherWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT_GATHER, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_SQUAD") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int numUnits;
        struct SSquadWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            numUnits,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT_SQUAD, &command);
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_TIME") == 0) {
        int unitId;
        int groupId;
        short options;
        int timeOut;
        int time;
        struct STimeWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            time,
        };
        int result = callback->Engine_handleCommand(team_id, team_id, -1, COMMAND_UNIT_WAIT_TIME, &command);
    }
}