/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "output.h"



void register_output(module_registry_t * registry){

  module_t text ={
    .name = "Plain Text Output",
    .ident = "text",
    .func = &text_out
  };
  register_module(registry, &text);

  module_t simple ={
    .name = "Simple Text Output",
    .ident = "simple",
    .func = &simple_out
  };
  register_module(registry, &simple);

  module_t csv ={
    .name = "CSV Output",
    .ident = "csv",
    .func = &csv_out
  };
  register_module(registry, &csv);


  module_t vcard ={
    .name = "vCard Output",
    .ident = "vcard",
    .func = &vcard_out
  };
  register_module(registry, &vcard);


  module_t json_module ={
    .name = "JSON Output",
    .ident = "json",
    .func = &json_out
  };
  register_module(registry, &json_module);

#ifdef SUPPORT_CALENDAR
  module_t calendar_module ={
    .name = "Calendar Output",
    .ident = "calendar",
    .func = &calendar_out
  };
  register_module(registry, &calendar_module);
#endif

}

void usage_output(module_registry_t * registry){
  printf("Use output modules with -o=MODULE.\n");
  printf("Like \"-o=%s\"\n", get_default_module(registry)->ident);
  usage_modules(registry);
}
