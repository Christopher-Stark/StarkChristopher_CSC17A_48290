/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 5, 2022, 12:00 PM
 * Purpose: Converts Dollar amount to Yen and Euro
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include <iomanip>
//Global Constants
float YEN_PER_DOLLAR = 143.44f;
float EURO_PER_DOLLAR = 1.01f;

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    float userInput;
    
    cout << "Please enter a dollar amount to convert to yen: ";
    cin >> userInput;
    cout << "The amount in yen is: " << fixed << setprecision(2) <<
            YEN_PER_DOLLAR * userInput << endl;
    
    cout << "Please enter a dollar amount to convert to euro: ";
    cin >> userInput;
    cout << "The amount in yen is: " << EURO_PER_DOLLAR * userInput;
    return 0;
}
//Functions