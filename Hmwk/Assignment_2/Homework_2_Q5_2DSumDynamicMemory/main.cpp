/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 23, 2022, 3:24 PM
 * Purpose: Determine the Sum of a 2-D Array using Dynamic Memory
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
int **getData(int &, int &);
void prntDat(const int* const *, int, int);
void destroy(int **, int, int);
int sum(const int * const *, int, int);
//Execution begins here!

int main(int argc, char** argv)
{
    int row, col, arySum, **array = nullptr;

    //Gets data for 2D-Array
    array = getData(row, col);
    //Prints 2D-Array
    prntDat(array, row, col);
    //Gets 2D-Array Sum
    arySum = sum(array, row, col);
    cout << arySum;
    //De-allocate 2D memory
    destroy(array, row, col);


    return 0;
}
//Functions

int **getData(int &row, int &col)//Return the 2-D array and its size.
{
    int num;
    
    cin >> num;
    row = num;
    cin >> num;
    col = num;
    
    int **ary = new int*[row];
    for(int i = 0; i < row; i++)
        ary[i] = new int[col];
        
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> num;
            ary[i][j] = num;
        }
    }
    return ary;
}

void prntDat(const int* const * array, int row, int col)//Print the 2-D Array
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << array[i][j];
            if ( j < col -1)
            {
                cout << " ";
            }
        }
            cout << endl;
    }
}

void destroy(int **array, int row, int col)//De-allocate memory
{
    for (int i = 0; i < row; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

int sum(const int * const *array, int row, int col)//Return the Sum
{
    int arySum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arySum += array[i][j];
        }
    }
    return arySum;
}
