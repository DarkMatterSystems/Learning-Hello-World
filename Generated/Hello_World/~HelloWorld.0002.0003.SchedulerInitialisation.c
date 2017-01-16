
#include "~HelloWorld.0000.0000.Header.h"


/* Domain Scheduler Initialisation */

void adm_scheduler_initialisation_friend(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_friend");
    #endif

    adm_dispatch_home_pool_greeting();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_friend");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */