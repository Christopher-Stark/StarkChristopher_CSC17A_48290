/* 
 * File:   Time.h
 * Author: Gaddis/Chris Stark
 *
 * Created on November 28, 2022, 9:25 PM
 */
#include <cstdlib>
#include <string>
using namespace std;

#ifndef TIME_H
#define TIME_H

class Time{
protected:
    int hour;
    int min;
    int sec;
public:
    //Constructors
    Time(){
        hour = 0;
        min = 0;
        sec = 0;
    }
    Time(int h,int m,int s){
        hour = h;
        min = m;
        sec = s;
    }
    //Accessors
    int getHour() const{
        return hour;
    }
    int getMin() const{
        return min;
    }
    int getSec() const{
        return sec;
    }
    
};


#endif /* TIME_H */

