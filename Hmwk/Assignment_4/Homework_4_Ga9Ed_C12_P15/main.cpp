/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 13, 2022, 5:55 PM
 * Purpose: Read a file and determines the average amount of words per line
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution begins here!

int main(int argc, char** argv)
{
    fstream fileIn;
    string file = {"text.txt"};//I made my own file for this program
    char fileCh;//Reading in every char
    int numWrds = 0, line = 0;
    float avg = 0.00f;//Calculates average

    fileIn.open(file, ios::in);
    fileIn.get(fileCh);
    while (!fileIn.eof())
    {
        if(fileCh == ' ')
        {
            numWrds++;
        }
        else if (fileCh == '.')//Counts new line
        {
            line++;
            numWrds++;
        }
        if(fileCh == '?')
        {
            line++;
        }
        fileIn.get(fileCh);
    }
    
    avg = (static_cast<float>(numWrds) / static_cast<float>(line));//
    cout << "The amount of words is " << numWrds << " and there are " << line << " lines." << endl;
    cout << "The average number of words per line is: " << fixed << setprecision(2) << avg;

    fileIn.close();
    return 0;
}
//Functions

