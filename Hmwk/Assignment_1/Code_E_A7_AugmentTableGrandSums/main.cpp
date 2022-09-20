/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created: 9/12/2022 7:16PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 80; //Max Columns much larger than needed.

//Function Prototypes Here
void read(int array[][COLMAX], int &row, int &col); //Prompt for size then table
void sum(const int array[][COLMAX], int row, int col, int augAry[][COLMAX]); //Sum rows,col,grand total
void print(const int array[][COLMAX], int row, int col, int num); //Either table can be printed

//Program Execution Begins Here

int main(int argc, char** argv)
{
    //Declare all Variables Here
    const int ROW = 80; //Max Rows much larger than needed
    int array[ROW][COLMAX] = {}; //Declare original array
    int augAry[ROW][COLMAX] = {}; //Actual augmented table row+1, col+1
    int row, col;

    //Input the original table
    read(array, row, col);

    //Augment the original table by the sums
    sum(array, row, col, augAry);

    //Output the original array
    cout << endl << "The Original Array" << endl;
    print(array, row, col, 10); //setw(10)

    //Output the augmented array
    cout << endl << "The Augmented Array" << endl;
    print(augAry, row + 1, col + 1, 10); //setw(10)

    //Exit
    return 0;
}
//Functions

void read(int array[][COLMAX], int &row, int &col)//Prompt for size then table
{
    int input;
    cout << "Input a table and output the Augment row,col and total sums." << endl;
    cout << "First input the number of rows and cols. <20 for each" << endl;
    cin >> row >> col;
    cout << "Now input the table." << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> input;
            array[i][j] = input;
        }
    }
}

void sum(const int array[][COLMAX], int row, int col, int augAry[][COLMAX])//Sum rows,col,grand total
{
    int grandSum = 0;
    for (int i = 0; i < row; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < col; j++)
        {
            int colSum = 0;
            rowSum += array[i][j];
            grandSum += array[i][j];
            augAry[i][j] = array[i][j];
            for (int k = 0; k < row; k++)
            {
                colSum += array[k][j];
                if (k == row - 1)
                {
                    augAry[k + 1][j] = colSum;
                    if (j == col - 1)
                    {
                        augAry[k + 1][j + 1] = grandSum;
                    }
                }
            }
            if (j == col - 1)
            {
                augAry[i][j + 1] = rowSum;
            }
        }
    }
}

void print(const int array[][COLMAX], int row, int col, int num)//Either table can be printed
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(num) << array[i][j];
        }
        cout << endl;
    }
}