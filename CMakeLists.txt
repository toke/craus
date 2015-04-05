cmake_minimum_required (VERSION 2.8.7)
project (craus)
set (craus_VERSION_MAJOR 1)
set (craus_VERSION_MINOR 3)

configure_file (
  "${PROJECT_SOURCE_DIR}/version.h.in"
  "${PROJECT_BINARY_DIR}/version.h"
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/output")
include_directories("${PROJECT_SOURCE_DIR}/strategy")

add_subdirectory(output)
add_subdirectory(strategy)

add_library(Module module.c)

add_executable (kraus kraus.c)
target_link_libraries(kraus Module)
target_link_libraries(kraus Output)
target_link_libraries(kraus Strategy)


set(MANPAGES docs/kraus.1)
install(FILES ${MANPAGES} DESTINATION man)
install(TARGETS kraus DESTINATION bin)
install(FILES craus.h DESTINATION include)
