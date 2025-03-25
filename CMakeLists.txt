cmake_minimum_required(VERSION 3.14)
project(209.1-ROBOT-SPRZATAJACY)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/v1.14.x.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

add_subdirectory(src)
