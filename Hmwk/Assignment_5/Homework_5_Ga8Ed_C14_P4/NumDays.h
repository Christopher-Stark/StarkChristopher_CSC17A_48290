/* 
 * File:   NumDays.h
 * Author: Chris Stark
 *
 * Created on November 27, 2022, 4:50 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
private:
    float hours;
    float days;
public:
    //Constructors
    NumDays();
    NumDays(float);
    //Accessors
    float getDays() const;
    float getHours() const;
    //Mutators
    void setDays();
    void setHours(float);
    //Operators
    NumDays operator+(const NumDays &);
    NumDays operator-(const NumDays &);
    NumDays operator++();
    NumDays operator--();
};
//Member Functions
NumDays::NumDays(){
    hours = 0;
    days = 0;
}

NumDays::NumDays(float h){
    hours = h;
    setDays();
}

float NumDays::getDays() const{
    return days;
}

float NumDays::getHours() const{
    return hours;
}

void NumDays::setDays(){
    int day = 8;
    days = hours / day;
}
void NumDays::setHours(float h){
    hours = h; 
}

NumDays NumDays::operator +(const NumDays &a){
    NumDays temp;
    temp.hours = hours + a.hours;
    temp.days = days + a.days;
    
    return temp;
}

NumDays NumDays::operator -(const NumDays &a){
    NumDays temp;
    temp.hours = hours - a.hours;
    temp.days = days - a.days;
    
    return temp;
}

NumDays NumDays::operator ++(){
    hours++;
    setDays();
    return *this;
}

NumDays NumDays::operator --(){
    hours--;
    setDays();
    return *this;
}
#endif /* NUMDAYS_H */

