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
    string userMn;
    int mnIndex;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"};
    int lastDay[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int dayInMn[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static string month;
    static int mntDay;
public:
    //constructor
    DayOfYear();
    DayOfYear(int);
    DayOfYear(int, string);
    //Accessor
    int getDay() const;
    //Functions
    void getDaysInMonth();
    void print();
    DayOfYear operator++();
    DayOfYear operator--();
};
//Set static
string DayOfYear::month = "";
int DayOfYear::mntDay = 0;
//Member Functions

DayOfYear::DayOfYear(int n) {
    day = n;
}

DayOfYear::DayOfYear(int n, string m) {
    day = n;
    userMn = m;
    mnIndex = stoi(userMn) - 1;
}

int DayOfYear::getDay() const {
    return day;
}

void DayOfYear::getDaysInMonth() {
    int num = stoi(userMn) - 1;
    if (dayInMn[num] < day) {//Terminates if invalid days in that month
        cout << "Not the correct amount of days in that month!" << endl;
        exit(0);
    }
}

DayOfYear DayOfYear::operator++() {
    int size = 12;

    if (mnIndex == 11 && day == 31) {
        day = 1;
        mnIndex = 0;
    } else {
        if (dayInMn[mnIndex] == day) {
            mnIndex++;
            day = 1;
        } else {
            day++;
        }
    }

    return *this;
}

DayOfYear DayOfYear::operator--() {
    int size = 12;

    if (mnIndex == 0 && day == 1) {
        day = 31;
        mnIndex = 11;
    } else {
        if (day == 1 && mnIndex != 0) {
            mnIndex--;
            day = dayInMn[mnIndex];
        } else {
            day--;
        }
    }

    return *this;
}

void DayOfYear::print() {
    getDaysInMonth(); //Checks for correct days in month, if not exits

    //Display
    cout << "That day in the year is: " << months[mnIndex] << " " << day << "." << endl;
}

#endif /* DAYOFYEAR_H */

