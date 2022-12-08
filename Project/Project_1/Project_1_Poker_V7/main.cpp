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
#include <cstring>
#include <algorithm>

using namespace std;

//User Defined Libraries
#include "Cards.h"
//Global Constants

//Function Prototypes
void clearScreen();
void fileCreateIfNoExist(string fileName);
void binCreateIfNoExist(string fileName);
void getPlayerName(Player *a);
void nonBinFileIn(string fileName, Player *a);
void nonBinFileOut(string fileName, Player *a);
void getRecords(string fileName, Player *a);
void recordUpdate(string fileName, Player *a);
Player *hand(Player *a, int &index, string &name);
void displayMenu(const Player *a, int &menu);
void menuReturn();
void stats(Player *a, string &name);
void dealHand(const Player *a);
int betAmount(const Player *a);
void discard(Player *a);
void replaceDiscard(Player *a, int num);
void winConditions(Player *a, int bet, int index);
void sortCards(string *card, const Player *b, char *suit);
int cardValue(const string card);
void swap(string *a, string *b);
void swap(char *a, char *b);
void royalFlush(const string *card, const char *suit, bool &cond, const Player *a);
void straightFlush(const string *card, const char *suit, bool &cond, const Player *a);
void fourKind(const string *card, bool &cond);
void fullHouse(const string *card, bool &cond);
void flush(const char *suit, bool &cond, const Player *a);
void straight(const string *card, bool &cond, const Player *a);
void threeKind(const string *card, bool &cond);
void twoKind(const string *card, bool &cond, const Player *a);
void jacksOrBetter(const string *card, bool &cond, const Player *a);
void winningAmt(bool Rf, bool Sf, bool frK, bool fHous, bool Flus, bool Strt,
        bool thrK, bool twoK, bool jcks, int bet, Player *a, int index);
//Execution begins here!

int main(int argc, char** argv)
{
    srand(time(NULL));
    Player *player = new Player; //Dynamic Player struct object
    
    //Fresh array that will hold record data
    player->record = new Player[player->crdData.rcdSize];
    
    //Variables for menu, bet amount, and players current credits
    int menu, betAmt, index = 0;
    string name; //Keeps track if user name is already entered
    
    //Create record files if none exist
    string txtFile = "VideoPokerRecords.dat";
    fileCreateIfNoExist(txtFile);
    string binFile = "BinaryPokerRecords.dat";
    binCreateIfNoExist(binFile);
    getRecords(txtFile, player);
    
    do
    {
        displayMenu(player, menu); //Displays Menu

        switch (menu)//Switch for menu options
        {
            case 1:
                clearScreen();//clears screen to keep things clean
                //Asks for player/record name if not already entered
                player = hand(player, index, name);//function that creates hand
                dealHand(player);//function that displays hand
                betAmt = betAmount(player);//function that determines bet amount
                player->credits -= betAmt;//adjust credits for bet amount
                discard(player);//function that allows user to discard cards
                dealHand(player);//display new discarded hand
                winConditions(player, betAmt, index);//function that handles win cond.
                recordUpdate(txtFile, player);//updates file with new records
                menuReturn();//a pseudo pause function for clearing screen when hand is over
                break;
            case 2:
                stats(player, name);//determines spot in records and displays stats
                menuReturn();
                break;
            case 3:
                cout << "\nCurrent credits are " << player->credits << endl;
                menuReturn();
                break;
            case 4:
                cout << "You have quit, better luck next time!" << endl;
                break;
            default:
                cout << "Please enter a valid menu option: ";
        }
    }
    while (menu != 4 && player->credits != 0);//Loops until out of credits or player quits
    if (player->credits == 0)
    {
        cout << "You have ran out of credits, better luck next time!" << endl;
    }

    delete player;//De-allocates Dynamic memory
    delete[] player->record;
    return 0;
}
//Functions

void displayMenu(const Player *a, int &menu)
{
    int input;
    do
    {
        clearScreen();//Clears screen to keep things clean
        cout << "------------------------------------------" << endl;
        cout << "*****Welcome to Video Poker All Stars*****" << endl;
        cout << "------------------------------------------" << endl;
        cout << "          **Jacks or Better**    " << endl;
        cout << "       **Start with 200 credits**" << endl;
        cout << "------------------------------------------" << endl;
        cout << "           *****Menu options*****" << endl;
        cout << "1)Play Video Poker" << endl;
        cout << "2)View recorded stats" << endl;
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

Player *hand(Player *a, int &index, string &name)
{
    a->hand = new string[a->crdData.hndSize]; //Dynamic struct string array
    a->hndSuit = new char[a->crdData.hndSize]; //Dynamic C-string array
    string plcHld = "Name";
    while (!name.size())
    {
        cout << "Will record stats up to 10 players!" << endl;
        cout << "Please enter your user name that is 6 chars long: ";
        cin >> name;
        a->name = name;
        while (name.size() != 6)
        {
            cout << "Please enter your user name that is 6 chars long: ";
            cin >> name;
            a->name = name;
        }

        for (int i = 0; i < a->crdData.rcdSize; i++)
        {
            if (a->record[i].name == name)
            {
                index = i;
                break;
            }
            else if (a->record[i].name == plcHld)
            {
                a->record[i].name = name;
                index = i;
                break;
            }
        }
    }


    for (int i = 0; i < a->crdData.hndSize; i++)//Fills hand with random card/suit
    {
        a->hand[i] = a->crdData.card[rand() % (a->crdData.ACE + 1)]; //Enumerator used
        a->hndSuit[i] = a->crdData.suits[rand() % (a->crdData.SPADES + 1)];
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

void stats(Player *a, string &name)
{
    int index = -1;
    while (!name.size() || name.size() != 6)
    {
        cout << "\nPlease enter your user name that is 6 chars long: ";
        cin >> name;
    }
    for (int i = 0; i < a->crdData.rcdSize; i++)
    {
        if (a->record[i].name == name)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        cout << "\nNo records are found with that user name!";
    }
    if (index >= 0)
    {
        cout << "\nThe player: " << a->record[index].name << endl;
        cout << "Credits won: " << a->record[index].crdWon << endl;
        cout << "Credits lost: " << a->record[index].crdLost << endl;
        cout << "Hands won: " << a->record[index].hndWon << endl;
        cout << "Hands lost: " << a->record[index].hndLost << endl;
    }
}

void dealHand(const Player *a)
{
    cout << "\n*******Your Hand*******" << endl;
    cout << "-------Card*Suit-------" << endl;
    cout << "-----------------------" << endl;
    cout << "   ";
    for (int i = 0; i < a->crdData.hndSize; i++)//Displays struct hand array
    {
        cout << a->hand[i] << "   ";
    }
    cout << endl;
    cout << "   ";
    for (int i = 0; i < a->crdData.hndSize; i++)//Displays struct hand array
    {
        cout << a->hndSuit[i] << "   ";
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
        cout << "\n\nCurrent credits: " << a->credits << endl;
        cout << "Please enter a valid bet amount 1-5 or no more then current credits: ";
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
        a->hand[val - 1] = a->crdData.card[rand() % a->crdData.ACE + 1]; //Replace discarded cards
        a->hndSuit[val - 1] = a->crdData.suits[rand() % a->crdData.SPADES + 1]; //Replace suits for new cards
    }
}

void winConditions(Player *a, int bet, int index)
{
    //Dynamic arrays of card/suit hand to sort for easier way of tracking winning hands
    string *tempCrd = new string[a->crdData.hndSize];
    char *tempSut = new char[a->crdData.hndSize]; //C-String array
    //Booleans for win conditions and winningAmt function
    bool rFlush, sFlush, fourKnd, fHouse, flsh, strt, thrKnd, twoKnd, jacks;

    sortCards(tempCrd, a, tempSut); //Assigns card hand to new sorted dynamic array 
    cout << endl;

    royalFlush(tempCrd, tempSut, rFlush, a); //Functions to check if winning hand
    straightFlush(tempCrd, tempSut, sFlush, a);
    fourKind(tempCrd, fourKnd);
    fullHouse(tempCrd, fHouse);
    flush(tempSut, flsh, a);
    straight(tempCrd, strt, a);
    threeKind(tempCrd, thrKnd);
    twoKind(tempCrd, twoKnd, a);
    jacksOrBetter(tempCrd, jacks, a);
    winningAmt(rFlush, sFlush, fourKnd, fHouse, flsh, strt, thrKnd, twoKnd, jacks,
            bet, a, index); //Function to adjust earnings and display winnings
    delete[] tempCrd; //De-Allocate memory for temp sorted array
    delete[] tempSut; //De-Allocate memory for temp sorted array
}

void sortCards(string *card, const Player *b, char *suit)
{
    for (int i = 0; i < b->crdData.hndSize; i++)
    {
        card[i] = b->hand[i];
        suit[i] = b->hndSuit[i];
    }

    for (int i = 0; i < b->crdData.hndSize; i++)//Nested for loop for bubble sorting
    {
        for (int j = 0; j < b->crdData.hndSize - 1; j++)
        {
            int card1, card2;
            card1 = cardValue(card[j]);
            card2 = cardValue(card[j + 1]);
            if (card1 > card2)
            {
                swap(card[j], card[j + 1]);
                swap(suit[j], suit[j + 1]);
            }
        }
    }
}

void swap(string *a, string *b)
{
    string *temp = a;
    a = b;
    b = temp;
}

void swap(char *a, char *b)
{
    char *temp = a;
    a = b;
    b = temp;
}

void royalFlush(const string *card, const char *suit, bool &cond, const Player *a)
{
    int count = 1;
    for (int i = 0; i < a->crdData.hndSize - 1; i++)//Checks for consec. suit
    {
        if (suit[i] == suit[i + 1])
        {
            count++;
        }
    }
    if (card[0] == "10" && card[1] == "J" && card[2] == "Q" && card[3]
            == "K" && card[4] == "A" && count == 5)
    {
        cond = true;
    }
    else
    {
        cond = false;
    }
}

void straightFlush(const string *card, const char *suit, bool &cond, const Player *a)
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, count = 1;
    bool noFace = true;
    for (int i = 0; i < a->crdData.hndSize; i++)//Check for non face cards for int conv bool
    {
        if (card[i] == "J" || card[i] == "Q" || card[i] == "K" || card[i] == "A")
        {
            noFace = false;
        }
    }
    for (int i = 0; i < a->crdData.hndSize - 1; i++)//Check consec. suits
    {
        if (suit[i] == suit[i + 1])
        {
            count++;
        }
    }

    if (noFace)//Converts string to int value for straight cond. check w/o facecards
    {
        num1 = stoi(card[0]);
        num2 = stoi(card[1]);
        num3 = stoi(card[2]);
        num4 = stoi(card[3]);
        num5 = stoi(card[4]);
    }

    if (card[0] == "9" && card[1] == "10" && card[2] == "J" && card[3] == "Q"
            && card[4] == "K" && count == 5)
    {
        cond = true;
    }
    else if (card[0] == "8" && card[1] == "9" && card[2] == "10" && card[3] == "J"
            && card[4] == "Q" && count == 5)
    {
        cond = true;
    }
    else if (card[0] == "7" && card[1] == "8" && card[2] == "9" && card[3] == "10"
            && card[4] == "J" && count == 5)
    {
        cond = true;
    }
    else if (num2 == num1 + 1 && num3 == num2 + 1 && num4 == num3 + 1
            && num5 == num4 + 1 && count == 5)
    {
        cond = true;
    }
    else
    {
        cond = false;
    }
}

void fourKind(const string *card, bool &cond)
{

    if (card[0] == card[1] && card[1] == card[2] && card[2] == card[3])
    {
        cond = true;
    }
    else if (card[1] == card[2] && card[2] == card[3] && card[3] == card[4])
    {
        cond = true;
    }
    else
    {
        cond = false;
    }
}

void fullHouse(const string *card, bool &cond)
{
    if (card[0] == card[1] && card[1] == card[2] && card[3] == card[4])
    {
        cond = true;
    }
    else if (card[0] == card[1] && card[2] == card[3] && card[3] == card[4])
    {
        cond = true;
    }
    else
    {
        cond = false;
    }
}

void flush(const char *suit, bool &cond, const Player *a)
{
    int count = 1;

    for (int i = 0; i < a->crdData.hndSize - 1; i++)//Check consec. suits
    {
        if (suit[i] == suit[i + 1])
        {
            count++;
        }
    }

    if (count == 5)
    {
        cond = true;
    }
    else
    {
        cond = false;
    }
}

void straight(const string *card, bool &cond, const Player *a)
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
    bool noFace = true;
    for (int i = 0; i < a->crdData.hndSize; i++)//Check for non face cards for int conv bool
    {
        if (card[i] == "J" || card[i] == "Q" || card[i] == "K" || card[i] == "A")
        {
            noFace = false;
        }
    }

    if (noFace)//Converts string to int value for straight cond. check w/o facecards
    {
        num1 = stoi(card[0]);
        num2 = stoi(card[1]);
        num3 = stoi(card[2]);
        num4 = stoi(card[3]);
        num5 = stoi(card[4]);
    }

    if (card[0] == "9" && card[1] == "10" && card[2] == "J" && card[3] == "Q"
            && card[4] == "K")
    {
        cond = true;
    }
    else if (card[0] == "8" && card[1] == "9" && card[2] == "10" && card[3] == "J"
            && card[4] == "Q")
    {
        cond = true;
    }
    else if (card[0] == "7" && card[1] == "8" && card[2] == "9" && card[3] == "10"
            && card[4] == "J")
    {
        cond = true;
    }
    else if (num2 == num1 + 1 && num3 == num2 + 1 && num4 == num3 + 1
            && num5 == num4 + 1)
    {
        cond = true;
    }
    else
    {
        cond = false;
    }
}

void threeKind(const string *card, bool &cond)
{
    if (card[0] == card[1] && card[1] == card[2])
    {
        cond = true;
    }
    else if (card[2] == card[3] && card[3] == card[4])
    {
        cond = true;
    }
    else
    {
        cond = false;
    }
}

void twoKind(const string *card, bool &cond, const Player *a)
{
    int count = 0, pair = 0;
    for (int i = 0; i < a->crdData.hndSize - 1; i++)
    {
        if (card[i] == card[i + 1])
        {
            count++;
            i++;
        }
    }
    if (count == 2)
    {
        cond = true;
    }
    else
    {
        cond = false;
    }
}

void jacksOrBetter(const string *card, bool &cond, const Player *a)
{
    int count = 1;
    for (int i = 0; i < a->crdData.hndSize - 1; i++)
    {
        if (card[i] == "J" || card[i] == "Q" || card[i] == "K" || card[i] == "A")
        {
            if (card[i] == card[i + 1])//Nested if loop
            {
                count++;
            }
        }
    }
    if (count == 2)
    {
        cond = true;
    }
    else
    {
        cond = false;
    }
}

void winningAmt(bool Rf, bool Sf, bool frK, bool fHous, bool Flus, bool Strt,
        bool thrK, bool twoK, bool jcks, int bet, Player *a, int index)
{
    int winAmt = 0;
    if (Rf)
    {
        cout << "You hit a Royal Flush!" << endl;
        if (bet == 1)
        {
            winAmt = 250;
            a->credits += winAmt;
        }
        if (bet == 2)
        {
            winAmt = 500;
            a->credits += winAmt;
        }
        if (bet == 3)
        {
            winAmt = 750;
            a->credits += winAmt;
        }
        if (bet == 4)
        {
            winAmt = 1000;
            a->credits += winAmt;
        }
        if (bet == 5)
        {
            winAmt = 4000;
            a->credits += winAmt;
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a->credits << endl;
        a->record[index].hndWon++;
    }
    else if (Sf)
    {
        cout << "You hit a Straight Flush!" << endl;
        if (bet == 1)
        {
            winAmt = 50;
            a->credits += winAmt;
        }
        if (bet == 2)
        {
            winAmt = 100;
            a->credits += winAmt;
        }
        if (bet == 3)
        {
            winAmt = 150;
            a->credits += winAmt;
        }
        if (bet == 4)
        {
            winAmt = 200;
            a->credits += winAmt;
        }
        if (bet == 5)
        {
            winAmt = 250;
            a->credits += winAmt;
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a->credits << endl;
        a->record[index].hndWon++;
    }
    else if (frK)
    {
        cout << "You hit a Four of a Kind!" << endl;
        if (bet == 1)
        {
            winAmt = 25;
            a->credits += winAmt;
        }
        if (bet == 2)
        {
            winAmt = 50;
            a->credits += winAmt;
        }
        if (bet == 3)
        {
            winAmt = 75;
            a->credits += winAmt;
        }
        if (bet == 4)
        {
            winAmt = 100;
            a->credits += winAmt;
        }
        if (bet == 5)
        {
            winAmt = 125;
            a->credits += winAmt;
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a->credits << endl;
        a->record[index].hndWon++;
    }
    else if (fHous)
    {
        cout << "You hit a Full House!" << endl;
        if (bet == 1)
        {
            winAmt = 9;
            a->credits += winAmt;
        }
        if (bet == 2)
        {
            winAmt = 18;
            a->credits += winAmt;
        }
        if (bet == 3)
        {
            winAmt = 27;
            a->credits += winAmt;
        }
        if (bet == 4)
        {
            winAmt = 36;
            a->credits += winAmt;
        }
        if (bet == 5)
        {
            winAmt = 45;
            a->credits += winAmt;
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a->credits << endl;
        a->record[index].hndWon++;
    }
    else if (Flus)
    {
        cout << "You hit a Flush!" << endl;
        if (bet == 1)
        {
            winAmt = 6;
            a->credits += winAmt;
        }
        if (bet == 2)
        {
            winAmt = 12;
            a->credits += winAmt;
        }
        if (bet == 3)
        {
            winAmt = 18;
            a->credits += winAmt;
        }
        if (bet == 4)
        {
            winAmt = 24;
            a->credits += winAmt;
        }
        if (bet == 5)
        {
            winAmt = 30;
            a->credits += winAmt;
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a->credits << endl;
        a->record[index].hndWon++;
    }
    else if (Strt)
    {
        cout << "You hit a Straight!" << endl;
        if (bet == 1)
        {
            winAmt = 4;
            a->credits += winAmt;
        }
        if (bet == 2)
        {
            winAmt = 8;
            a->credits += winAmt;
        }
        if (bet == 3)
        {
            winAmt = 12;
            a->credits += winAmt;
        }
        if (bet == 4)
        {
            winAmt = 16;
            a->credits += winAmt;
        }
        if (bet == 5)
        {
            winAmt = 20;
            a->credits += winAmt;
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a->credits << endl;
        a->record[index].hndWon++;
    }
    else if (thrK)
    {
        cout << "You hit a Three of a Kind!" << endl;
        if (bet == 1)
        {
            winAmt = 3;
            a->credits += winAmt;
        }
        if (bet == 2)
        {
            winAmt = 6;
            a->credits += winAmt;
        }
        if (bet == 3)
        {
            winAmt = 9;
            a->credits += winAmt;
        }
        if (bet == 4)
        {
            winAmt = 12;
            a->credits += winAmt;
        }
        if (bet == 5)
        {
            winAmt = 15;
            a->credits += winAmt;
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a->credits << endl;
        a->record[index].hndWon++;
    }
    else if (twoK)
    {
        cout << "You hit a Two of a Kind!" << endl;
        if (bet == 1)
        {
            winAmt = 2;
            a->credits += winAmt;
        }
        if (bet == 2)
        {
            winAmt = 4;
            a->credits += winAmt;
        }
        if (bet == 3)
        {
            winAmt = 6;
            a->credits += winAmt;
        }
        if (bet == 4)
        {
            winAmt = 8;
            a->credits += winAmt;
        }
        if (bet == 5)
        {
            winAmt = 10;
            a->credits += winAmt;
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a->credits << endl;
        a->record[index].hndWon++;
    }
    else if (jcks)
    {
        cout << "You hit a Pair of Jacks or better!" << endl;
        if (bet == 1)
        {
            winAmt = 1;
            a->credits += winAmt;
        }
        if (bet == 2)
        {
            winAmt = 2;
            a->credits += winAmt;
        }
        if (bet == 3)
        {
            winAmt = 3;
            a->credits += winAmt;
        }
        if (bet == 4)
        {
            winAmt = 4;
            a->credits += winAmt;
        }
        if (bet == 5)
        {
            winAmt = 5;
            a->credits += winAmt;
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a->credits << endl;
        a->record[index].hndWon++;
    }
    else
    {
        cout << "You did not have a winning hand!" << endl;
        cout << "       0 credits earned" << endl;
        cout << "    Current credits = " << a->credits << endl;
        a->record[index].hndLost++;
        a->record[index].crdLost += bet;
    }
    a->record[index].crdWon += winAmt;
}

int cardValue(const string card)
{
    try
    {
        return stoi(card);
    } catch (...)
    {
        if (card == "J")
        {
            return 11;
        }
        else if (card == "Q")
        {
            return 12;
        }
        else if (card == "K")
        {
            return 13;
        }
        else if (card == "A")
        {
            return 14;
        }
    }
}

void fileCreateIfNoExist(string fileName)
{
    fstream fileIn, fileOut;
    string frstLine = "VideoPokerRecords";
    string name = "Name";
    fileIn.open(fileName, ios::in);
    if (fileIn.fail())
    {
        fileIn.close();
        fileOut.open(fileName, ios::out);
        fileOut << frstLine << endl;
        for (int i = 0; i < 10; i++)
        {
            fileOut << name << endl;
            for (int j = 0; j < 4; j++)
            {
                fileOut << 0 << endl;
            }
        }
        fileOut.close();
    }
    else
    {
        fileIn.close();
    }
}

void binCreateIfNoExist(string fileName)
{
    fstream fileIn, fileOut;
    string frstLine = "VideoPokerRecords";
    fileIn.open(fileName, ios::in | ios::binary);
    if (fileIn.fail())
    {
        fileIn.close();
        fileOut.open(fileName, ios::out | ios::binary);
        fileOut << frstLine << endl;
        fileOut.close();
    }
    else
    {
        fileIn.close();
    }
}

void recordUpdate(string fileName, Player *a)
{
    fstream fileOut;
    string frstLine = "VideoPokerRecords";
    bool stop = true;
    fileOut.open(fileName, ios::out);
    fileOut << frstLine << endl;
    while (!fileOut.eof() && stop)
    {
        for (int i = 0; i < a->crdData.rcdSize; i++)
        {
            fileOut << a->record[i].name << endl;
            fileOut << a->record[i].crdWon << endl;
            fileOut << a->record[i].crdLost << endl;
            fileOut << a->record[i].hndWon << endl;
            fileOut << a->record[i].hndLost << endl;
        }
        stop = false;
    }
    fileOut.close();
}
//Non working*******************

void getRecords(string fileName, Player *a)
{
    string nxtLine;
    fstream fileIn;
    int loopSz = 50;
    bool stop = true;
    fileIn.open(fileName, ios::in);

    while (!fileIn.eof() && stop)
    {
        getline(fileIn, nxtLine);
        for (int i = 0; i < a->crdData.rcdSize; i++)
        {
            getline(fileIn, nxtLine);
            a->record[i].name = nxtLine;
            getline(fileIn, nxtLine);
            a->record[i].crdWon = stoi(nxtLine);
            getline(fileIn, nxtLine);
            a->record[i].crdLost = stoi(nxtLine);
            getline(fileIn, nxtLine);
            a->record[i].hndWon = stoi(nxtLine);
            getline(fileIn, nxtLine);
            a->record[i].hndLost = stoi(nxtLine);
        }
        stop = false;
    }
    fileIn.close();
}

void binFileOut(string fileName)
{

}

void binFileIn()
{

}

void menuReturn()
{
    char rtnMenu;
    cout << "\nType any key to clear screen and return to menu!";
    cin >> rtnMenu;
}
