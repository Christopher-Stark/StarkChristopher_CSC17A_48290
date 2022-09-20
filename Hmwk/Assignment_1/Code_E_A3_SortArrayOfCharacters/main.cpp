/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on January 8, 2022, 11:50 AM
 * Purpose: Sort array of characters
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here
#include <algorithm>
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int read(char array[]);
void sort(char array[], int size);
void print(const char array[], int size);

//Program Execution Begins Here

int main(int argc, char** argv)
{
    //Declare all Variables Here
    const int SIZE = 80; //Larger than needed
    char array[SIZE];//Character array larger than needed
    char input;
    int index = 0;
    int sizeIn, sizeDet; //Number of characters to be read, check against length

    //Input the size of the array you are sorting
    cout << "Read in a 1 dimensional array of characters and sort" << endl;
    cout << "Input the array size where size <= 20" << endl;
    cin>>sizeIn;
    while (cin >> input)
    {
        array[index] = input;
        index++;
    }

    //Now read in the array of characters and determine it's size
    cout << "Now read the Array" << endl;
    sizeDet = read(array); //Determine it's size

    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if (sizeDet == sizeIn)
    {
        sort(array, sizeIn); //Sort the array
        print(array, sizeIn); //Print the array
    }
    else
    {
        cout << (sizeDet < sizeIn ? "Input size less than specified." :
                "Input size greater than specified.") << endl;
    }

    //Exit
    return 0;
}

int read(char array[])
{
    int sizeOfArray = strlen(array);
    return sizeOfArray;
}

void sort(char array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[i])
            {
                char temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void print(const char array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
    }
    cout << endl;
}