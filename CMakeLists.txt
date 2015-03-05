cmake_minimum_required (VERSION 2.8.7)
set(SDK_32bits TRUE) #Use this line for the 64 bits SDK
project (craus)
add_executable (kraus  kraus.c)
install (TARGETS kraus DESTINATION bin)

