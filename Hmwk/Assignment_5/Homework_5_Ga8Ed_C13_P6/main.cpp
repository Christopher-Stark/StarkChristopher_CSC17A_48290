/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 10, 2022, 12:03 PM
 * Purpose: Create Inventory class with item#, quant, cost, tCost data
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries
#include "inventory.h"
//Global Constants

//Function Prototypes
void display(const Inventory a);
//Execution begins here!
int main(int argc, char** argv) 
{
    int itNum, quan;
    float cst;
    //Get Data
    do
    {
        cout << "No negative values!" << endl;
        cout << "Please enter item number: ";
        cin >> itNum;
        cout << "Please enter quantity of item: ";
        cin >> quan;
        cout << "Please enter item cost: ";
        cin >> cst;
        cout << endl;
    }while(itNum < 0 || quan < 0 || cst < 0);
    //Declare object with arguments
    Inventory item(itNum, cst, quan);
    //Display object data
    display(item);
    return 0;
}
//Functions
void display(const Inventory a)
{
    cout << "Item Number: " << a.getItemNumber() << endl;
    cout << "Item Quantity: " << a.getQuantity() << endl;
    cout << "Item Cost: $" << fixed << setprecision(2) << a.getCost() << endl;
    cout << "Total Cost: $" << fixed << setprecision(2) << a.getTotalCost() << endl;
}
