/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 24, 2022, 3:05 PM
 * Purpose: Outputs all the Conversions/IEEE 754 Nasa formats
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
void displayFormats();
//Execution begins here!
int main(int argc, char** argv) 
{
    displayFormats();
    return 0;
}
//Functions
void displayFormats()
{
    cout << "\nBase 10: 49.1875 / Base 2: 110001.0011 / Base 8: 61.14 / Base 16: 31.3" << endl;
    cout << "IEEE 754 Nasa Hex Format: 62600006 / Negative Decimal Format: 9DA00006" << endl;
    
    cout << "\nBase 10: 3.07421875 / Base 2: 11.00010011 / Base 8: 3.046 / Base 16: 3.13" << endl;
    cout << "IEEE 754 Nasa Hex Format: 62600002 / Negative Decimal Format: 9DA00002" << endl;
    
    cout << "\nBase 10: 0.2 / Base 2: 0.00110011(repeating) / Base 8: 0.14631463(repeating)"
            " / Base 16: 0.33(repeating)" << endl;
    cout << "IEEE 754 Nasa Hex Format: 666666FE / Negative Decimal Format: 99999AFE" << endl;
    
    cout << "\nIEEE 754 Nasa Hex Format: 69999902 / "
            "Decimal Number: 11.0100110011 Base 2" << endl;
    
    cout << "IEEE 754 Nasa Hex Format: 69999903 / Decimal Number: 110.10011001 Base 2" << endl;
    
    cout << "IEEE 754 Nasa Hex Format: 966667FF / Decimal Number: -.011010011001 Base 2" << endl;
    
    cout << "Work shown in .xlsx file in folder problem 6 'Midterm_Conversions_NASA_Format'";
}
