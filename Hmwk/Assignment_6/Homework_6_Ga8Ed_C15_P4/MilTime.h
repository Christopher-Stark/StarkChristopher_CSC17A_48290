/* 
 * File:   MilTime.h
 * Author: Chris Stark
 *
 * Created on November 28, 2022, 9:30 PM
 */
#include "Time.h"

#ifndef MILTIME_H
#define MILTIME_H

class MilTime : public Time {
private:
    int milHrs;
    int milSec;
public:
    //Constructor
    MilTime();
    MilTime(int, int);
    //Mutator
    void setTime(int, int);
    //Accessors
    int getHour() const;
    int getStandHr() const;

};


#endif /* MILTIME_H */

