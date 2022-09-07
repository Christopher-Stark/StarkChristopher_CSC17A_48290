/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 5, 2022, 11:49 AM
 * Purpose: Converts Celsius to Fahrenheit temp
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Function Prototypes
float celsToFahren(float celsius);
//Execution begins here!

int main(int argc, char** argv)
{
    float temp = 0.00f;
    cout << "Please enter a temp to convert from Celsius to Fahrenheit: ";
    cin >> temp;
    float result = celsToFahren(temp);
    cout << "The temp in Fahrenheit is: " << result;

    return 0;
}

//Functions
/**
 * Converts Celsius temp to Fahrenheit
 * @param celsius
 * @return Fahrenheit amount
 */
float celsToFahren(float celsius)
{
    float fahren = (1.8 * celsius + 32);
    return fahren;
}

