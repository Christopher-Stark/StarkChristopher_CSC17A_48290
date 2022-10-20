/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   structs.h
 * Author: Chris Stark
 *
 * Created on October 19, 2022, 4:36 PM
 */

#ifndef STRUCTS_H
#define STRUCTS_H

struct Deck {
    string card[14] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string suits[4] = {"D", "H", "S", "C"};

};

struct Player {
    const int strCred = 200;
    int hSize = 5;
    int sSize = 4;
    int deckSize = 14;
    Deck *hndCrds;
    Deck *hndSuits;
};

#endif /* STRUCTS_H */

