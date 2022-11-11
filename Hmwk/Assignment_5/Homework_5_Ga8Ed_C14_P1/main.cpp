/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 11, 2022, 11:48 AM
 * Purpose: Create class that translates number amounts into english description
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
#include "numbers.h"
//Execution begins here!
int main(int argc, char** argv) 
{
    int num;
    //GetData
    do{
        cout << "Please enter a number between 0-9999 to get english amount: ";
        cin >> num;
    }while(num < 0 || num > 9999);
    //Declaration of class object
    Numbers number(num);
    number.print();
    return 0;
}
//Functions

