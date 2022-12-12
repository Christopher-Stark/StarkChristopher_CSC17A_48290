/* 
 * File:   Table.h
 * Author: Chris Stark
 *
 * Created on December 11, 2022, 2:56 PM
 */

#ifndef TABLE_H
#define TABLE_H
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Prob3Table {
protected:
    int rows; //Number of rows in the table
    int cols; //Number of cols in the table
    T *rowSum; //RowSum array
    T *colSum; //ColSum array
    T *table; //Table array
    T grandTotal; //Grand total
    void calcTable(void); //Calculate all the sums
public:

    Prob3Table(const char * file, int r, int c) { //Constructor then Destructor
        rows = r;
        cols = c;
        grandTotal = 0;
        string fName = file;
        ifstream infile;
        infile.open(fName, ios::in);
        table = new T[r * c];
        int num, cnt = 0;
        while (infile >> num) {
            table[cnt] = num;
            cnt++;
        }
        infile.close();
        
        rowSum = new T[r];
        colSum = new T[c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                rowSum[i] += table[i * c + j];
                grandTotal += table[i * c + j];
                colSum[j] += table[i * c + j];
            }
        }
    }

    ~Prob3Table() {
        delete [] table;
        delete [] rowSum;
        delete [] colSum;
    };

    const T *getTable(void) {
        return table;
    };

    const T *getRowSum(void) {
        return rowSum;
    };

    const T *getColSum(void) {
        return colSum;
    };

    T getGrandTotal(void) {
        return grandTotal;
    };
} ;
//Functions
/*template<class T>
Prob3Table::Prob3Table(char * file, int r, int c) {
    
}*/
#endif /* TABLE_H */

