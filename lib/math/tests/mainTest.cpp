/**
 * @author      : worldpotato
 * @file        : mainTest
 * @created     : Monday Aug 31, 2020 20:45:57 CEST
 */

#include <gtest/gtest.h>
#include "add-test.cpp"
#include "subtract-test.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
