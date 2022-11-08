/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 7, 2022, 2:56 PM
 * Purpose: Create Class called Date that stores/displays date information
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries
#include "date.h"
//Global Constants

//Function Prototypes
void userDay(Date &);
void userMonth(Date &);
void userYear(Date &);
void display(const Date);
//Execution begins here!

int main(int argc, char** argv)
{
    //Declarations
    Date date;
    //Sets class variables
    userDay(date);
    userMonth(date);
    userYear(date);
    //Displays class variables in date formats
    display(date);
    return 0;
}
//Functions

void userDay(Date &a)
{
    int day;
    do
    {
        cout << "Please enter a correct day for your month 1-31: ";
        cin >> day;
        a.setDay(day);
    }
    while (day < 1 || day > 31);
}

void userMonth(Date &a)
{
    int month;
    do
    {
        cout << "Please enter month 1-12: ";
        cin >> month;
        a.setMonth(month);
    }
    while (month < 1 || month > 12);
}

void userYear(Date &a)
{
    int year;
    cout << "Please enter year: ";
    cin >> year;
    a.setYear(year);
}
void display(const Date a)
{
    int size = 12;
    string month[size] = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November",
                          "December"};
    
    cout << "**Date formats below**" << endl << endl;
    cout << a.getMonth() << "/" << a.getDay() << "/" << a.getYear() << endl;
    cout << month[a.getMonth()-1] << " " << a.getDay() << ", " << a.getYear() << endl;
    cout << a.getDay() << " " << month[a.getMonth()-1] << " " << a.getYear() << endl;
}
