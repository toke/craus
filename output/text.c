#include "output.h"

/*
*  Plain text output
*/
void text_out(calendar_t *calendar) {
  int i;
  struct tm *kd;
  kraus_t floor;

  for (i = 0; i < calendar->count; i++) {
    kd = localtime(&calendar->start_date);
    kd->tm_mday += i;
    mktime(kd);
    floor = kraus_floor(kd);
    if (calendar->flags.weekday && (kd->tm_wday == SA || kd->tm_wday == SU)) {
      printf("Wochenende\n");
    } else {
      (void)printf("Am %02i.%02i treffen wir uns in Stockwerk %i\n", kd->tm_mday,
                 kd->tm_mon + 1, floor);
    }
  }
}
