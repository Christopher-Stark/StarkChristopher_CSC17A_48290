/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 2, 2022, 2:59 PM
 * Purpose: Create absolute value template function
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include "Absolute.h"
//Global Constants

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    //Variable
    int num;
    //Get Data
    cout << "Please enter any number to get it's absolute value: ";
    cin >> num;
    //Display Data using absolute template
    cout << "The absolute value of that number is: " << absolute(num);
    return 0;
}
//Functions

