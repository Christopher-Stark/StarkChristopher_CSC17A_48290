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
float sort(int *, int);
//Execution begins here!

int main(int argc, char** argv)
{
    int size, num, *array = nullptr;
    float *ary = nullptr;
    

    cin >> size;
    //Gets data for array
    array = getData(size);
    //Prints array
    prntDat(array, size);
    //Sort array for median calculation
    //Gets data for float array
    ary = median(array, size);
    //Prints Final Float Median array
    prntMed(ary, size);

    delete []ary;
    delete []array;
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
    float median = sort(array, size);
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

float sort(int *array, int size)
{
    float median = 0.00;
    int *sortAry = new int[size];
    for(int i = 0; i < size; i++)
    {
        sortAry[i] = array[i];
        
    }
    for (int i = 0; i < size - 1; i++)
    {
        int minimumValue = i;
        for (int j = i; j < size; j++)
        {
            if (sortAry[j] < sortAry[minimumValue])
            {
                minimumValue = j;
            }
        }
        swap(sortAry[i], sortAry[minimumValue]);
    }
    if (size % 2 == 0)
    {
        median = (sortAry[(size/2)]+(sortAry[(size/2)-1]))/2.0;
    }
    else
    {
        median = sortAry[(size/2)];
    }
    delete[] sortAry;
    return median;
}
