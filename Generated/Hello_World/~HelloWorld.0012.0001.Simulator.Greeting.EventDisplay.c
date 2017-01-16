
#include "~HelloWorld.0000.0000.Header.h"


/* Simulator Greeting Display Event */

void adm_sim_display_event_greeting_wave(
    adm_ent_greeting_typ * ent_greeting,
    adm_str_text_typ * evd_message,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_greeting_wave");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Greeting[");
        printf("%d", ent_greeting->identity);
        printf("] Wave (");
        printf("Message:\"%s\"", evd_message);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_greeting_wave");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */