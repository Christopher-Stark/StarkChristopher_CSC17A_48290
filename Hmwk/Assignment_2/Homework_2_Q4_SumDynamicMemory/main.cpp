/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 23, 2022, 12:55 PM
 * Purpose:Determine the sum of a array with Dynamic Memory
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
int *getData(int &);
int *sumAry(const int *, int);
void prntAry(const int *, int);
//Execution begins here!

int main(int argc, char** argv)
{
    int size; 
    const int *array = nullptr;
    const int *smAry = nullptr;
    
    //Gets data for array
    array = getData(size);
    //Print array
    prntAry(array, size);
    cout << endl;
    //Gets consec sum array
    smAry = sumAry(array, size);
    //Prints sum array
    prntAry(smAry, size); 
    
    delete[] array;
    delete[] smAry;
    return 0;
}
//Functions

int *getData(int &size)//Return the array size and the array from the inputs
{
    int num;
    cin >> num;
    size = num;
    int *ary = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> num;
        ary[i] = num;
    }
    return ary;
}

int *sumAry(const int *array, int size)//Return the array with successive sums
{
    int sum, *ary = new int[size];
    for (int i = 0; i < size; i++)
    {
        ary[i] = array[i];
    }
    for (int i = 0; i < size - 1; i++)
    {
        sum = 0;
        sum = ary[i]+ary[i+1];
        ary[i+1] = sum;
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

