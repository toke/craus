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

  module_t * out_module;
  module_t * strat_module;

  char *output_s = NULL;
  char *strategy_s = NULL;
  int c;


  while ((c = getopt(argc, argv, "hwc:o:s:")) != -1)
    switch (c) {
    case 'w': // Skip Weekends
      cal.flags.weekday = 1;
      break;
    case 'c': // Count
      if (optarg && atoi(optarg) > 0) {
        cal.count = optarg ? atoi(optarg) : 1;
      } else {
        cal.count = 1;
      }
      break;
    case 'o': // Output Module
      output_s = optarg;
      break;
    case 's': // Strategy Module
      strategy_s = optarg;
      break;
    case 'h':
      usage();
      return 0;
      break;
    case '?':
      printf("craus %i.%i.%i\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);

      if (optopt == 'c' || optopt == 'o' || optopt == 's') {
        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
        usage();
      } else if (isprint(optopt)) {
        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
      } else {
        fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
      }
      return 1;
    default:
      abort();
  }


  module_registry_t strategy_modules = {
    .name = "Strategy",
  };

  module_registry_t output_modules = {
    .name = "Output",
  };

  register_strategy(&strategy_modules);
  register_output(&output_modules);

  // Handle output Modules
  if (output_s != NULL) {
    out_module = search_module(&output_modules, (module_ident_t *) output_s);
    if (out_module == NULL) {
      printf("Output-module not found\n\n");
      usage_output(&output_modules);
      return -1;
    }
  } else {
    out_module = get_default_module(&output_modules);
  }

  // Handle strategy Modules
  if (strategy_s != NULL) {
    strat_module = search_module(&strategy_modules, (module_ident_t *) strategy_s);
    if (strat_module == NULL) {
      printf("Strategy-module not found\n\n");
      usage_output(&strategy_modules);
      return -1;
    }
  } else {
    strat_module = get_default_module(&strategy_modules);
  }

  time(&cal.start_date);
  cal.count = cal.count ? cal.count : 1;

  output   = out_module->func;
  strategy = strat_module->func;
  output(&cal, strategy);

  return 0;
}

void usage(void) {

  module_registry_t strategy_registry = {
    .name = "Strategy",
  };
  module_registry_t output_registry = {
    .name = "Output",
  };

  register_output(&output_registry);
  register_strategy(&strategy_registry);


  printf("craus Version %i.%i.%i\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
  printf("kraus [-o=OUTPUT MODULE] [-s=STRATEGY MODULE] [-w] [-c count]\n\n");

  printf("\n");
  usage_modules(&output_registry);
  printf("\n");
  usage_modules(&strategy_registry);

}
