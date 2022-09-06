/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 5, 2022, 12:00 PM
 * Purpose: Explain display results of Code
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    int integer1, integer2;
    double result;
    integer1 = 19;
    integer2 = 2;
    result = integer1 / integer2;
    /*This will display 9 due to the value being truncated, neither integers are 
     *doubles and they do not divide evenly*/ 
    cout << result << endl;
    result = static_cast<double>(integer1) / integer2;
    /*This will display 9.5 due to static casting integer1 into a double
     *which in return makes result variable show the remainder of the division*/
    cout << result << endl;
    result = static_cast<double>(integer1 / integer2);
    /*This will display 9 due to improper static cast statement, the division is
     *done while both variables are still int's so number is truncated*/
    cout << result << endl;
    return 0;
}

//Functions

