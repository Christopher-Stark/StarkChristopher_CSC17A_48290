/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 2, 2022, 2:31 PM
 * Purpose: Create template class for lesser/greater return
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include "Min_Max.h"
//Global Constants

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    //Variables
    int num1, num2;
    //Get Data
    cout << "Please enter two numbers to compare: ";
    cin >> num1 >> num2;
    //Compare numbers with templates
    cout << "The lesser number is: " << minimum(num1, num2) << endl;
    cout << "The higher number is: " << maximum(num1, num2) << endl;
    return 0;
}
//Functions

