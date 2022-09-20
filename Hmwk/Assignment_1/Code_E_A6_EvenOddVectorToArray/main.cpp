/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on 9/12/2022
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 2; //Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &even, vector<int> &odd, int size);
void copy(vector<int> even, vector<int> odd, int array[][COLMAX]);
void prntVec(vector<int> even, vector<int> odd, int num); //int n is the format setw(n)
void prntAry(const int array[][COLMAX], int evenSize, int oddSize, int num);

//Program Execution Begins Here

int main(int argc, char** argv)
{
    //Declare all Variables Here
    const int ROW = 80; //No more than 80 rows
    int array[ROW][COLMAX]; //Really, just an 80x2 array, even vs. odd
    vector<int> even(0), odd(0); //Declare even,odd vectors
    int size;

    //Input data and place even in one vector odd in the other
    cout << "Input the number of integers to input." << endl;
    cin >> size;
    cout << "Input each number." << endl;
    read(even, odd, size);

    //Now output the content of the vectors
    //          setw(10)
    prntVec(even, odd, 10); //Input even, odd vectors with setw(10);

    //Copy the vectors into the 2 dimensional array
    copy(even, odd, array);

    //Now output the content of the array
    //                              setw(10)
    prntAry(array, even.size(), odd.size(), 10); //Same format as even/odd vectors

    //Exit
    return 0;
}
//Functions

void read(vector<int> &even, vector<int> &odd, int size)
{
    int input;
    for (int i = 0; i < size; i++)
    {
        cin >> input;
        if (input % 2 == 0)
        {
            even.push_back(input);
        }
        else
        {
            odd.push_back(input);
        }
    }
}

void copy(vector<int> even, vector<int> odd, int array[][COLMAX])
{
    int oddRow = odd.size();
    int evenRow = even.size();

    for (int i = 0; i < evenRow; i++)
    {
        array[i][0] = even[i];
    }
    for (int i = 0; i < oddRow; i++)
    {
        array[i][1] = odd[i];
    }
}

void prntVec(vector<int> even, vector<int> odd, int num)//int n is the format setw(n)
{
    int loops;
    if (even.size() > odd.size())
    {
        loops = even.size();
    }
    else
    {
        loops = odd.size();
    }

    cout << setw(num) << "Vector" << setw(num) << "Even" << setw(num) << "Odd" << endl;
    for (int i = 0; i < loops; i++)
    {
        if (i < even.size())
        {
            cout << setw(num * 2) << even[i];
        }
        else
        {
            cout << setw(num * 2) << " ";
            if(i > odd.size()) cout << endl;
        }
        if(i < odd.size())
        {
        cout << setw(num) << odd[i] << endl;
        }
        else
        {
            cout << setw(num) << " " << endl;
        }
    }
}

void prntAry(const int array[][COLMAX], int evenSize, int oddSize, int num)
{
    int loops;
    if (evenSize > oddSize)
    {
        loops = evenSize;
    }
    else
    {
        loops = oddSize;
    }
    cout << setw(num) << "Array" << setw(num) << "Even" << setw(num) << "Odd" << endl;
    for (int i = 0; i < loops; i++)
    {
        if (i < evenSize)
        {
            cout << setw(num * 2) << array[i][0];
        }
        else
        {
            cout << setw(num * 2) << " ";
            if(i > oddSize) cout << endl;
        }
        if(i < oddSize)
        {
        cout << setw(num) << array[i][1] << endl;
        }
        else
        {
            cout << setw(num) << " " << endl;
        }
    }
}