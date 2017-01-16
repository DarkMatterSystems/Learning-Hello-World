
#include "~HelloWorld.0000.0000.Header.h"


/* Greeting Simulator Display Entity */

void adm_sim_display_entity_greeting(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_greeting_typ * ent_greeting;

    adm_sim_width_greeting_typ width_greeting;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_greeting");
    #endif

    width_greeting.identity = strlen("Identity");
    width_greeting.status = strlen("Status");

    ent_greeting = adm_entity_system.ent_greeting.live_list_head;

    while (ent_greeting != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_greeting->identity);
        if (width > width_greeting.identity) width_greeting.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_greeting[ent_greeting->status]);
        if (width > width_greeting.status) width_greeting.status = width;

        ent_greeting = ent_greeting->next;
    }

    printf(NEWLINE);
    printf("Greeting:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_greeting.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_greeting.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_greeting.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_greeting.status);

    ent_greeting = adm_entity_system.ent_greeting.live_list_head;

    while (ent_greeting != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_greeting.identity, ent_greeting->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_greeting->status) {
            case ADM_STATUS_GREETING_DISPLAY :
                printf("%-*s", width_greeting.status, "Display");
            break;
            default :
                printf("%-*s", width_greeting.status, "ERROR");
            break;
        }


        ent_greeting = ent_greeting->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_greeting");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */