
/* THIS FILE GETS GENERATED, DO NOT EDIT DIRECTLY! */

#include <string.h>

#include "ei.h"
#include "rts/ExternalAI/Interface/SSkirmishAICallback.h"
#include "send_to.h"

int handle_callback(int skirmishAIId, const struct SSkirmishAICallback* callback, ei_x_buff buff){
    char callback_what[64] = "";
    {
        int result = ei_decode_atom(buff.buff, &buff.index, callback_what);
        if (result != 0) {
            fprintf(stderr, "[ERROR] cannot decode 'callback_what' as 'char*', error code %i\n", result);
            ei_x_free(&buff);
            return result;
        }
    }

    printf("\tcallback: %s\n", callback_what);    if (strcmp(callback_what, "Cheats_isEnabled") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Cheats_isEnabled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Cheats_isOnlyPassive") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Cheats_isOnlyPassive(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Cheats_setEnabled") == 0) {
        int enable;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &enable);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'enable' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Cheats_setEnabled(skirmishAIId, enable);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Cheats_setEventsEnabled") == 0) {
        int enabled;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &enabled);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'enabled' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Cheats_setEventsEnabled(skirmishAIId, enabled);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_Roots_getDir") == 0) {
        char* path;
        {
            int result = ei_decode_string(buff.buff, &buff.index, path);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'path' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int path_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'path_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            path_sizeMax = (int)tmp;
        }

        int dirIndex;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'dirIndex' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            dirIndex = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->DataDirs_Roots_getDir(skirmishAIId, path, path_sizeMax, dirIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_Roots_getSize") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->DataDirs_Roots_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_Roots_locatePath") == 0) {
        char* path;
        {
            int result = ei_decode_string(buff.buff, &buff.index, path);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'path' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int path_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'path_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            path_sizeMax = (int)tmp;
        }

        char* relPath;
        {
            int result = ei_decode_string(buff.buff, &buff.index, relPath);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'relPath' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int writeable;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &writeable);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'writeable' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int create;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &create);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'create' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int dir;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &dir);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'dir' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->DataDirs_Roots_locatePath(skirmishAIId, path, path_sizeMax, relPath, writeable, create, dir);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_getConfigDir") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->DataDirs_getConfigDir(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_getPathSeparator") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        char result = callback->DataDirs_getPathSeparator(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_char(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_getWriteableDir") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->DataDirs_getWriteableDir(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "DataDirs_locatePath") == 0) {
        char* path;
        {
            int result = ei_decode_string(buff.buff, &buff.index, path);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'path' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int path_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'path_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            path_sizeMax = (int)tmp;
        }

        char* relPath;
        {
            int result = ei_decode_string(buff.buff, &buff.index, relPath);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'relPath' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int writeable;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &writeable);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'writeable' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int create;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &create);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'create' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int dir;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &dir);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'dir' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int common;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &common);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'common' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->DataDirs_locatePath(skirmishAIId, path, path_sizeMax, relPath, writeable, create, dir, common);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Debug_GraphDrawer_isEnabled") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Debug_GraphDrawer_isEnabled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getCurrent") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Economy_getCurrent(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getExcess") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Economy_getExcess(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getIncome") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Economy_getIncome(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getPull") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Economy_getPull(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getReceived") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Economy_getReceived(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getSent") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Economy_getSent(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getShare") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Economy_getShare(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getStorage") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Economy_getStorage(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Economy_getUsage") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Economy_getUsage(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getAdditional") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getAdditional(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getBranch") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getBranch(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getBuildTime") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getBuildTime(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getCommits") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getCommits(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getFull") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getFull(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getHash") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getHash(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getMajor") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getMajor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getMinor") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getMinor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getNormal") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getNormal(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getPatchset") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getPatchset(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_getSync") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Engine_Version_getSync(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Engine_Version_isRelease") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Engine_Version_isRelease(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getContainedResource") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->FeatureDef_getContainedResource(skirmishAIId, featureDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getDeathFeature") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->FeatureDef_getDeathFeature(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getDescription") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->FeatureDef_getDescription(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getDrawType") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->FeatureDef_getDrawType(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getFileName") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->FeatureDef_getFileName(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getMass") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->FeatureDef_getMass(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getMaxHealth") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->FeatureDef_getMaxHealth(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getModelName") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->FeatureDef_getModelName(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getName") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->FeatureDef_getName(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getReclaimTime") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->FeatureDef_getReclaimTime(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getResurrectable") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->FeatureDef_getResurrectable(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getSmokeTime") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->FeatureDef_getSmokeTime(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getXSize") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->FeatureDef_getXSize(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_getZSize") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->FeatureDef_getZSize(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isBlocking") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->FeatureDef_isBlocking(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isBurnable") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->FeatureDef_isBurnable(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isDestructable") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->FeatureDef_isDestructable(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isFloating") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->FeatureDef_isFloating(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isGeoThermal") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->FeatureDef_isGeoThermal(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isNoSelect") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->FeatureDef_isNoSelect(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isReclaimable") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->FeatureDef_isReclaimable(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "FeatureDef_isUpright") == 0) {
        int featureDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->FeatureDef_isUpright(skirmishAIId, featureDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Feature_getDef") == 0) {
        int featureId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Feature_getDef(skirmishAIId, featureId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Feature_getHealth") == 0) {
        int featureId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Feature_getHealth(skirmishAIId, featureId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Feature_getPosition") == 0) {
        int featureId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureId = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Feature_getPosition(skirmishAIId, featureId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Feature_getReclaimLeft") == 0) {
        int featureId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Feature_getReclaimLeft(skirmishAIId, featureId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "File_getSize") == 0) {
        char* fileName;
        {
            int result = ei_decode_string(buff.buff, &buff.index, fileName);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'fileName' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->File_getSize(skirmishAIId, fileName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "GameRulesParam_getName") == 0) {
        int gameRulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'gameRulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            gameRulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->GameRulesParam_getName(skirmishAIId, gameRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "GameRulesParam_getValueFloat") == 0) {
        int gameRulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'gameRulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            gameRulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->GameRulesParam_getValueFloat(skirmishAIId, gameRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "GameRulesParam_getValueString") == 0) {
        int gameRulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'gameRulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            gameRulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->GameRulesParam_getValueString(skirmishAIId, gameRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getAiInterfaceVersion") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getAiInterfaceVersion(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getCategoriesFlag") == 0) {
        char* categoryNames;
        {
            int result = ei_decode_string(buff.buff, &buff.index, categoryNames);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'categoryNames' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getCategoriesFlag(skirmishAIId, categoryNames);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getCategoryFlag") == 0) {
        char* categoryName;
        {
            int result = ei_decode_string(buff.buff, &buff.index, categoryName);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'categoryName' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getCategoryFlag(skirmishAIId, categoryName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getCategoryName") == 0) {
        int categoryFlag;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'categoryFlag' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            categoryFlag = (int)tmp;
        }

        char* name;
        {
            int result = ei_decode_string(buff.buff, &buff.index, name);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'name' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int name_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'name_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            name_sizeMax = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Game_getCategoryName(skirmishAIId, categoryFlag, name, name_sizeMax);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getCurrentFrame") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getCurrentFrame(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getGameRulesParamById") == 0) {
        int rulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'rulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            rulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getGameRulesParamById(skirmishAIId, rulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getGameRulesParamByName") == 0) {
        char* rulesParamName;
        {
            int result = ei_decode_string(buff.buff, &buff.index, rulesParamName);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'rulesParamName' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getGameRulesParamByName(skirmishAIId, rulesParamName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getGameRulesParams") == 0) {
        int paramIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'paramIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            paramIds_sizeMax = (int)tmp;
        }

        int paramIds[paramIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getGameRulesParams(skirmishAIId, paramIds, paramIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
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
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getMode(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getMyAllyTeam") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getMyAllyTeam(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getMyTeam") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getMyTeam(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getPlayerTeam") == 0) {
        int playerId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'playerId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            playerId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getPlayerTeam(skirmishAIId, playerId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getSetupScript") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Game_getSetupScript(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getSpeedFactor") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getSpeedFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamAllyTeam") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getTeamAllyTeam(skirmishAIId, otherTeamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamIncomeMultiplier") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamIncomeMultiplier(skirmishAIId, otherTeamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceCurrent") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamResourceCurrent(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceExcess") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamResourceExcess(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceIncome") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamResourceIncome(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourcePull") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamResourcePull(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceReceived") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamResourceReceived(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceSent") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamResourceSent(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceShare") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamResourceShare(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceStorage") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamResourceStorage(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamResourceUsage") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Game_getTeamResourceUsage(skirmishAIId, otherTeamId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeamSide") == 0) {
        int otherTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'otherTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            otherTeamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Game_getTeamSide(skirmishAIId, otherTeamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_getTeams") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Game_getTeams(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_isAllied") == 0) {
        int firstAllyTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'firstAllyTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            firstAllyTeamId = (int)tmp;
        }

        int secondAllyTeamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'secondAllyTeamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            secondAllyTeamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Game_isAllied(skirmishAIId, firstAllyTeamId, secondAllyTeamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_isDebugModeEnabled") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Game_isDebugModeEnabled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_isExceptionHandlingEnabled") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Game_isExceptionHandlingEnabled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Game_isPaused") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Game_isPaused(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_OrderPreview_getId") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Group_OrderPreview_getId(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_OrderPreview_getOptions") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        short result = callback->Group_OrderPreview_getOptions(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_OrderPreview_getTag") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Group_OrderPreview_getTag(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_OrderPreview_getTimeOut") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Group_OrderPreview_getTimeOut(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_getId") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Group_SupportedCommand_getId(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_getName") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Group_SupportedCommand_getName(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_getToolTip") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Group_SupportedCommand_getToolTip(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_isDisabled") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Group_SupportedCommand_isDisabled(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_SupportedCommand_isShowUnique") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Group_SupportedCommand_isShowUnique(skirmishAIId, groupId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_getSupportedCommands") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Group_getSupportedCommands(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Group_isSelected") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Group_isSelected(skirmishAIId, groupId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Gui_Camera_getDirection") == 0) {
        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Gui_Camera_getDirection(skirmishAIId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Gui_Camera_getPosition") == 0) {
        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Gui_Camera_getPosition(skirmishAIId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Gui_getScreenX") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Gui_getScreenX(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Gui_getScreenY") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Gui_getScreenY(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Gui_getViewRange") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Gui_getViewRange(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Log_exception") == 0) {
        char* msg;
        {
            int result = ei_decode_string(buff.buff, &buff.index, msg);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'msg' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int severety;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'severety' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            severety = (int)tmp;
        }

        int die;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &die);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'die' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Log_exception(skirmishAIId, msg, severety, die);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Log_log") == 0) {
        char* msg;
        {
            int result = ei_decode_string(buff.buff, &buff.index, msg);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'msg' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Log_log(skirmishAIId, msg);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_Line_getFirstPosition") == 0) {
        int lineId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'lineId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            lineId = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Map_Line_getFirstPosition(skirmishAIId, lineId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_Line_getSecondPosition") == 0) {
        int lineId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'lineId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            lineId = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Map_Line_getSecondPosition(skirmishAIId, lineId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_Point_getLabel") == 0) {
        int pointId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'pointId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            pointId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Map_Point_getLabel(skirmishAIId, pointId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_Point_getPosition") == 0) {
        int pointId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'pointId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            pointId = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Map_Point_getPosition(skirmishAIId, pointId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_findClosestBuildSite") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %%i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float searchRadius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'searchRadius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            searchRadius = (float)tmp;
        }

        int minDist;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'minDist' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            minDist = (int)tmp;
        }

        int facing;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'facing' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            facing = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Map_findClosestBuildSite(skirmishAIId, unitDefId, pos_posF3, searchRadius, minDist, facing, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getChecksum") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Map_getChecksum(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getCurWind") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getCurWind(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getElevationAt") == 0) {
        float x;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'x' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            x = (float)tmp;
        }

        float z;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'z' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            z = (float)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getElevationAt(skirmishAIId, x, z);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getExtractorRadius") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getExtractorRadius(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getGravity") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getGravity(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getHash") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Map_getHash(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getHeight") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Map_getHeight(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getHumanName") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Map_getHumanName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getLines") == 0) {
        int includeAllies;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &includeAllies);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'includeAllies' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Map_getLines(skirmishAIId, includeAllies);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMaxHeight") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getMaxHeight(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMaxResource") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getMaxResource(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMaxWind") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getMaxWind(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMinHeight") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getMinHeight(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMinWind") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getMinWind(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getMousePos") == 0) {
        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Map_getMousePos(skirmishAIId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getName") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Map_getName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getPoints") == 0) {
        int includeAllies;
        {
            int result = ei_decode_boolean(buff.buff, &buff.index, &includeAllies);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'includeAllies' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Map_getPoints(skirmishAIId, includeAllies);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getResourceMapSpotsAverageIncome") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getResourceMapSpotsAverageIncome(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getResourceMapSpotsNearest") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %%i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Map_getResourceMapSpotsNearest(skirmishAIId, resourceId, pos_posF3, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getResourceMapSpotsPositions") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        float spots_AposF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %%i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    spots_AposF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        spots_AposF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode spots_AposF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        int spots_AposF3_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'spots_AposF3_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            spots_AposF3_sizeMax = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Map_getResourceMapSpotsPositions(skirmishAIId, resourceId, spots_AposF3, spots_AposF3_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getStartPos") == 0) {
        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Map_getStartPos(skirmishAIId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getTidalStrength") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getTidalStrength(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getWaterDamage") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Map_getWaterDamage(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_getWidth") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Map_getWidth(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_isPosInCamera") == 0) {
        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %%i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Map_isPosInCamera(skirmishAIId, pos_posF3, radius);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Map_isPossibleToBuildAt") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %%i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        int facing;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'facing' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            facing = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Map_isPossibleToBuildAt(skirmishAIId, unitDefId, pos_posF3, facing);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getAirLosMul") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Mod_getAirLosMul(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getAirMipLevel") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getAirMipLevel(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getAllowTeamColors") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Mod_getAllowTeamColors(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getCaptureEnergyCostFactor") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Mod_getCaptureEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getConstructionDecay") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Mod_getConstructionDecay(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getConstructionDecaySpeed") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Mod_getConstructionDecaySpeed(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getConstructionDecayTime") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getConstructionDecayTime(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getDescription") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Mod_getDescription(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getFileName") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Mod_getFileName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getFireAtCrashing") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getFireAtCrashing(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getFireAtKilled") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getFireAtKilled(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getFlankingBonusModeDefault") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getFlankingBonusModeDefault(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getHash") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getHash(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getHumanName") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Mod_getHumanName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getLosMipLevel") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getLosMipLevel(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getLosMul") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Mod_getLosMul(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getMultiReclaim") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getMultiReclaim(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getMutator") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Mod_getMutator(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimAllowAllies") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Mod_getReclaimAllowAllies(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimAllowEnemies") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Mod_getReclaimAllowEnemies(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimFeatureEnergyCostFactor") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Mod_getReclaimFeatureEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimMethod") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getReclaimMethod(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimUnitEfficiency") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Mod_getReclaimUnitEfficiency(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimUnitEnergyCostFactor") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Mod_getReclaimUnitEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getReclaimUnitMethod") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getReclaimUnitMethod(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getRepairEnergyCostFactor") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Mod_getRepairEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getRequireSonarUnderWater") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Mod_getRequireSonarUnderWater(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getResurrectEnergyCostFactor") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Mod_getResurrectEnergyCostFactor(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getShortName") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Mod_getShortName(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getTransportAir") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getTransportAir(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getTransportGround") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getTransportGround(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getTransportHover") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getTransportHover(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getTransportShip") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Mod_getTransportShip(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Mod_getVersion") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Mod_getVersion(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Resource_getName") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Resource_getName(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Resource_getOptimum") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Resource_getOptimum(skirmishAIId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getDescription") == 0) {
        int infoIndex;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'infoIndex' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            infoIndex = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->SkirmishAI_Info_getDescription(skirmishAIId, infoIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getKey") == 0) {
        int infoIndex;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'infoIndex' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            infoIndex = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->SkirmishAI_Info_getKey(skirmishAIId, infoIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getSize") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->SkirmishAI_Info_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getValue") == 0) {
        int infoIndex;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'infoIndex' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            infoIndex = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->SkirmishAI_Info_getValue(skirmishAIId, infoIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_Info_getValueByKey") == 0) {
        char* key;
        {
            int result = ei_decode_string(buff.buff, &buff.index, key);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'key' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->SkirmishAI_Info_getValueByKey(skirmishAIId, key);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_OptionValues_getKey") == 0) {
        int optionIndex;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'optionIndex' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            optionIndex = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->SkirmishAI_OptionValues_getKey(skirmishAIId, optionIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_OptionValues_getSize") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->SkirmishAI_OptionValues_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_OptionValues_getValue") == 0) {
        int optionIndex;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'optionIndex' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            optionIndex = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->SkirmishAI_OptionValues_getValue(skirmishAIId, optionIndex);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_OptionValues_getValueByKey") == 0) {
        char* key;
        {
            int result = ei_decode_string(buff.buff, &buff.index, key);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'key' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->SkirmishAI_OptionValues_getValueByKey(skirmishAIId, key);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAI_getTeamId") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->SkirmishAI_getTeamId(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAIs_getMax") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->SkirmishAIs_getMax(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "SkirmishAIs_getSize") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->SkirmishAIs_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_TeamRulesParam_getName") == 0) {
        int teamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamId = (int)tmp;
        }

        int teamRulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamRulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamRulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Team_TeamRulesParam_getName(skirmishAIId, teamId, teamRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_TeamRulesParam_getValueFloat") == 0) {
        int teamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamId = (int)tmp;
        }

        int teamRulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamRulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamRulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Team_TeamRulesParam_getValueFloat(skirmishAIId, teamId, teamRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_TeamRulesParam_getValueString") == 0) {
        int teamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamId = (int)tmp;
        }

        int teamRulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamRulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamRulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Team_TeamRulesParam_getValueString(skirmishAIId, teamId, teamRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_getTeamRulesParamById") == 0) {
        int teamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamId = (int)tmp;
        }

        int rulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'rulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            rulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Team_getTeamRulesParamById(skirmishAIId, teamId, rulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_getTeamRulesParamByName") == 0) {
        int teamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamId = (int)tmp;
        }

        char* rulesParamName;
        {
            int result = ei_decode_string(buff.buff, &buff.index, rulesParamName);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'rulesParamName' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Team_getTeamRulesParamByName(skirmishAIId, teamId, rulesParamName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_getTeamRulesParams") == 0) {
        int teamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamId = (int)tmp;
        }

        int paramIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'paramIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            paramIds_sizeMax = (int)tmp;
        }

        int paramIds[paramIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Team_getTeamRulesParams(skirmishAIId, teamId, paramIds, paramIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, paramIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Team_hasAIController") == 0) {
        int teamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Team_hasAIController(skirmishAIId, teamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Teams_getSize") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Teams_getSize(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_FlankingBonus_getDir") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->UnitDef_FlankingBonus_getDir(skirmishAIId, unitDefId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_FlankingBonus_getMax") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_FlankingBonus_getMax(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_FlankingBonus_getMin") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_FlankingBonus_getMin(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_FlankingBonus_getMobilityAdd") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_FlankingBonus_getMobilityAdd(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_FlankingBonus_getMode") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_FlankingBonus_getMode(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getCrushStrength") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_MoveData_getCrushStrength(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getDepth") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_MoveData_getDepth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getDepthMod") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        float height;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'height' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            height = (float)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_MoveData_getDepthMod(skirmishAIId, unitDefId, height);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getFollowGround") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_MoveData_getFollowGround(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxAcceleration") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_MoveData_getMaxAcceleration(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxBreaking") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_MoveData_getMaxBreaking(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxSlope") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_MoveData_getMaxSlope(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_MoveData_getMaxSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMaxTurnRate") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        short result = callback->UnitDef_MoveData_getMaxTurnRate(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getMoveType") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_MoveData_getMoveType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getName") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_MoveData_getName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getPathType") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_MoveData_getPathType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getSlopeMod") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_MoveData_getSlopeMod(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getSpeedModClass") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_MoveData_getSpeedModClass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getTerrainClass") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_MoveData_getTerrainClass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getXSize") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_MoveData_getXSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_getZSize") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_MoveData_getZSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_MoveData_isSubMarine") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_MoveData_isSubMarine(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getBadTargetCategory") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int weaponMountId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponMountId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponMountId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_WeaponMount_getBadTargetCategory(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getFuelUsage") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int weaponMountId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponMountId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponMountId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_WeaponMount_getFuelUsage(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getMainDir") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int weaponMountId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponMountId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponMountId = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->UnitDef_WeaponMount_getMainDir(skirmishAIId, unitDefId, weaponMountId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getMaxAngleDif") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int weaponMountId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponMountId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponMountId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_WeaponMount_getMaxAngleDif(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getName") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int weaponMountId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponMountId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponMountId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_WeaponMount_getName(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getOnlyTargetCategory") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int weaponMountId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponMountId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponMountId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_WeaponMount_getOnlyTargetCategory(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getSlavedTo") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int weaponMountId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponMountId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponMountId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_WeaponMount_getSlavedTo(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_WeaponMount_getWeaponDef") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int weaponMountId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponMountId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponMountId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_WeaponMount_getWeaponDef(skirmishAIId, unitDefId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_canManualFire") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_canManualFire(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getAiHint") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getAiHint(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getAirLosRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getAirLosRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getArmorType") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getArmorType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getArmoredMultiple") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getArmoredMultiple(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getAutoHeal") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getAutoHeal(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildAngle") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getBuildAngle(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildDistance") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getBuildDistance(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildOptions") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int unitDefIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefIds_sizeMax = (int)tmp;
        }

        int unitDefIds[unitDefIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getBuildOptions(skirmishAIId, unitDefId, unitDefIds, unitDefIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitDefIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getBuildSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildTime") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getBuildTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildingDecalDecaySpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getBuildingDecalDecaySpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildingDecalSizeX") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getBuildingDecalSizeX(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildingDecalSizeY") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getBuildingDecalSizeY(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getBuildingDecalType") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getBuildingDecalType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCaptureSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getCaptureSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCategory") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getCategory(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCategoryString") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_getCategoryString(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCloakCost") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getCloakCost(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCloakCostMoving") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getCloakCostMoving(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCobId") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getCobId(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getCost") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getCost(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDeathExplosion") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getDeathExplosion(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDecloakDistance") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getDecloakDistance(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDecoyDef") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getDecoyDef(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDlHoverFactor") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getDlHoverFactor(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getDrag") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getDrag(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getExtractsResource") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getExtractsResource(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFallSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getFallSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFileName") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_getFileName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFireState") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getFireState(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareDelay") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getFlareDelay(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareDropVector") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->UnitDef_getFlareDropVector(skirmishAIId, unitDefId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareEfficiency") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getFlareEfficiency(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareReloadTime") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getFlareReloadTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareSalvoDelay") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getFlareSalvoDelay(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareSalvoSize") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getFlareSalvoSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFlareTime") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getFlareTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getFrontToSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getFrontToSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getGaia") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_getGaia(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getHealth") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getHealth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getHeight") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getHeight(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getHighTrajectoryType") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getHighTrajectoryType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getHumanName") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_getHumanName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getIdleAutoHeal") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getIdleAutoHeal(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getIdleTime") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getIdleTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getJammerRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getJammerRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getKamikazeDist") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getKamikazeDist(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getLoadingRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getLoadingRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getLosHeight") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getLosHeight(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getLosRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getLosRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMakesResource") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMakesResource(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMass") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxAcceleration") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxAcceleration(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxAileron") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxAileron(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxBank") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxBank(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxDeceleration") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxDeceleration(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxElevator") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxElevator(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxFuel") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxFuel(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxHeightDif") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxHeightDif(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxPitch") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxPitch(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxRepairSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxRepairSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxRudder") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxRudder(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxSlope") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxSlope(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxThisUnit") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getMaxThisUnit(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxWaterDepth") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxWaterDepth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMaxWeaponRange") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMaxWeaponRange(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinAirBasePower") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMinAirBasePower(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinCollisionSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMinCollisionSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinTransportMass") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMinTransportMass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinTransportSize") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getMinTransportSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMinWaterDepth") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMinWaterDepth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMoveState") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getMoveState(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getMyGravity") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getMyGravity(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getName") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_getName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getNoChaseCategory") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getNoChaseCategory(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getPower") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getPower(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getRadarRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getRadarRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getReclaimSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getReclaimSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getRefuelTime") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getRefuelTime(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getRepairSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getRepairSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getResourceExtractorRange") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getResourceExtractorRange(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getResourceMake") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getResourceMake(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getResurrectSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getResurrectSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSeismicRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getSeismicRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSeismicSignature") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getSeismicSignature(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSelfDCountdown") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getSelfDCountdown(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSelfDExplosion") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getSelfDExplosion(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getShieldDef") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getShieldDef(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSlideTolerance") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getSlideTolerance(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSonarJamRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getSonarJamRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSonarRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getSonarRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getSpeedToFront") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getSpeedToFront(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getStockpileDef") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getStockpileDef(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getStorage") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getStorage(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTechLevel") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getTechLevel(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTerraformSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTerraformSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTidalResourceGenerator") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTidalResourceGenerator(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTooltip") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_getTooltip(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackOffset") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTrackOffset(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackStrength") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTrackStrength(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackStretch") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTrackStretch(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackType") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getTrackType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTrackWidth") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTrackWidth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTransportCapacity") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getTransportCapacity(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTransportMass") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTransportMass(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTransportSize") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getTransportSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTransportUnloadMethod") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getTransportUnloadMethod(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTurnInPlaceDistance") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTurnInPlaceDistance(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTurnInPlaceSpeedLimit") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTurnInPlaceSpeedLimit(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTurnRadius") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTurnRadius(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getTurnRate") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getTurnRate(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getType") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_getType(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getUnitFallSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getUnitFallSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getUnloadSpread") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getUnloadSpread(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getUpkeep") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getUpkeep(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getVerticalSpeed") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getVerticalSpeed(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWantedHeight") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getWantedHeight(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWaterline") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getWaterline(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWeaponMounts") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getWeaponMounts(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWindResourceGenerator") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getWindResourceGenerator(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWingAngle") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getWingAngle(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWingDrag") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->UnitDef_getWingDrag(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getWreckName") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->UnitDef_getWreckName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getXSize") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getXSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_getZSize") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->UnitDef_getZSize(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToAssist") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToAssist(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToAttack") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToAttack(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToCapture") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToCapture(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToCloak") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToCloak(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToCrash") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToCrash(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToDropFlare") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToDropFlare(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToFight") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToFight(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToFireControl") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToFireControl(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToFly") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToFly(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToGuard") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToGuard(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToHover") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToHover(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToKamikaze") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToKamikaze(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToLoopbackAttack") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToLoopbackAttack(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToMove") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToMove(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToPatrol") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToPatrol(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToReclaim") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToReclaim(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToRepair") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToRepair(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToRepeat") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToRepeat(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToRestore") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToRestore(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToResurrect") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToResurrect(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToSelfD") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToSelfD(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToSelfRepair") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToSelfRepair(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAbleToSubmerge") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAbleToSubmerge(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isActivateWhenBuilt") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isActivateWhenBuilt(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAirBase") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAirBase(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAirStrafe") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAirStrafe(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isAssistable") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isAssistable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isBuildRange3D") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isBuildRange3D(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isBuilder") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isBuilder(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isCapturable") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isCapturable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isCollide") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isCollide(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isCommander") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isCommander(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isDecloakOnFire") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isDecloakOnFire(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isDecloakSpherical") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isDecloakSpherical(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isDontLand") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isDontLand(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFactoryHeadingTakeoff") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isFactoryHeadingTakeoff(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFeature") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isFeature(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFirePlatform") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isFirePlatform(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFloater") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isFloater(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isFullHealthFactory") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isFullHealthFactory(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isHideDamage") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isHideDamage(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isHoldSteady") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isHoldSteady(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isHoverAttack") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isHoverAttack(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isLeaveTracks") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isLeaveTracks(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isLevelGround") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isLevelGround(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isMoveDataAvailable") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isMoveDataAvailable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isNeedGeo") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isNeedGeo(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isNotTransportable") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isNotTransportable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isOnOffable") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isOnOffable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isPushResistant") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isPushResistant(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isReclaimable") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isReclaimable(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isReleaseHeld") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isReleaseHeld(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isShowPlayerName") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isShowPlayerName(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isSonarStealth") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isSonarStealth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isSquareResourceExtractor") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isSquareResourceExtractor(skirmishAIId, unitDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isStartCloaked") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isStartCloaked(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isStealth") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isStealth(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isStrafeToAttack") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isStrafeToAttack(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isTargetingFacility") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isTargetingFacility(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isTransportByEnemy") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isTransportByEnemy(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isTurnInPlace") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isTurnInPlace(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isUpright") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isUpright(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "UnitDef_isUseBuildingGroundDecal") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->UnitDef_isUseBuildingGroundDecal(skirmishAIId, unitDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getId") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int commandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'commandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            commandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_CurrentCommand_getId(skirmishAIId, unitId, commandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getOptions") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int commandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'commandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            commandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        short result = callback->Unit_CurrentCommand_getOptions(skirmishAIId, unitId, commandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getTag") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int commandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'commandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            commandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_CurrentCommand_getTag(skirmishAIId, unitId, commandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getTimeOut") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int commandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'commandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            commandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_CurrentCommand_getTimeOut(skirmishAIId, unitId, commandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_CurrentCommand_getType") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_CurrentCommand_getType(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_getId") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_SupportedCommand_getId(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_getName") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Unit_SupportedCommand_getName(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_getToolTip") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Unit_SupportedCommand_getToolTip(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_isDisabled") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Unit_SupportedCommand_isDisabled(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_SupportedCommand_isShowUnique") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int supportedCommandId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'supportedCommandId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            supportedCommandId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Unit_SupportedCommand_isShowUnique(skirmishAIId, unitId, supportedCommandId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_UnitRulesParam_getName") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int unitRulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitRulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitRulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Unit_UnitRulesParam_getName(skirmishAIId, unitId, unitRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_UnitRulesParam_getValueFloat") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int unitRulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitRulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitRulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_UnitRulesParam_getValueFloat(skirmishAIId, unitId, unitRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_UnitRulesParam_getValueString") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int unitRulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitRulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitRulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->Unit_UnitRulesParam_getValueString(skirmishAIId, unitId, unitRulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_Weapon_getDef") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int weaponId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_Weapon_getDef(skirmishAIId, unitId, weaponId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_Weapon_getRange") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int weaponId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_Weapon_getRange(skirmishAIId, unitId, weaponId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_Weapon_getReloadFrame") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int weaponId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_Weapon_getReloadFrame(skirmishAIId, unitId, weaponId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_Weapon_getReloadTime") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int weaponId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_Weapon_getReloadTime(skirmishAIId, unitId, weaponId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getAiHint") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getAiHint(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getAllyTeam") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getAllyTeam(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getBuildingFacing") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getBuildingFacing(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getCurrentCommands") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getCurrentCommands(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getCurrentFuel") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getCurrentFuel(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getDef") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getDef(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getExperience") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getExperience(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getGroup") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getGroup(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getHealth") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getHealth(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getLastUserOrderFrame") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getLastUserOrderFrame(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getLimit") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getLimit(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getMax") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getMax(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getMaxHealth") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getMaxHealth(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getMaxRange") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getMaxRange(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getMaxSpeed") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getMaxSpeed(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getPos") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Unit_getPos(skirmishAIId, unitId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getPower") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getPower(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getResourceMake") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getResourceMake(skirmishAIId, unitId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getResourceUse") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getResourceUse(skirmishAIId, unitId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getSpeed") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->Unit_getSpeed(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getStockpile") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getStockpile(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getStockpileQueued") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getStockpileQueued(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getSupportedCommands") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getSupportedCommands(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getTeam") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getTeam(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getUnitRulesParamById") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int rulesParamId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'rulesParamId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            rulesParamId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getUnitRulesParamById(skirmishAIId, unitId, rulesParamId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getUnitRulesParamByName") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        char* rulesParamName;
        {
            int result = ei_decode_string(buff.buff, &buff.index, rulesParamName);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'rulesParamName' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getUnitRulesParamByName(skirmishAIId, unitId, rulesParamName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getUnitRulesParams") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int paramIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'paramIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            paramIds_sizeMax = (int)tmp;
        }

        int paramIds[paramIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getUnitRulesParams(skirmishAIId, unitId, paramIds, paramIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, paramIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getVel") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        float return_posF3_out[3];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        callback->Unit_getVel(skirmishAIId, unitId, return_posF3_out);
        int result = 3;
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_tuple_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_double(&sendbuff, return_posF3_out[i]);
        }
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getWeapon") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int weaponMountId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponMountId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponMountId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getWeapon(skirmishAIId, unitId, weaponMountId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_getWeapons") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->Unit_getWeapons(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isActivated") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Unit_isActivated(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isBeingBuilt") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Unit_isBeingBuilt(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isCloaked") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Unit_isCloaked(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isNeutral") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Unit_isNeutral(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "Unit_isParalyzed") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->Unit_isParalyzed(skirmishAIId, unitId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getCraterBoost") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Damage_getCraterBoost(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getCraterMult") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Damage_getCraterMult(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getImpulseBoost") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Damage_getImpulseBoost(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getImpulseFactor") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Damage_getImpulseFactor(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Damage_getParalyzeDamageTime") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_Damage_getParalyzeDamageTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getAlpha") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        short result = callback->WeaponDef_Shield_getAlpha(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getForce") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Shield_getForce(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getInterceptType") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_Shield_getInterceptType(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getMaxSpeed") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Shield_getMaxSpeed(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getPower") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Shield_getPower(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getPowerRegen") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Shield_getPowerRegen(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getPowerRegenResource") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Shield_getPowerRegenResource(skirmishAIId, weaponDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getRadius") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Shield_getRadius(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getRechargeDelay") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_Shield_getRechargeDelay(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getResourceUse") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Shield_getResourceUse(skirmishAIId, weaponDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_Shield_getStartingPower") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_Shield_getStartingPower(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getAccuracy") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getAccuracy(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getAreaOfEffect") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getAreaOfEffect(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getBeamTime") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getBeamTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getBounceRebound") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getBounceRebound(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getBounceSlip") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getBounceSlip(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCameraShake") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getCameraShake(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCegTag") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->WeaponDef_getCegTag(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCollisionFlags") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getCollisionFlags(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCollisionSize") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getCollisionSize(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCoreThickness") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getCoreThickness(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCost") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getCost(skirmishAIId, weaponDefId, resourceId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCoverageRange") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getCoverageRange(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getCylinderTargetting") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getCylinderTargetting(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDance") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getDance(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDescription") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->WeaponDef_getDescription(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDuration") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getDuration(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDynDamageExp") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getDynDamageExp(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDynDamageMin") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getDynDamageMin(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getDynDamageRange") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getDynDamageRange(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getEdgeEffectiveness") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getEdgeEffectiveness(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getExplosionSpeed") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getExplosionSpeed(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getFalloffRate") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getFalloffRate(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getFileName") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->WeaponDef_getFileName(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getFireStarter") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getFireStarter(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getFlightTime") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getFlightTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getGraphicsType") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getGraphicsType(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getHeightBoostFactor") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getHeightBoostFactor(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getHeightMod") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getHeightMod(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getHighTrajectory") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getHighTrajectory(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getIntensity") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getIntensity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getInterceptedByShieldType") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getInterceptedByShieldType(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getInterceptor") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getInterceptor(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getLaserFlareSize") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getLaserFlareSize(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getLeadBonus") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getLeadBonus(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getLeadLimit") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getLeadLimit(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getLodDistance") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getLodDistance(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMaxAngle") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getMaxAngle(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMaxVelocity") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getMaxVelocity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMinIntensity") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getMinIntensity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMovingAccuracy") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getMovingAccuracy(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getMyGravity") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getMyGravity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getName") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->WeaponDef_getName(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getNumBounce") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getNumBounce(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getNumDamageTypes") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getNumDamageTypes(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getOnlyTargetCategory") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getOnlyTargetCategory(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getPredictBoost") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getPredictBoost(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getProjectileSpeed") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getProjectileSpeed(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getProjectilesPerShot") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getProjectilesPerShot(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getProximityPriority") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getProximityPriority(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getRange") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getRange(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getReload") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getReload(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSalvoDelay") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getSalvoDelay(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSalvoSize") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getSalvoSize(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSize") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getSize(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSizeGrowth") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getSizeGrowth(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getSprayAngle") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getSprayAngle(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getStartVelocity") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getStartVelocity(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getStockpileTime") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getStockpileTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTargetBorder") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getTargetBorder(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTargetMoveError") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getTargetMoveError(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTargetable") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getTargetable(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getThickness") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getThickness(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTrajectoryHeight") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getTrajectoryHeight(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getTurnRate") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getTurnRate(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getType") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        const char* result = callback->WeaponDef_getType(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_string(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getUpTime") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getUpTime(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getVisibleShieldHitFrames") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->WeaponDef_getVisibleShieldHitFrames(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getWeaponAcceleration") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getWeaponAcceleration(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_getWobble") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        float result = callback->WeaponDef_getWobble(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_double(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isAbleToAttackGround") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isAbleToAttackGround(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isAvoidFeature") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isAvoidFeature(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isAvoidFriendly") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isAvoidFriendly(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isAvoidNeutral") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isAvoidNeutral(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isBeamBurst") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isBeamBurst(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isDropped") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isDropped(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isDynDamageInverted") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isDynDamageInverted(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isExteriorShield") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isExteriorShield(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isFireSubmersed") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isFireSubmersed(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isFixedLauncher") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isFixedLauncher(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isGravityAffected") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isGravityAffected(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isGroundBounce") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isGroundBounce(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isImpactOnly") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isImpactOnly(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isLargeBeamLaser") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isLargeBeamLaser(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isManualFire") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isManualFire(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isNoAutoTarget") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isNoAutoTarget(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isNoExplode") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isNoExplode(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isNoSelfDamage") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isNoSelfDamage(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isOnlyForward") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isOnlyForward(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isParalyzer") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isParalyzer(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSelfExplode") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isSelfExplode(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isShield") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isShield(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isShieldRepulser") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isShieldRepulser(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSmartShield") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isSmartShield(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSoundTrigger") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isSoundTrigger(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isStockpileable") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isStockpileable(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSubMissile") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isSubMissile(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isSweepFire") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isSweepFire(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isTracks") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isTracks(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isTurret") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isTurret(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isVisibleShield") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isVisibleShield(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isVisibleShieldRepulse") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isVisibleShieldRepulse(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isWaterBounce") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isWaterBounce(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "WeaponDef_isWaterWeapon") == 0) {
        int weaponDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            weaponDefId = (int)tmp;
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        bool result = callback->WeaponDef_isWaterWeapon(skirmishAIId, weaponDefId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_boolean(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getAllyTeams") == 0) {
        int teamIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamIds_sizeMax = (int)tmp;
        }

        int teamIds[teamIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getAllyTeams(skirmishAIId, teamIds, teamIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, teamIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getEnemyTeams") == 0) {
        int teamIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'teamIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            teamIds_sizeMax = (int)tmp;
        }

        int teamIds[teamIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getEnemyTeams(skirmishAIId, teamIds, teamIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, teamIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getEnemyUnits") == 0) {
        int unitIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitIds_sizeMax = (int)tmp;
        }

        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getEnemyUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
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
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %%i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        int unitIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitIds_sizeMax = (int)tmp;
        }

        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getEnemyUnitsIn(skirmishAIId, pos_posF3, radius, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getEnemyUnitsInRadarAndLos") == 0) {
        int unitIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitIds_sizeMax = (int)tmp;
        }

        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getEnemyUnitsInRadarAndLos(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getFeatureDefs") == 0) {
        int featureDefIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureDefIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureDefIds_sizeMax = (int)tmp;
        }

        int featureDefIds[featureDefIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getFeatureDefs(skirmishAIId, featureDefIds, featureDefIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, featureDefIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getFeatures") == 0) {
        int featureIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureIds_sizeMax = (int)tmp;
        }

        int featureIds[featureIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getFeatures(skirmishAIId, featureIds, featureIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
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
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %%i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        int featureIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'featureIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            featureIds_sizeMax = (int)tmp;
        }

        int featureIds[featureIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getFeaturesIn(skirmishAIId, pos_posF3, radius, featureIds, featureIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, featureIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getFriendlyUnits") == 0) {
        int unitIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitIds_sizeMax = (int)tmp;
        }

        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getFriendlyUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
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
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %%i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        int unitIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitIds_sizeMax = (int)tmp;
        }

        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getFriendlyUnitsIn(skirmishAIId, pos_posF3, radius, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getGroups") == 0) {
        int groupIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupIds_sizeMax = (int)tmp;
        }

        int groupIds[groupIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getGroups(skirmishAIId, groupIds, groupIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, groupIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getNeutralUnits") == 0) {
        int unitIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitIds_sizeMax = (int)tmp;
        }

        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getNeutralUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
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
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %%i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        int unitIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitIds_sizeMax = (int)tmp;
        }

        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getNeutralUnitsIn(skirmishAIId, pos_posF3, radius, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
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
        {
            int result = ei_decode_string(buff.buff, &buff.index, resourceName);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceName' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getResourceByName(skirmishAIId, resourceName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getResources") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getResources(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getSelectedUnits") == 0) {
        int unitIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitIds_sizeMax = (int)tmp;
        }

        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getSelectedUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_list_header(&sendbuff, result);
        int i = 0;
        for (; i < result; i++) {
            ei_x_encode_long(&sendbuff, unitIds[i]);
        }
        ei_x_encode_empty_list(&sendbuff);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getTeamUnits") == 0) {
        int unitIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitIds_sizeMax = (int)tmp;
        }

        int unitIds[unitIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getTeamUnits(skirmishAIId, unitIds, unitIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
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
        {
            int result = ei_decode_string(buff.buff, &buff.index, unitName);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitName' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getUnitDefByName(skirmishAIId, unitName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getUnitDefs") == 0) {
        int unitDefIds_sizeMax;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefIds_sizeMax' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefIds_sizeMax = (int)tmp;
        }

        int unitDefIds[unitDefIds_sizeMax];
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getUnitDefs(skirmishAIId, unitDefIds, unitDefIds_sizeMax);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
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
        {
            int result = ei_decode_string(buff.buff, &buff.index, weaponDefName);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'weaponDefName' as 'char*', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getWeaponDefByName(skirmishAIId, weaponDefName);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    if (strcmp(callback_what, "getWeaponDefs") == 0) {
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        int result = callback->getWeaponDefs(skirmishAIId);
        ei_x_buff sendbuff;
        ei_x_new_with_version(&sendbuff);
        ei_x_encode_tuple_header(&sendbuff, 2);
        ei_x_encode_atom(&sendbuff, "ok");
        ei_x_encode_long(&sendbuff, result);
        return send_to_pid(skirmishAIId, &from, sendbuff);
    }
    return -1;
}
