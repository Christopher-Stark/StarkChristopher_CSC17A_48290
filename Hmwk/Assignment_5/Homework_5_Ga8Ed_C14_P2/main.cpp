/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 23, 2022, 12:37 PM
 * Purpose: Create Day of year class that outputs month/day
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//User Defined Libraries
#include "DayOfYear.h"
//Global Constants

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    //Variables
    int num;
    //Get data
    do{
        cout << "Please enter the day of year 1-365: ";
        cin >> num;
    }while(num < 1 || num > 365);
    //Class Variable
    DayOfYear day(num);
    //Display
    day.print();
    
    return 0;
}
//Functions

