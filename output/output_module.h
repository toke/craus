/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef _OUTPUTMODULE_H_
#define _OUTPUTMODULE_H_

#include <stdio.h>
#include "config.h"
#include "../types.h"

#define SU 0
#define SA 6


void (*output)(calendar_t *, void *);


#endif
