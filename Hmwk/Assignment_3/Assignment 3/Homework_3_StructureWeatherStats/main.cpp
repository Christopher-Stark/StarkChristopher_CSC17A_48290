/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 5, 2022, 2:18 PM
 * Purpose: Structure for weather data monthly,annually
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

//User Defined Libraries

struct WthSt
{
    int size = 12;
    string month;
    float rain;
    int lTmp;
    int hTmp;
    int avgTmp;
};
//Global Constants

//Function Prototypes
void getData(WthSt a[], int &lTmp, int &hTmp, float &avRn, float &avTmp, string &lM, string &hM);
void display(const WthSt a[], int lTmp, int hTmp, float avRn, float avTmp, string lM, string hM);
//Execution begins here!

int main(int argc, char** argv)
{
    //Declare variables
    int size = 12;
    int lTmp = 140, hTmp = -100;
    float avgRn = 0, avgTmp = 0;
    string lMth, hMth;
    //Declare struct object
    WthSt mth[size];
    //Get Data
    getData(mth, lTmp, hTmp, avgRn, avgTmp, lMth, hMth);
    //Display Data
    display(mth, lTmp, hTmp, avgRn, avgTmp, lMth, hMth);

    return 0;
}
//Functions

void getData(WthSt a[], int &lTmp, int &hTmp, float &avRn, float &avTmp, string &lM, string &hM)
{
    string mt;
    float rn;
    int lTemp, hTemp;

    for (int i = 0; i < a[0].size; i++)
    {
        cin >> skipws >> mt >> rn >> lTemp >> hTemp;
        while (lTemp < -100 || hTemp > 140)
        {
            cout << "Please re-enter with temps in range of -100 to 140: ";
            cin >> skipws >> lTemp >> hTemp;
        }
        a[i].month = mt;
        a[i].rain = rn;
        a[i].lTmp = lTemp;
        a[i].hTmp = hTemp;
        a[i].avgTmp = (lTemp + hTemp) / 2;
        if (a[i].lTmp < lTmp)
        {
            lTmp = a[i].lTmp;
            lM = a[i].month;
        }
        if (a[i].hTmp > hTmp)
        {
            hTmp = a[i].hTmp;
            hM = a[i].month;
        }
        avRn += a[i].rain;
        avTmp += a[i].avgTmp;
    }
    avRn = avRn / 12;
    avTmp = avTmp / 12;
}

void display(const WthSt a[], int lTmp, int hTmp, float avRn, float avTmp, string lM, string hM)
{
    cout << fixed << setprecision(1) << "Average Rainfall " << avRn << " inches/month" << endl;
    cout << "Lowest  Temperature " << lM << "  " << lTmp << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << hM << "  " << hTmp << " Degrees Fahrenheit" << endl;
    cout << fixed << setprecision(0) << "Average Temperature for the year " << avTmp 
         << " Degrees Fahrenheit" << endl;
}
