#include "output.h"

/*
*  Simple numeric output
*/
void simple_out(calendar_t *calendar) {
  int i;
  struct tm *kd;
  kraus_t floor;

  for (i = 0; i < calendar->count; i++) {
    kd = localtime(&calendar->start_date);
    kd->tm_mday += i;
    mktime(kd);
    floor = kraus_floor(kd);
    if (calendar->flags.weekday && (kd->tm_wday == SA || kd->tm_wday == SU)) {
      printf("\n");
    } else {
      (void)printf("%i\n", floor);
    }
  }
}
