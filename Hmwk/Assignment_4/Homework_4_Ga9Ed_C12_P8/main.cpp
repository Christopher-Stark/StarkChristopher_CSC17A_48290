/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 13, 2022, 1:16 PM
 * Purpose:
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
void arrayToFile(string, int *, int);
void fileToArray(string, int *, int);
//Execution begins here!

int main(int argc, char** argv)
{
    string file = {"binFile.dat"};//File name
    int size = 5, array[size] = {1, 2, 3, 4, 5}, array2[size],
        *aPtr = array, *aPtr2 = array2;
    
    arrayToFile(file, aPtr, size);//Prints array to binary file
    fileToArray(file, aPtr2, size);//Reads binary file into array

    return 0;
}
//Functions

/**
 * Print array to binary file
 * @param binary file name
 * @param pointer to array
 * @param array size
 */
void arrayToFile(string file, int *a, int size)
{
    fstream outFile;
    outFile.open(file, ios::out | ios::binary);
    for(int i = 0; i < size; i++)
    {
    outFile << a[i] << " ";
    }

    outFile.close();
}

/**
 * prints binary file to array
 * @param binary file name
 * @param pointer to array
 * @param array size
 */
void fileToArray(string file, int *a, int size)
{
    fstream inFile;
    inFile.open(file, ios::in);
    for(int i = 0; i < size; i++)
    {
        inFile >> a[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    inFile.close();
}
