cmake_minimum_required(VERSION 3.14)
project(209.1-ROBOT-SPRZATAJACY)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.7.0/gcc_64")

# Download qt library then add the the qt path to environment PATH (example C:\Qt\6.7.0\msvc2019_64\bin)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)

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

add_executable(main main.cpp robot.cpp room.cpp furniture.cpp visualiser.cpp simulation.cpp cat.cpp) # add this executable

add_executable(robot_test robot.cpp room.cpp robot_test.cc) # add this executable
add_test(robot_test robot_test)
target_link_libraries(robot_test GTest::gtest_main) # link google test to this executable

add_executable(furniture_test furniture.cpp furniture_test.cc)
add_test(furniture_test furniture_test)
target_link_libraries(furniture_test GTest::gtest_main)

add_executable(room_test room.cpp furniture.cpp cat.cpp room_test.cc)
add_test(room_test room_test)
target_link_libraries(room_test GTest::gtest_main)

add_executable(cat_test cat.cpp furniture.cpp cat_test.cc)
add_test(cat_test cat_test)
target_link_libraries(cat_test GTest::gtest_main)
add_executable(furniture_generator_test furniture_generator.cpp furniture.cpp furniture_generator_test.cc)
add_test(furniture_generator_test furniture_generator_test)
target_link_libraries(furniture_generator_test GTest::gtest_main)

target_link_libraries(main
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )


include(GoogleTest)
# gtest_discover_tests(robot_test) # discovers tests by asking the compiled test executable to enumerate its tests
gtest_add_tests(
    TARGET      robot_test
    TEST_LIST   robot_test.cc
)

gtest_add_tests(
    TARGET      furniture_test
    TEST_LIST   furniture_test.cc
)

gtest_add_tests(
    TARGET      room_test
    TEST_LIST   room_test.cc
)

gtest_add_tests(
    TARGET      cat_test
    TEST_LIST   cat_test.cc
)

gtest_add_tests(
    TARGET      furniture_generator_test
    TEST_LIST   furniture_generator_test.cc
)
