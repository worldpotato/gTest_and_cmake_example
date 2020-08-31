cmake_minimum_required (VERSION 3.5)

project(gtest_example)

add_compile_options(-Wall -Werror)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(lib/math)

add_executable (gtest_example main.cpp)

target_link_libraries(gtest_example math)

# moving compile_commands.json file to root directory
add_custom_command(TARGET gtest_example POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${PROJECT_SOURCE_DIR}/compile_commands.json
)

# moving binary to <root>/bin folder
add_custom_command(TARGET gtest_example POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/gtest_example
    ${PROJECT_SOURCE_DIR}/bin/gtest_example
)

