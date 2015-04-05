/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "module.h"

void init_registry(module_registry_t * registry){

}

int register_module(module_registry_t * registry, module_t * output) {
  if (registry->max_id < MAX_MODULES) {
    registry->modules[registry->max_id] = * output;
    registry->max_id++;
    return registry->max_id; // Number of modules
  }
  return -1;
}

void usage_modules(module_registry_t * registry){
  module_t * module;
  size_t i;

  printf("%s modules:\n", registry->name);

  for (i=0; i < registry->max_id; i++) {
    module = &registry->modules[i];
    printf("%s:\t%s", module->ident, module->name);
    if (registry->default_id == i) {
      printf(" (default)");
    }
    printf("\n");
  }
}

module_t * search_module(module_registry_t * registry, module_ident_t * ident){
  module_t * module;
  size_t i;

  for (i=0; i < registry->max_id; i++) {
    module = &registry->modules[i];
    if (strcmp(module->ident, (char *) ident) == 0) {
      return (module);
    }
  }
  return (module_t *) NULL;
}

module_t * get_default_module(module_registry_t * registry){
  if (&registry->modules[registry->default_id] != NULL) {
    return &registry->modules[registry->default_id];
  }

  return (module_t *) NULL;
}
