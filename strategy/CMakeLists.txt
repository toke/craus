add_library(Strategy strategy.c)
add_library(NullStrategy null.c)
add_library(CrausStrategy craus.c)

target_link_libraries(Strategy NullStrategy)
target_link_libraries(Strategy CrausStrategy)
