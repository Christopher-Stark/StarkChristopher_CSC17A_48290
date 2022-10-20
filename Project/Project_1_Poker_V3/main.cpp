/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 18, 2022, 4:17 PM
 * Purpose: Project 1 Assignment, Poker card game, Standard rules 3 card draw
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//User Defined Libraries
#include "structs.h"
//Global Constants
const int DCKSIZE = 14; //Number of different cards in deck
const int SUITSZ = 4; //Number of different suits in deck
const int CRDSTART = 200;
const int HSIZE = 5;

//Function Prototypes
void clearScreen();
string* createFaceCards();
string* createSuits();
void displayMenu(int credits, int &menu);
void dealerHand();
//Execution begins here!

int main(int argc, char** argv)
{
    srand(time(NULL));
    Player player;
    Player dealer;
    int credits = player.strCred, menu;
    
    
    displayMenu(credits, menu);
    switch (menu)
    {
        case 1:
            cout << "Current credits are " << credits << endl;
            break;
        case 2:
            dealerHand();
            break;
        case 3:
            break;
        case 4:
            cout << "You have quit, better luck next time!" << endl;
            break;
        default:
            cout << "Please enter a valid menu option: ";
    }
    while (menu != 4);


    return 0;
}
//Functions

void displayMenu(int credits, int &menu)
{
    do
    {
        clearScreen();
        cout << "------------------------------------------" << endl;
        cout << "******Welcome to Poker All Stars******" << endl;
        cout << "------------------------------------------" << endl;
        cout << "   **Standard Poker rules 3 card draw**" << endl;
        cout << "       **Start with 200 credits**" << endl;
        cout << "   **Try your hand against the Dealer**" << endl;
        cout << "------------------------------------------" << endl;
        cout << "           *****Menu options*****" << endl;
        cout << "1)View current credits" << endl;
        cout << "2)Play against dealer" << endl;
        cout << "3)View win/loss stats" << endl;
        cout << "4)Quit!" << endl;
        cout << "Please select a menu option: ";
        cin >> menu;
    }
    while (credits > 0 && menu != 4);
    if (credits == 0)
    {
        cout << "You have ran out of credits, better luck next time!" << endl;
    }
}

string* createFaceCards()
{
    Player *player = new Player;
    player->hndCrds = new Deck;
    player->hndCrds = new string[player->hSize];
    for(int i = 0; i < player->hSize; i++)
    {
        player->hndCrds[i] = player->[rand() % 6];
    }
}

string* createSuits()
{
    
}

void clearScreen()
{
    int size = 40;
    for (int i = 0; i < size; i++)
    {
        cout << "\n";
    }
}

void dealerHand()
{
    cout << "|****Dealer Hand****|" << endl;
    cout << "|-------------------|" << endl;
    
}

