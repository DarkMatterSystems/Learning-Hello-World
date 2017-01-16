
#include "~HelloWorld.0000.0000.Header.h"


/* Simulator Greeting Display State */

void adm_sim_display_state_greeting_display(
    adm_pool_target_greeting_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_greeting_display");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:26:46) - Greeting[");
        printf("%d", (pool_target->ent_greeting)->identity);
        printf("] ");
        printf("Display");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_FRIEND_GREETING, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_greeting[(pool_target->ent_greeting)->status]);
        printf("} (");
        printf("Message:");
        printf("\"%s\"", (pool_target->dataset.hail)->message);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_greeting_display");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */