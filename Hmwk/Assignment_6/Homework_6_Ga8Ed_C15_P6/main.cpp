/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 29, 2022, 5:18 PM
 * Purpose: Uses Gaddis GradedActivity class and derived Essay Class to det. grade
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include "GradedActivity.h"
#include "Essay.h"
//Global Constants

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    //Variables
    float gScr, sScr, lScr, cnScr;
    int maxScr = 100;
    //Get Data
    do{
     cout << "Please enter students grammar(0-30), spelling(0-20), length(20) and content(0-30) scores: ";
     cin >> gScr >> sScr >> lScr >> cnScr;
    }while(gScr > 30 || sScr > 20 || lScr > 20 || cnScr > 30); 
    //Object Class Variable
    Essay test(gScr, sScr, lScr, cnScr);
    //Display Grade
    cout << "Your score was " << test.getScore() << " out of " << maxScr << " total points." << endl;
    cout << "Your Essay grade is: " << test.getLetterGrade() << endl;
    return 0;
}
//Functions

