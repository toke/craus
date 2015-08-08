option (MOD_STRATEGY_JAUTZ
  "Support for kraus http call" ON)
if (MOD_STRATEGY_JAUTZ)
message ("Searching for libcurl")
find_package (
	CURL
)
endif(MOD_STRATEGY_JAUTZ)
if (CURL_FOUND)
message("Build with curl support")
endif(CURL_FOUND)

include_directories(
	${CURL_INCLUDE_DIRS}
)

add_library(Strategy strategy.c)
add_library(NullStrategy null.c)
add_library(CrausStrategy craus.c)
add_library(JautzStrategy jautz.c)

target_link_libraries(Strategy NullStrategy)
target_link_libraries(Strategy CrausStrategy)
if (MOD_STRATEGY_JAUTZ)
target_link_libraries(Strategy JautzStrategy ${CURL_LIBRARIES})
endif (MOD_STRATEGY_JAUTZ)

