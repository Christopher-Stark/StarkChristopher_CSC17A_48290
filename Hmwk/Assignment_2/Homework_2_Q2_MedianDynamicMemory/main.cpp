/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 20, 2022, 8:21 PM
 * Purpose: Find Median in a Dynamic float array
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
int *getData(int &);
void prntDat(int *, int);
float *median(int *, int &);
void prntMed(float *, int);
//Execution begins here!

int main(int argc, char** argv)
{
    int size, num, *array;
    float *ary;

    cin >> size;
    //Gets data for array
    array = getData(size);
    //Prints array
    prntDat(array, size);
    //Gets data for float array
    ary = median(array, size);
    //Prints Final Float Median array
    prntMed(ary, size);


    return 0;
}
//Functions

int *getData(int &size)
{
    int num;
    int *ary = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> num;
        ary[i] = num;
    }
    return ary;
}

void prntDat(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i < size - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

float *median(int *array, int &size)
{
    float median = 0.00;
    if (size % 2 == 0)
    {
        median = (array[(size/2)]+(array[(size/2)-1]))/2.0;
    }
    else
    {
        median = array[(size/2)];
        if (size == 1)
        {
            median = array[0]/2.0;
        }
    }
    size = size + 2;
    float *ary = new float[size];
    int cnt = 0;
    for (int i = 2; i < size; i++)
    {
        ary[i] = array[cnt];
        cnt++;
    }
    ary[0] = size;
    ary[1] = median;
    return ary;
}

void prntMed(float *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i >= 1)
        {
            cout << fixed << setprecision(2) << array[i];
        }
        else
        {
            cout << array[i];
        }
        if (i < size - 1)
        {
            cout << " ";
        }
    }
}
