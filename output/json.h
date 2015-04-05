/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef _JSON_MODULE_H_
#define _JSON_MODULE_H_

#include "output.h"

void json_out(calendar_t *calendar, KRAUS_PTR strategy);

#define JSON_HEAD "{\"kraus\": [\n"
#define JSON_BODY "\t{\"date\": \"%02i.%02i.%i\", \"level\": %i}"
#define JSON_FOOT "\n]}\n"
#define JSON_DELIMIT ",\n"
#define JSON_DATA kd->tm_mday, kd->tm_mon + 1, kd->tm_year + 1900, floor

#endif
