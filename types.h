/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef _KRAUS_TYPES_H_
#define _KRAUS_TYPES_H_


#include <time.h>
#include <stdlib.h>


typedef unsigned char kraus_t;

typedef int (*KRAUS_PTR)(struct tm *);


typedef struct {
    unsigned weekday: 1;
    unsigned reserved: 7;
} cal_flags_t;

typedef struct {
  time_t        start_date;
  unsigned int  count;
  cal_flags_t   flags;
} calendar_t;


#endif
