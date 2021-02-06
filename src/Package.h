#pragma once

#include <vector>
#include <string>
#include <iosfwd>

// A package is a configuration of pizzas, better said, how many pizzas go to each team type
class Package
{
public:
    unsigned int t1_pizzas;
    unsigned int t2_pizzas;
    unsigned int t3_pizzas;

    Package(uint t1, uint t2, uint t3);
    Package();
    ~Package();
};

