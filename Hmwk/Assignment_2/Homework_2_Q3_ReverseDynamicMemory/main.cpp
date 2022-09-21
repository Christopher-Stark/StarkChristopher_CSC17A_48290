/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 20, 2022, 10:30 PM
 * Purpose: Reverse a sorted Dynamic Array
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
int *getData(int &);
int *sort(int *, int);
int *reverse(int *, int);
void prntDat(int *, int);
//Execution begins here!

int main(int argc, char** argv)
{
    int size, num, *array, *sortAry;

    cin >> size;
    //Gets data for array
    array = getData(size);
    //Sorts array
    array = sort(array, size);
    //Prints sorted array
    prntDat(array, size);
    cout << endl;
    //Reverse
    reverse(array, size);
    //Print reverse
    prntDat(array, size);



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

int *sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minimumValue = i;
        for (int j = i; j < size; j++)
        {
            if (array[j] < array[minimumValue])
            {
                minimumValue = j;
            }
        }
        swap(array[i], array[minimumValue]);
    }
    return array;
}

int *reverse(int *array, int size)
{
    int temp;
    int start = 0;
    int finish = size - 1;
    while (start < finish)
    {
        temp = array[start];
        array[start] = array[finish];
        array[finish] = temp;
        start++;
        finish--;
    }
    return array;
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
}
