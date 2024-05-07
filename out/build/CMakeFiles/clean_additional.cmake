# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\furniture_test_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\furniture_test_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\main_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\main_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\robot_test_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\robot_test_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\room_test_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\room_test_autogen.dir\\ParseCache.txt"
  "_deps\\googletest-build\\googlemock\\CMakeFiles\\gmock_autogen.dir\\AutogenUsed.txt"
  "_deps\\googletest-build\\googlemock\\CMakeFiles\\gmock_autogen.dir\\ParseCache.txt"
  "_deps\\googletest-build\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\AutogenUsed.txt"
  "_deps\\googletest-build\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\ParseCache.txt"
  "_deps\\googletest-build\\googlemock\\gmock_autogen"
  "_deps\\googletest-build\\googlemock\\gmock_main_autogen"
  "_deps\\googletest-build\\googletest\\CMakeFiles\\gtest_autogen.dir\\AutogenUsed.txt"
  "_deps\\googletest-build\\googletest\\CMakeFiles\\gtest_autogen.dir\\ParseCache.txt"
  "_deps\\googletest-build\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\AutogenUsed.txt"
  "_deps\\googletest-build\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\ParseCache.txt"
  "_deps\\googletest-build\\googletest\\gtest_autogen"
  "_deps\\googletest-build\\googletest\\gtest_main_autogen"
  "furniture_test_autogen"
  "main_autogen"
  "robot_test_autogen"
  "room_test_autogen"
  )
endif()
