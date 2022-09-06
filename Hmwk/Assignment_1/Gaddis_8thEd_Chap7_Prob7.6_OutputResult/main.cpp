/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 5, 2022, 12:45 PM
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
    int values[5], count;
    for (count = 0; count < 5; count++)
    values[count] = count + 1;
    for (count = 0; count < 5; count++)
    /*The result will display 12345 due to the array holding 5 values and it
     *starts at 0+1 and increments by 1 each time in the for loop set to 5 loops*/
    cout << values[count] << endl;
    return 0;
}

//Functions