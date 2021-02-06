#include "Package.h"

// Constructors
Package::Package(unsigned int t1, unsigned int  t2, unsigned int  t3)
{
    this->t1_pizzas = t1;
    this->t2_pizzas = t2;
    this->t3_pizzas = t3;
}

Package::Package()
{
    this->t1_pizzas = 0;
    this->t2_pizzas = 0;
    this->t3_pizzas = 0;
}

Package::~Package(){}
