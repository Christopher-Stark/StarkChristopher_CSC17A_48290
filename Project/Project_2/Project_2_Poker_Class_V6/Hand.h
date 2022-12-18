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
    string *fHand = new string[HSIZE];
    string *sHand = new string[HSIZE];
    int credits;
    Deck deck; //Aggregate
public:
    //Default Constructor
    Hand(): Deck() {
        credits = 200;
    }
    //Destructor **Destructor**
    ~Hand() {
        //delete[] fHand;
        //delete[] sHand;
    }
    //Mutators - **Specification vs Implementation .h/.cpp**
    void setInitialHand();
    void setFaceHand(int index);
    void setSuitHand(int index);
    void winCredits(int win);
    void loseCredits(int lose);
    //Accessors
    string* getFaceArray() const {
        return fHand;
    }

    string* getSuitArray() const {
        return sHand;
    }

    int getCredits() const {
        return credits;
    }
} ;

#endif /* HAND_H */

