/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 20, 2022, 11:50 AM
 * Purpose: Takes time.h from gaddis and creates derived class MilTime to conv
 * to military time
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries
#include "Time.h"
#include "MilTime.h"
//Global Constants

//Function Prototypes

//Execution begins here!

int main(int argc, char** argv){
    //Variables
    int milHrs, milSecs;
    //Get Data
    do{
        cout << "Please enter military time hours: ";
        cin >> milHrs;
        cout << "Please enter military time secs: ";
        cin >> milSecs;
    }while(milHrs < 0 || milHrs > 2359 || milSecs < 0 || milSecs > 59 || 
           milHrs % 100 > 59);
    //Object Variable
    MilTime test(milHrs, milSecs);
    //Display Data
    cout << "Military Time = " << setfill('0') << setw(4) <<  test.getHour() 
         << ":" << test.getSec() << endl;
    cout << "Standard Time = ";
    if(test.getStandHr() <= 12){
        cout << test.getStandHr() << ":";
    }else{
        cout << test.getStandHr() - 12 << ":";
    }
    if(test.getMin() == 0){
        cout << test.getMin() << "0:";
    }else{
        cout << test.getMin() << ":";
    }
    cout << test.getSec();
    if(test.getStandHr() <= 12){
        cout << " AM";
    }else{
        cout << " PM";
    }

    return 0;
}
//Functions

