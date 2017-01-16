
#include "~HelloWorld.0000.0000.Header.h"


/* Domain - Initialisation */

void adm_initialisation_friend(
    void)
{
    /* Declare Objects */

    /* Greeting */
    adm_ent_greeting_typ * ent_greeting_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_friend");
    #endif

    /* Entity System */

    adm_entity_system.ent_greeting.tote = 0;

    adm_entity_system.ent_greeting.live_list_head = NULL;

    adm_entity_system.ent_greeting.live_list_tail = NULL;

    adm_entity_system.ent_greeting.dead_list_head = NULL;

    adm_entity_system.ent_greeting.dead_list_tail = NULL;

    adm_entity_system.ent_greeting.home_pool_head = NULL;

    adm_entity_system.ent_greeting.home_pool_tail = NULL;

    adm_entity_system.ent_greeting.away_pool_head = NULL;

    adm_entity_system.ent_greeting.away_pool_tail = NULL;


    /* Make Objects */

    /* Greeting */
    ent_greeting_0000000001 = adm_make_object_greeting(ADM_STATUS_GREETING_DISPLAY);


    /* Bind Objects */

    /* Greeting */
    adm_bind_object_greeting(
        ent_greeting_0000000001,
        1, 41, 29);


    /* Generate Events */

    /* Greeting */

    adm_send_event_greeting_wave(
        ent_greeting_0000000001,
        ent_greeting_0000000001,
        "Hello World!", 
        1, 44, 29);


    /* Integrity Check */
    adm_integrity_check();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_friend");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */