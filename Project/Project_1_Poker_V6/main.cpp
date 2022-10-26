/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 25, 2022, 2:15 PM
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
const int DECKSIZE = 13; //Size card deck array for rand generation within a deck
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
void winConditions(Player *a, int bet);
void sortCards(string *a, const Player *b);
void sortSuits(string *a, const Player *b);
void swap(string *a, string *b);
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
            dealHand(player);
            winConditions(player, betAmt);
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
    a->hand = new string[HNDSIZE]; //Dynamic struct string array
    a->hndSuit = new string[HNDSIZE];
    for (int i = 0; i < HNDSIZE; i++)//Fills hand with random card/suit
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
    for (int i = 0; i < HNDSIZE; i++)//Displays struct hand array
    {
        cout << a->hand[i] << "*" << a->hndSuit[i] << " ";
    }
    cout << endl;
}

int betAmount(const Player *a)
{
    int betAmt;
    cout << "\n\nCurrent credits: " << a->credits << endl; //Display credits
    cout << "**Higher bet = increased pay outs**" << endl; //Announce bet payouts
    cout << "Choose your starting bet amount 1-5: ";
    cin >> betAmt;

    while (betAmt < 1 || betAmt > 5 || a->credits < betAmt)//Error checking for bet
    {
        cout << "Please enter a valid bet amount 1-5: ";
        cin >> betAmt;
        if (a->credits == 0)//If player has no credits
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

    while (input != "y" && input != "n")//Error checking for Y/N
    {
        cout << "Please choose a valid option Y/N!" << endl;
        cin >> input;
        input = tolower(input[0]);
    }

    if (input == "y")//If player wants to discard
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
    else//player chose not to discard
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
        while (val < 1 || val > 5)//Error checking for valid card index
        {
            cout << "Choose valid option between 1-5? " << endl;
            cout << "Card " << cardNum << ": ";
            cin >> val;
        }
        while (i != 0 && val - 1 == index[i - 1])//Error checking for duplicate discard
        {
            cout << "Please choose a card you have not discarded yet: " << endl;
            cout << "Card " << cardNum << ": ";
            cin >> val;
        }
        index[i] = val - 1; //val - 1 since index starts at 0
        cardNum++;
        a->hand[val - 1] = a->crdData.card[rand() % DECKSIZE]; //Replace discarded cards
        a->hndSuit[val - 1] = a->crdData.suits[rand() % SUITSIZE]; //Replace suits for new cards
    }
}

void winConditions(Player *a, int bet)
{
    //Dynamic arrays of card/suit hand to sort for easier way of tracking winning hands
    string *tempCrd = new string[HNDSIZE];
    string *tempSut = new string[HNDSIZE];

    sortCards(tempCrd, a);//Assigns card hand to new sorted dynamic array 
    sortSuits(tempSut, a);//Assigns suit hand to new sorted dynamic array 

    if(tempCrd[0] == "10")
    {
        
    }
    
    
    /*for (int i = 0; i < HNDSIZE; i++)//TESTING FOR SORTING
    {
        cout << tempCrd[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < HNDSIZE; i++)
    {
        cout << tempSut[i] << " ";
    }*/

    delete[] tempCrd;
    delete[] tempSut;
}

void sortCards(string *a, const Player *b)
{
    for (int i = 0; i < HNDSIZE; i++)
    {
        a[i] = b->hand[i];
    }

    for (int i = 0; i < HNDSIZE - 1; i++)//Nested for loop for bubble sorting
    {
        for (int j = 0; j < HNDSIZE - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void sortSuits(string *a, const Player *b)
{
    for (int i = 0; i < HNDSIZE; i++)
    {
        a[i] = b->hndSuit[i];
    }

    for (int i = 0; i < HNDSIZE - 1; i++)//Nested for loop for bubble sorting
    {
        for (int j = 0; j < HNDSIZE - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void swap(string *a, string *b)
{
    string temp = *a;
    *a = *b;
    *b = temp;
}

