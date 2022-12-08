/* 
 * File:   Cards.h
 * Author: Chris Stark
 *
 * Created on October 25, 2022, 8:34 AM
 */

#ifndef CARDS_H
#define CARDS_H

struct Cards
{
    //Deck array static size no joker cards for dealing hand
    string card[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    //Suit array for dealing hand
    string suits[4] = {"C", "D", "H", "S"};
    
};

struct Player
{
    Cards crdData;//Other struct object for access within this structure
    string name;//Name of player
    string *hand;//Array to hold player 5 card hand
    string *hndSuit;//Array that holds player card suits
    int handSz;//hand array size
    int suitSz;//size of suit array
    int credits;//Credits for player with starting amount
};



#endif /* CARDS_H */

