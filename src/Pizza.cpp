#include <string>
#include <iostream>
#include <vector>

#ifndef _PIZZACLASS_
#define _PIZZACLASS_

using namespace std;
class Pizza
{
    vector<string> *ingredient_list;
    int ingredient_count;
public:
    Pizza(int ingredient_count, vector<string> *ingredients){
        this->ingredient_list = ingredients;
        this->ingredient_count = ingredient_count;
    }

    Pizza(){
        this->ingredient_list = new vector<string>;
        this->ingredient_count = 0;
    }

    friend ostream & operator<<(ostream & out, const Pizza & p){
        out << "Pizza are " << p.ingredient_count << " ingrediente";
        for (auto &&i : *(p.ingredient_list)) {
            out << "Lista ingrediente " << i << endl;
        }
        return out;
    }
};

#endif