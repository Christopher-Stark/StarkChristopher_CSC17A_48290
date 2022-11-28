/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 27, 2022, 4:49 PM
 * Purpose: NumDays Class to represent work hours converted to days
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries
#include "NumDays.h"
//Global Constants

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    //Variables
    int hrs;
    //Get data for worker 1
    do{
     cout << "Please enter your work hours (non negative) for worker 1: ";
     cin >> hrs;
       
    }while(hrs < 0);
    //Object Variable
    NumDays wkr1(hrs);
    //Get data for worker 2
    do{
     cout << "Please enter your work hours (non negative) for worker 2: ";
     cin >> hrs;
       
    }while(hrs < 0);
    NumDays wkr2(hrs);
    //Display
    cout << "\nThe amount of hours worked for worker 1 is: " << wkr1.getHours() << endl;
    cout << "The amount of days worked for worker 1 is: " << wkr1.getDays() << endl;
    cout << "The amount of hours worked for worker 2 is: " << wkr2.getHours() << endl;
    cout << "The amount of days worked for worker 2 is: " << wkr2.getDays() << endl;
    //Add two objects together using overloaded operator
    NumDays cmbWrks;
    cmbWrks = wkr1 + wkr2;
    cout << "\nThe amount of hours combined are: " << cmbWrks.getHours() << endl;
    cout << "The amount of days combined are: " << cmbWrks.getDays() << endl;
    //Using increment operator
    cmbWrks = ++cmbWrks;
    cout << "\nThe new hours incremented by 1 are: " << cmbWrks.getHours() << endl;
    cout << "The new days worked is: " << cmbWrks.getDays() << endl;
    //Using decrement operator
    cmbWrks = --cmbWrks;
    cmbWrks = --cmbWrks;//Doing twice since i added 1 already
    cout << "\nThe new hours decremented by 1 are: " << cmbWrks.getHours() << endl;
    cout << "The new days worked is: " << cmbWrks.getDays() << endl;
    return 0;
}
//Functions

