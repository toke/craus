option (MOD_OUTPUT_CALENDAR
  "Support for Unix calendar" ON)

add_library(Output output.c)
add_library(SimpleOutput simple.c)
add_library(NeatOutput neat.c)
add_library(TextOutput text.c)
add_library(CSVOutput csv.c)
add_library(JSONOutput json.c)
add_library(vCardOutput vcard.c)
if (MOD_OUTPUT_CALENDAR)
  add_definitions(-DUSE_OUTPUT_CALENDAR)
  add_library(CalendarOutput calendar.c)
endif (MOD_OUTPUT_CALENDAR)


target_link_libraries(Output SimpleOutput)
target_link_libraries(Output NeatOutput)
target_link_libraries(Output TextOutput)
target_link_libraries(Output CSVOutput)
target_link_libraries(Output JSONOutput)
target_link_libraries(Output vCardOutput)
if (MOD_OUTPUT_CALENDAR)
target_link_libraries(Output CalendarOutput)
endif (MOD_OUTPUT_CALENDAR)


