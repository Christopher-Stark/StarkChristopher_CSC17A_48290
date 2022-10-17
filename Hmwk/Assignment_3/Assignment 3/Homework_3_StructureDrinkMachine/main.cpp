/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 4, 2022, 7:01 PM
 * Purpose: Use struct of soda machine inventory and emulate buying soda simulation
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries

struct DrkMch
{
    string drinkName;
    float drinkCost;
    int stock;
};

enum Name
{
    Cola, Root, Lemon, Grape, Cream
};
//Global Constants

//Function Prototypes
void getData(DrkMch a[], int index, float &totl);
//Execution begins here!

int main(int argc, char** argv)
{
    int size = 5;
    float totalAmt = 0.00f;
    int totl = 0;
    bool menu = true;
    string name;

    DrkMch drink[size] = {
        {"Cola       ", .75, 20},
        {"Root Beer  ", .75, 20},
        {"Lemon-Lime ", .75, 20},
        {"Grape Soda ", .80, 20},
        {"Cream Soda ", .80, 20}};

    //Get Data
    while (menu)
    {
        for (int i = 0; i < size; i++)
        {
            cout << drink[i].drinkName << setprecision(2) << drink[i].drinkCost * 100
                    << "  " << drink[i].stock << endl;
        }
        getline(cin, name);
        if (name == "Cola")
        {
            getData(drink, 0, totalAmt);
        }
        else if (name == "Root Beer")
        {
            getData(drink, 1, totalAmt);
        }
        else if (name == "Lemon-Lime")
        {
            getData(drink, 2, totalAmt);
        }
        else if (name == "Grape Soda")
        {
            getData(drink, 3, totalAmt);
        }
        else if (name == "Cream Soda")
        {
            getData(drink, 4, totalAmt);
        }
        else
        {
            menu = false;
            cout << "Quit" << endl;
            totl = totalAmt * 100;
            cout << totl << endl;
        }
        cin.ignore();
    }
    //Display Data
    return 0;
}
//Functions

void getData(DrkMch a[], int index, float &totl)
{
    float change;
    float amount;
    cin >> amount;
    amount /= 100;
    while (amount > 1.00 || amount < 0)
    {
        cin >> amount;
        amount /= 100;
    }

    if (a[index].stock == 0)
    {
        cout << "That Soda is sold out, please select another!" << endl;
    }
    else
    {
        a[index].stock = a[index].stock - 1;
        change = (amount - a[index].drinkCost) * 100;
        cout << "Quit" << endl;
        cout << change << endl;
        totl = totl + a[index].drinkCost;
    }
}
