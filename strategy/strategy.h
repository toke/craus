/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */


#ifndef _STRATEGY_H_
#define _STRATEGY_H_

#include <time.h>
#include <stdlib.h>

#include "config.h"
#include "../types.h"
#include "../module.h"

#include "craus.h"
#ifdef USE_STRATEGY_NULL
#include "null.h"
#endif
#ifdef USE_STRATEGY_JAUTZ
#include "jautz.h"
#endif

kraus_t (*strategy)(struct tm *);

void register_strategy(module_registry_t * registry);

#endif
