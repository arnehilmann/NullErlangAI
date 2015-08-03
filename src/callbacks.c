
/* THIS FILE GETS GENERATED, DO NOT EDIT DIRECTLY! */

#include <string.h>

#include "ei.h"
#include "rts/ExternalAI/Interface/SSkirmishAICallback.h"
#include "send_to.h"

int handle_callback(int skirmishAIId, const struct SSkirmishAICallback* callback, char* recvbuff, int index){
    char callback_what[64] = "";
    ei_decode_atom(recvbuff, &index, callback_what);

    if (strcmp(callback_what, "Cheats_isEnabled") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Cheats_isEnabled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Cheats_isEnabled");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Cheats_isOnlyPassive") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Cheats_isOnlyPassive(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Cheats_isOnlyPassive");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Cheats_setEnabled") == 0) {
        int enable;
        ei_decode_boolean(recvbuff, &index, &enable);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Cheats_setEnabled(skirmishAIId, enable);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Cheats_setEnabled");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Cheats_setEventsEnabled") == 0) {
        int enabled;
        ei_decode_boolean(recvbuff, &index, &enabled);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Cheats_setEventsEnabled(skirmishAIId, enabled);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Cheats_setEventsEnabled");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_Roots_getDir") == 0) {
        char* path;
        ei_decode_string(recvbuff, &index, path);
        long path_sizeMax;
        ei_decode_long(recvbuff, &index, &path_sizeMax);
        long dirIndex;
        ei_decode_long(recvbuff, &index, &dirIndex);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->DataDirs_Roots_getDir(skirmishAIId, path, path_sizeMax, dirIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "DataDirs_Roots_getDir");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_Roots_getSize") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->DataDirs_Roots_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "DataDirs_Roots_getSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_Roots_locatePath") == 0) {
        char* path;
        ei_decode_string(recvbuff, &index, path);
        long path_sizeMax;
        ei_decode_long(recvbuff, &index, &path_sizeMax);
        char* relPath;
        ei_decode_string(recvbuff, &index, relPath);
        int writeable;
        ei_decode_boolean(recvbuff, &index, &writeable);
        int create;
        ei_decode_boolean(recvbuff, &index, &create);
        int dir;
        ei_decode_boolean(recvbuff, &index, &dir);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->DataDirs_Roots_locatePath(skirmishAIId, path, path_sizeMax, relPath, writeable, create, dir);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "DataDirs_Roots_locatePath");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_getConfigDir") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->DataDirs_getConfigDir(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "DataDirs_getConfigDir");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_getPathSeparator") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        char result = callback->DataDirs_getPathSeparator(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "DataDirs_getPathSeparator");
        ei_x_encode_char(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_getWriteableDir") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->DataDirs_getWriteableDir(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "DataDirs_getWriteableDir");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_locatePath") == 0) {
        char* path;
        ei_decode_string(recvbuff, &index, path);
        long path_sizeMax;
        ei_decode_long(recvbuff, &index, &path_sizeMax);
        char* relPath;
        ei_decode_string(recvbuff, &index, relPath);
        int writeable;
        ei_decode_boolean(recvbuff, &index, &writeable);
        int create;
        ei_decode_boolean(recvbuff, &index, &create);
        int dir;
        ei_decode_boolean(recvbuff, &index, &dir);
        int common;
        ei_decode_boolean(recvbuff, &index, &common);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->DataDirs_locatePath(skirmishAIId, path, path_sizeMax, relPath, writeable, create, dir, common);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "DataDirs_locatePath");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Debug_GraphDrawer_isEnabled") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Debug_GraphDrawer_isEnabled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Debug_GraphDrawer_isEnabled");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getCurrent") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Economy_getCurrent(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Economy_getCurrent");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getExcess") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Economy_getExcess(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Economy_getExcess");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getIncome") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Economy_getIncome(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Economy_getIncome");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getPull") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Economy_getPull(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Economy_getPull");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getReceived") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Economy_getReceived(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Economy_getReceived");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getSent") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Economy_getSent(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Economy_getSent");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getShare") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Economy_getShare(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Economy_getShare");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getStorage") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Economy_getStorage(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Economy_getStorage");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getUsage") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Economy_getUsage(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Economy_getUsage");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getAdditional") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getAdditional(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getAdditional");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getBranch") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getBranch(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getBranch");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getBuildTime") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getBuildTime(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getBuildTime");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getCommits") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getCommits(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getCommits");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getFull") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getFull(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getFull");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getHash") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getHash(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getHash");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getMajor") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getMajor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getMajor");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getMinor") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getMinor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getMinor");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getNormal") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getNormal(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getNormal");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getPatchset") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getPatchset(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getPatchset");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getSync") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Engine_Version_getSync(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_getSync");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_isRelease") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Engine_Version_isRelease(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Engine_Version_isRelease");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getContainedResource") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->FeatureDef_getContainedResource(skirmishAIId, featureDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getContainedResource");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getDeathFeature") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->FeatureDef_getDeathFeature(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getDeathFeature");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getDescription") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->FeatureDef_getDescription(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getDescription");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getDrawType") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->FeatureDef_getDrawType(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getDrawType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getFileName") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->FeatureDef_getFileName(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getFileName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getMass") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->FeatureDef_getMass(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getMass");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getMaxHealth") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->FeatureDef_getMaxHealth(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getMaxHealth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getModelName") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->FeatureDef_getModelName(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getModelName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getName") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->FeatureDef_getName(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getReclaimTime") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->FeatureDef_getReclaimTime(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getReclaimTime");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getResurrectable") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->FeatureDef_getResurrectable(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getResurrectable");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getSmokeTime") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->FeatureDef_getSmokeTime(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getSmokeTime");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getXSize") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->FeatureDef_getXSize(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getXSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getZSize") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->FeatureDef_getZSize(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_getZSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isBlocking") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->FeatureDef_isBlocking(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_isBlocking");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isBurnable") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->FeatureDef_isBurnable(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_isBurnable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isDestructable") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->FeatureDef_isDestructable(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_isDestructable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isFloating") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->FeatureDef_isFloating(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_isFloating");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isGeoThermal") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->FeatureDef_isGeoThermal(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_isGeoThermal");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isNoSelect") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->FeatureDef_isNoSelect(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_isNoSelect");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isReclaimable") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->FeatureDef_isReclaimable(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_isReclaimable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isUpright") == 0) {
        long featureDefId;
        ei_decode_long(recvbuff, &index, &featureDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->FeatureDef_isUpright(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "FeatureDef_isUpright");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Feature_getDef") == 0) {
        long featureId;
        ei_decode_long(recvbuff, &index, &featureId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Feature_getDef(skirmishAIId, featureId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Feature_getDef");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Feature_getHealth") == 0) {
        long featureId;
        ei_decode_long(recvbuff, &index, &featureId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Feature_getHealth(skirmishAIId, featureId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Feature_getHealth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Feature_getReclaimLeft") == 0) {
        long featureId;
        ei_decode_long(recvbuff, &index, &featureId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Feature_getReclaimLeft(skirmishAIId, featureId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Feature_getReclaimLeft");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "File_getSize") == 0) {
        char* fileName;
        ei_decode_string(recvbuff, &index, fileName);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->File_getSize(skirmishAIId, fileName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "File_getSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "GameRulesParam_getName") == 0) {
        long gameRulesParamId;
        ei_decode_long(recvbuff, &index, &gameRulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->GameRulesParam_getName(skirmishAIId, gameRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "GameRulesParam_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "GameRulesParam_getValueFloat") == 0) {
        long gameRulesParamId;
        ei_decode_long(recvbuff, &index, &gameRulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->GameRulesParam_getValueFloat(skirmishAIId, gameRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "GameRulesParam_getValueFloat");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "GameRulesParam_getValueString") == 0) {
        long gameRulesParamId;
        ei_decode_long(recvbuff, &index, &gameRulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->GameRulesParam_getValueString(skirmishAIId, gameRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "GameRulesParam_getValueString");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getAiInterfaceVersion") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getAiInterfaceVersion(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getAiInterfaceVersion");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getCategoriesFlag") == 0) {
        char* categoryNames;
        ei_decode_string(recvbuff, &index, categoryNames);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getCategoriesFlag(skirmishAIId, categoryNames);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getCategoriesFlag");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getCategoryFlag") == 0) {
        char* categoryName;
        ei_decode_string(recvbuff, &index, categoryName);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getCategoryFlag(skirmishAIId, categoryName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getCategoryFlag");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getCurrentFrame") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getCurrentFrame(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getCurrentFrame");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getGameRulesParamById") == 0) {
        long rulesParamId;
        ei_decode_long(recvbuff, &index, &rulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getGameRulesParamById(skirmishAIId, rulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getGameRulesParamById");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getGameRulesParamByName") == 0) {
        char* rulesParamName;
        ei_decode_string(recvbuff, &index, rulesParamName);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getGameRulesParamByName(skirmishAIId, rulesParamName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getGameRulesParamByName");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getGameRulesParams") == 0) {
        long paramIds_sizeMax;
        ei_decode_long(recvbuff, &index, &paramIds_sizeMax);
        int paramIds[paramIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getGameRulesParams(skirmishAIId, paramIds, paramIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getGameRulesParams");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, paramIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getMode") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getMode(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getMode");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getMyAllyTeam") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getMyAllyTeam(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getMyAllyTeam");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getMyTeam") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getMyTeam(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getMyTeam");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getPlayerTeam") == 0) {
        long playerId;
        ei_decode_long(recvbuff, &index, &playerId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getPlayerTeam(skirmishAIId, playerId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getPlayerTeam");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getSetupScript") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Game_getSetupScript(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getSetupScript");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getSpeedFactor") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getSpeedFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getSpeedFactor");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamAllyTeam") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getTeamAllyTeam(skirmishAIId, otherTeamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamAllyTeam");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamIncomeMultiplier") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamIncomeMultiplier(skirmishAIId, otherTeamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamIncomeMultiplier");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceCurrent") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamResourceCurrent(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamResourceCurrent");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceExcess") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamResourceExcess(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamResourceExcess");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceIncome") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamResourceIncome(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamResourceIncome");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourcePull") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamResourcePull(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamResourcePull");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceReceived") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamResourceReceived(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamResourceReceived");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceSent") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamResourceSent(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamResourceSent");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceShare") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamResourceShare(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamResourceShare");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceStorage") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamResourceStorage(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamResourceStorage");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceUsage") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Game_getTeamResourceUsage(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamResourceUsage");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamSide") == 0) {
        long otherTeamId;
        ei_decode_long(recvbuff, &index, &otherTeamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Game_getTeamSide(skirmishAIId, otherTeamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeamSide");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeams") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Game_getTeams(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_getTeams");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_isAllied") == 0) {
        long firstAllyTeamId;
        ei_decode_long(recvbuff, &index, &firstAllyTeamId);
        long secondAllyTeamId;
        ei_decode_long(recvbuff, &index, &secondAllyTeamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Game_isAllied(skirmishAIId, firstAllyTeamId, secondAllyTeamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_isAllied");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_isDebugModeEnabled") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Game_isDebugModeEnabled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_isDebugModeEnabled");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_isExceptionHandlingEnabled") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Game_isExceptionHandlingEnabled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_isExceptionHandlingEnabled");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_isPaused") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Game_isPaused(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Game_isPaused");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_OrderPreview_getId") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Group_OrderPreview_getId(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_OrderPreview_getId");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_OrderPreview_getOptions") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        short result = callback->Group_OrderPreview_getOptions(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_OrderPreview_getOptions");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_OrderPreview_getTag") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Group_OrderPreview_getTag(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_OrderPreview_getTag");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_OrderPreview_getTimeOut") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Group_OrderPreview_getTimeOut(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_OrderPreview_getTimeOut");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_getId") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Group_SupportedCommand_getId(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_SupportedCommand_getId");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_getName") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Group_SupportedCommand_getName(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_SupportedCommand_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_getToolTip") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Group_SupportedCommand_getToolTip(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_SupportedCommand_getToolTip");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_isDisabled") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Group_SupportedCommand_isDisabled(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_SupportedCommand_isDisabled");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_isShowUnique") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Group_SupportedCommand_isShowUnique(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_SupportedCommand_isShowUnique");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_getSupportedCommands") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Group_getSupportedCommands(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_getSupportedCommands");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_isSelected") == 0) {
        long groupId;
        ei_decode_long(recvbuff, &index, &groupId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Group_isSelected(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Group_isSelected");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Gui_getScreenX") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Gui_getScreenX(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Gui_getScreenX");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Gui_getScreenY") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Gui_getScreenY(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Gui_getScreenY");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Gui_getViewRange") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Gui_getViewRange(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Gui_getViewRange");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_Point_getLabel") == 0) {
        long pointId;
        ei_decode_long(recvbuff, &index, &pointId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Map_Point_getLabel(skirmishAIId, pointId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_Point_getLabel");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getChecksum") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Map_getChecksum(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getChecksum");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getCurWind") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getCurWind(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getCurWind");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getElevationAt") == 0) {
        double x;
        ei_decode_double(recvbuff, &index, &x);
        double z;
        ei_decode_double(recvbuff, &index, &z);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getElevationAt(skirmishAIId, x, z);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getElevationAt");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getExtractorRadius") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getExtractorRadius(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getExtractorRadius");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getGravity") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getGravity(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getGravity");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getHash") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Map_getHash(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getHash");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getHeight") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Map_getHeight(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getHeight");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getHumanName") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Map_getHumanName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getHumanName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getLines") == 0) {
        int includeAllies;
        ei_decode_boolean(recvbuff, &index, &includeAllies);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Map_getLines(skirmishAIId, includeAllies);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getLines");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMaxHeight") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getMaxHeight(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getMaxHeight");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMaxResource") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getMaxResource(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getMaxResource");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMaxWind") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getMaxWind(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getMaxWind");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMinHeight") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getMinHeight(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getMinHeight");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMinWind") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getMinWind(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getMinWind");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getName") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Map_getName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getPoints") == 0) {
        int includeAllies;
        ei_decode_boolean(recvbuff, &index, &includeAllies);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Map_getPoints(skirmishAIId, includeAllies);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getPoints");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getResourceMapSpotsAverageIncome") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getResourceMapSpotsAverageIncome(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getResourceMapSpotsAverageIncome");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getResourceMapSpotsPositions") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        float spots_AposF3[3];
        double tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        spots_AposF3[0] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        spots_AposF3[1] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        spots_AposF3[2] = tmp;
        long spots_AposF3_sizeMax;
        ei_decode_long(recvbuff, &index, &spots_AposF3_sizeMax);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Map_getResourceMapSpotsPositions(skirmishAIId, resourceId, spots_AposF3, spots_AposF3_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getResourceMapSpotsPositions");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getTidalStrength") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getTidalStrength(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getTidalStrength");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getWaterDamage") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Map_getWaterDamage(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getWaterDamage");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getWidth") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Map_getWidth(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_getWidth");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_isPosInCamera") == 0) {
        float pos_posF3[3];
        double tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[0] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[1] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[2] = tmp;
        double radius;
        ei_decode_double(recvbuff, &index, &radius);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Map_isPosInCamera(skirmishAIId, pos_posF3, radius);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_isPosInCamera");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_isPossibleToBuildAt") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        float pos_posF3[3];
        double tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[0] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[1] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[2] = tmp;
        long facing;
        ei_decode_long(recvbuff, &index, &facing);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Map_isPossibleToBuildAt(skirmishAIId, unitDefId, pos_posF3, facing);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Map_isPossibleToBuildAt");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getAirLosMul") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Mod_getAirLosMul(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getAirLosMul");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getAirMipLevel") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getAirMipLevel(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getAirMipLevel");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getAllowTeamColors") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Mod_getAllowTeamColors(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getAllowTeamColors");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getCaptureEnergyCostFactor") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Mod_getCaptureEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getCaptureEnergyCostFactor");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getConstructionDecay") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Mod_getConstructionDecay(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getConstructionDecay");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getConstructionDecaySpeed") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Mod_getConstructionDecaySpeed(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getConstructionDecaySpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getConstructionDecayTime") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getConstructionDecayTime(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getConstructionDecayTime");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getDescription") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Mod_getDescription(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getDescription");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getFileName") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Mod_getFileName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getFileName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getFireAtCrashing") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getFireAtCrashing(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getFireAtCrashing");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getFireAtKilled") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getFireAtKilled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getFireAtKilled");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getFlankingBonusModeDefault") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getFlankingBonusModeDefault(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getFlankingBonusModeDefault");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getHash") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getHash(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getHash");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getHumanName") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Mod_getHumanName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getHumanName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getLosMipLevel") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getLosMipLevel(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getLosMipLevel");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getLosMul") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Mod_getLosMul(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getLosMul");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getMultiReclaim") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getMultiReclaim(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getMultiReclaim");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getMutator") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Mod_getMutator(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getMutator");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimAllowAllies") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Mod_getReclaimAllowAllies(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getReclaimAllowAllies");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimAllowEnemies") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Mod_getReclaimAllowEnemies(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getReclaimAllowEnemies");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimFeatureEnergyCostFactor") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Mod_getReclaimFeatureEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getReclaimFeatureEnergyCostFactor");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimMethod") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getReclaimMethod(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getReclaimMethod");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimUnitEfficiency") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Mod_getReclaimUnitEfficiency(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getReclaimUnitEfficiency");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimUnitEnergyCostFactor") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Mod_getReclaimUnitEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getReclaimUnitEnergyCostFactor");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimUnitMethod") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getReclaimUnitMethod(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getReclaimUnitMethod");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getRepairEnergyCostFactor") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Mod_getRepairEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getRepairEnergyCostFactor");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getRequireSonarUnderWater") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Mod_getRequireSonarUnderWater(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getRequireSonarUnderWater");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getResurrectEnergyCostFactor") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Mod_getResurrectEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getResurrectEnergyCostFactor");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getShortName") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Mod_getShortName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getShortName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getTransportAir") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getTransportAir(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getTransportAir");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getTransportGround") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getTransportGround(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getTransportGround");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getTransportHover") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getTransportHover(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getTransportHover");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getTransportShip") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Mod_getTransportShip(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getTransportShip");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getVersion") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Mod_getVersion(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Mod_getVersion");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Resource_getName") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Resource_getName(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Resource_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Resource_getOptimum") == 0) {
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Resource_getOptimum(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Resource_getOptimum");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getDescription") == 0) {
        long infoIndex;
        ei_decode_long(recvbuff, &index, &infoIndex);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->SkirmishAI_Info_getDescription(skirmishAIId, infoIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_Info_getDescription");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getKey") == 0) {
        long infoIndex;
        ei_decode_long(recvbuff, &index, &infoIndex);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->SkirmishAI_Info_getKey(skirmishAIId, infoIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_Info_getKey");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getSize") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->SkirmishAI_Info_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_Info_getSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getValue") == 0) {
        long infoIndex;
        ei_decode_long(recvbuff, &index, &infoIndex);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->SkirmishAI_Info_getValue(skirmishAIId, infoIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_Info_getValue");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getValueByKey") == 0) {
        char* key;
        ei_decode_string(recvbuff, &index, key);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->SkirmishAI_Info_getValueByKey(skirmishAIId, key);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_Info_getValueByKey");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_OptionValues_getKey") == 0) {
        long optionIndex;
        ei_decode_long(recvbuff, &index, &optionIndex);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->SkirmishAI_OptionValues_getKey(skirmishAIId, optionIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_OptionValues_getKey");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_OptionValues_getSize") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->SkirmishAI_OptionValues_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_OptionValues_getSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_OptionValues_getValue") == 0) {
        long optionIndex;
        ei_decode_long(recvbuff, &index, &optionIndex);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->SkirmishAI_OptionValues_getValue(skirmishAIId, optionIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_OptionValues_getValue");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_OptionValues_getValueByKey") == 0) {
        char* key;
        ei_decode_string(recvbuff, &index, key);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->SkirmishAI_OptionValues_getValueByKey(skirmishAIId, key);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_OptionValues_getValueByKey");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_getTeamId") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->SkirmishAI_getTeamId(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAI_getTeamId");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAIs_getMax") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->SkirmishAIs_getMax(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAIs_getMax");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAIs_getSize") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->SkirmishAIs_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "SkirmishAIs_getSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_TeamRulesParam_getName") == 0) {
        long teamId;
        ei_decode_long(recvbuff, &index, &teamId);
        long teamRulesParamId;
        ei_decode_long(recvbuff, &index, &teamRulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Team_TeamRulesParam_getName(skirmishAIId, teamId, teamRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Team_TeamRulesParam_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_TeamRulesParam_getValueFloat") == 0) {
        long teamId;
        ei_decode_long(recvbuff, &index, &teamId);
        long teamRulesParamId;
        ei_decode_long(recvbuff, &index, &teamRulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Team_TeamRulesParam_getValueFloat(skirmishAIId, teamId, teamRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Team_TeamRulesParam_getValueFloat");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_TeamRulesParam_getValueString") == 0) {
        long teamId;
        ei_decode_long(recvbuff, &index, &teamId);
        long teamRulesParamId;
        ei_decode_long(recvbuff, &index, &teamRulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Team_TeamRulesParam_getValueString(skirmishAIId, teamId, teamRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Team_TeamRulesParam_getValueString");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_getTeamRulesParamById") == 0) {
        long teamId;
        ei_decode_long(recvbuff, &index, &teamId);
        long rulesParamId;
        ei_decode_long(recvbuff, &index, &rulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Team_getTeamRulesParamById(skirmishAIId, teamId, rulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Team_getTeamRulesParamById");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_getTeamRulesParamByName") == 0) {
        long teamId;
        ei_decode_long(recvbuff, &index, &teamId);
        char* rulesParamName;
        ei_decode_string(recvbuff, &index, rulesParamName);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Team_getTeamRulesParamByName(skirmishAIId, teamId, rulesParamName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Team_getTeamRulesParamByName");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_getTeamRulesParams") == 0) {
        long teamId;
        ei_decode_long(recvbuff, &index, &teamId);
        long paramIds_sizeMax;
        ei_decode_long(recvbuff, &index, &paramIds_sizeMax);
        int paramIds[paramIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Team_getTeamRulesParams(skirmishAIId, teamId, paramIds, paramIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Team_getTeamRulesParams");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, paramIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_hasAIController") == 0) {
        long teamId;
        ei_decode_long(recvbuff, &index, &teamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Team_hasAIController(skirmishAIId, teamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Team_hasAIController");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Teams_getSize") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Teams_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Teams_getSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_FlankingBonus_getMax") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_FlankingBonus_getMax(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_FlankingBonus_getMax");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_FlankingBonus_getMin") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_FlankingBonus_getMin(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_FlankingBonus_getMin");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_FlankingBonus_getMobilityAdd") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_FlankingBonus_getMobilityAdd(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_FlankingBonus_getMobilityAdd");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_FlankingBonus_getMode") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_FlankingBonus_getMode(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_FlankingBonus_getMode");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getCrushStrength") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_MoveData_getCrushStrength(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getCrushStrength");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getDepth") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_MoveData_getDepth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getDepth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getDepthMod") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        double height;
        ei_decode_double(recvbuff, &index, &height);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_MoveData_getDepthMod(skirmishAIId, unitDefId, height);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getDepthMod");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getFollowGround") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_MoveData_getFollowGround(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getFollowGround");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxAcceleration") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_MoveData_getMaxAcceleration(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getMaxAcceleration");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxBreaking") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_MoveData_getMaxBreaking(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getMaxBreaking");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxSlope") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_MoveData_getMaxSlope(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getMaxSlope");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_MoveData_getMaxSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getMaxSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxTurnRate") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        short result = callback->UnitDef_MoveData_getMaxTurnRate(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getMaxTurnRate");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMoveType") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_MoveData_getMoveType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getMoveType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getName") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_MoveData_getName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getPathType") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_MoveData_getPathType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getPathType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getSlopeMod") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_MoveData_getSlopeMod(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getSlopeMod");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getSpeedModClass") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_MoveData_getSpeedModClass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getSpeedModClass");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getTerrainClass") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_MoveData_getTerrainClass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getTerrainClass");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getXSize") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_MoveData_getXSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getXSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getZSize") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_MoveData_getZSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_getZSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_isSubMarine") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_MoveData_isSubMarine(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_MoveData_isSubMarine");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getBadTargetCategory") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long weaponMountId;
        ei_decode_long(recvbuff, &index, &weaponMountId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_WeaponMount_getBadTargetCategory(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_WeaponMount_getBadTargetCategory");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getFuelUsage") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long weaponMountId;
        ei_decode_long(recvbuff, &index, &weaponMountId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_WeaponMount_getFuelUsage(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_WeaponMount_getFuelUsage");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getMaxAngleDif") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long weaponMountId;
        ei_decode_long(recvbuff, &index, &weaponMountId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_WeaponMount_getMaxAngleDif(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_WeaponMount_getMaxAngleDif");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getName") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long weaponMountId;
        ei_decode_long(recvbuff, &index, &weaponMountId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_WeaponMount_getName(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_WeaponMount_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getOnlyTargetCategory") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long weaponMountId;
        ei_decode_long(recvbuff, &index, &weaponMountId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_WeaponMount_getOnlyTargetCategory(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_WeaponMount_getOnlyTargetCategory");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getSlavedTo") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long weaponMountId;
        ei_decode_long(recvbuff, &index, &weaponMountId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_WeaponMount_getSlavedTo(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_WeaponMount_getSlavedTo");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getWeaponDef") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long weaponMountId;
        ei_decode_long(recvbuff, &index, &weaponMountId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_WeaponMount_getWeaponDef(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_WeaponMount_getWeaponDef");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_canManualFire") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_canManualFire(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_canManualFire");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getAiHint") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getAiHint(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getAiHint");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getAirLosRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getAirLosRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getAirLosRadius");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getArmorType") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getArmorType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getArmorType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getArmoredMultiple") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getArmoredMultiple(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getArmoredMultiple");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getAutoHeal") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getAutoHeal(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getAutoHeal");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildAngle") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getBuildAngle(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getBuildAngle");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildDistance") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getBuildDistance(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getBuildDistance");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildOptions") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long unitDefIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitDefIds_sizeMax);
        int unitDefIds[unitDefIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getBuildOptions(skirmishAIId, unitDefId, unitDefIds, unitDefIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getBuildOptions");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitDefIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getBuildSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getBuildSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildTime") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getBuildTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getBuildTime");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildingDecalDecaySpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getBuildingDecalDecaySpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getBuildingDecalDecaySpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildingDecalSizeX") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getBuildingDecalSizeX(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getBuildingDecalSizeX");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildingDecalSizeY") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getBuildingDecalSizeY(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getBuildingDecalSizeY");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildingDecalType") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getBuildingDecalType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getBuildingDecalType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCaptureSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getCaptureSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getCaptureSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCategory") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getCategory(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getCategory");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCategoryString") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_getCategoryString(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getCategoryString");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCloakCost") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getCloakCost(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getCloakCost");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCloakCostMoving") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getCloakCostMoving(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getCloakCostMoving");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCobId") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getCobId(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getCobId");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCost") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getCost(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getCost");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDeathExplosion") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getDeathExplosion(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getDeathExplosion");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDecloakDistance") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getDecloakDistance(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getDecloakDistance");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDecoyDef") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getDecoyDef(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getDecoyDef");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDlHoverFactor") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getDlHoverFactor(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getDlHoverFactor");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDrag") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getDrag(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getDrag");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getExtractsResource") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getExtractsResource(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getExtractsResource");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFallSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getFallSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFallSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFileName") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_getFileName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFileName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFireState") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getFireState(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFireState");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareDelay") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getFlareDelay(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFlareDelay");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareEfficiency") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getFlareEfficiency(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFlareEfficiency");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareReloadTime") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getFlareReloadTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFlareReloadTime");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareSalvoDelay") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getFlareSalvoDelay(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFlareSalvoDelay");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareSalvoSize") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getFlareSalvoSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFlareSalvoSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareTime") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getFlareTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFlareTime");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFrontToSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getFrontToSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getFrontToSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getGaia") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_getGaia(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getGaia");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getHealth") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getHealth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getHealth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getHeight") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getHeight(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getHeight");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getHighTrajectoryType") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getHighTrajectoryType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getHighTrajectoryType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getHumanName") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_getHumanName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getHumanName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getIdleAutoHeal") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getIdleAutoHeal(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getIdleAutoHeal");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getIdleTime") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getIdleTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getIdleTime");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getJammerRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getJammerRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getJammerRadius");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getKamikazeDist") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getKamikazeDist(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getKamikazeDist");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getLoadingRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getLoadingRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getLoadingRadius");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getLosHeight") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getLosHeight(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getLosHeight");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getLosRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getLosRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getLosRadius");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMakesResource") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMakesResource(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMakesResource");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMass") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMass");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxAcceleration") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxAcceleration(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxAcceleration");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxAileron") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxAileron(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxAileron");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxBank") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxBank(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxBank");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxDeceleration") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxDeceleration(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxDeceleration");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxElevator") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxElevator(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxElevator");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxFuel") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxFuel(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxFuel");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxHeightDif") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxHeightDif(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxHeightDif");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxPitch") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxPitch(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxPitch");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxRepairSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxRepairSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxRepairSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxRudder") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxRudder(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxRudder");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxSlope") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxSlope(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxSlope");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxThisUnit") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getMaxThisUnit(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxThisUnit");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxWaterDepth") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxWaterDepth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxWaterDepth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxWeaponRange") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMaxWeaponRange(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMaxWeaponRange");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinAirBasePower") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMinAirBasePower(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMinAirBasePower");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinCollisionSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMinCollisionSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMinCollisionSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinTransportMass") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMinTransportMass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMinTransportMass");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinTransportSize") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getMinTransportSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMinTransportSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinWaterDepth") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMinWaterDepth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMinWaterDepth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMoveState") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getMoveState(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMoveState");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMyGravity") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getMyGravity(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getMyGravity");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getName") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_getName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getNoChaseCategory") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getNoChaseCategory(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getNoChaseCategory");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getPower") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getPower(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getPower");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getRadarRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getRadarRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getRadarRadius");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getRadius");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getReclaimSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getReclaimSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getReclaimSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getRefuelTime") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getRefuelTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getRefuelTime");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getRepairSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getRepairSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getRepairSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getResourceExtractorRange") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getResourceExtractorRange(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getResourceExtractorRange");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getResourceMake") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getResourceMake(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getResourceMake");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getResurrectSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getResurrectSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getResurrectSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSeismicRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getSeismicRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getSeismicRadius");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSeismicSignature") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getSeismicSignature(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getSeismicSignature");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSelfDCountdown") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getSelfDCountdown(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getSelfDCountdown");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSelfDExplosion") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getSelfDExplosion(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getSelfDExplosion");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getShieldDef") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getShieldDef(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getShieldDef");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSlideTolerance") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getSlideTolerance(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getSlideTolerance");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSonarJamRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getSonarJamRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getSonarJamRadius");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSonarRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getSonarRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getSonarRadius");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSpeedToFront") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getSpeedToFront(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getSpeedToFront");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getStockpileDef") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getStockpileDef(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getStockpileDef");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getStorage") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getStorage(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getStorage");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTechLevel") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getTechLevel(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTechLevel");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTerraformSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTerraformSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTerraformSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTidalResourceGenerator") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTidalResourceGenerator(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTidalResourceGenerator");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTooltip") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_getTooltip(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTooltip");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackOffset") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTrackOffset(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTrackOffset");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackStrength") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTrackStrength(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTrackStrength");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackStretch") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTrackStretch(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTrackStretch");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackType") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getTrackType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTrackType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackWidth") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTrackWidth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTrackWidth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTransportCapacity") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getTransportCapacity(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTransportCapacity");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTransportMass") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTransportMass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTransportMass");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTransportSize") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getTransportSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTransportSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTransportUnloadMethod") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getTransportUnloadMethod(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTransportUnloadMethod");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTurnInPlaceDistance") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTurnInPlaceDistance(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTurnInPlaceDistance");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTurnInPlaceSpeedLimit") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTurnInPlaceSpeedLimit(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTurnInPlaceSpeedLimit");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTurnRadius") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTurnRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTurnRadius");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTurnRate") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getTurnRate(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getTurnRate");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getType") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_getType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getType");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getUnitFallSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getUnitFallSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getUnitFallSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getUnloadSpread") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getUnloadSpread(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getUnloadSpread");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getUpkeep") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getUpkeep(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getUpkeep");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getVerticalSpeed") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getVerticalSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getVerticalSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWantedHeight") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getWantedHeight(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getWantedHeight");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWaterline") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getWaterline(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getWaterline");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWeaponMounts") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getWeaponMounts(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getWeaponMounts");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWindResourceGenerator") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getWindResourceGenerator(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getWindResourceGenerator");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWingAngle") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getWingAngle(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getWingAngle");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWingDrag") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->UnitDef_getWingDrag(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getWingDrag");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWreckName") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->UnitDef_getWreckName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getWreckName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getXSize") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getXSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getXSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getZSize") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->UnitDef_getZSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_getZSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToAssist") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToAssist(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToAssist");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToAttack") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToAttack(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToAttack");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToCapture") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToCapture(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToCapture");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToCloak") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToCloak(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToCloak");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToCrash") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToCrash(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToCrash");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToDropFlare") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToDropFlare(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToDropFlare");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToFight") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToFight(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToFight");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToFireControl") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToFireControl(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToFireControl");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToFly") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToFly(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToFly");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToGuard") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToGuard(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToGuard");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToHover") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToHover(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToHover");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToKamikaze") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToKamikaze(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToKamikaze");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToLoopbackAttack") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToLoopbackAttack(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToLoopbackAttack");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToMove") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToMove(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToMove");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToPatrol") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToPatrol(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToPatrol");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToReclaim") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToReclaim(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToReclaim");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToRepair") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToRepair(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToRepair");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToRepeat") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToRepeat(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToRepeat");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToRestore") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToRestore(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToRestore");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToResurrect") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToResurrect(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToResurrect");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToSelfD") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToSelfD(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToSelfD");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToSelfRepair") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToSelfRepair(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToSelfRepair");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToSubmerge") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAbleToSubmerge(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAbleToSubmerge");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isActivateWhenBuilt") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isActivateWhenBuilt(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isActivateWhenBuilt");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAirBase") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAirBase(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAirBase");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAirStrafe") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAirStrafe(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAirStrafe");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAssistable") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isAssistable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isAssistable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isBuildRange3D") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isBuildRange3D(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isBuildRange3D");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isBuilder") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isBuilder(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isBuilder");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isCapturable") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isCapturable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isCapturable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isCollide") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isCollide(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isCollide");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isCommander") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isCommander(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isCommander");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isDecloakOnFire") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isDecloakOnFire(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isDecloakOnFire");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isDecloakSpherical") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isDecloakSpherical(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isDecloakSpherical");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isDontLand") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isDontLand(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isDontLand");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFactoryHeadingTakeoff") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isFactoryHeadingTakeoff(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isFactoryHeadingTakeoff");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFeature") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isFeature(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isFeature");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFirePlatform") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isFirePlatform(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isFirePlatform");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFloater") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isFloater(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isFloater");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFullHealthFactory") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isFullHealthFactory(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isFullHealthFactory");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isHideDamage") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isHideDamage(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isHideDamage");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isHoldSteady") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isHoldSteady(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isHoldSteady");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isHoverAttack") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isHoverAttack(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isHoverAttack");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isLeaveTracks") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isLeaveTracks(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isLeaveTracks");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isLevelGround") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isLevelGround(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isLevelGround");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isMoveDataAvailable") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isMoveDataAvailable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isMoveDataAvailable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isNeedGeo") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isNeedGeo(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isNeedGeo");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isNotTransportable") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isNotTransportable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isNotTransportable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isOnOffable") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isOnOffable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isOnOffable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isPushResistant") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isPushResistant(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isPushResistant");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isReclaimable") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isReclaimable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isReclaimable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isReleaseHeld") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isReleaseHeld(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isReleaseHeld");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isShowPlayerName") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isShowPlayerName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isShowPlayerName");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isSonarStealth") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isSonarStealth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isSonarStealth");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isSquareResourceExtractor") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isSquareResourceExtractor(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isSquareResourceExtractor");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isStartCloaked") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isStartCloaked(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isStartCloaked");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isStealth") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isStealth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isStealth");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isStrafeToAttack") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isStrafeToAttack(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isStrafeToAttack");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isTargetingFacility") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isTargetingFacility(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isTargetingFacility");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isTransportByEnemy") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isTransportByEnemy(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isTransportByEnemy");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isTurnInPlace") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isTurnInPlace(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isTurnInPlace");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isUpright") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isUpright(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isUpright");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isUseBuildingGroundDecal") == 0) {
        long unitDefId;
        ei_decode_long(recvbuff, &index, &unitDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->UnitDef_isUseBuildingGroundDecal(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "UnitDef_isUseBuildingGroundDecal");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getId") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long commandId;
        ei_decode_long(recvbuff, &index, &commandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_CurrentCommand_getId(skirmishAIId, unitId, commandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_CurrentCommand_getId");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getOptions") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long commandId;
        ei_decode_long(recvbuff, &index, &commandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        short result = callback->Unit_CurrentCommand_getOptions(skirmishAIId, unitId, commandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_CurrentCommand_getOptions");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getTag") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long commandId;
        ei_decode_long(recvbuff, &index, &commandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_CurrentCommand_getTag(skirmishAIId, unitId, commandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_CurrentCommand_getTag");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getTimeOut") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long commandId;
        ei_decode_long(recvbuff, &index, &commandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_CurrentCommand_getTimeOut(skirmishAIId, unitId, commandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_CurrentCommand_getTimeOut");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getType") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_CurrentCommand_getType(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_CurrentCommand_getType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_getId") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_SupportedCommand_getId(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_SupportedCommand_getId");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_getName") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Unit_SupportedCommand_getName(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_SupportedCommand_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_getToolTip") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Unit_SupportedCommand_getToolTip(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_SupportedCommand_getToolTip");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_isDisabled") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Unit_SupportedCommand_isDisabled(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_SupportedCommand_isDisabled");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_isShowUnique") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long supportedCommandId;
        ei_decode_long(recvbuff, &index, &supportedCommandId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Unit_SupportedCommand_isShowUnique(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_SupportedCommand_isShowUnique");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_UnitRulesParam_getName") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long unitRulesParamId;
        ei_decode_long(recvbuff, &index, &unitRulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Unit_UnitRulesParam_getName(skirmishAIId, unitId, unitRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_UnitRulesParam_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_UnitRulesParam_getValueFloat") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long unitRulesParamId;
        ei_decode_long(recvbuff, &index, &unitRulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_UnitRulesParam_getValueFloat(skirmishAIId, unitId, unitRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_UnitRulesParam_getValueFloat");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_UnitRulesParam_getValueString") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long unitRulesParamId;
        ei_decode_long(recvbuff, &index, &unitRulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->Unit_UnitRulesParam_getValueString(skirmishAIId, unitId, unitRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_UnitRulesParam_getValueString");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_Weapon_getDef") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long weaponId;
        ei_decode_long(recvbuff, &index, &weaponId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_Weapon_getDef(skirmishAIId, unitId, weaponId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_Weapon_getDef");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_Weapon_getRange") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long weaponId;
        ei_decode_long(recvbuff, &index, &weaponId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_Weapon_getRange(skirmishAIId, unitId, weaponId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_Weapon_getRange");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_Weapon_getReloadFrame") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long weaponId;
        ei_decode_long(recvbuff, &index, &weaponId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_Weapon_getReloadFrame(skirmishAIId, unitId, weaponId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_Weapon_getReloadFrame");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_Weapon_getReloadTime") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long weaponId;
        ei_decode_long(recvbuff, &index, &weaponId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_Weapon_getReloadTime(skirmishAIId, unitId, weaponId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_Weapon_getReloadTime");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getAiHint") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getAiHint(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getAiHint");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getAllyTeam") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getAllyTeam(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getAllyTeam");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getBuildingFacing") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getBuildingFacing(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getBuildingFacing");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getCurrentCommands") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getCurrentCommands(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getCurrentCommands");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getCurrentFuel") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getCurrentFuel(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getCurrentFuel");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getDef") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getDef(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getDef");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getExperience") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getExperience(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getExperience");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getGroup") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getGroup(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getGroup");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getHealth") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getHealth(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getHealth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getLastUserOrderFrame") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getLastUserOrderFrame(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getLastUserOrderFrame");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getLimit") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getLimit(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getLimit");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getMax") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getMax(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getMax");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getMaxHealth") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getMaxHealth(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getMaxHealth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getMaxRange") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getMaxRange(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getMaxRange");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getMaxSpeed") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getMaxSpeed(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getMaxSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getPower") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getPower(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getPower");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getResourceMake") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getResourceMake(skirmishAIId, unitId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getResourceMake");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getResourceUse") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getResourceUse(skirmishAIId, unitId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getResourceUse");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getSpeed") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->Unit_getSpeed(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getStockpile") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getStockpile(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getStockpile");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getStockpileQueued") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getStockpileQueued(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getStockpileQueued");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getSupportedCommands") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getSupportedCommands(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getSupportedCommands");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getTeam") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getTeam(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getTeam");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getUnitRulesParamById") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long rulesParamId;
        ei_decode_long(recvbuff, &index, &rulesParamId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getUnitRulesParamById(skirmishAIId, unitId, rulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getUnitRulesParamById");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getUnitRulesParamByName") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        char* rulesParamName;
        ei_decode_string(recvbuff, &index, rulesParamName);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getUnitRulesParamByName(skirmishAIId, unitId, rulesParamName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getUnitRulesParamByName");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getUnitRulesParams") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long paramIds_sizeMax;
        ei_decode_long(recvbuff, &index, &paramIds_sizeMax);
        int paramIds[paramIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getUnitRulesParams(skirmishAIId, unitId, paramIds, paramIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getUnitRulesParams");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, paramIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getWeapon") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        long weaponMountId;
        ei_decode_long(recvbuff, &index, &weaponMountId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getWeapon(skirmishAIId, unitId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getWeapon");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getWeapons") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->Unit_getWeapons(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_getWeapons");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isActivated") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Unit_isActivated(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_isActivated");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isBeingBuilt") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Unit_isBeingBuilt(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_isBeingBuilt");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isCloaked") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Unit_isCloaked(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_isCloaked");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isNeutral") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Unit_isNeutral(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_isNeutral");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isParalyzed") == 0) {
        long unitId;
        ei_decode_long(recvbuff, &index, &unitId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->Unit_isParalyzed(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "Unit_isParalyzed");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getCraterBoost") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Damage_getCraterBoost(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Damage_getCraterBoost");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getCraterMult") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Damage_getCraterMult(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Damage_getCraterMult");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getImpulseBoost") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Damage_getImpulseBoost(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Damage_getImpulseBoost");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getImpulseFactor") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Damage_getImpulseFactor(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Damage_getImpulseFactor");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getParalyzeDamageTime") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_Damage_getParalyzeDamageTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Damage_getParalyzeDamageTime");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getAlpha") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        short result = callback->WeaponDef_Shield_getAlpha(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getAlpha");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getForce") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Shield_getForce(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getForce");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getInterceptType") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_Shield_getInterceptType(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getInterceptType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getMaxSpeed") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Shield_getMaxSpeed(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getMaxSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getPower") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Shield_getPower(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getPower");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getPowerRegen") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Shield_getPowerRegen(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getPowerRegen");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getPowerRegenResource") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Shield_getPowerRegenResource(skirmishAIId, weaponDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getPowerRegenResource");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getRadius") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Shield_getRadius(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getRadius");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getRechargeDelay") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_Shield_getRechargeDelay(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getRechargeDelay");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getResourceUse") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Shield_getResourceUse(skirmishAIId, weaponDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getResourceUse");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getStartingPower") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_Shield_getStartingPower(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_Shield_getStartingPower");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getAccuracy") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getAccuracy(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getAccuracy");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getAreaOfEffect") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getAreaOfEffect(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getAreaOfEffect");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getBeamTime") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getBeamTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getBeamTime");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getBounceRebound") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getBounceRebound(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getBounceRebound");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getBounceSlip") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getBounceSlip(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getBounceSlip");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCameraShake") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getCameraShake(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getCameraShake");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCegTag") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->WeaponDef_getCegTag(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getCegTag");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCollisionFlags") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getCollisionFlags(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getCollisionFlags");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCollisionSize") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getCollisionSize(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getCollisionSize");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCoreThickness") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getCoreThickness(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getCoreThickness");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCost") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        long resourceId;
        ei_decode_long(recvbuff, &index, &resourceId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getCost(skirmishAIId, weaponDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getCost");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCoverageRange") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getCoverageRange(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getCoverageRange");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCylinderTargetting") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getCylinderTargetting(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getCylinderTargetting");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDance") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getDance(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getDance");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDescription") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->WeaponDef_getDescription(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getDescription");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDuration") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getDuration(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getDuration");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDynDamageExp") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getDynDamageExp(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getDynDamageExp");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDynDamageMin") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getDynDamageMin(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getDynDamageMin");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDynDamageRange") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getDynDamageRange(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getDynDamageRange");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getEdgeEffectiveness") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getEdgeEffectiveness(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getEdgeEffectiveness");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getExplosionSpeed") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getExplosionSpeed(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getExplosionSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getFalloffRate") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getFalloffRate(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getFalloffRate");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getFileName") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->WeaponDef_getFileName(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getFileName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getFireStarter") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getFireStarter(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getFireStarter");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getFlightTime") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getFlightTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getFlightTime");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getGraphicsType") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getGraphicsType(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getGraphicsType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getHeightBoostFactor") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getHeightBoostFactor(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getHeightBoostFactor");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getHeightMod") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getHeightMod(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getHeightMod");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getHighTrajectory") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getHighTrajectory(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getHighTrajectory");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getIntensity") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getIntensity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getIntensity");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getInterceptedByShieldType") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getInterceptedByShieldType(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getInterceptedByShieldType");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getInterceptor") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getInterceptor(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getInterceptor");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getLaserFlareSize") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getLaserFlareSize(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getLaserFlareSize");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getLeadBonus") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getLeadBonus(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getLeadBonus");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getLeadLimit") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getLeadLimit(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getLeadLimit");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getLodDistance") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getLodDistance(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getLodDistance");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMaxAngle") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getMaxAngle(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getMaxAngle");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMaxVelocity") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getMaxVelocity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getMaxVelocity");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMinIntensity") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getMinIntensity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getMinIntensity");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMovingAccuracy") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getMovingAccuracy(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getMovingAccuracy");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMyGravity") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getMyGravity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getMyGravity");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getName") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->WeaponDef_getName(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getName");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getNumBounce") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getNumBounce(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getNumBounce");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getNumDamageTypes") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getNumDamageTypes(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getNumDamageTypes");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getOnlyTargetCategory") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getOnlyTargetCategory(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getOnlyTargetCategory");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getPredictBoost") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getPredictBoost(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getPredictBoost");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getProjectileSpeed") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getProjectileSpeed(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getProjectileSpeed");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getProjectilesPerShot") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getProjectilesPerShot(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getProjectilesPerShot");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getProximityPriority") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getProximityPriority(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getProximityPriority");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getRange") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getRange(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getRange");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getReload") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getReload(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getReload");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSalvoDelay") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getSalvoDelay(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getSalvoDelay");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSalvoSize") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getSalvoSize(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getSalvoSize");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSize") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getSize(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getSize");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSizeGrowth") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getSizeGrowth(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getSizeGrowth");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSprayAngle") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getSprayAngle(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getSprayAngle");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getStartVelocity") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getStartVelocity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getStartVelocity");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getStockpileTime") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getStockpileTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getStockpileTime");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTargetBorder") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getTargetBorder(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getTargetBorder");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTargetMoveError") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getTargetMoveError(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getTargetMoveError");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTargetable") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getTargetable(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getTargetable");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getThickness") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getThickness(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getThickness");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTrajectoryHeight") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getTrajectoryHeight(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getTrajectoryHeight");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTurnRate") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getTurnRate(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getTurnRate");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getType") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        const char* result = callback->WeaponDef_getType(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getType");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getUpTime") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getUpTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getUpTime");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getVisibleShieldHitFrames") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->WeaponDef_getVisibleShieldHitFrames(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getVisibleShieldHitFrames");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getWeaponAcceleration") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getWeaponAcceleration(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getWeaponAcceleration");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getWobble") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        float result = callback->WeaponDef_getWobble(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_getWobble");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isAbleToAttackGround") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isAbleToAttackGround(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isAbleToAttackGround");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isAvoidFeature") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isAvoidFeature(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isAvoidFeature");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isAvoidFriendly") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isAvoidFriendly(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isAvoidFriendly");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isAvoidNeutral") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isAvoidNeutral(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isAvoidNeutral");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isBeamBurst") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isBeamBurst(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isBeamBurst");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isDropped") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isDropped(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isDropped");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isDynDamageInverted") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isDynDamageInverted(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isDynDamageInverted");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isExteriorShield") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isExteriorShield(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isExteriorShield");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isFireSubmersed") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isFireSubmersed(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isFireSubmersed");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isFixedLauncher") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isFixedLauncher(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isFixedLauncher");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isGravityAffected") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isGravityAffected(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isGravityAffected");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isGroundBounce") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isGroundBounce(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isGroundBounce");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isImpactOnly") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isImpactOnly(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isImpactOnly");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isLargeBeamLaser") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isLargeBeamLaser(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isLargeBeamLaser");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isManualFire") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isManualFire(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isManualFire");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isNoAutoTarget") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isNoAutoTarget(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isNoAutoTarget");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isNoExplode") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isNoExplode(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isNoExplode");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isNoSelfDamage") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isNoSelfDamage(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isNoSelfDamage");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isOnlyForward") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isOnlyForward(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isOnlyForward");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isParalyzer") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isParalyzer(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isParalyzer");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSelfExplode") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isSelfExplode(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isSelfExplode");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isShield") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isShield(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isShield");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isShieldRepulser") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isShieldRepulser(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isShieldRepulser");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSmartShield") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isSmartShield(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isSmartShield");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSoundTrigger") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isSoundTrigger(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isSoundTrigger");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isStockpileable") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isStockpileable(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isStockpileable");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSubMissile") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isSubMissile(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isSubMissile");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSweepFire") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isSweepFire(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isSweepFire");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isTracks") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isTracks(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isTracks");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isTurret") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isTurret(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isTurret");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isVisibleShield") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isVisibleShield(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isVisibleShield");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isVisibleShieldRepulse") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isVisibleShieldRepulse(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isVisibleShieldRepulse");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isWaterBounce") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isWaterBounce(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isWaterBounce");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isWaterWeapon") == 0) {
        long weaponDefId;
        ei_decode_long(recvbuff, &index, &weaponDefId);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        bool result = callback->WeaponDef_isWaterWeapon(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "WeaponDef_isWaterWeapon");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getAllyTeams") == 0) {
        long teamIds_sizeMax;
        ei_decode_long(recvbuff, &index, &teamIds_sizeMax);
        int teamIds[teamIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getAllyTeams(skirmishAIId, teamIds, teamIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getAllyTeams");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, teamIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getEnemyTeams") == 0) {
        long teamIds_sizeMax;
        ei_decode_long(recvbuff, &index, &teamIds_sizeMax);
        int teamIds[teamIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getEnemyTeams(skirmishAIId, teamIds, teamIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getEnemyTeams");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, teamIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getEnemyUnits") == 0) {
        long unitIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getEnemyUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getEnemyUnits");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getEnemyUnitsIn") == 0) {
        float pos_posF3[3];
        double tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[0] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[1] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[2] = tmp;
        double radius;
        ei_decode_double(recvbuff, &index, &radius);
        long unitIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getEnemyUnitsIn(skirmishAIId, pos_posF3, radius, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getEnemyUnitsIn");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getEnemyUnitsInRadarAndLos") == 0) {
        long unitIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getEnemyUnitsInRadarAndLos(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getEnemyUnitsInRadarAndLos");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getFeatureDefs") == 0) {
        long featureDefIds_sizeMax;
        ei_decode_long(recvbuff, &index, &featureDefIds_sizeMax);
        int featureDefIds[featureDefIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getFeatureDefs(skirmishAIId, featureDefIds, featureDefIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getFeatureDefs");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, featureDefIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getFeatures") == 0) {
        long featureIds_sizeMax;
        ei_decode_long(recvbuff, &index, &featureIds_sizeMax);
        int featureIds[featureIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getFeatures(skirmishAIId, featureIds, featureIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getFeatures");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, featureIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getFeaturesIn") == 0) {
        float pos_posF3[3];
        double tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[0] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[1] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[2] = tmp;
        double radius;
        ei_decode_double(recvbuff, &index, &radius);
        long featureIds_sizeMax;
        ei_decode_long(recvbuff, &index, &featureIds_sizeMax);
        int featureIds[featureIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getFeaturesIn(skirmishAIId, pos_posF3, radius, featureIds, featureIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getFeaturesIn");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, featureIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getFriendlyUnits") == 0) {
        long unitIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getFriendlyUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getFriendlyUnits");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getFriendlyUnitsIn") == 0) {
        float pos_posF3[3];
        double tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[0] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[1] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[2] = tmp;
        double radius;
        ei_decode_double(recvbuff, &index, &radius);
        long unitIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getFriendlyUnitsIn(skirmishAIId, pos_posF3, radius, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getFriendlyUnitsIn");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getGroups") == 0) {
        long groupIds_sizeMax;
        ei_decode_long(recvbuff, &index, &groupIds_sizeMax);
        int groupIds[groupIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getGroups(skirmishAIId, groupIds, groupIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getGroups");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, groupIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getNeutralUnits") == 0) {
        long unitIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getNeutralUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getNeutralUnits");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getNeutralUnitsIn") == 0) {
        float pos_posF3[3];
        double tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[0] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[1] = tmp;
        ei_decode_double(recvbuff, &index, &tmp);
        pos_posF3[2] = tmp;
        double radius;
        ei_decode_double(recvbuff, &index, &radius);
        long unitIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getNeutralUnitsIn(skirmishAIId, pos_posF3, radius, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getNeutralUnitsIn");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getResourceByName") == 0) {
        char* resourceName;
        ei_decode_string(recvbuff, &index, resourceName);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getResourceByName(skirmishAIId, resourceName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getResourceByName");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getResources") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getResources(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getResources");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getSelectedUnits") == 0) {
        long unitIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getSelectedUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getSelectedUnits");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getTeamUnits") == 0) {
        long unitIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitIds_sizeMax);
        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getTeamUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getTeamUnits");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getUnitDefByName") == 0) {
        char* unitName;
        ei_decode_string(recvbuff, &index, unitName);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getUnitDefByName(skirmishAIId, unitName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getUnitDefByName");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getUnitDefs") == 0) {
        long unitDefIds_sizeMax;
        ei_decode_long(recvbuff, &index, &unitDefIds_sizeMax);
        int unitDefIds[unitDefIds_sizeMax];
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getUnitDefs(skirmishAIId, unitDefIds, unitDefIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getUnitDefs");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitDefIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getWeaponDefByName") == 0) {
        char* weaponDefName;
        ei_decode_string(recvbuff, &index, weaponDefName);
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getWeaponDefByName(skirmishAIId, weaponDefName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getWeaponDefByName");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getWeaponDefs") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuff, &index, &from);
        int result = callback->getWeaponDefs(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 3);
        ei_x_encode_atom(&sendbuff, "result");
        ei_x_encode_atom(&sendbuff, "getWeaponDefs");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    return -1;
}
