/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 20, 2022, 11:50 AM
 * Purpose: Takes time.h from gaddis and creates derived class MilTime to conv
 * to military time
 */

#include "Time.h"
#include "MilTime.h"

//Constructor

MilTime::MilTime(){

}

MilTime::MilTime(int h, int s){
    setTime(h, s);
}
//Mutator

void MilTime::setTime(int h, int s){
    if(h >= 1 && h <= 2359){
    milHrs = h;
    milSec = s;
    hour = h / 100;
    min = h % 100;
    }
    else{
        throw BadHour();
    }
    if(s >= 0 && s <= 59){
    sec = s;
    }
    else{
        throw BadSeconds();
    }
}
//Accessors

int MilTime::getHour() const{
    return milHrs;
}

int MilTime::getStandHr() const{
    return hour;
}

