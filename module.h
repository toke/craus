/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef _MODULE_H_
#define _MODULE_H_

#include <string.h>
#include <stdio.h>

#ifndef MAX_MODULES
#define MAX_MODULES 10
#endif

typedef char module_name_t[50];
typedef char module_ident_t[10];

// Module
typedef struct {
  module_name_t    name;
  module_ident_t   ident;
  void           * func;    // The module executable
} module_t;

// Modules registry
typedef struct {
  module_name_t     name;
  module_t          modules[MAX_MODULES];
  unsigned char     max_id;
  signed char       default_id;
} module_registry_t;

void init_registry(module_registry_t * registry);
int register_module(module_registry_t * registry, module_t * module);
void usage_modules(module_registry_t * registry);
module_t * search_module(module_registry_t * registry, module_ident_t * ident);
module_t * get_default_module(module_registry_t * registry);

#endif
