/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "output.h"

/*
*  VCARD output
*/
void vcard_out(calendar_t *calendar) {
  int i;
  struct tm *kd;
  kraus_t floor;

  printf(VCARD_HEAD);
  for (i = 0; i < calendar->count; i++) {
    kd = localtime(&calendar->start_date);
    kd->tm_mday += i;
    mktime(kd);
    floor = kraus_floor(kd);
    if (!calendar->flags.weekday || (kd->tm_wday > 0 && kd->tm_wday < 6)) {
      printf(VCARD_BODY, VCARD_DATA(kd, floor));
    }
  }
  printf(VCARD_FOOT);
}
