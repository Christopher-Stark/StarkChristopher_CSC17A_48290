/* 
 * File:   Player.h
 * Author: Chris Stark
 *
 * Created on December 7, 2022, 11:34 AM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "Hand.h"

class Player: public Hand{
private:
    string name;
    int cWon;
    int cLost;
    int hWon;
    int hLost;
public:
    //Default Constructors - **Polymorphism & Overloaded**
    Player(){
        name = "Name", cWon = 0, cLost = 0, hWon = 0, hLost = 0;
    }
    Player(string n, int cW, int cL, int hW, int hL){
        name = n, cWon = cW, cLost = cL, hWon = hW, hLost = hL;
    }
    //Mutators
    void setName(string);
    void setCreditsWon(int);
    void setCreditsLost(int);
    void setHandWon(int);
    void setHandLost(int);
    //Operator overloaded
    Player operator++(int);
    Player operator--(int);
    //Accessors
    string getName() const{
        return name;
    }
    int getCreditsWon() const{
        return cWon;
    }
    int getCreditsLost() const{
        return cLost;
    }
    int getHandWon() const{
        return hWon;
    }
    int getHandLost() const{
        return hLost;
    }
};
#endif /* PLAYER_H */

