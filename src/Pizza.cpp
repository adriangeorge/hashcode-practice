#include <string>
#include <iostream>
#include <vector>

#include "Pizza.h"

using namespace std;

Pizza::Pizza(int ingredient_count, vector<string> *ingredients){
    this->ingredient_list = ingredients;
    this->ingredient_count = ingredient_count;
    this->id = ++pizza_counter;
}

Pizza::Pizza(){
    this->ingredient_list = new vector<string>;
    this->ingredient_count = 0;
    this->id = ++pizza_counter;
}

Pizza::~Pizza(){

}

unsigned int Pizza::pizza_counter = 0;