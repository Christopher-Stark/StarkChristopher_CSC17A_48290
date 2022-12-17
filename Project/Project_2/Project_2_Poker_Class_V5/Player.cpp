/* 
 * File:   Hand.cpp
 * Author: Christopher Stark
 * Created on December 7, 2022, 10:30 AM
 * Purpose: Project 2 Video Poker Jacks or Better, changing to a class and adding 
 * content from chapters 13-16. Revision of Project 1, Previous Final of 
 * Project 1 included for change reference.
 */
#include "Hand.h"
#include "Player.h"
void Player::setName(string n){
    name = n;
}

void Player::setCreditsWon(int c){
    cWon = c;
}

void Player::setCreditsLost(int c){
    cLost = c;
}

void Player::setHandWon(int h){
    hWon = h;
}

void Player::setHandLost(int h){
    hLost = h;
}

Player Player::operator++(){
    ++hWon;
    return *this;
}

Player Player::operator--(){
    ++hLost;
    return *this;
}
