/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */


#ifndef _JAUTZSTRATEGY_H_
#define _JAUTZSTRATEGY_H_

#include "strategy.h"
#include <stdlib.h>
#include <curl/curl.h>
#define DEFAULT_URL "http://www.jautz.org/kraus/index.cgi?format=raw"

kraus_t jautz_floor(struct tm *date);

#endif
