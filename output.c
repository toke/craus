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
*  CSV output
*/
void csv_out(calendar_t *calendar) {
  int i;
  struct tm *kd;
  kraus_t floor;

  for (i = 0; i < calendar->count; i++) {
    kd = localtime(&calendar->start_date);
    kd->tm_mday += i;
    mktime(kd);
    floor = kraus_floor(kd);
    if (calendar->flags.weekday && (kd->tm_wday == SA || kd->tm_wday == SU)) {
      printf("%02i.%02i.%i;\n", kd->tm_mday,
                 kd->tm_mon + 1, kd->tm_year + 1900);
    } else {
      (void) printf("%02i.%02i.%i;%i\n", kd->tm_mday,
                 kd->tm_mon + 1, kd->tm_year + 1900, floor);
    }
  }
}

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
