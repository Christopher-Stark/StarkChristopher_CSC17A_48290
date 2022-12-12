/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 8, 2022, 5:10 PM
 * Purpose: Final Problem 1 - Random Sequence Class
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include "Random.h"
//Global Constants

//Function Prototypes

//Execution begins here!

int main(int argc, char** argv){
    srand(time(NULL));
    char n = 5;
    char rndseq[] = {19, 34, 57, 79, 126};
    int ntimes = 100000;
    Prob1Random a(n, rndseq);
    for(int i = 1; i <= ntimes; i++){
        a.randFromSet();
    }
    int *x = a.getFreq();
    char *y = a.getSet();
    for(int i = 0; i < n; i++){
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
    return 0;
}
//Functions

