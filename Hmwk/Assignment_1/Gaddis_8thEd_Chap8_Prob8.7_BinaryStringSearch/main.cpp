/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on January 7, 2022, 1:16 PM
 * Purpose: Change Binary search to use string instead of int
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Global Constants
const int NUM_NAMES = 20;
//Function Prototypes
void displayArray(string names[], int size);
void sortArray(string names[], int size);
void adjustArray(string &index, string &index2);
int binarySearch(string names[], int size, string userInput);
void outputLocation(int location);
//Execution begins here!

int main(int argc, char** argv)
{
    string lastName;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill",
        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
        "James, Jean", "Weaver, Jim", "Pore, Bob",
        "Rutherford, Greg", "Javens, Renee",
        "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth"};

    cout << "Before sort: \n";
    displayArray(names, NUM_NAMES);
    sortArray(names, NUM_NAMES);
    cout << "\nAfter sort: \n";
    displayArray(names, NUM_NAMES);

    cout << "Please enter a name: ";
    getline(cin, lastName);
    outputLocation(binarySearch(names, NUM_NAMES, lastName));
    //Binary search function
    return 0;
}
//Functions

/**
 * Displays array
 * @param name
 * @param size
 */
void displayArray(string names[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << names[i] << endl;
    }
}

/**
 * sorts array by last name
 * @param names
 * @param size
 */
void sortArray(string names[], int size)
{
    int index;
    string compare;

    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        compare = names[i];
        for (int j = index + 1; j < size; j++)
        {
            if (names[j] < compare)
            {
                compare = names[j];
                index = j;
            }
        }
        adjustArray(names[index], names[i]);
    }
}

/**
 * takes index of array and swaps with second index
 * @param index
 * @param index2
 */
void adjustArray(string &index, string &index2)
{
    string temp = index;
    index = index2;
    index2 = temp;
}

/**
 * Binary search method of array of names
 * @param names
 * @param size
 * @param userInput
 * @return index location of user specified name starting at index 0
 */
int binarySearch(string names[], int size, string userInput)
{
    int low = 0;
    int high = size - 1;
    int middleNum = (low + high) / 2;
    string compCheck = names[middleNum];

    while (compCheck != userInput && low <= high)
    {
        if (compCheck < userInput)
        {
            low = middleNum + 1;
            middleNum = (low + high) / 2;
            compCheck = names[middleNum];
        }
        else
        {
            high = middleNum - 1;
            middleNum = (low + high) / 2;
            compCheck = names[middleNum];
        }
    }
    if (low > high)
    {
        return -1;
    }
    else
    {
        return middleNum;
    }
}

/**
 * Outputs an index location for an array with error checking
 * @param location
 */
void outputLocation(int location)
{
    if (location == -1)
    {
        cout << "That name was not found";
    }
    else
    {
        cout << "That name is located at index: " << location << endl;
    }
}


