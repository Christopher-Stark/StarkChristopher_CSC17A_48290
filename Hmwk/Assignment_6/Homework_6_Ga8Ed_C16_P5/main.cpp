/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 2, 2022, 2:57 PM
 * Purpose: Create template function that runs a total of values from user
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include "Total.h"
//Global Constants

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    //Variables
    int tNums, tAmt = 0;
    //Get Data
    do{
    cout << "Please enter how many numbers to total: ";
    cin >> tNums;
    tAmt = total(tNums);
    }while (tNums < 0);
    cout << "The total amount of those numbers is: " << tAmt;
    return 0;
}
//Functions

