/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 5, 2022, 12:30 PM
 * Purpose: Determines days in month based off current year/including leap years
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Function Prototypes
void numDaysInMonth(int month, int year);
//Execution begins here!

int main(int argc, char** argv)
{
    int month;
    int year;

    while (month < 1 || month > 12)
    {
        cout << "Please enter a month between 1-12: ";
        cin >> month;
    }

    cout << "Please enter a year to determine how many days in that month: ";
    cin >> year;
    numDaysInMonth(month, year);

    return 0;
}
//Functions

/**
 * Displays number of days in each month in a year, also calculates leap years
 * @param month
 * @param year
 */
void numDaysInMonth(int month, int year)
{
    switch (month)
    {
        case 1:
            cout << "There are 31 days in that month.";
            break;
        case 2:
            if (year % 100 == 0 && year % 400 == 0)
            {
                cout << "There are 29 days in that month.";
            }
            else if (year % 100 != 0 && year % 4 == 0)
            {
                cout << "There are 29 days in that month.";
            }
            else
            {
                cout << "There are 28 days in that month.";
            }
            break;
        case 3:
            cout << "There are 31 days in that month.";
            break;
        case 4:
            cout << "There are 30 days in that month.";
            break;
        case 5:
            cout << "There are 31 days in that month.";
            break;
        case 6:
            cout << "There are 30 days in that month.";
            break;
        case 7:
            cout << "There are 31 days in that month.";
            break;
        case 8:
            cout << "There are 31 days in that month.";
            break;
        case 9:
            cout << "There are 30 days in that month.";
            break;
        case 10:
            cout << "There are 31 days in that month.";
            break;
        case 11:
            cout << "There are 30 days in that month.";
            break;
        case 12:
            cout << "There are 31 days in that month.";
            break;
    }
}