#include "output.h"

/*
*  JSON output
*/
void json_out(calendar_t *calendar) {
  int i;
  struct tm *kd;
  kraus_t floor;

  printf(JSON_HEAD);
  for (i = 0; i < calendar->count; i++) {
    kd = localtime(&calendar->start_date);
    kd->tm_mday += i;
    mktime(kd);
    floor = kraus_floor(kd);
    if (!calendar->flags.weekday || (kd->tm_wday > 0 && kd->tm_wday < 6)) {
      if (i > 0)
        printf(JSON_DELIMIT);
      (void)printf(JSON_BODY, JSON_DATA);
    }
  }
  printf(JSON_FOOT);
}
