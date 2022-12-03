/* 
 * File:   Total.h
 * Author: Chris Stark
 *
 * Created on December 3, 2022, 3:06 PM
 */

#ifndef TOTAL_H
#define TOTAL_H

template <class T>
T total (T tNums){
    T total = 0, num;
    for(int i = 0; i < tNums; i++){
        cout << "Please enter a number to total: ";
        cin >> num;
        total = total + num;
    }
    return total;
}

#endif /* TOTAL_H */

