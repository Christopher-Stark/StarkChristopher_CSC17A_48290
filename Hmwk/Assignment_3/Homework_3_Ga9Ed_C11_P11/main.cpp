/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 5, 2022, 11:50 AM
 * Purpose:
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries

struct Expenses
{
    float housBgt;
    float utlBgt;
    float housEx;
    float transp;
    float food;
    float medic;
    float insur;
    float entert;
    float cloth;
    float misc;
};
//Global Constants

//Function Prototypes
void getExpen(Expenses &a);
void display(const Expenses a);
//Execution begins here!

int main(int argc, char** argv)
{
    int size = 10;
    Expenses monthly;
    //Get data
    getExpen(monthly);
    //Display data
    display(monthly);
    return 0;
}
//Functions

void getExpen(Expenses &a)
{
    float num;

    while (cin >> num)
    {
        cout << "Enter housing cost for the month:$" << endl;
        a.housBgt = num;
        cin >> num;
        cout << "Enter utilities cost for the month:$" << endl;
        a.utlBgt = num;
        cin >> num;
        cout << "Enter household expenses cost for the month:$" << endl;
        a.housEx = num;
        cin >> num;
        cout << "Enter transportation cost for the month:$" << endl;
        a.transp = num;
        cin >> num;
        cout << "Enter food cost for the month:$" << endl;
        a.food = num;
        cin >> num;
        cout << "Enter medical cost for the month:$" << endl;
        a.medic = num;
        cin >> num;
        cout << "Enter insurance cost for the month:$" << endl;
        a.insur = num;
        cin >> num;
        cout << "Enter entertainment cost for the month:$" << endl;
        a.entert = num;
        cin >> num;
        cout << "Enter clothing cost for the month:$" << endl;
        a.cloth = num;
        cin >> num;
        cout << "Enter miscellaneous cost for the month:$" << endl;
        a.misc = num;
    }
}

void display(const Expenses a)
{
    float diff, total = 0;

    diff = 500.00 - a.housBgt;
    total += a.housBgt;
    cout << "Housing ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 150.00 - a.utlBgt;
    total += a.utlBgt;
    cout << "Utilities ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 65.00 - a.housEx;
    total += a.housEx;
    cout << "Household Expenses ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 50.00 - a.transp;
    total += a.transp;
    cout << "Transportation ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 250.00 - a.food;
    total += a.food;
    cout << "Food ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 30.00 - a.medic;
    total += a.medic;
    cout << "Medical ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 100.00 - a.insur;
    total += a.insur;
    cout << "Insurance ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 150.00 - a.entert;
    total += a.entert;
    cout << "Entertainment ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 75.00 - a.cloth;
    total += a.cloth;
    cout << "Clothing ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 50.00 - a.misc;
    total += a.misc;
    cout << "Miscellaneous ";
    if (diff < 0)
    {
        cout << "Over" << endl;
    }
    else if (diff > 0)
    {
        cout << "Under" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    diff = 1420.00 - total;
    cout << "You were $";
    if (diff < 0)
    {
        diff = -1 * diff;
        cout << fixed << setprecision(2) << diff << " over budget";
    }
    else if (diff > 0)
    {
        cout << fixed << setprecision(2) << diff << " under budget";
    }
    else
    {
        cout << fixed << setprecision(2) << diff << " even budget";
    }
}
