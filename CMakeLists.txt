cmake_minimum_required (VERSION 2.8.7)
project (craus)
set (VERSION_MAJOR 1)
set (VERSION_MINOR 4)
set (VERSION_PATCH 8)

set (CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
set (CPACK_PACKAGE_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

set (CPACK_PACKAGE_NAME "craus")
set (CPACK_PACKAGE_DESCRIPTION_SUMMARY "K.R.A.U.S. in C")
set (CPACK_PACKAGE_FILE_NAME "craus_${CPACK_PACKAGE_VERSION}-i386")
set (CPACK_PACKAGE_CONTACT "toke@toke.de")
set (CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
set (CPACK_RESOURCE_FILE_README "${PROJECT_SOURCE_DIR}/README.md")

set (CPACK_DEBIAN_PACKAGE_SHLIBDEPS "on")
set (CPACK_DEBIAN_PACKAGE_PROVIDES "kraus")

INCLUDE(CPack)

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
install(FILES ${MANPAGES} DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
install(TARGETS kraus DESTINATION bin)


enable_testing ()
add_test (kraus kraus)
set_tests_properties (kraus
  PROPERTIES PASS_REGULAR_EXPRESSION "Am ..\\... treffen wir uns in Stockwerk .")
add_test (kraus2 kraus -c 2)
add_test (kraus_null kraus -s null)
set_tests_properties (kraus_null
PROPERTIES PASS_REGULAR_EXPRESSION "Am ..\\... treffen wir uns in Stockwerk 0")


