/* 
 * File:   TableInherit.h
 * Author: Chris Stark
 *
 * Created on December 11, 2022, 2:59 PM
 */

#ifndef TABLEINHERIT_H
#define TABLEINHERIT_H
#include "Table.h"

template<class T>
class Prob3TableInherited: public Prob3Table<T> {
protected:
    T *augTable; //Augmented Table with sums
public:

    Prob3TableInherited(const char *file, int r, int c) : Prob3Table<T>(file, r, c) { //Constructor
        augTable = new T[(r + 1) * (c + 1)];
        Prob3Table<T> tempObj(file, r, c);
        const T *temp = new T[r*c];
        const T *rSum = new T[r];
        const T *cSum = new T[c];
        rSum = tempObj.getRowSum();
        cSum = tempObj.getColSum();
        temp = tempObj.getTable();
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                augTable[i * (c+1) + j] = temp[i * (c) + j];
                if(j == c){
                    augTable[i * (c+1) + j] = rSum[i];
                }
                if(i == r){
                   augTable[i * (c+1) + j] = cSum[j]; 
                }
                if(j == c && i == r){
                   augTable[i * (c+1) + j] = tempObj.getGrandTotal(); 
                }
            }
        }
        //Could not de allocate because const, would not let me = arrays unless const
        //delete[] temp;
        //delete[] rSum;
        //delete[] cSum;
    }

    ~Prob3TableInherited() {
        delete [] augTable;
    }; //Destructor

    const T *getAugTable(void) {
        return augTable;
    };
} ;
//Functions

#endif /* TABLEINHERIT_H */

