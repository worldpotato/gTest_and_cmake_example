/**
 * @author      : worldpotato
 * @file        : subtract-test
 * @created     : Monday Aug 31, 2020 17:26:39 CEST
 */

#include "math.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(subtract, subtractPositive_true)
{
    math m;
    ASSERT_EQ(0, m.subtract(1, 1));
    ASSERT_EQ(INT8_MAX-1, m.subtract(INT8_MAX, 1));
}

TEST(subtract, subtractPositive_false)
{
    math m;
    ASSERT_NE(1, m.subtract(1, 1));
    ASSERT_NE(INT8_MAX, m.subtract(INT8_MAX, 1));
}

TEST(subtract, subtractNegative_true)
{
    math m;
    ASSERT_EQ(0, m.subtract(-1, -1));
    ASSERT_EQ(INT8_MIN + 1, m.subtract(INT8_MIN, -1));
}

TEST(subtract, subtractNegative_false)
{
    math m;
    ASSERT_NE(1, m.subtract(-1, -1));
    ASSERT_NE(INT8_MIN + 2, m.subtract(INT8_MIN, -1));
}

