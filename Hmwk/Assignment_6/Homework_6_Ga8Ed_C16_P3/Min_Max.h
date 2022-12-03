/* 
 * File:   Lesser.h
 * Author: Chris Stark
 *
 * Created on December 3, 2022, 2:32 PM
 */

#ifndef MIN_MAX_H
#define MIN_MAX_H

template <class T>
T minimum(T num1, T num2){
    if(num1 > num2){
        return num2;
    }
    else{
        return num1;
    }
}
template <class T>
T maximum(T num1, T num2){
   if(num1 > num2){
        return num1;
    }
    else{
        return num2;
    } 
}


#endif /* LESSER_H */

