/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 23, 2022, 12:37 PM
 * Purpose: Create Day of year class that outputs month/day
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//User Defined Libraries
#include "DayOfYear.h"
//Global Constants

//Function Prototypes

//Execution begins here!

int main(int argc, char** argv){
    //Variables
    int day;
    string month;
    //Get data
    do{
        cout << "Please enter a month 1-12: ";
        cin >> month;
    }while(stoi(month) < 1 || stoi(month) > 12);
    
    do{
    cout << "Please enter the day in that month 1-31: ";
    cin >> day;
    }while(day < 1 || day > 31);

    //Class Variable
    DayOfYear date(day, month);
    //Display
    date.print();
    cout << "\nThe next day!" << endl;
    //Prefix
    date = ++date;//Object is changed by 1 to represent next day
    date.print();
    //Postfix
    cout << "\nThe previous day was!" << endl;
    date = --date;//After to decrement twice since we already changed for next day
    date = --date;
    date.print();

    return 0;
}
//Functions

