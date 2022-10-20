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

//Global Constants
const int DCKSIZE = 14; //Number of different cards in deck
const int SUITSZ = 4; //Number of different suits in deck
const int CRDSTART = 200;
const int HSIZE = 5;
const string CARDS[DCKSIZE] = {"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
const string SUITS[SUITSZ] = {"D", "H", "S", "C"};

//Function Prototypes
void clearScreen();
string* createFaceCards();
string* createSuits();
void displayMenu(int credits, const string crd[], const string suit[]);
void menuSelection(int credits, int input, const string crd[], const string suit[]);
void dealerHand();
//Execution begins here!

int main(int argc, char** argv)
{
    srand(time(NULL));
    int credits = CRDSTART;

    displayMenu(credits, CARDS, SUITS);


    return 0;
}
//Functions

void displayMenu(int credits, const string crd[], const string suit[])
{
    int menu;
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
        menuSelection(credits, menu, crd, suit);
    }
    while (credits > 0 && menu != 4);
    if (credits == 0)
    {
        cout << "You have ran out of credits, better luck next time!" << endl;
    }
}

string* createFaceCards()
{
    string *a = new string[HSIZE];
    for (int i = 0; i < HSIZE; i++)
    {
        a[i] = CARDS[rand() % HSIZE];
    }
    return a;
}

string* createSuits()
{
    string *a = new string[SUITSZ];
    for (int i = 0; i < SUITSZ; i++)
    {
        a[i] = SUITS[rand() % SUITSZ];
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

void menuSelection(int credits, int input, const string crd[], const string suit[])
{
    switch (input)
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
    while (input != 4);
}

void dealerHand()
{
    string *dealCrd = new string[HSIZE];
    string *dealSuit = new string[SUITSZ];
    dealCrd = createFaceCards();
    dealSuit = createSuits();
    cout << "|****Dealer Hand****|" << endl;
    cout << "|-------------------|" << endl;
    for (int i = 0; i < HSIZE; i++)
    {
        cout << " " << dealCrd[i];
        if (i < HSIZE - 1)
        {
            cout << dealSuit[i] << " ";
        }
        else
        {
            cout << dealSuit[i-1] << endl;
        }
    }
}

