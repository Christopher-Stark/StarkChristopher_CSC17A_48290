/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 5, 2022, 12:38 PM
 * Purpose: Determines the increase in population of an organism
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Function Prototypes

//Execution begins here!

int main(int argc, char** argv)
{
    int sizePop;
    int popIncr;
    int numDays;

    while (sizePop < 2)
    {
        cout << "What is the starting amount of organisms(greater than 2): ";
        cin >> sizePop;
    }
    while (popIncr < 0)
    {
        cout << "What is the daily population increase(non negative): ";
        cin >> popIncr;
    }
    while (numDays < 1)
    {
        cout << "How many days will they multiply (greater than 0): ";
        cin >> numDays;
    }

    int adjPop = sizePop;

    for (int i = 1; i <= numDays; i++)
    {
        cout << "The population on day " << i << " is: " << adjPop << endl;
        adjPop += popIncr;
    }
}
//Functions

