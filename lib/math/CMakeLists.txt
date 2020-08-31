######################################################################
# @author      : worldpotato
# @file        : CMakeLists
# @created     : Monday Aug 31, 2020 19:36:17 CEST
######################################################################

cmake_minimum_required(VERSION 3.18)

project(math)

set(CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# main part
# using math.cpp
add_library(math SHARED
    src/math.cpp
)

# using the header files
target_include_directories(math PUBLIC include)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests/mainTest.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread math)
