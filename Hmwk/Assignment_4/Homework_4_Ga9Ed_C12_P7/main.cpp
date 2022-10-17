/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 12, 2022, 5:50 PM
 * Purpose: Filter sentences from File
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution begins here!

int main(int argc, char** argv)
{
    fstream inFile, outFile;
    string user, nonBina = {"nonBin.txt"};
    char fileCh;
    int num = 1;
    bool upper = true;//bool used for tracking beg. sentence

    cout << "Please enter the file name 'inputFile.txt' to grab file data: ";
    cin >> user;
    inFile.open(user, ios::in);//File already created with test sentences
    while (!inFile)//Error checking for correct file name
    {
        cout << "Please enter correct file name 'inputFile.txt': ";
        cin >> user;
        inFile.open(user, ios::in);
    }
    outFile.open(nonBina, ios::out);

    inFile.get(fileCh);
    while (!inFile.eof())
    {
        if (fileCh == ' ' || fileCh == '\n' || fileCh == '\r')
        {
            outFile.put(fileCh);
        }
        else if (upper)
        {
            outFile.put(toupper(fileCh));
            upper = false;//Triggers lower casing until beg. of sentence
        }
        else
        {
            outFile.put(tolower(fileCh));
        }
        if (fileCh == '.')
        {
            upper = true;//Triggers the start of a new sentence for upper
        }
        inFile.get(fileCh);
    }

    inFile.close();
    outFile.close();
    return 0;
}
//Functions

