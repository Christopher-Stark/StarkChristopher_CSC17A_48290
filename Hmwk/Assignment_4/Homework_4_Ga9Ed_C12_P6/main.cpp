/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 13, 2022, 5:00 PM
 * Purpose: search for specified string in file
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    fstream fileIn;
    string user, str;
    int strFnd = 0;
    int lineNum = 0;
    cout << "Please enter the file name 'nonBin.txt' to search for a string:";
    cin >> user;
    fileIn.open(user, ios::in);
    
    while(!fileIn)//Error checking for correct file
    {
        cout << "Please enter correct file name 'nonBin.txt':";
        cin >> user;
        fileIn.open(user, ios::in);
    }
    
    cout << "Enter a string to search for within the file:";
    cin >> user;//The users string to search for
    getline(fileIn, str);//Gets first line in file
    
    while(!fileIn.eof())
    {
        lineNum++;//Counter for line
        bool find = false;//Bool for finding string
        int pos = str.find(user);//string.find function to find the position of the found string
        
        while(pos >= 0)//While string is found
        {
           find = true;
           strFnd++;//Counter for finding string
           str = str.substr(pos+user.length());//Returns end of found string
           pos = str.find(user);//Cont. searching for string
        }
        if(find)
        {
            cout << "Your string " << user << " was in line " << lineNum << endl;
        }
        getline(fileIn, str);//Gets next line
    }
    
    cout << "That string appeared " << strFnd << " times." << endl;
    fileIn.close();
    return 0;
}
//Functions

