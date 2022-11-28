/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 27, 2022, 6:25 PM
 * Purpose: FeetInches Class showing <=, >=, != operators
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries
#include "FeetInches.h"
//Global Constants

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    //Variables
    int feet, inches;
    //Object Variables
    FeetInches first, second;
    //Get Data
    cout << "Please enter inches for object one: ";
    cin >> inches;
    cout << "Please enter feet for object one: ";
    cin >> feet;
    first.setInches(inches);
    first.setFeet(feet);
    
    cout << "Please enter inches for object two: ";
    cin >> inches;
    cout << "Please enter feet for object two: ";
    cin >> feet;
    second.setInches(inches);
    second.setFeet(feet);
    //Display Data
    cout << "\nObject 1 has this many inches: " << first.getInches() << endl;
    cout << "Object 1 has this many feet: " << first.getFeet() << endl;
    cout << "\nObject 2 has this many inches: " << second.getInches() << endl;
    cout << "Object 2 has this many feet: " << second.getFeet() << endl << endl;
    //Overloaded operators <=, >=, !=
    if (first <= second){
        cout << "Object 1 is less than or equal to Object 2." << endl;
    }
    if (first >= second){
        cout << "Object 1 is greater than or equal to Object 2." << endl;
    }
    if (first != second){
        cout << "Object 1 is not equal to Object 2." << endl;
    }
    
    return 0;
}
//Functions

