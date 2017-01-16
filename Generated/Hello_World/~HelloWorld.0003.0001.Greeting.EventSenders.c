
#include "~HelloWorld.0000.0000.Header.h"


/* Greeting Event Senders */

void adm_send_event_greeting_wave(
    void * source_object,
    adm_ent_greeting_typ * ent_greeting,
    adm_str_text_typ * evd_message,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_greeting_typ * pool_target;
    adm_pool_target_greeting_typ * home_pool_target;

    adm_dst_greeting_hail_typ * dst_hail;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_greeting_wave");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_greeting_wave(
            ent_greeting,
            evd_message,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_greeting(
            ent_greeting,
            error_file,
            error_line,
            error_rank);

        if (strlen(evd_message) > ADM_TYPE_SIZE_TEXT) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Greeting",
                ent_greeting->identity,
                "message",
                evd_message);
        }

        dst_hail = (adm_dst_greeting_hail_typ*)
            adm_allocate_memory(sizeof(adm_dst_greeting_hail_typ));

        dst_hail->message = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

        strcpy_s(dst_hail->message, ADM_TYPE_SIZE_TEXT+1, evd_message);

        pool_target = (adm_pool_target_greeting_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_greeting_typ));

        pool_target->evente = ADM_EVENT_GREETING_WAVE;
        pool_target->ent_greeting = ent_greeting;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.hail = dst_hail;

        if (source_object == ent_greeting) {

            if (adm_entity_system.ent_greeting.home_pool_head == NULL) {

                adm_entity_system.ent_greeting.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_greeting.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_greeting == ent_greeting) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Greeting",
                            ent_greeting->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_greeting.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_greeting.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_greeting.away_pool_head == NULL) {

                adm_entity_system.ent_greeting.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_greeting.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_greeting.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_greeting_wave");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */