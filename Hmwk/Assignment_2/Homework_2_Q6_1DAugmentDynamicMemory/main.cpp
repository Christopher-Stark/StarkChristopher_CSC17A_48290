/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 23, 2022, 4:49 PM
 * Purpose: 1D Augment of Dynamic Array
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
int *getData(int &);
int *augment(const int *, int);
void prntAry(const int *, int);
//Execution begins here!

int main(int argc, char** argv)
{
    int size, *array = nullptr;

    //Gets array data
    array = getData(size);
    //Prints array
    prntAry(array, size);
    cout << endl;
    //Augments array by 1
    array = augment(array, size);
    //Prints 1-augmented array
    size++;
    prntAry(array, size);

    delete[] array;
    return 0;
}
//Functions

int *getData(int &size)//Read the array
{
    int num, *ary = new int [size];
    cin >> num;
    size = num;

    for (int i = 0; i < size; i++)
    {
        cin >> num;
        ary[i] = num;
    }
    return ary;
}

int *augment(const int *array, int size)//Augment and copy the original array
{
    int cnt, *ary = new int[size + 1];
    ary[0] = 0;
    cnt = 0;
    for (int i = 1; i < size + 1; i++)
    {
        ary[i] = array[cnt];
        cnt++;
    }
    return ary;
}

void prntAry(const int *array, int size)//Print the array
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i < size - 1)
        {
            cout << " ";
        }
    }
}
