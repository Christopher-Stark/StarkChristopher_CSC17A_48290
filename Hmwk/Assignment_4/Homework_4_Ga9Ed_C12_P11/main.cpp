/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 13, 2022, 2:45 PM
 * Purpose: Print Corp.Sales data for each qtr. to file
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//User Defined Libraries
struct Sales
{
    string name[4] = {"North", "East", "South", "West"};
    int qtr[4] = {1,2,3,4};
    float qSales[4];
};
//Global Constants

//Function Prototypes
void binFile(Sales dSales);
//Execution begins here!
int main(int argc, char** argv) 
{
    float sales, size = 4;
    Sales dSales;//Struct object
    
    for(int i = 0; i < size; i++)
    {
        //Displays division
        cout << "Please enter each quarter sales for " << dSales.name[i] << " division:" << endl;
        for(int j = 0; j < size; j++)
        {
           cout << "Quarter " << dSales.qtr[j] << ":";//Displays quarter
           cin >> sales;
           while(sales < 0)//Error checking for positive value
           {
               cout << "Please enter a positive sales value:";
               cin >> sales;
           }
           dSales.qSales[j] = sales;//Inputs user info into sales
        }
        cout << endl;
    }
    binFile(dSales);//Writes struct object dSales to bin file
    return 0;
}
//Functions
/**
 * Writes struct to bin file
 * @param dSales - division sales of structure
 */
void binFile(Sales dSales)
{
    fstream outFile;
    string file = {"DivSales.dat"};
    
    outFile.open(file,ios::out|ios::binary);
    outFile.write(reinterpret_cast<char *>(&dSales), sizeof(dSales));
    
    outFile.close();
}

