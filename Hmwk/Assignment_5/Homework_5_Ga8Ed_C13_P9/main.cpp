/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 11, 2022, 9:43 AM
 * Purpose: Create a population class that determines pop rate/death rate
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries
#include "population.h"
//Global Constants

//Function Prototypes
void display(const Population a);
//Execution begins here!

int main(int argc, char** argv){
    //Variables
    int pop, brth, dth;
    //Get Data
    do{
        cout << "Please enter the population of the area no less then 1: ";
        cin >> pop;
        cout << "Please enter how many births no less then 0: ";
        cin >> brth;
        cout << "Please enter how many deaths no less then 0: ";
        cin >> dth;
    }while(pop < 1 || brth < 0 || dth < 0);
    //Declaration of Class Object
    Population data(pop, brth, dth);
    //Display Data
    display(data);
    return 0;
}
//Functions
void display(const Population a){
    cout << "The population of this area is: " << a.getPop() << endl;
    cout << "The births in this area are: " << a.getBirths() << endl;
    cout << "The deaths in this area are: " << a.getDeaths() << endl;
    cout << "The birth rate in this area is: " << fixed << setprecision(2)
         << a.getBRate() << "%" << endl;
    cout << "The death rate in this area is: " << fixed << setprecision(2)
         << a.getDRate() << "%" << endl;
}
