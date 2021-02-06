#pragma once

#include <vector>
#include <string>
#include <iosfwd>

class Pizza
{
    std::vector<std::string> *ingredient_list;
    unsigned int ingredient_count;
    static unsigned int pizza_counter;
    unsigned int id;
public:
    Pizza(int ingredient_count, std::vector<std::string> *ingredients);
    Pizza();
    ~Pizza();
    
    friend std::ostream & operator<<(std::ostream & out, const Pizza & p){
        out << "Pizza " << p.id << " are " << p.ingredient_count << " ingrediente" << std::endl;
        for (auto &&i : *(p.ingredient_list)) {
            out << "Lista ingrediente " << i << std::endl;
        }
        return out;
    }
};
