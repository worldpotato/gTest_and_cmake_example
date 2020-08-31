/**
 * @author      : worldpotato
 * @file        : test1
 * @created     : Monday Aug 31, 2020 17:26:39 CEST
 */

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
 


