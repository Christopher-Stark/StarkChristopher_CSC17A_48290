/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on January 8, 2022, 2:55 AM
 * Purpose: Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here
#include <algorithm>
//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int read(char array[][COLMAX],int &size);//Outputs row and columns detected from input
void sort(char array[][COLMAX],int rowSize,int colSize);//Sort by row
void print(const char array[][COLMAX],int rowSize,int colSize);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    char input;
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now input the array."<<endl;
    for (int i = 0; i < colIn; i++)
    {
        for (int j = 0; j < rowIn; j++)
        {
            cin >> input;
            array[j][i] = input;
        }
    }
    //print(array,rowIn,colIn);//Test
    rowDet=rowIn;
    colDet=read(array,rowDet);
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);//Sort not working
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
//Functions
int read(char array[][COLMAX],int &rowSize)
{
    int size = rowSize / sizeof(array[0][0]);
    return size;
}
void sort(char array[][COLMAX],int rowSize,int colSize)
{
    int num = 2;
    for (int i = 0; i < colSize; i++)
    {
        for (int j = rowSize-1; j > 1; j--)
        {
           if(array[rowSize-1][i] < array[j-2][i] && rowSize != 1)
            {
                char temp = array[rowSize-1][i];
                array[rowSize-1][i] = array[j-2][i];
                array[j-2][i] = temp;
            }
            
        }
    }
}
void print(const char array[][COLMAX],int rowSize,int colSize)
{
   for (int i = 0; i < rowSize; i++)
   {
       for (int j = 0; j < colSize; j++)
       {
           cout << array[i][j];
       }
       cout << endl;
   }
}