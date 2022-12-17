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
    T *augTable = NULL; //Augmented Table with sums
public:

    Prob3TableInherited(const char *file, int r, int c) : Prob3Table<T>(file, r, c) { //Constructor
        augTable = new T[(r + 1) * (c + 1)];
        Prob3Table<T> tempObj(file, r, c);
        
        //Augmenting row/col by 1
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                augTable[i * (c+1) + j] = tempObj.getTable()[i * (c) + j];
                if(j == c){
                    augTable[i * (c+1) + j] = tempObj.getRowSum()[i];
                }
                if(i == r){
                   augTable[i * (c+1) + j] = tempObj.getColSum()[j]; 
                }
                if(j == c && i == r){
                   augTable[i * (c+1) + j] = tempObj.getGrandTotal(); 
                }
            }
        }
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

