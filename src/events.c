
#include "ei.h"
#include "rts/ExternalAI/Interface/AISEvents.h"

int add_event_data(ei_x_buff* sendbuf, int topic, const void* data) {
    switch (topic) {
        case EVENT_COMMAND_FINISHED: {
            fprintf(stderr, "encoding EVENT_COMMAND_FINISHED\n");
            ei_x_encode_atom(sendbuf, "event_command_finished");
            struct SCommandFinishedEvent* event_data = (struct SCommandFinishedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 6);
            {
                fprintf(stderr, "    encoding %s\n", "unitid");
                if (ei_x_encode_atom(sendbuf, "unitid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->unitId);
                if (ei_x_encode_long(sendbuf, event_data->unitId) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "commandid");
                if (ei_x_encode_atom(sendbuf, "commandid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->commandId);
                if (ei_x_encode_long(sendbuf, event_data->commandId) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "commandtopicid");
                if (ei_x_encode_atom(sendbuf, "commandtopicid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->commandTopicId);
                if (ei_x_encode_long(sendbuf, event_data->commandTopicId) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_CREATED: {
            fprintf(stderr, "encoding EVENT_ENEMY_CREATED\n");
            ei_x_encode_atom(sendbuf, "event_enemy_created");
            struct SEnemyCreatedEvent* event_data = (struct SEnemyCreatedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "enemy");
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->enemy);
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_DESTROYED: {
            fprintf(stderr, "encoding EVENT_ENEMY_DESTROYED\n");
            ei_x_encode_atom(sendbuf, "event_enemy_destroyed");
            struct SEnemyDestroyedEvent* event_data = (struct SEnemyDestroyedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                fprintf(stderr, "    encoding %s\n", "enemy");
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->enemy);
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "attacker");
                if (ei_x_encode_atom(sendbuf, "attacker") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->attacker);
                if (ei_x_encode_long(sendbuf, event_data->attacker) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_ENTER_LOS: {
            fprintf(stderr, "encoding EVENT_ENEMY_ENTER_LOS\n");
            ei_x_encode_atom(sendbuf, "event_enemy_enter_los");
            struct SEnemyEnterLOSEvent* event_data = (struct SEnemyEnterLOSEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "enemy");
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->enemy);
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_ENTER_RADAR: {
            fprintf(stderr, "encoding EVENT_ENEMY_ENTER_RADAR\n");
            ei_x_encode_atom(sendbuf, "event_enemy_enter_radar");
            struct SEnemyEnterRadarEvent* event_data = (struct SEnemyEnterRadarEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "enemy");
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->enemy);
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_FINISHED: {
            fprintf(stderr, "encoding EVENT_ENEMY_FINISHED\n");
            ei_x_encode_atom(sendbuf, "event_enemy_finished");
            struct SEnemyFinishedEvent* event_data = (struct SEnemyFinishedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "enemy");
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->enemy);
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_LEAVE_LOS: {
            fprintf(stderr, "encoding EVENT_ENEMY_LEAVE_LOS\n");
            ei_x_encode_atom(sendbuf, "event_enemy_leave_los");
            struct SEnemyLeaveLOSEvent* event_data = (struct SEnemyLeaveLOSEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "enemy");
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->enemy);
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_LEAVE_RADAR: {
            fprintf(stderr, "encoding EVENT_ENEMY_LEAVE_RADAR\n");
            ei_x_encode_atom(sendbuf, "event_enemy_leave_radar");
            struct SEnemyLeaveRadarEvent* event_data = (struct SEnemyLeaveRadarEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "enemy");
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->enemy);
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_LOAD: {
            fprintf(stderr, "encoding EVENT_LOAD\n");
            ei_x_encode_atom(sendbuf, "event_load");
            struct SLoadEvent* event_data = (struct SLoadEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "file");
                if (ei_x_encode_atom(sendbuf, "file") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %s\n", event_data->file);
                if (ei_x_encode_string(sendbuf, event_data->file) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_LUA_MESSAGE: {
            fprintf(stderr, "encoding EVENT_LUA_MESSAGE\n");
            ei_x_encode_atom(sendbuf, "event_lua_message");
            struct SLuaMessageEvent* event_data = (struct SLuaMessageEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "indata");
                if (ei_x_encode_atom(sendbuf, "indata") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %s\n", event_data->inData);
                if (ei_x_encode_string(sendbuf, event_data->inData) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_MESSAGE: {
            fprintf(stderr, "encoding EVENT_MESSAGE\n");
            ei_x_encode_atom(sendbuf, "event_message");
            struct SMessageEvent* event_data = (struct SMessageEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                fprintf(stderr, "    encoding %s\n", "player");
                if (ei_x_encode_atom(sendbuf, "player") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->player);
                if (ei_x_encode_long(sendbuf, event_data->player) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "message");
                if (ei_x_encode_atom(sendbuf, "message") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %s\n", event_data->message);
                if (ei_x_encode_string(sendbuf, event_data->message) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_RELEASE: {
            fprintf(stderr, "encoding EVENT_RELEASE\n");
            ei_x_encode_atom(sendbuf, "event_release");
            struct SReleaseEvent* event_data = (struct SReleaseEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "reason");
                if (ei_x_encode_atom(sendbuf, "reason") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->reason);
                if (ei_x_encode_long(sendbuf, event_data->reason) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_SAVE: {
            fprintf(stderr, "encoding EVENT_SAVE\n");
            ei_x_encode_atom(sendbuf, "event_save");
            struct SSaveEvent* event_data = (struct SSaveEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "file");
                if (ei_x_encode_atom(sendbuf, "file") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %s\n", event_data->file);
                if (ei_x_encode_string(sendbuf, event_data->file) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_CAPTURED: {
            fprintf(stderr, "encoding EVENT_UNIT_CAPTURED\n");
            ei_x_encode_atom(sendbuf, "event_unit_captured");
            struct SUnitCapturedEvent* event_data = (struct SUnitCapturedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 6);
            {
                fprintf(stderr, "    encoding %s\n", "unitid");
                if (ei_x_encode_atom(sendbuf, "unitid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->unitId);
                if (ei_x_encode_long(sendbuf, event_data->unitId) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "oldteamid");
                if (ei_x_encode_atom(sendbuf, "oldteamid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->oldTeamId);
                if (ei_x_encode_long(sendbuf, event_data->oldTeamId) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "newteamid");
                if (ei_x_encode_atom(sendbuf, "newteamid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->newTeamId);
                if (ei_x_encode_long(sendbuf, event_data->newTeamId) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_CREATED: {
            fprintf(stderr, "encoding EVENT_UNIT_CREATED\n");
            ei_x_encode_atom(sendbuf, "event_unit_created");
            struct SUnitCreatedEvent* event_data = (struct SUnitCreatedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                fprintf(stderr, "    encoding %s\n", "unit");
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->unit);
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "builder");
                if (ei_x_encode_atom(sendbuf, "builder") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->builder);
                if (ei_x_encode_long(sendbuf, event_data->builder) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_DESTROYED: {
            fprintf(stderr, "encoding EVENT_UNIT_DESTROYED\n");
            ei_x_encode_atom(sendbuf, "event_unit_destroyed");
            struct SUnitDestroyedEvent* event_data = (struct SUnitDestroyedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                fprintf(stderr, "    encoding %s\n", "unit");
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->unit);
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "attacker");
                if (ei_x_encode_atom(sendbuf, "attacker") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->attacker);
                if (ei_x_encode_long(sendbuf, event_data->attacker) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_FINISHED: {
            fprintf(stderr, "encoding EVENT_UNIT_FINISHED\n");
            ei_x_encode_atom(sendbuf, "event_unit_finished");
            struct SUnitFinishedEvent* event_data = (struct SUnitFinishedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "unit");
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->unit);
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_GIVEN: {
            fprintf(stderr, "encoding EVENT_UNIT_GIVEN\n");
            ei_x_encode_atom(sendbuf, "event_unit_given");
            struct SUnitGivenEvent* event_data = (struct SUnitGivenEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 6);
            {
                fprintf(stderr, "    encoding %s\n", "unitid");
                if (ei_x_encode_atom(sendbuf, "unitid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->unitId);
                if (ei_x_encode_long(sendbuf, event_data->unitId) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "oldteamid");
                if (ei_x_encode_atom(sendbuf, "oldteamid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->oldTeamId);
                if (ei_x_encode_long(sendbuf, event_data->oldTeamId) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "newteamid");
                if (ei_x_encode_atom(sendbuf, "newteamid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->newTeamId);
                if (ei_x_encode_long(sendbuf, event_data->newTeamId) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_IDLE: {
            fprintf(stderr, "encoding EVENT_UNIT_IDLE\n");
            ei_x_encode_atom(sendbuf, "event_unit_idle");
            struct SUnitIdleEvent* event_data = (struct SUnitIdleEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "unit");
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->unit);
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_MOVE_FAILED: {
            fprintf(stderr, "encoding EVENT_UNIT_MOVE_FAILED\n");
            ei_x_encode_atom(sendbuf, "event_unit_move_failed");
            struct SUnitMoveFailedEvent* event_data = (struct SUnitMoveFailedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "unit");
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->unit);
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_UPDATE: {
            fprintf(stderr, "encoding EVENT_UPDATE\n");
            ei_x_encode_atom(sendbuf, "event_update");
            struct SUpdateEvent* event_data = (struct SUpdateEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                fprintf(stderr, "    encoding %s\n", "frame");
                if (ei_x_encode_atom(sendbuf, "frame") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->frame);
                if (ei_x_encode_long(sendbuf, event_data->frame) < 0) {
                    return -1;
                }
            }
            break;
        }
        case EVENT_WEAPON_FIRED: {
            fprintf(stderr, "encoding EVENT_WEAPON_FIRED\n");
            ei_x_encode_atom(sendbuf, "event_weapon_fired");
            struct SWeaponFiredEvent* event_data = (struct SWeaponFiredEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                fprintf(stderr, "    encoding %s\n", "unitid");
                if (ei_x_encode_atom(sendbuf, "unitid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->unitId);
                if (ei_x_encode_long(sendbuf, event_data->unitId) < 0) {
                    return -1;
                }
            }
            {
                fprintf(stderr, "    encoding %s\n", "weapondefid");
                if (ei_x_encode_atom(sendbuf, "weapondefid") < 0) {
                    return -1;
                }
                fprintf(stderr, "    encoding %i\n", event_data->weaponDefId);
                if (ei_x_encode_long(sendbuf, event_data->weaponDefId) < 0) {
                    return -1;
                }
            }
            break;
        }
        default: {
            ei_x_encode_long(sendbuf, topic);
            ei_x_encode_binary(sendbuf, data, sizeof(data));
        }
    }
    return 0;
}
