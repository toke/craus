#include "output.h"

/*
*  Plain text output
*/
void print_floor(time_t *start_date, int count)
{
    int i;
    struct tm *kd;
    kraus_t floor;

    for (i=0; i < count; i++) {
        kd = localtime(start_date);
        kd->tm_mday += i;
        mktime(kd);
        floor = kraus_floor(kd);
        (void) printf("Am %02i.%02i treffen wir uns in Stockwerk %i\n",
          kd->tm_mday, kd->tm_mon + 1, floor);
    }
}


/*
*  Plain text output
*/
void json_floor(time_t *start_date, int count)
{
    int i;
    struct tm *kd;
    kraus_t floor;

    printf("{\"kraus\": [\n");
    for (i=0; i < count; i++) {
        kd = localtime(start_date);
        kd->tm_mday += i;
        mktime(kd);
        floor = kraus_floor(kd);
        (void) printf("    {\"date\": \"%02i.%02i.%i\", \"level\": %i},\n",
          kd->tm_mday, kd->tm_mon + 1, kd->tm_year + 1900, floor);
    }
    printf("]}");
}


/*
*  Plain text output
*/
void vcard_floor(time_t *start_date, int count)
{
    int i;
    struct tm *kd;
    kraus_t floor;

    printf(VCARD_HEAD);
    for (i=0; i < count; i++) {
        kd = localtime(start_date);
        kd->tm_mday += i;
        mktime(kd);
        floor = kraus_floor(kd);
        printf(VCARD_BODY, VCARD_DATA(kd, floor));
    }
    printf(VCARD_FOOT);
}
