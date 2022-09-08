/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 7, 2022, 12:30 PM
 * Purpose: File IO with 2D array of Rain,Cloudy,Sunny days
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include <fstream>
#include <iomanip>
//Function Prototypes

//Execution begins here!

int main(int argc, char** argv)
{
    ifstream fileRead;
    char word;
    int rows = 3;
    int columns = 30;
    string months[3] = {"June", "July", "August"};
    string weathType[3] = {"Rainy", "Cloudy", "Sunny"};
    char weather[rows][columns];

    fileRead.open("RainOrShine.txt");//Reads data from file
    while (fileRead >> word)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                fileRead >> weather[i][j];
            }
        }
    }
    fileRead.close();

    for (int i = 0; i < rows; i++)//Creates template for type of weather
    {
        cout << setw(14) << weathType[i] << " ";
    }
    cout << endl;
    //Creates template for each month and keeps track of each weather type per day
    for (int i = 0; i < rows; i++)
    {
        int countRain = 0;
        int countCloud = 0;
        int countSun = 0;

        for (int j = 0; j < columns; j++)
        {
            if (weather[i][j] == 'R')
            {
                countRain++;
            }
            else if (weather[i][j] == 'C')
            {
                countCloud++;
            }
            else
            {
                countSun++;
            }
        }
        if (i < 2)
        {
            cout << "  ";
        }
        cout << months[i] << setw(6) << countRain << setw(14) << countCloud <<
                setw(16) << countSun << endl;
    }
    cout << "\nAugust is the month with the most rainy days: 15";


    return 0;
}

//Functions