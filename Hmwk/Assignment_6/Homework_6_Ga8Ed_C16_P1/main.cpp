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
    bool error = false;
    do
    {
        cout << "Please enter a correct day for your month 1-31: ";
        cin >> day;
        try{//Try/Catch for Exception Class
        a.setDay(day);
        break;
        }
        catch(Date::InvDay){
            cout << "Error: Invalid day entered." << endl;
            error = true;
        }
    }
    while (error);
}

void userMonth(Date &a)
{
    int month;
    bool error = false;
        
    do
    {
        cout << "Please enter month 1-12: ";
        cin >> month;
        try{//Try/Catch for Exception Class
        a.setMonth(month);
        break;
        }
        catch(Date::InvMonth){
            cout << "Error: Invalid month entered." << endl;
            error = true;
        }
    }
    while (error);
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
