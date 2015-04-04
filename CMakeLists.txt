cmake_minimum_required (VERSION 2.8.7)
project (craus)
set (craus_VERSION_MAJOR 1)
set (craus_VERSION_MINOR 2)

configure_file (
  "${PROJECT_SOURCE_DIR}/version.h.in"
  "${PROJECT_BINARY_DIR}/version.h"
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/output")
add_subdirectory(output)

add_executable (kraus kraus.c)
target_link_libraries(kraus Output)

set(MANPAGES docs/kraus.1)
INSTALL( FILES ${MANPAGES} DESTINATION man)
INSTALL( TARGETS kraus DESTINATION bin)
