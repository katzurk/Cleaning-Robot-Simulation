enable_testing()

# ==========================
# GOOGLE TESTS
# ==========================

add_executable(robot_test
    ../models/robot.cpp
    ../models/room.cpp
    robot_test.cc
)

target_link_libraries(robot_test GTest::gtest_main)

add_test(NAME robot_test COMMAND robot_test)

add_executable(furniture_test
    ../models/furniture.cpp
    furniture_test.cc
)
target_link_libraries(furniture_test GTest::gtest_main)
add_test(NAME furniture_test COMMAND furniture_test)

add_executable(room_test
    ../models/room.cpp
    ../models/furniture.cpp
    room_test.cc
)
target_link_libraries(room_test GTest::gtest_main)
add_test(NAME room_test COMMAND room_test)

add_executable(furniture_generator_test
    ../models/furniture_generator.cpp
    ../models/furniture.cpp
    ../models/cat.cpp
    furniture_generator_test.cc
)
target_link_libraries(furniture_generator_test GTest::gtest_main)
add_test(NAME furniture_generator_test COMMAND furniture_generator_test)

add_executable(cat_test
    ../models/cat.cpp
    ../models/furniture.cpp
    cat_test.cc
)
target_link_libraries(cat_test GTest::gtest_main)
add_test(NAME cat_test COMMAND cat_test)

include(GoogleTest)

gtest_add_tests(TARGET robot_test)
gtest_add_tests(TARGET furniture_test)
gtest_add_tests(TARGET room_test)
gtest_add_tests(TARGET furniture_generator_test)
gtest_add_tests(TARGET cat_test)

target_link_libraries(main
    Qt::Core
    Qt::Gui
    Qt::Widgets
)
