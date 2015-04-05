cmake_minimum_required (VERSION 2.8.7)
project (craus)
set (craus_VERSION_MAJOR 1)
set (craus_VERSION_MINOR 4)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
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
