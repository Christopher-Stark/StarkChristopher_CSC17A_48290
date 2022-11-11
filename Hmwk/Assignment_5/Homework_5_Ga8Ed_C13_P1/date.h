/* 
 * File:   date.h
 * Author: Christopher Stark
 *
 * Created on November 7, 2022, 2:58 PM
 */

#ifndef DATE_H
#define DATE_H

class Date {
private:
    int month;
    int day;
    int year;

public:
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
};

//Member Functions

void Date::setMonth(int m) {
    month = m;
}

void Date::setDay(int d) {
    day = d;
}

void Date::setYear(int y) {
    year = y;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}
#endif /* DATE_H */

