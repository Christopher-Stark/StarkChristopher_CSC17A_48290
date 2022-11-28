/* 
 * File:   DayOfYear.h
 * Author: Chris Stark
 *
 * Created on November 23, 2022, 12:38 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

class DayOfYear {
private:
    int day;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"};
    int lastDay[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    static string month;
    static int mntDay;
public:
    //constructor
    DayOfYear();
    DayOfYear(int);
    //Accessor
    int getDay() const;
    //Functions
    void print();
};
//Set static
string DayOfYear::month = "";
int DayOfYear::mntDay = 0;
//Member Functions

DayOfYear::DayOfYear(int n) {
    day = n;
}

int DayOfYear::getDay() const {
    return day;
}

void DayOfYear::print() {
    int num = 0;

    while (lastDay[num] < day) {//Find correct month
        num++;
    }

    month += months[num - 1]; //Sets print string to correct month
    mntDay += day - lastDay[num - 1]; //Find specific day in month

    //Display
    cout << "That day in the year is: " << month << " " << mntDay << ".";
}

#endif /* DAYOFYEAR_H */

