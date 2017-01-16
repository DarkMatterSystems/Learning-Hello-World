
#include "~HelloWorld.0000.0000.Header.h"


/* Greeting State Actions */

void adm_state_action_greeting_display(
    adm_ent_greeting_typ * ent_greeting,
    adm_dst_greeting_hail_typ * dst_hail)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_greeting_display");
    #endif

    /* Template */

    adm_write_str(dst_hail->message);
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_greeting_display");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */