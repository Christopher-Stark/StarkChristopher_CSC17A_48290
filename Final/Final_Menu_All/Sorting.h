/* 
 * File:   Sorting.h
 * Author: Chris Stark
 *
 * Created on December 8, 2022, 8:03 PM
 */

#ifndef SORTING_H
#define SORTING_H
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>

template<class T>
class Prob2Sort {
private:
    int *index; //Index that is utilized in the sort
public:

    Prob2Sort() {
        index = NULL;
    }; //Constructor

    ~Prob2Sort() {
        delete []index;
    }; //Destructor
    T * sortArray(const T*, int, bool); //Sorts a single column array
    T * sortArray(const T*, int, int, int, bool); //Sorts a 2 dimensional array
    //represented as a 1 dim array
} ;
//Template member functions - **No source/.cpp file**

template<class T>
T* Prob2Sort<T>::sortArray(const T* a, int size, bool asc) { //Sorts a single column array
    T *temp = new T[size];
    int tIndex = *index;
    for (int i = 0; i < size; i++) {
        temp[i] = a[tIndex];
        tIndex++;
    }
    return temp;
}
//Sorts a 2 dimensional array represented as a 1 dim array

template<class T>
T* Prob2Sort<T>::sortArray(const T* a, int rows, int cols, int cSrt, bool asc) {
    bool ascend = asc;
    int tInd = 0;
    char one = a[cSrt - 1], two = a[cSrt + 16];
    int sCnt = 0;
    cout << one << " " << two << endl;
    T *temp = new T[cols];
    T *temp2 = new T[cols];
    T *temp3 = new T[rows * cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp3[i * 16 + j] = a[i * 16 + j];
            if (a[i * 16 + (cSrt - 1)] < a[(i + 1) * 16 + (cSrt)] && i != rows - 1) {
                tInd = i * 16;
                index = &tInd;
                temp = sortArray(a, cols, asc);
                tInd = (i + 1) * 16 + 1;
                index = &tInd;
                temp2 = sortArray(a, cols, asc);
                for (int k = 0; k < cols; k++) {
                    temp3[i * 16 + k] = temp2[k];
                    temp3[(i + 1) * 16 + k + 1] = temp[k];
                }
            }
        }
    }
    delete[] temp;
    delete[] temp2;
    return temp3;
}

#endif /* SORTING_H */

