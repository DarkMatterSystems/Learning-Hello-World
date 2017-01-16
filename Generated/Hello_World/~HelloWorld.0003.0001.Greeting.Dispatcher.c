
#include "~HelloWorld.0000.0000.Header.h"


/* Greeting Dispatcher */

/* Dispatcher */

void adm_dispatcher_greeting(
    void)
{
    adm_pool_target_greeting_typ * pool_target_greeting;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_greeting");
    #endif

    pool_target_greeting = adm_find_away_target_event_greeting();

    adm_dispatch_state_action_greeting(pool_target_greeting);

    adm_dispatch_home_pool_greeting();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_greeting");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_greeting(
    void)
{
    adm_pool_target_greeting_typ * pool_target_greeting;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_greeting");
    #endif

    while (adm_entity_system.ent_greeting.home_pool_head != NULL) {

        pool_target_greeting = adm_find_home_target_event_greeting();

        adm_dispatch_state_action_greeting(pool_target_greeting);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_greeting");
    #endif
}


/* Find Home Target Event */

adm_pool_target_greeting_typ * adm_find_home_target_event_greeting(
    void)
{
    adm_pool_target_greeting_typ * pool_target_greeting;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_greeting");
    #endif

    pool_target_greeting = adm_entity_system.ent_greeting.home_pool_head;

    adm_entity_system.ent_greeting.home_pool_head = pool_target_greeting->next;

    if (adm_entity_system.ent_greeting.home_pool_head == NULL) {

        adm_entity_system.ent_greeting.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_greeting");
    #endif

    return (pool_target_greeting);
}


/* Find Away Target Event */

adm_pool_target_greeting_typ * adm_find_away_target_event_greeting(
    void)
{
    adm_pool_target_greeting_typ * pool_target_greeting;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_greeting");
    #endif

    pool_target_greeting = adm_entity_system.ent_greeting.away_pool_head;

    adm_entity_system.ent_greeting.away_pool_head = pool_target_greeting->next;

    if (adm_entity_system.ent_greeting.away_pool_head == NULL) {

        adm_entity_system.ent_greeting.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_greeting");
    #endif

    return (pool_target_greeting);
}


/* Dispatch State Action */

void adm_dispatch_state_action_greeting(
    adm_pool_target_greeting_typ * pool_target)
{
    adm_dst_greeting_hail_typ * dst_hail;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_greeting");
    #endif

    if (pool_target->ent_greeting != NULL) {

        adm_object_existent_greeting(
            pool_target->ent_greeting,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_GREETING_WAVE :

            switch ((pool_target->ent_greeting)->status) {

                case ADM_STATUS_GREETING_DISPLAY :

                    dst_hail = (adm_dst_greeting_hail_typ*)pool_target->dataset.hail;

                    adm_sim_display_state_greeting_display(pool_target);

                    (pool_target->ent_greeting)->status = ADM_STATUS_GREETING_DISPLAY;

                    adm_state_action_greeting_display(
                        pool_target->ent_greeting,
                        dst_hail);

                    adm_deallocate_memory(dst_hail->message);

                    adm_deallocate_memory(pool_target->dataset.hail);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_greeting");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */