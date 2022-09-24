/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 23, 2022, 5:08 PM
 * Purpose: Augment 2-D Array by 1 in rows & cols
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
int **augment(const int * const *, int, int);
void destroy(int **, int, int);
//Execution begins here!

int main(int argc, char** argv)
{
    int row, col, **array = nullptr;

    //Gets data for 2D-Array
    array = getData(row, col);
    //Prints 2D-Array
    prntDat(array, row, col);
    cout << endl;
    //Augments 2D-Array
    row++, col++;
    array = augment(array, row, col);
    //Print Augmented array
    prntDat(array, row, col);
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
    for (int i = 0; i < row; i++)
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
            if (j < col - 1)
            {
                cout << " ";
            }
        }
        if ( i < row - 1)
        {
        cout << endl;
        }
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

int **augment(const int * const *array, int row, int col)//Augment the original array
{
    int rowCnt = 0, colCnt = 0, **ary = new int*[row];
    for (int i = 0; i < row; i++)
        ary[i] = new int[col];

    for (int i = 1; i < row; i++)
    {
        ary[0][0] = 0;
        ary[i][0] = 0;
        for (int j = 1; j < col; j++)
        {
            ary[i][j] = array[rowCnt][colCnt];
            ary[0][j] = 0;
            colCnt++;
        }
        colCnt = 0;
        rowCnt++;
    }
    return ary;
}
