/* 
 * File:   Absolute.h
 * Author: Chris Stark
 *
 * Created on December 3, 2022, 3:00 PM
 */

#ifndef ABSOLUTE_H
#define ABSOLUTE_H

template <class T>
T absolute(T num){
    if(num < 0){
        return num * -1;
    }
    else{
        return num;
    }
}

#endif /* ABSOLUTE_H */

