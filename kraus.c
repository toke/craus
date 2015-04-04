/*
* ----------------------------------------------------------------------------
* "THE COFFEE-WARE LICENSE" (Revision 23):
* <toke@toke.de> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can bring me a coffee in return.
* ----------------------------------------------------------------------------
*/

#include "kraus.h"

int main(int argc, char *argv[]) {
  calendar_t cal = {0};
  int c;

  void (*output)(calendar_t *);
  output = DEFAULT_FORMAT; // default output

  while ((c = getopt(argc, argv, "hvCpsjwc:")) != -1)
    switch (c) {
    case 'C':
      output = &csv_out;
      break;
    case 'p':
      output = &text_out;
      break;
    case 's':
      output = &simple_out;
      break;
    case 'j':
      output = &json_out;
      break;
    case 'v':
      output = &vcard_out;
      break;
    case 'w': // Skip Weekends
      cal.flags.weekday = 1;
      break;
    case 'c':
      if (optarg && atoi(optarg) > 0) {
        cal.count = optarg ? atoi(optarg) : 1;
      } else {
        cal.count = 1;
      }
      break;
    case 'h':
      usage();
      return 0;
      break;
    case '?':
      printf("craus %i.%i\n", craus_VERSION_MAJOR, craus_VERSION_MINOR);

      if (optopt == 'c') {
        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
      } else if (isprint(optopt)) {
        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
      } else {
        fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
      }
      return 1;
    default:
      abort();
  }

  time(&cal.start_date);

  cal.count = cal.count ? cal.count : 1;
  output(&cal);

  return 0;
}

/*
*  Calculate kraus_t floor for given date
*  returns kraus_t floor
*/
kraus_t kraus_floor(struct tm *date) {
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


void usage(void) {
  printf("craus Version %i.%i\n", craus_VERSION_MAJOR, craus_VERSION_MINOR);
  printf("kraus [-C|-p|-j|-v|-s] [-w] [-c count]\n");
}
