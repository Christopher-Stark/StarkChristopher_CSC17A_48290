/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 25, 2022, 8:30 AM
 * Purpose: Project 1 Assignment, Poker card game, Standard rules 3 card draw
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//User Defined Libraries
#include "Cards.h"
//Global Constants
const int DECKSIZE = 13; //Size card deck array for rand generation within a deck
const int HNDSIZE = 5;
const int SUITSIZE = 4;
//Function Prototypes
void clearScreen();
Player* createFaceCards();
Player* createSuits();
void displayMenu(const Player *a, int &menu);
void dealHand(const Player *a);
int betAmount(const Player *a);
//Execution begins here!

int main(int argc, char** argv)
{
    srand(time(NULL));
    Player *player; //Player struct object
    //Variables for menu, bet amount, and players current credits
    int menu = 0, betAmt;
    player->credits = 400;
    player->handSz = HNDSIZE;
    player->suitSz = SUITSIZE;
    
    displayMenu(player, menu); //Displays Menu
    cout << menu << endl;
    switch (menu)
    {
        case 1:
            cout << "Check: " << endl;
            player = createFaceCards();
            dealHand(player);
            break;
        case 2:

            break;
        case 3:
            cout << "Current credits are " << player->credits << endl;
            break;
        case 4:
            cout << "You have quit, better luck next time!" << endl;
            break;
        default:
            cout << "Please enter a valid menu option: ";
    }
    while (menu != 4);

    delete player;
    return 0;
}
//Functions

void displayMenu(const Player *a, int &menu)
{
    int input;
    do
    {
        //clearScreen();
        cout << "------------------------------------------" << endl;
        cout << "*****Welcome to Video Poker All Stars*****" << endl;
        cout << "------------------------------------------" << endl;
        cout << "   **Standard Poker rules 5 card draw**" << endl;
        cout << "       **Start with 400 credits**" << endl;
        cout << "------------------------------------------" << endl;
        cout << "           *****Menu options*****" << endl;
        cout << "1)Play Video Poker" << endl;
        cout << "2)View win/loss stats" << endl;
        cout << "3)View current credits" << endl;
        cout << "4)Quit!" << endl;
        cout << "Please select a menu option: ";
        cin >> input;
        menu = input;
    }
    while (input > 4 || input < 1);
    if (a->credits == 0)
    {
        cout << "You have ran out of credits, better luck next time!" << endl;
    }
}

Player *createFaceCards()
{
    Player *player = new Player;
    player->hand = new string[player->handSz];
    for (int i = 0; i < player->handSz; i++)
    {
        player->hand[i] = player->crdData.card[rand() % DECKSIZE];
    }
    return player;
}

Player* createSuits()
{
    Player *player = new Player;
    player->hndSuit = new string[player->suitSz];
    for (int i = 0; i < player->handSz; i++)
    {
        player->hndSuit[i] = player->crdData.suits[rand() % player->suitSz];
    }
    return player;
}

void clearScreen()
{
    int size = 40;
    for (int i = 0; i < size; i++)
    {
        cout << "\n";
    }
}

void dealHand(const Player *a)
{
    cout << "*****Your Hand*****" << endl;
    cout << "-------------------" << endl;
    for(int i = 0; i < a->handSz; i++)
    {
        cout << a->hand[i] << " ";
    }
}

int betAmount(const Player *a)
{
    int betAmt;
    cout << "Current credits: " << a->credits << endl;
    cout << "**Higher bet = increased pay outs**" << endl;
    cout << "Choose your starting bet amount 1-5: ";
    cin >> betAmt;

    while (betAmt < 1 || betAmt > 5 || a->credits < betAmt)
    {
        cout << "Please enter a valid bet amount 1-5: ";
        cin >> betAmt;
    }

    return betAmt;
}

