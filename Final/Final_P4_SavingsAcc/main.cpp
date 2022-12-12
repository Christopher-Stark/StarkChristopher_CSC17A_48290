/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 2, 2022, 2:57 PM
 * Purpose:Final Problem 4 - Savings account class
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//User Defined Libraries
#include "Savings.h"
//Global Constants

//Function Prototypes

//Execution begins here!

int main(int argc, char** argv){
    SavingsAccount mine(-300);
    for(int i = 1; i <= 10; i++){
        mine.Transaction((float) (rand() % 500)*(rand() % 3 - 1));
    }
    mine.toString();
    cout << "Balance after 7 years given 10% interest = "
            << mine.Total((float) (0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = "
            << mine.TotalRecursive((float) (0.10), 7)
            << " Recursive Calculation " << endl;
    return 0;
}
//Functions

