/* 
 * File:   Sorting.h
 * Author: Chris Stark
 *
 * Created on December 8, 2022, 8:03 PM
 */

#ifndef SORTING_H
#define SORTING_H
#include <cstdlib>

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
    for(int i = 0; i < sizeof(index); i++){
        
    }
    return temp;
}
//Sorts a 2 dimensional array represented as a 1 dim array
template<class T>
T* Prob2Sort<T>::sortArray(const T* a, int rows, int cols, int cSrt, bool asc) {
    
    T *temp = new T[rows * cols];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            temp[i * cols + j] = a[i * cols + j];
            //if(j = cSrt && a){
            //    
            //}
        }
    }
    return temp;
}

#endif /* SORTING_H */

