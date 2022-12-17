/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 12, 2022, 5:54 PM
 * Purpose: Final Problem 6 - Conversions
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
void displayConversions();
//Execution begins here!
int main(int argc, char** argv) 
{
    displayConversions();
    float num1 = 5.75, num2 = .9, num3 = 99.7, num4 = 7;
    unsigned char value = num4; 
    unsigned char binary = 0b10111000;
    unsigned short octal = 0160000; 
    unsigned int hex = 0xC76600;
    unsigned int result;
    cout << num1 << " in Scaled Binary = " << static_cast<int>(binary) << endl;
    cout << num2 << " in Scaled Octal = " << static_cast<int>(octal) << endl;
    cout << num3 << " in Scaled Hex = " << static_cast<int>(hex) << endl;
    result = value*binary;
    result >>= 11;
    cout << "\nBinary result after shift: " << result << endl;
    result = value*octal;
    result >>= 19;
    cout << "Octal result after shift: " << result << endl;
    result = value*hex;
    result >>= 27;
    cout << "Hex result after shift: " << result << endl;
    return 0;
}
//Functions
void displayConversions(){
    cout << "Base 10 = 5.75 in Base 2 = 101.11, Base 8 = 5.6, Base 16 = 5.C" << endl;
    cout << "Nasa Format = 5C000003, IEEE 754 Format = 40B80000" << endl;
    cout << "\nBase 10 = .9 in Base 2 = .11100 Rep., Base 8 = .71463 Rep., "
            "Base 16 = .E6 Rep." << endl;
    cout << "Nasa Format = 73333300, IEEE 754 Format = 3F666666" << endl;
    cout << "\nBase 10 = 99.7 in Base 2 = 1100011.10110011 Rep., Base 8 = 143.54631 "
            "Rep., Base 16 = 63.B3 Rep." << endl;
    cout << "Nasa Format = 63B33307, IEEE 754 Format = 42C76666" << endl << endl;
}
