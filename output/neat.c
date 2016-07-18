/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "neat.h"

/*
*  Simple numeric output
*/
void neat_out(calendar_t *calendar, KRAUS_PTR strategy) {
  int i;
  struct tm *kd;
  kraus_t floor;

  for (i = 0; i < calendar->count; i++) {
    kd = localtime(&calendar->start_date);
    kd->tm_mday += i;
    mktime(kd);
    floor = strategy(kd);
    if (calendar->flags.weekday && (kd->tm_wday == SA || kd->tm_wday == SU)) {
      printf("\n");
    } else {
      (void)printf(" %i\n", floor);
    }
  }
}
