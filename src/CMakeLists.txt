# Collect all source files (excluding test files)
file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/components/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/models/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
list(FILTER SRC_FILES EXCLUDE REGEX ".*_test\\.cc$") # Exclude test files

# Create main executable
add_executable(main ${SRC_FILES})

# Link Qt to main executable
target_link_libraries(main
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

add_subdirectory(tests)