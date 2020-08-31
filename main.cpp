/**
 * @author      : worldpotato (worldpotato)
 * @file        : main
 * @created     : Thursday Aug 27, 2020 19:22:44 CEST
 */

#include "math.hpp"
#include <iostream>

int main()
{

    math m;

    std::cout <<  "1 + 1 = " << m.add(1,1) << std::endl;
    std::cout <<  "1 - 1 = " << m.subtract(1,1) << std::endl;

    return 0;
}

