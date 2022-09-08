/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 5, 2022, 12:42 PM
 * Purpose: Function/Loop to convert Fahrenheit to Celsius
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include <iomanip>
//Function Prototypes
double celsius(double fahren);
//Execution begins here!

int main(int argc, char** argv)
{
    double tempFahr = 0.00;

    for (int i = 0; i <= 20; i++)
    {
        cout << "When it is " << setprecision(0) << tempFahr << " Fahrenheit it is " <<
        fixed << setprecision(2) << celsius(tempFahr) << " Celsius" << endl;
        tempFahr++;
    }
    return 0;
}

//Functions

/**
 * Converts fahrenheit temp to celsius
 * @param fahren
 * @return temp in Celsius
 */
double celsius(double fahren)
{
    double celsius = 0.00;
    celsius = ((fahren - 32) * 5/9 );
    return celsius;
}
