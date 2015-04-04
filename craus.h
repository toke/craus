/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef _CRAUS_H_
#define _CRAUS_H_

#include <time.h>
#include <stdlib.h>

#define MIN_FLOOR 1
#define MAX_FLOOR 8
#define SEEDMAGIC 0x330e

typedef unsigned char kraus_t;

kraus_t kraus_floor(struct tm *date);

#endif
