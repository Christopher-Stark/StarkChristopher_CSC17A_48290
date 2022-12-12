/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 8, 2022, 5:10 PM
 * Purpose: Final Problem 1 - Random Sequence Class
 */

#include "Random.h"

Prob1Random::Prob1Random(const char n, const char *s){//Constructor
    nset = n;
    set = new char[nset];
    freq = new int[nset];
    for(int i = 0; i < nset; i++){
        set[i] = static_cast<int>(s[i]);
    }
    numRand = 0;
} 

Prob1Random::~Prob1Random(void){//Destructor
    delete[] set;
    delete[] freq;
} 

char Prob1Random::randFromSet(void){//Returns a random number from the set
    int rNum = rand() % 5;
    char rChar = set[rNum];
    freq[rNum] = freq[rNum] + 1;
    numRand++;
    return rChar;
} 

int* Prob1Random::getFreq(void) const{//Returns the frequency histogram
    return freq;
} 

char* Prob1Random::getSet(void) const{//Returns the set used
    char *tempSet = set;
    return tempSet;
} 

int Prob1Random::getNumRand(void) const{//Gets the number of times randFromSet has been called
    int rNum = numRand;
    return rNum;
}