/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <stdio.h>

#include "config.h"
#include "../types.h"
#include "../module.h"

#include "csv.h"
#include "json.h"
#include "vcard.h"
#include "text.h"
#include "simple.h"
#include "neat.h"

#ifdef USE_OUTPUT_CALENDAR
#include "calendar.h"
#endif

#define SU 0
#define SA 6


void (*output)(calendar_t *, void *);

void register_output(module_registry_t * registry);
void usage_output(module_registry_t * registry);

#endif
