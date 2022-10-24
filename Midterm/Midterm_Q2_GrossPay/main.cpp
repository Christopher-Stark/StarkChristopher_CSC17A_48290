/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 18, 2022, 12:02 PM
 * Purpose: Gross pay of employees with displayed paycheck for the month
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

//User Defined Libraries
#include "GrossPay.h"//Header file with struct data
//Global Constants

//Function Prototypes
void employeeData(Employ *a, int size);
void displayData(const Employ *a, int size);
void totalPay(Employ *a, int size);
void romanNumConv(const Employ *a, int index);
//Execution begins here!

int main(int argc, char** argv)
{
    int size;

    cout << "Please enter how many employees: ";
    cin >> size; //Size for struct array

    Employ *person = nullptr;
    person = new Employ[size]; //Dynamic struct array

    employeeData(person, size); //Gets employee data from user
    totalPay(person, size); //Determines total pay with straight,double,triple adjustments
    displayData(person, size); //Displays struct array data in the form of a check

    delete[] person; //De-allocate dynamic struct array
    return 0;
}
//Functions

void employeeData(Employ *a, int size)
{
    //Declared variables for this function
    string cmp = {"Stark Inc."}, name, addrs;
    float hrs, rtPay;

    for (int emp = 0; emp < size; emp++)
    {
        a[emp].comp = cmp; //Company name is static
        cout << "\nWhat is the employees name: ";
        cin.ignore();
        getline(cin, name);
        a[emp].name = name; //Adds name to struct at current index

        cout << "What is " << a[emp].name << "'s address: ";
        getline(cin, addrs);
        a[emp].addrs = addrs; //Adds address to struct at current index

        cout << "How many hours worked: ";
        cin >> hrs;
        while (hrs < 0)//Error checking for positive hours worked
        {
            cout << "Please enter a positive amount of hours worked: ";
            cin >> hrs;
        }
        a[emp].hrs = hrs; //Adds hours worked to struct at current index

        cout << "What is " << a[emp].name << "'s rate of pay: $";
        cin >> rtPay;
        while (rtPay < 0)//Error checking for positive pay rate worked
        {
            cout << "Please enter a positive rate of pay: ";
            cin >> rtPay;
        }
        a[emp].rtPay = rtPay; //Adds rate of pay to struct at current index
    }
    cout << endl;
}

/**
 * Displays struct array data in the form of a check
 * @param a
 * @param size
 */
void displayData(const Employ *a, int size)
{
    for (int emp = 0; emp < size; emp++)
    {
        cout << "\nCompany " << a[emp].comp << endl;
        cout << "Address " << a[emp].addrs << endl;
        cout << "Name: " << a[emp].name << fixed << setprecision(2)
                << " Amount: $" << a[emp].totPay << endl;
        cout << "Amount: ";
        romanNumConv(a, emp); //Roman numeral conversion for check display
        cout << endl;
        cout << "Signature Line:" << endl;
    }
}

/**
 * Determines total pay with adjustments to double and triple time.
 * @param a
 * @param size
 */
void totalPay(Employ *a, int size)
{
    //Remainder when calculating overtime, increase pay rates based off hours
    float remain = 0.00;
    int str = 20, dHrs = 20, trip = 40, dPay = 2, tPay = 3;

    for (int emp = 0; emp < size; emp++)
    {
        if (a[emp].hrs > trip)//Determines straight,double,triple time amounts
        {
            remain = fmod(a[emp].hrs,trip);
            a[emp].totPay += remain * (a[emp].rtPay * tPay);
            a[emp].totPay += dHrs * (a[emp].rtPay * dPay);
            a[emp].totPay += str * a[emp].rtPay;
        }
        else if (a[emp].hrs > str && a[emp].hrs <= trip)//Determines straight,double
        {
            if (a[emp].hrs == trip)
            {
                a[emp].totPay += dHrs * (a[emp].rtPay * dPay);
                a[emp].totPay += str * a[emp].rtPay;
            }
            else
            {
                remain = fmod(a[emp].hrs,str);
                a[emp].totPay += remain * (a[emp].rtPay * dPay);
                a[emp].totPay += str * a[emp].rtPay;
            }
        }
        else//Else just standard straight pay
        {
            a[emp].totPay += a[emp].hrs * a[emp].rtPay;
        }
    }
}

/**
 * Code supplied by Dr.Lehr made minor adjustments to fit my code
 * Converts struct array Total pay into Roman Numeral system for paycheck display
 * @param a
 * @param index
 */
void romanNumConv(const Employ *a, int index)
{
    //Uses struct total pay amount
    if (a[index].totPay >= 1 && a[index].totPay <= 1000000)
    {
        //Takes total pay and determines 1000's, 100's, 10's, 1's
        unsigned int n1000s, n100s, n10s, n1s;
        n1000s = static_cast<int> (a[index].totPay) / 1000; //Shift 3 places to the left
        n100s = static_cast<int> (a[index].totPay) % 1000 / 100; //Remainder of division of 1000 then shift 2 left
        n10s = static_cast<int> (a[index].totPay) % 100 / 10; //Remainder of division of 100 then shift 1 left
        n1s = static_cast<int> (a[index].totPay) % 10; //Remainder of division by 10

        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch (n1000s)
        {
            case 3:cout << 'M';
            case 2:cout << 'M';
            case 1:cout << 'M';
        }

        //Output the number of 100's
        //Using the Ternary Operator
        cout << (n100s == 9 ? "CM" :
                n100s == 8 ? "DCCC" :
                n100s == 7 ? "DCC" :
                n100s == 6 ? "DC" :
                n100s == 5 ? "D" :
                n100s == 4 ? "CD" :
                n100s == 3 ? "CCC" :
                n100s == 2 ? "CC" :
                n100s == 1 ? "C" : "");

        //Output the number of 10's
        //Using Independent If Statements
        if (n10s == 9)cout << "XC";
        if (n10s == 8)cout << "LXXX";
        if (n10s == 7)cout << "LXX";
        if (n10s == 6)cout << "LX";
        if (n10s == 5)cout << "L";
        if (n10s == 4)cout << "XL";
        if (n10s == 3)cout << "XXX";
        if (n10s == 2)cout << "XX";
        if (n10s == 1)cout << "X";

        //Output the number of 1's
        //Using Dependent If Statements
        if (n1s == 9)cout << "IX";
        else if (n1s == 8)cout << "VIII";
        else if (n1s == 7)cout << "VII";
        else if (n1s == 6)cout << "VI";
        else if (n1s == 5)cout << "V";
        else if (n1s == 4)cout << "IV";
        else if (n1s == 3)cout << "III";
        else if (n1s == 2)cout << "II";
        else if (n1s == 1)cout << "I";
    }
}
