cmake_minimum_required (VERSION 2.8.7)
project (craus)
add_executable (kraus  kraus.c output.c)
install (TARGETS kraus DESTINATION bin)
