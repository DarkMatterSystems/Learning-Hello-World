
#include "~HelloWorld.0000.0000.Header.h"


/* Simulator Greeting Acquire Identity Event */

void adm_sim_acquire_identity_event_greeting_wave(
    void)
{
    adm_ent_greeting_typ * ent_greeting;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ evd_nme_message [ADM_TYPE_SIZE_TEXT+1];

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_greeting_wave");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

    adm_sim_str_fetch(
        evd_nme_message,
        ADM_TYPE_SIZE_TEXT+1);

    /* Check Event Data Type Ranges */

    /* Generate Event */

    entity_not_found = TRUE;

    ent_greeting = adm_entity_system.ent_greeting.live_list_head;

    while (
        entity_not_found &&
        ent_greeting != NULL) {

        if (ent_greeting->identity == identity) {

            adm_send_event_greeting_wave(
                NULL,
                ent_greeting,
                evd_nme_message,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_greeting = ent_greeting->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_greeting_wave");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */