option (MOD_STRATEGY_JAUTZ
  "Support for kraus http call" ON)
option (MOD_STRATEGY_NULL
  "Support for NULL output" OFF)

if (MOD_STRATEGY_JAUTZ)
  add_definitions(-DUSE_STRATEGY_JAUTZ)
  message ("Searching for libcurl")
  find_package (
    CURL
  7.16.2 REQUIRED
  )
endif(MOD_STRATEGY_JAUTZ)

if (CURL_FOUND)
  message("Build with curl support")
endif(CURL_FOUND)

include_directories(
  ${CURL_INCLUDE_DIRS}
)

add_library(Strategy strategy.c)

if (MOD_STRATEGY_NULL)
  add_definitions(-DUSE_STRATEGY_NULL)
  add_library(NullStrategy null.c)
  target_link_libraries(Strategy NullStrategy)
endif (MOD_STRATEGY_NULL)


if (MOD_STRATEGY_JAUTZ)
  add_library(JautzStrategy jautz.c)
  target_link_libraries(Strategy JautzStrategy ${CURL_LIBRARIES})
endif (MOD_STRATEGY_JAUTZ)

add_library(CrausStrategy craus.c)
target_link_libraries(Strategy CrausStrategy)
