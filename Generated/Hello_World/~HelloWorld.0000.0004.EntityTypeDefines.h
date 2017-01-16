
/* Entity Type Defines Header */

/* Entity Status Type Defines */

typedef enum {
    ADM_STATUS_GREETING_DISPLAY
} adm_sta_greeting_typ;


/* Entity Event Type Defines */

typedef enum {
    ADM_EVENT_GREETING_WAVE
} adm_evt_greeting_typ;


/* Entity Type Defines */

/* Greeting */

typedef struct adm_ent_greeting {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_greeting_typ status;
    struct adm_ent_greeting * back;
    struct adm_ent_greeting * next;
} adm_ent_greeting_typ;


/* Entity Dataset Type Defines */

typedef struct {
    adm_str_text_typ * message;
} adm_dst_greeting_hail_typ;


/* Error Location Type Define */

typedef struct {
    adm_base_integer_typ file;
    adm_base_integer_typ line;
    adm_base_integer_typ rank;
} adm_error_location_typ;


/* Entity Event Pool Target Type Defines */

typedef struct adm_pool_target_greeting {
    adm_evt_greeting_typ evente;
    adm_ent_greeting_typ * ent_greeting;
    adm_error_location_typ error_location;
    struct adm_pool_target_greeting * next;
    union {
        adm_dst_greeting_hail_typ * hail;
    } dataset;
} adm_pool_target_greeting_typ;


/* Entity System - Entity Type Defines */

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_greeting_typ * live_list_head;
    adm_ent_greeting_typ * live_list_tail;
    adm_ent_greeting_typ * dead_list_head;
    adm_ent_greeting_typ * dead_list_tail;
    adm_pool_target_greeting_typ * home_pool_head;
    adm_pool_target_greeting_typ * home_pool_tail;
    adm_pool_target_greeting_typ * away_pool_head;
    adm_pool_target_greeting_typ * away_pool_tail;
} adm_entity_system_greeting_typ;


/* Entity System - System Type Define */

typedef struct {
    adm_entity_system_greeting_typ ent_greeting;
} adm_entity_system_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */