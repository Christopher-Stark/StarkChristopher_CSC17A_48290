/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 14, 2022, 6:30 PM
 * Purpose: Convert the lab Dynamic_1D_2D_Arrays to use all vectors.
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void fillVect(vector<vector<int>> &table, vector<int> b, int wchCol);
void fillVect(vector<int> &a,int hr, int lr, int per);
void fill2DVector(vector<vector<int>> &a, int per);
void prnt2DVect(vector<vector<int>> a);//Adjusted all functions to use vectors
void prntVect(const vector<int> a, int perLine);
void mrkSort(vector<int> a);
void smlLst(vector<int> a, int pos);
void swap(vector<int> &a, vector<int> &b);
//Program Execution Begins Here

int main(int argc, char** argv)
{
    //Set the random number seed
    srand(static_cast<unsigned int> (time(0)));

    //Declare all Variables Here
    vector<int> one;//1D Vectors
    vector<int> two;
    vector<int> three;
    int rows = 4, cols = 3;//Size for vector
    vector<vector<int>> table(rows, vector<int>(cols));//2D Vector
    int lowRng = 100, highRng = 999;
    int perLine = 4;

    //Fill each parallel vector
    fillVect(one,highRng, lowRng, perLine);
    fillVect(two,highRng / 10, lowRng / 10, perLine);
    fillVect(three,highRng / 100, lowRng / 100, perLine);

    //Sort vector for all positions
    mrkSort(one);
    mrkSort(two);
    mrkSort(three);

    //Fill the 2-D vector
    fill2DVector(table, perLine);
    fillVect(table, one, 0);
    fillVect(table, two, 1);
    fillVect(table, three, 2);

    //Print the values in the vectors
    prntVect(one, perLine);
    prntVect(two, perLine);
    prntVect(three, perLine);
    prnt2DVect(table);

    //Exit
    return 0;
}

void fillVect(vector<vector<int>> &table, vector<int> b, int wchCol)
{
    for (int row = 0; row < table.size(); row++)
    {
        table[row][wchCol] = b[row];
    }
}

void fillVect(vector<int> &a,int hr, int lr, int per)
{
    for (int indx = 0; indx < per; indx++)
    {
        a.push_back((rand() % (hr - lr + 1) + lr));
    }
}

void fill2DVector(vector<vector<int>> &a, int per)
{
    int numRows = 3;
    //Fill it with 0's
    for (int row = 0; row < per; row++)
    {
        for (int col = 0; col < numRows; col++)
        {
            a[row][col] = 0;
        }
    }
}

void prnt2DVect(vector<vector<int>> a)
{
    cout << endl << "The Vector Values" << endl;
    for (int row = 0; row < a.size(); row++)
    {
        for (int col = 0; col < a[row].size(); col++)
        {
            cout << setw(4) << a[row][col];
        }
        cout << endl;
    }
}

void prntVect(const vector<int> a, int perLine)
{
    //Print the values in the vector
    cout << endl << "The Vector Values" << endl;
    for (int indx = 0; indx < a.size(); indx++)
    {
        cout << a[indx] << " ";
        if (indx % perLine == (perLine - 1))cout << endl;
    }
    cout << endl;
}

void mrkSort(vector<int> a)
{
    for (int pos = 0; pos < a.size(); pos++)
    {
        smlLst(a,pos);
    }
}

void smlLst(vector<int> a, int pos)
{
    for (int i = pos + 1; i < a.size(); i++)
    {
        if (a[pos] > a[i])
        {
            swap(a[pos], a[i]);
        }
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

