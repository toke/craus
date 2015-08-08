/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "strategy.h"
#include "config.h"


void register_strategy(module_registry_t * registry){

  module_t craus_strat ={
    .name = "K.R.A.U.S. in C",
    .ident = "craus",
    .func = &craus_floor
  };
  register_module(registry, &craus_strat);

#ifdef USE_STRATEGY_NULL
  module_t null_strat ={
    .name = "Null output",
    .ident = "null",
    .func = &null_floor
  };
  register_module(registry, &null_strat);
#endif

#ifdef USE_STRATEGY_JAUTZ
  module_t jautz_strat ={
    .name = "Jautz.org http (experimental)",
    .ident = "jautz",
    .func = &jautz_floor
  };
  register_module(registry, &jautz_strat);
#endif


}
