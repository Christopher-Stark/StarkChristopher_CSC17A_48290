/* 
 * File:   Hand.cpp
 * Author: Christopher Stark
 * Created on December 7, 2022, 10:30 AM
 * Purpose: Project 2 Video Poker Jacks or Better, changing to a class and adding 
 * content from chapters 13-16. Revision of Project 1, Previous Final of 
 * Project 1 included for change reference.
 */
#include "Deck.h"
#include "Hand.h"

void Hand::setInitialHand(){
    for(int i = 0; i < HSIZE; i++)//Fills hand with random card/suit
    {
        fHand[i] = getFace(rand() % (ACE + 1)); //Enumerator used
        sHand[i] = getSuit(rand() % (SPADES + 1));
    }
}

void Hand::setFaceHand(int index){//Swaps cards out when player discards
    fHand[index] = getFace(rand() % (ACE + 1));
}

void Hand::setSuitHand(int index){
    sHand[index] = getSuit(rand() % (SPADES + 1));
}