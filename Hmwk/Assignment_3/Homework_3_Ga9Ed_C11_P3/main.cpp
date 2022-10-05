/* 
 * File:  main.cpp 
 * Author: Christopher Stark
 * Created on 28,Sep. 2022
 * Purpose:  Store Structure Data
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct QSales
{
    int size;
    string month[4] = {"North","West","East","South"}; 
    float *quarters, totQ, avgQ;
};
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    QSales north;
    QSales east;
    QSales south;
    QSales west;
    float num;
    int size = 4, cnt = 0;
    north.size=size, east.size=size, south.size=size ,west.size=size;
    north.quarters = new float[size],east.quarters = new float[size];
    south.quarters = new float[size],west.quarters = new float[size];
    
    //Initialize Variables & Declare Outputs
    cout << "North" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> num;
    north.quarters[cnt] = num;
    cnt++;
    cout << "Enter second-quarter sales:" << endl;
    cin >> num;
    north.quarters[cnt] = num;
    cnt++;
    cout << "Enter third-quarter sales:" << endl;
    cin >> num;
    north.quarters[cnt] = num;
    cnt++;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> num;
    north.quarters[cnt] = num;
    cnt++;
    cout << "Total Annual sales:$";
    north.totQ = north.quarters[0] + north.quarters[1] + north.quarters[2] + north.quarters[3];
    cout << fixed << setprecision(2) << north.totQ << endl;
    cout << "Average Quarterly Sales:$";
    north.avgQ = (north.quarters[0] + north.quarters[1] + north.quarters[2] + north.quarters[3]) / 4;
    cout << fixed << setprecision(2) << north.avgQ << endl;
    cnt = 0;
    
    cout << "West" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> num;
    west.quarters[cnt] = num;
    cnt++;
    cout << "Enter second-quarter sales:" << endl;
    cin >> num;
    west.quarters[cnt] = num;
    cnt++;
    cout << "Enter third-quarter sales:" << endl;
    cin >> num;
    west.quarters[cnt] = num;
    cnt++;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> num;
    west.quarters[cnt] = num;
    cnt++;
    cout << "Total Annual sales:$";
    west.totQ = west.quarters[0] + west.quarters[1] + west.quarters[2] + west.quarters[3];
    cout << fixed << setprecision(2) << west.totQ << endl;
    cout << "Average Quarterly Sales:$";
    west.avgQ = (west.quarters[0] + west.quarters[1] + west.quarters[2] + west.quarters[3]) / 4;
    cout << fixed << setprecision(2) << west.avgQ << endl;
    cnt = 0;
    
    
    cout << "East" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> num;
    east.quarters[cnt] = num;
    cnt++;
    cout << "Enter second-quarter sales:" << endl;
    cin >> num;
    east.quarters[cnt] = num;
    cnt++;
    cout << "Enter third-quarter sales:" << endl;
    cin >> num;
    east.quarters[cnt] = num;
    cnt++;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> num;
    east.quarters[cnt] = num;
    cnt++;
    cout << "Total Annual sales:$";
    east.totQ = east.quarters[0] + east.quarters[1] + east.quarters[2] + east.quarters[3];
    cout << fixed << setprecision(2) << east.totQ << endl;
    cout << "Average Quarterly Sales:$";
    east.avgQ = (east.quarters[0] + east.quarters[1] + east.quarters[2] + east.quarters[3]) / 4;
    cout << fixed << setprecision(2) << east.avgQ << endl;
    cnt = 0;
    
    
    cout << "South" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> num;
    south.quarters[cnt] = num;
    cnt++;
    cout << "Enter second-quarter sales:" << endl;
    cin >> num;
    south.quarters[cnt] = num;
    cnt++;
    cout << "Enter third-quarter sales:" << endl;
    cin >> num;
    south.quarters[cnt] = num;
    cnt++;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> num;
    south.quarters[cnt] = num;
    cnt++;
    cout << "Total Annual sales:$";
    south.totQ = south.quarters[0] + south.quarters[1] + south.quarters[2] + south.quarters[3];
    cout << fixed << setprecision(2) << south.totQ << endl;
    cout << "Average Quarterly Sales:$";
    south.avgQ = (south.quarters[0] + south.quarters[1] + south.quarters[2] + south.quarters[3]) / 4;
    cout << fixed << setprecision(2) << south.avgQ;
    cnt = 0;
    
    //Exit stage right!
    delete[] north.quarters;
    delete[] east.quarters;
    delete[] south.quarters;
    delete[] west.quarters;
    return 0;
}

void fillAry(QSales &a, int &cnt)
{
    for(int i = 0; i < a.size; i++)
    {
        
    }
}

void prntAry(const QSales)
{
    
}
