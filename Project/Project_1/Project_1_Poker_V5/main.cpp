/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 25, 2022, 10:30 AM
 * Purpose: Project 1 Assignment, Poker card game, Standard rules 3 card draw
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

//User Defined Libraries
#include "Cards.h"
//Global Constants
const int DECKSIZE = 14; //Size card deck array for rand generation within a deck
const int HNDSIZE = 5;
const int SUITSIZE = 4;
//Function Prototypes
void clearScreen();
Player *hand(Player *a);
void displayMenu(const Player *a, int &menu);
void dealHand(const Player *a);
int betAmount(const Player *a);
void discard(Player *a);
void replaceDiscard(Player *a, int num);
//Execution begins here!

int main(int argc, char** argv)
{
    srand(time(NULL));
    Player *player = new Player; //Dynamic Player struct object
    //Variables for menu, bet amount, and players current credits
    int menu, betAmt;

    displayMenu(player, menu); //Displays Menu

    switch (menu)
    {
        case 1:
            clearScreen();
            player = hand(player);
            dealHand(player);
            betAmt = betAmount(player);
            player->credits -= betAmt;
            discard(player);
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
        clearScreen();
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
    while ((input > 4 || input < 1) && a->credits != 0);
    if (a->credits == 0)
    {
        cout << "You have ran out of credits, better luck next time!" << endl;
    }
}

Player *hand(Player *a)
{
    a->hand = new string[HNDSIZE];
    a->hndSuit = new string[HNDSIZE];
    for (int i = 0; i < HNDSIZE; i++)
    {
        a->hand[i] = a->crdData.card[rand() % DECKSIZE];
        a->hndSuit[i] = a->crdData.suits[rand() % SUITSIZE];
    }
    return a;
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
    cout << "\n*******Your Hand*******" << endl;
    cout << "-------Card*Suit-------" << endl;
    cout << "-----------------------" << endl;
    cout << " ";
    for (int i = 0; i < HNDSIZE; i++)
    {
        cout << a->hand[i] << "*" << a->hndSuit[i] << " ";
    }
    cout << endl;
}

int betAmount(const Player *a)
{
    int betAmt;
    cout << "\n\nCurrent credits: " << a->credits << endl;
    cout << "**Higher bet = increased pay outs**" << endl;
    cout << "Choose your starting bet amount 1-5: ";
    cin >> betAmt;

    while (betAmt < 1 || betAmt > 5 || a->credits < betAmt)
    {
        cout << "Please enter a valid bet amount 1-5: ";
        cin >> betAmt;
        if (a->credits == 0)
        {
            cout << "You have ran out of credits";
            break;
        }
    }

    return betAmt;
}

void discard(Player *a)
{
    string input;
    int num;

    cout << "\n\nYou can discard up to 5 cards once per bet!" << endl;
    cout << "Would you like to discard cards Y/N? ";
    cin >> input;
    input = tolower(input[0]);

    while (input != "y" && input != "n")
    {
        cout << "Please choose a valid option Y/N!" << endl;
        cin >> input;
        input = tolower(input[0]);
    }

    if (input == "y")
    {
        cout << "How many cards would you like to discard? ";
        cin >> num;
        while (num < 1 || num > 5)
        {
            cout << "Please choose a valid amount 1-5: ";
            cin >> num;
        }
        replaceDiscard(a, num);
    }
    else
    {
        cout << "You have chose not to discard any cards!" << endl;
    }
}

void replaceDiscard(Player *a, int num)
{
    int index[num]; //Array to hold index of cards to discard
    int cardNum = 1, val;
    cout << "Which cards would you like to discard 1-5? " << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "Card " << cardNum << ": ";
        cin >> val;
        while (val < 1 || val > 5)
        {
            cout << "Choose valid option between 1-5? " << endl;
            cout << "Card " << cardNum << ": ";
            cin >> val;
        }
        while (i != 0 && val - 1 == index[i - 1])
        {
            cout << "Please choose a card you have not discarded yet: " << endl;
            cout << "Card " << cardNum << ": ";
            cin >> val;
        }
        index[i] = val - 1;
        cardNum++;
    }
}

