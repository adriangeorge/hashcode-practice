#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include "Pizza.h"
#include "Package.h"

using namespace std;


int main() {

    // Pizza count will hold the total number of pizzas available
    unsigned int pizza_count;
    // tN_count will hold the number of teams for each type N = {2, 3, 4}
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

    // The restaurant will hold all the available pizzas we read from the input file    
    vector<Pizza> *restaurant = new vector<Pizza>(0);

    // Generating all the pizzas
    Pizza *current_pizza;
    for(unsigned int i = 0 ; i < pizza_count; i++) {
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

    // Calculate how many pizzas we can distribute to the teams
    // i = pizzas for team of 2 members
    // j = pizzas for team of 3 members
    // k = pizzas for team of 4 members

    // iter and total_matcher are defined only for stats
    unsigned int iter = 0;
    unsigned int total_matches = 0;

    // We'll store each delivery configuration in a Package object
    vector<Package> *packages = new vector<Package>(0);
    for (unsigned int i = 0; i <= t2_count * 2; i += 2) {   
        for (unsigned int j = 0; j <= t3_count * 3; j += 3) {
            for (unsigned int k = 0; k <= t4_count * 4; k += 4) {
                // Since the score will be bigger if we distribute all the pizzas
                if(i + j + k <= pizza_count && i + j + k > pizza_count / 2 ) { 
                    // PRINT FOR DEBUG
                    // cout << "T2" << setw(5) << i << " | ";
                    // cout << "T3" << setw(5) << j << " | ";
                    // cout << "T4" << setw(5) << k << " | ";
                    // cout << "Total Pizzas " << setw(5) << i + j + k << " | ";
                    // cout << "Pizzas not delivered " << setw(5) << pizza_count - ( i + j + k ) << endl;

                    // Add this package configuration to a list
                    packages->push_back(*(new Package(i, j , k)));
                    total_matches++;
                }
                iter++;
            }
            iter++;
        }
        iter++;
    }

    // Sort all pizzas according to rarity score
    for (Pizza pizza : *restaurant) {
        cout << pizza << endl;
    }

    // For each loop iterating through all packages
    unsigned int maxScore = 0;
    for (Package package  : *packages) {
        cout << package.t1_pizzas << " "  << package.t2_pizzas << " " << package.t3_pizzas << endl;
    }

    cout << "Iterations " << iter << " Total matches " <<  total_matches << endl;
    return 0;    
}
