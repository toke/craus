/*
* ----------------------------------------------------------------------------
* "THE COFFEE-WARE LICENSE" (Revision 23):
* <toke@toke.de> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can bring me a coffee in return.
* ----------------------------------------------------------------------------
*/
 
#include "kraus.h"
 
int main(int argc, char *argv[])
{
    time_t current_time;
    struct tm *kd;
    int deltad = 0; // delta in days from current day
    unsigned int count = 1; // number of results
    int i;
    kraus_t floor;
     
    // Optional handling of arguments (delta days and count)
    if (argc > 1) {
        deltad = atoi(argv[1]);
        if (argc > 2) {
            count = atoi(argv[2]);
        }
    }
    time(&current_time);
    current_time += deltad;
     
    for (i=0; i < count; i++) {
        kd = localtime(&current_time);
        kd->tm_mday += deltad + i;
        mktime(kd);
        floor = kraus_floor(kd);
        (void) printf("Am %02i.%02i treffen wir uns in Stockwerk %i\n",
        kd->tm_mday, kd->tm_mon + 1, floor);
    }
    return 0;
}
 
 
 
 
kraus_t kraus_floor(struct tm *date)
{
    unsigned short perl_seed[2] = {0};
    double rand_number = 0;
    kraus_t floor;
     
    // The S.U.P.E.R. secret Algorithm (Part 1)
    perl_seed[0] = (date->tm_mday * date->tm_mday + date->tm_mon + 1);
     
    // Seed like perl 5.6 does
    unsigned short seed[3] = {SEEDMAGIC, perl_seed[0], perl_seed[1]};
    seed48(&seed[0]);
    rand_number = drand48();
     
    // The S.U.P.E.R. secret Algorithm (Part 2)
    floor = (rand_number * MAX_FLOOR) + MIN_FLOOR;
     
    return floor;
}
