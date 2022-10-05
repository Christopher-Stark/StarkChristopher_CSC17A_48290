/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 4, 2022, 1:00 PM
 * Purpose: Enumerated data type for array of structures
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries
struct WeaStat
{
    float tRain;
    float hTmp;
    float lTmp;
    float avgTmp;
};
enum Months 
{
    JANUARY, FEBUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};
    
//Global Constants

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) 
{
    int size = 12, cnt = 0;
    float num, avgRain = 0, avgTemp = 0, highTmp = -100, lowTmp = 140;
   WeaStat mthStat[size];
   Months month = JANUARY;
   
   while(cin >> num)
   {
       cout << "Enter the total rainfall for the month:" << endl;
       mthStat[month].tRain = num;
       cout << "Enter the high temp:" << endl;
       cin >> num;
       mthStat[month].hTmp = num;
       if (num > highTmp)
       {
           highTmp = num;
       }
       cout << "Enter the low temp:" << endl;
       cin >> num;
       mthStat[month].lTmp = num;
       if (num < lowTmp)
       {
           lowTmp = num;
       }
       mthStat[month].avgTmp = (mthStat[month].hTmp + mthStat[month].lTmp) / 2;
       month = static_cast<Months>(month + 1);
       cnt++;
   }
   
   for (month = JANUARY; month <= cnt; month = static_cast<Months>(month + 1))
   {
       avgRain += mthStat[month].tRain;
       avgTemp += mthStat[month].avgTmp;
   }
   avgRain = avgRain / cnt;
   avgTemp = avgTemp / cnt;
   
   cout << fixed << setprecision(2) << "Average monthly rainfall:" << avgRain << endl;
   cout << fixed << setprecision(0) << "High Temp:" << highTmp << endl;
   cout << fixed << setprecision(0) << "Low Temp:" << lowTmp << endl;
   cout << fixed << setprecision(1) << "Average Temp:" << avgTemp;
   
    return 0;
}
//Functions

