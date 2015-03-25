/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef _KRAUS_H_
#define _KRAUS_H_

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>

#include "output.h"

#define MIN_FLOOR 1
#define MAX_FLOOR 8
#define SEEDMAGIC 0x330e
#define DEFAULT_FORMAT &text_out

typedef unsigned char kraus_t;

kraus_t kraus_floor(struct tm *date);

#endif
