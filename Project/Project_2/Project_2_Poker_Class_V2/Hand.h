/* 
 * File:   Hand.h
 * Author: Chris Stark
 *
 * Created on December 7, 2022, 11:35 AM
 */

#ifndef HAND_H
#define HAND_H
#include "Deck.h"
//Constant Variables
const int HSIZE = 5;

class Hand: protected Deck {//**Base Class to Derived Class**
private://**Private Members**
    string *fHand;
    string *sHand;
public:
    //Default Constructor
    Hand() {
        fHand = new string[HSIZE];
        sHand = new string[HSIZE];
    }
    //Destructor **Destructor**

    ~Hand() {
        delete[] fHand;
        delete[] sHand;
    }
    //Mutators - **Specification vs Implementation .h/.cpp**
    void setInitialHand();
    void setFaceHand(int index);
    void setSuitHand(int index);
    //Accessors

    string* getFaceArray() const {
        return fHand;
    }

    string* getSuitArray() const {
        return sHand;
    }
};
#endif /* HAND_H */

