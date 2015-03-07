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

#include "kraus.h"

#define VCARD_HEAD                                                             \
  "BEGIN:VCALENDAR\nVERSION:2.0\nMETHOD:PUBLISH\n\
PRODID:-//hack//toke//kraus v1.0//EN\n"
#define VCARD_BODY                                                             \
  "BEGIN:VEVENT\n\
UID:%i%02i%02iT120000-123000@toke.de\n\
URL:http://jautz.org/kraus/\n\
DTSTAMP;TZID=Europe/Berlin:%i%02i%02iT000000\n\
DTSTART;TZID=Europe/Berlin:%i%02i%02iT120000\n\
DTEND;TZID=Europe/Berlin:%i%02i%02iT123000\n\
RRULE:FREQ=YEARLY;INTERVAL=1\n\
EXRULE:FREQ=WEEKLY;BYDAY=SA,SU;INTERVAL=1\n\
SUMMARY:K.R.A.U.S.: %i. Stock\n\
CATEGORIES:KRAUS\n\
LOCATION:Karlsruhe, Ernst-Frey-Str. 9: %i. Stock\n\
TRANSP:TRANSPARENT\n\
END:VEVENT\n"
#define VCARD_FOOT "END:VCALENDAR\n"

#define VCARD_DATA(date, floor)                                                \
  date->tm_year + 1900, date->tm_mon + 1, date->tm_mday, date->tm_year + 1900, \
      date->tm_mon + 1, date->tm_mday, date->tm_year + 1900, date->tm_mon + 1, \
      date->tm_mday, date->tm_year + 1900, date->tm_mon + 1, date->tm_mday,    \
      floor, floor

void text_out(time_t *start_date, int count);
void json_out(time_t *start_date, int count);
void vcard_out(time_t *start_date, int count);

#endif
