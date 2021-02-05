#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Pizza.cpp"

using namespace std;


int main() {
    unsigned int pizza_count;
    unsigned int t2_count;
    unsigned int t3_count;
    unsigned int t4_count;

    // Reading inputs
    ifstream input("input");

    input >> pizza_count;
    input >> t2_count;
    input >> t3_count;
    input >> t4_count;

    
    string ingredient;
    int ingredient_count;
    
    vector<Pizza> *restaurant = new vector<Pizza>(0);

    Pizza *current_pizza;
    for(int i = 0 ; i < pizza_count; i++) {
        // Getting ammount of ingredients
        input >> ingredient_count;

        // Building ingredients list
        vector<string> *ingredient_list = new vector<string>(0);
        for (int j = 0; j < ingredient_count; j++) {
            input >> ingredient;
            (*ingredient_list).push_back(ingredient);
        }
        current_pizza = new Pizza(ingredient_count, ingredient_list);
        restaurant->push_back(*current_pizza);
    }

    for (auto &&pizza : *restaurant)
    {
        cout << pizza << endl;
    }
        
}
