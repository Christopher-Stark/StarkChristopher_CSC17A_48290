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
    char suits[5] = {'C', 'D', 'H', 'S', '\0'};//C-string array
    int hndSize = 5;
    int rcdSize = 10;
    
    enum crdNames
    {
        TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
    };
    enum stNames
    {
        CLUBS, DIAMONDS, HEARTS, SPADES
    };
};

struct Player
{
    Cards crdData;//Other struct object for access within this structure
    Player *record;//array with size 6 name for records max of 10 records
    string name;
    string *hand;//Array to hold player 5 card hand
    char *hndSuit;//Array that holds player card suits
    int credits = 200;//Credits for player with starting amount
    int crdWon = 0;//Stats of credits win/lost
    int crdLost = 0;
    int hndWon = 0;//Stats if hands won/lost
    int hndLost = 0;
};



#endif /* CARDS_H */

