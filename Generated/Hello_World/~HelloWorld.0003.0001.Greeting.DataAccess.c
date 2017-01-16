
#include "~HelloWorld.0000.0000.Header.h"


/* Greeting Data Access */

/* Make Entity Object */

adm_ent_greeting_typ * adm_make_object_greeting(
    adm_sta_greeting_typ status)
{
    adm_ent_greeting_typ * ent_greeting;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_greeting");
    #endif

    if (adm_entity_system.ent_greeting.dead_list_head != NULL) {

        ent_greeting = adm_entity_system.ent_greeting.dead_list_head;

        if (adm_entity_system.ent_greeting.dead_list_head == ent_greeting) {

            adm_entity_system.ent_greeting.dead_list_head = ent_greeting->next;

        } else {

            (ent_greeting->back)->next = ent_greeting->next;
        }

        if (adm_entity_system.ent_greeting.dead_list_tail == ent_greeting) {

            adm_entity_system.ent_greeting.dead_list_tail = ent_greeting->back;

        } else {

            (ent_greeting->next)->back = ent_greeting->back;
        }

    } else {

        ent_greeting = (adm_ent_greeting_typ*)adm_allocate_memory(sizeof(adm_ent_greeting_typ));
    }

    ent_greeting->identity = ++adm_entity_system.ent_greeting.tote;

    ent_greeting->unique  = FALSE;
    ent_greeting->deleted = FALSE;
    ent_greeting->marked  = FALSE;
    ent_greeting->status  = status;

    ent_greeting->back = NULL;
    ent_greeting->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_greeting");
    #endif

    return (ent_greeting);
}


/* Bind Entity Object */

void adm_bind_object_greeting(
    adm_ent_greeting_typ * ent_greeting,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_greeting");
    #endif

    adm_object_existent_greeting(
        ent_greeting,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_greeting.live_list_head == NULL) {

        ent_greeting->back = NULL;

        adm_entity_system.ent_greeting.live_list_head = ent_greeting;

    } else {

        ent_greeting->back = adm_entity_system.ent_greeting.live_list_tail;

        (adm_entity_system.ent_greeting.live_list_tail)->next = ent_greeting;
    }

    ent_greeting->next = NULL;

    adm_entity_system.ent_greeting.live_list_tail = ent_greeting;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_greeting");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_greeting(
    void * source_object,
    adm_ent_greeting_typ * ent_greeting,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_greeting");
    #endif

    adm_object_existent_greeting(
        ent_greeting,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_greeting) {

        if (adm_entity_system.ent_greeting.live_list_head == ent_greeting) {

            adm_entity_system.ent_greeting.live_list_head = ent_greeting->next;

        } else {

            (ent_greeting->back)->next = ent_greeting->next;
        }

        if (adm_entity_system.ent_greeting.live_list_tail == ent_greeting) {

            adm_entity_system.ent_greeting.live_list_tail = ent_greeting->back;

        } else {

            (ent_greeting->next)->back = ent_greeting->back;
        }

        ent_greeting->deleted = TRUE;

        if (adm_entity_system.ent_greeting.dead_list_head == NULL) {

            ent_greeting->back = NULL;

            adm_entity_system.ent_greeting.dead_list_head = ent_greeting;

        } else {

            ent_greeting->back = adm_entity_system.ent_greeting.dead_list_tail;

            (adm_entity_system.ent_greeting.dead_list_tail)->next = ent_greeting;
        }

        ent_greeting->next = NULL;

        adm_entity_system.ent_greeting.dead_list_tail = ent_greeting;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Greeting",
            ent_greeting->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_greeting");
    #endif
}


/* Object Existent */

void adm_object_existent_greeting(
    adm_ent_greeting_typ * ent_greeting,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_greeting");
    #endif

    if (ent_greeting->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Greeting",
            ent_greeting->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_greeting");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */