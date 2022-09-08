/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on January 7, 2022, 5:40 PM
 * Purpose: Truth Table
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
void truthTable(int input, int input2);
//Execution begins here!

int main(int argc, char** argv)
{
    cout << "X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y " <<
            " !(X||Y) !X&&!Y" << endl;

    int input1 = 1;
    int input2 = 0;
    //First Row
    truthTable(input1, input2);
    //Second Row
    input1 = 0;
    input2 = 1;
    truthTable(input1, input2);
    return 0;
}
//Functions
/**
 * Takes in input for truth false values on truth table
 * @param input
 * @param input2
 */
void truthTable(int input, int input2)
{
    bool x, y;
    if (input == 0)
    {
        x = false;
    }
    else
    {
        x = true;
    }
    if (input2 == 0)
    {
        y = false;
    }
    else
    {
        y = true;
    }
    cout << (x ? 'T' : 'F') << " "
            << (y ? 'T' : 'F') << "  "
            << (!x ? 'T' : 'F') << "  "
            << (!y ? 'T' : 'F') << "   "
            << (x && y ? 'T' : 'F') << "    "
            << (x || y ? 'T' : 'F') << "   "
            << (x^y ? 'T' : 'F') << "    "
            << (x^y^x ? 'T' : 'F') << "     "
            << (x^y^y ? 'T' : 'F') << "       "
            << (!(x && y) ? 'T' : 'F') << "      "
            << (!x || !y ? 'T' : 'F') << "        "
            << (!(x || y) ? 'T' : 'F') << "      "
            << (!x&&!y ? 'T' : 'F') << "\n";
}