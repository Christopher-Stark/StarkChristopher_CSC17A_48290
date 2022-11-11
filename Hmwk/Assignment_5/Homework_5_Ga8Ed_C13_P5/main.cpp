/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 10, 2022, 10:37 AM
 * Purpose: Create retail item class that hold description, units, price
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//User Defined Libraries
#include "item.h"
//Global Constants

//Function Prototypes
void displayObjects(const RetailItem, const RetailItem, const RetailItem);
//Execution begins here!

int main(int argc, char** argv)
{
    //Variable declaration
    string jack = "Jacket", jean = "Designer Jeans", shrt = "Shirt";
    int num1 = 12, num2 = 40, num3 = 20;
    float prc1 = 59.95, prc2 = 34.95, prc3 = 24.95;
    //Class object declaration using constructor
    RetailItem one(jack, num1, prc1);
    RetailItem two(jean, num2, prc2);
    RetailItem three(shrt, num3, prc3);
    
    //Display
    displayObjects(one, two, three);
    return 0;
}
//Functions
void displayObjects(const RetailItem a, const RetailItem b, const RetailItem c)
{
    cout << setw(43) << "Units" << endl;
    cout << setw(27) << "Description" << setw(18) << "On Hand" << setw(12)
               << "Price" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Item #1" << fixed << setw(15) << a.getDescri() << setw(18) << a.getUnits() 
         << setw(17) << setprecision(2) << a.getPrice() << endl;
    cout << "Item #2" << fixed << setw(23) << b.getDescri() << setw(10) << b.getUnits() 
         << setw(17) << setprecision(2) << b.getPrice() << endl;
    cout << "Item #3" << fixed << setw(14) << c.getDescri() << setw(19) << c.getUnits() 
         << setw(17) << setprecision(2) << c.getPrice() << endl;
}
