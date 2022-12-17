/* 
 * File:   Deck.h
 * Author: Chris Stark
 *
 * Created on December 7, 2022, 10:39 AM
 */

#ifndef DECK_H
#define DECK_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
//Const Variables for size
const int FSIZE = 13;
const int SSIZE = 4;

//Enumerator
enum crdNames // Enumeration for cards and suits
{
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

enum stNames {
    CLUBS, DIAMONDS, HEARTS, SPADES
};

class Deck{

protected://**Protected/Static Data members**
    string face[FSIZE] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string suit[SSIZE] = {"C", "D", "H", "S"};
public:
    //Default Constructor
    Deck() {
        
    }
    //Accessors - **Inline**
    string getFace(int i) const {
        return face[i];
    }

    string getSuit(int i) const {
        return suit[i];
    }
};
#endif /* DECK_H */

