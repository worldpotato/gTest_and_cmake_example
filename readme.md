# gtest/cmake example

This is my example how to use gtest together with cmake. It's maybe not the best way but it works and is easy to understand.

## Project structure

```
├── CMakeLists.txt                      // main CMakeLists.txt
├── lib
│   └── math                            // library to test
│       ├── CMakeLists.txt              // library CMakeLists.txt
│       ├── include
│       │   └── math.hpp                // header of class which should be tested
│       ├── src
│       │   └── math.cpp                // source of class which should be tested
│       └── tests
│           ├── add-test.cpp            // test file 1
│           ├── mainTest.cpp            // test file with gtest main method
│           └── subtract-test.cpp       // test file 2
└── main.cpp
```

### main.cpp

Just a little example how to use the math "library".

### math.hpp/cpp

Header and source file of the math "library" which should be tested.

### Main CMakeLists.txt

Nothing special here

```
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
```

### library CMakeLists.txt

```
cmake_minimum_required(VERSION 3.18)

project(math)

set(CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# using math.cpp
add_library(math SHARED
    src/math.cpp
)

# using the header files
target_include_directories(math PUBLIC include)

# Locate GTest in the system
# GTest needs to be installed
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# create an executable from the mainTest.cpp file
# and link it with GTest, pthread and what we want to test
add_executable(runTests tests/mainTest.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread math)
```

### mainTest.cpp

```

#include <gtest/gtest.h>

// include the single test files
#include "add-test.cpp"
#include "subtract-test.cpp"

// use the default main method
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### test file 1

```

#include "math.hpp"
#include <gtest/gtest.h>
 
TEST(addTest, addPositive) { 
    math m;
    ASSERT_EQ(2, m.add(1,1));
    ASSERT_EQ(10, m.add(5,5));
}
 
TEST(addTest, addNegatives) {
    math m;
    ASSERT_EQ(-2, m.add(-1,-1));
    ASSERT_EQ(-10, m.add(-5,-5));
}

```
