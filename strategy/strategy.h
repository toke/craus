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

#include "../types.h"
#include "../module.h"
#include "craus.h"
#include "null.h"

kraus_t (*strategy)(struct tm *);

void register_strategy(module_registry_t * registry);

#endif
