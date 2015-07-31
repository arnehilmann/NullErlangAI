
/* THIS FILE GETS GENERATED, DO NOT EDIT DIRECTLY! */

#include "ei.h"
#include "rts/ExternalAI/Interface/AISEvents.h"

int add_event_data(ei_x_buff* sendbuf, int topic, const void* data) {
    switch (topic) {
        case EVENT_COMMAND_FINISHED: {
            ei_x_encode_atom(sendbuf, "event_command_finished");
            struct SCommandFinishedEvent* event_data = (struct SCommandFinishedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 6);
            {
                if (ei_x_encode_atom(sendbuf, "unitid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unitid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unitId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unitId);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "commandid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "commandid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->commandId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->commandId);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "commandtopicid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "commandtopicid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->commandTopicId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->commandTopicId);
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_CREATED: {
            ei_x_encode_atom(sendbuf, "event_enemy_created");
            struct SEnemyCreatedEvent* event_data = (struct SEnemyCreatedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "enemy");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->enemy);
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_DAMAGED: {
            ei_x_encode_atom(sendbuf, "event_enemy_damaged");
            struct SEnemyDamagedEvent* event_data = (struct SEnemyDamagedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 12);
            {
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "enemy");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->enemy);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "attacker") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "attacker");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->attacker) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->attacker);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "damage") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "damage");
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->damage) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->damage);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "dir_posf3") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "dir_posf3");
                    return -1;
                }
                if (ei_x_encode_tuple_header(sendbuf, 3) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'tuple_header'\n", 3);
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->dir_posF3[0]) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->dir_posF3[0]);
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->dir_posF3[1]) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->dir_posF3[1]);
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->dir_posF3[2]) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->dir_posF3[2]);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "weapondefid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "weapondefid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->weaponDefId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->weaponDefId);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "paralyzer") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "paralyzer");
                    return -1;
                }
                if (ei_x_encode_atom(sendbuf, event_data->paralyzer ? "true" : "false") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", event_data->paralyzer ? "true" : "false");
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_DESTROYED: {
            ei_x_encode_atom(sendbuf, "event_enemy_destroyed");
            struct SEnemyDestroyedEvent* event_data = (struct SEnemyDestroyedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "enemy");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->enemy);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "attacker") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "attacker");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->attacker) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->attacker);
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_ENTER_LOS: {
            ei_x_encode_atom(sendbuf, "event_enemy_enter_los");
            struct SEnemyEnterLOSEvent* event_data = (struct SEnemyEnterLOSEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "enemy");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->enemy);
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_ENTER_RADAR: {
            ei_x_encode_atom(sendbuf, "event_enemy_enter_radar");
            struct SEnemyEnterRadarEvent* event_data = (struct SEnemyEnterRadarEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "enemy");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->enemy);
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_FINISHED: {
            ei_x_encode_atom(sendbuf, "event_enemy_finished");
            struct SEnemyFinishedEvent* event_data = (struct SEnemyFinishedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "enemy");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->enemy);
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_LEAVE_LOS: {
            ei_x_encode_atom(sendbuf, "event_enemy_leave_los");
            struct SEnemyLeaveLOSEvent* event_data = (struct SEnemyLeaveLOSEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "enemy");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->enemy);
                    return -1;
                }
            }
            break;
        }
        case EVENT_ENEMY_LEAVE_RADAR: {
            ei_x_encode_atom(sendbuf, "event_enemy_leave_radar");
            struct SEnemyLeaveRadarEvent* event_data = (struct SEnemyLeaveRadarEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "enemy") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "enemy");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->enemy) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->enemy);
                    return -1;
                }
            }
            break;
        }
        case EVENT_LOAD: {
            ei_x_encode_atom(sendbuf, "event_load");
            struct SLoadEvent* event_data = (struct SLoadEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "file") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "file");
                    return -1;
                }
                if (ei_x_encode_string(sendbuf, event_data->file) < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'string'\n", event_data->file);
                    return -1;
                }
            }
            break;
        }
        case EVENT_LUA_MESSAGE: {
            ei_x_encode_atom(sendbuf, "event_lua_message");
            struct SLuaMessageEvent* event_data = (struct SLuaMessageEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "indata") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "indata");
                    return -1;
                }
                if (ei_x_encode_string(sendbuf, event_data->inData) < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'string'\n", event_data->inData);
                    return -1;
                }
            }
            break;
        }
        case EVENT_MESSAGE: {
            ei_x_encode_atom(sendbuf, "event_message");
            struct SMessageEvent* event_data = (struct SMessageEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                if (ei_x_encode_atom(sendbuf, "player") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "player");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->player) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->player);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "message") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "message");
                    return -1;
                }
                if (ei_x_encode_string(sendbuf, event_data->message) < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'string'\n", event_data->message);
                    return -1;
                }
            }
            break;
        }
        case EVENT_RELEASE: {
            ei_x_encode_atom(sendbuf, "event_release");
            struct SReleaseEvent* event_data = (struct SReleaseEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "reason") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "reason");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->reason) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->reason);
                    return -1;
                }
            }
            break;
        }
        case EVENT_SAVE: {
            ei_x_encode_atom(sendbuf, "event_save");
            struct SSaveEvent* event_data = (struct SSaveEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "file") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "file");
                    return -1;
                }
                if (ei_x_encode_string(sendbuf, event_data->file) < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'string'\n", event_data->file);
                    return -1;
                }
            }
            break;
        }
        case EVENT_SEISMIC_PING: {
            ei_x_encode_atom(sendbuf, "event_seismic_ping");
            struct SSeismicPingEvent* event_data = (struct SSeismicPingEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                if (ei_x_encode_atom(sendbuf, "pos_posf3") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "pos_posf3");
                    return -1;
                }
                if (ei_x_encode_tuple_header(sendbuf, 3) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'tuple_header'\n", 3);
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->pos_posF3[0]) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->pos_posF3[0]);
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->pos_posF3[1]) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->pos_posF3[1]);
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->pos_posF3[2]) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->pos_posF3[2]);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "strength") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "strength");
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->strength) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->strength);
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_CAPTURED: {
            ei_x_encode_atom(sendbuf, "event_unit_captured");
            struct SUnitCapturedEvent* event_data = (struct SUnitCapturedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 6);
            {
                if (ei_x_encode_atom(sendbuf, "unitid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unitid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unitId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unitId);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "oldteamid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "oldteamid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->oldTeamId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->oldTeamId);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "newteamid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "newteamid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->newTeamId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->newTeamId);
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_CREATED: {
            ei_x_encode_atom(sendbuf, "event_unit_created");
            struct SUnitCreatedEvent* event_data = (struct SUnitCreatedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unit");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unit);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "builder") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "builder");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->builder) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->builder);
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_DAMAGED: {
            ei_x_encode_atom(sendbuf, "event_unit_damaged");
            struct SUnitDamagedEvent* event_data = (struct SUnitDamagedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 12);
            {
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unit");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unit);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "attacker") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "attacker");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->attacker) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->attacker);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "damage") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "damage");
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->damage) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->damage);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "dir_posf3") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "dir_posf3");
                    return -1;
                }
                if (ei_x_encode_tuple_header(sendbuf, 3) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'tuple_header'\n", 3);
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->dir_posF3[0]) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->dir_posF3[0]);
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->dir_posF3[1]) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->dir_posF3[1]);
                    return -1;
                }
                if (ei_x_encode_double(sendbuf, event_data->dir_posF3[2]) < 0) {
                    fprintf(stderr, "cannot encode '%f' as 'double'\n", event_data->dir_posF3[2]);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "weapondefid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "weapondefid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->weaponDefId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->weaponDefId);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "paralyzer") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "paralyzer");
                    return -1;
                }
                if (ei_x_encode_atom(sendbuf, event_data->paralyzer ? "true" : "false") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", event_data->paralyzer ? "true" : "false");
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_DESTROYED: {
            ei_x_encode_atom(sendbuf, "event_unit_destroyed");
            struct SUnitDestroyedEvent* event_data = (struct SUnitDestroyedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unit");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unit);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "attacker") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "attacker");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->attacker) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->attacker);
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_FINISHED: {
            ei_x_encode_atom(sendbuf, "event_unit_finished");
            struct SUnitFinishedEvent* event_data = (struct SUnitFinishedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unit");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unit);
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_GIVEN: {
            ei_x_encode_atom(sendbuf, "event_unit_given");
            struct SUnitGivenEvent* event_data = (struct SUnitGivenEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 6);
            {
                if (ei_x_encode_atom(sendbuf, "unitid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unitid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unitId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unitId);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "oldteamid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "oldteamid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->oldTeamId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->oldTeamId);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "newteamid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "newteamid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->newTeamId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->newTeamId);
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_IDLE: {
            ei_x_encode_atom(sendbuf, "event_unit_idle");
            struct SUnitIdleEvent* event_data = (struct SUnitIdleEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unit");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unit);
                    return -1;
                }
            }
            break;
        }
        case EVENT_UNIT_MOVE_FAILED: {
            ei_x_encode_atom(sendbuf, "event_unit_move_failed");
            struct SUnitMoveFailedEvent* event_data = (struct SUnitMoveFailedEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "unit") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unit");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unit) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unit);
                    return -1;
                }
            }
            break;
        }
        case EVENT_UPDATE: {
            ei_x_encode_atom(sendbuf, "event_update");
            struct SUpdateEvent* event_data = (struct SUpdateEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 2);
            {
                if (ei_x_encode_atom(sendbuf, "frame") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "frame");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->frame) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->frame);
                    return -1;
                }
            }
            break;
        }
        case EVENT_WEAPON_FIRED: {
            ei_x_encode_atom(sendbuf, "event_weapon_fired");
            struct SWeaponFiredEvent* event_data = (struct SWeaponFiredEvent*)data;
            ei_x_encode_tuple_header(sendbuf, 4);
            {
                if (ei_x_encode_atom(sendbuf, "unitid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "unitid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->unitId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->unitId);
                    return -1;
                }
            }
            {
                if (ei_x_encode_atom(sendbuf, "weapondefid") < 0) {
                    fprintf(stderr, "cannot encode '%s' as 'atom'\n", "weapondefid");
                    return -1;
                }
                if (ei_x_encode_long(sendbuf, event_data->weaponDefId) < 0) {
                    fprintf(stderr, "cannot encode '%i' as 'long'\n", event_data->weaponDefId);
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
