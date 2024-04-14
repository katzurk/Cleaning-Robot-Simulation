cmake_minimum_required(VERSION 3.14)
project(209.1-ROBOT-SPRZATAJACY)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/v1.14.x.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

###

enable_testing() #to  discover tests in test explorer

#add_subdirectory(googletest) # add googletest subdirectory

# include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(main main.cpp robot.cpp) # add this executable

add_executable(robot_test robot.cpp robot_test.cc) # add this executable
add_test(robot_test robot_test)

target_link_libraries(robot_test GTest::gtest_main) # link google test to this executable

include(GoogleTest)
# gtest_discover_tests(robot_test) # discovers tests by asking the compiled test executable to enumerate its tests
gtest_add_tests(
    TARGET      robot_test
    TEST_LIST   robot_test.cc
)