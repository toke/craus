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

#include "../types.h"
#include "../kraus.h"
#include "../module.h"

#define MAX_OUTPUT_MODULES 10

#define SU 0
#define SA 6


void (*output)(calendar_t *, void *);

void register_output(module_registry_t * registry);
void usage_output(module_registry_t * registry);

void csv_out(calendar_t *calendar, KRAUS_PTR  strategy);
void text_out(calendar_t *calendar, KRAUS_PTR  strategy);
void simple_out(calendar_t *calendar, KRAUS_PTR  strategy);
void json_out(calendar_t *calendar, KRAUS_PTR  strategy);
void vcard_out(calendar_t *calendar, KRAUS_PTR  strategy);



#endif
