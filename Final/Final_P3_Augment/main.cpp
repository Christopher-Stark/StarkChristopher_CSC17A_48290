/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 11, 2022, 2:57 PM
 * Purpose: Final Problem 3 - Augment Table Class
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include "Table.h"
#include "TableInherit.h"
//Global Constants

//Function Prototypes

//Execution begins here!

int main(int argc, char** argv){
    cout << "Entering problem number 3" << endl;
    int rows = 5;
    int cols = 6;
    Prob3TableInherited<int> tab("Problem3.txt", rows, cols);
    const int *naugT = tab.getTable();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << naugT[i * cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    const int *augT = tab.getAugTable();
    for(int i = 0; i <= rows; i++){
        for(int j = 0; j <= cols; j++){
            cout << augT[i * (cols + 1) + j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//Functions

