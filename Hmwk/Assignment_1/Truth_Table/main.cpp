/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on: 9/8/2022
 * Purpose:  To tell the Truth
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void print(bool a, bool b);
//Program Execution Begins Here

int main(int argc, char** argv)
{
    //Declare all Variables Here
    bool x, y;
    int input;
    int input2;

    //Display the Heading
    cout << "X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y " <<
            " !(X||Y) !X&&!Y" << endl;

    while (cin >> input >> input2)
    {
        print(input, input2);
    }
    cout << endl;

    //Exit
    return 0;
}
//Functions

void print(bool a, bool b)
{
    bool x = a;
    bool y = b;
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
