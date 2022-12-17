/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 7, 2022, 10:30 AM
 * Purpose: Project 2 Video Poker Jacks or Better, changing to a class and adding 
 * content from chapters 13-16. Revision of Project 1, Previous Final of 
 * Project 1 included for change reference.
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

//User Defined Libraries
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
//Global Constants
const int RECSIZE = 5;
//Function Prototypes
void clearScreen();
void displayMenu(const Player *a, int &menu, int index);
void menuReturn();
Player *hand(Player *a, int &index, string &name);
void dealHand(const Player *a, const int index);
int betAmount(const Player *a, const int index);
void discard(Player *a, const int index);
void replaceDiscard(Player *a, int num, const int index);
void winConditions(Player *a, int bet, const int index);
void sortCards(string *card, const Player *b, string *suit, const int index);
int cardValue(const string card);
void swap(string *a, string *b);
void royalFlush(const string *card, const string *suit, bool &cond);
void straightFlush(const string *card, const string *suit, bool &cond);
void fourKind(const string *card, bool &cond);
void fullHouse(const string *card, bool &cond);
void flush(const string *suit, bool &cond);
void straight(const string *card, bool &cond);
void threeKind(const string *card, bool &cond);
void twoKind(const string *card, bool &cond);
void jacksOrBetter(const string *card, bool &cond);
void winningAmt(bool Rf, bool Sf, bool frK, bool fHous, bool Flus, bool Strt,
        bool thrK, bool twoK, bool jcks, int bet, Player *a, const int index);
void fileCreateIfNoExist(string fileName);
void binCreateIfNoExist(string fileName);
void recordUpdate(string fileName, Player *a);
void getRecords(string fileName, Player *a);
//Execution begins here!

int main(int argc, char** argv){
    srand(time(NULL)); //Set Random Seed
    //Variables
    int recSize = 5;
    int menu, betAmt, index = 0;//Variables for menu, bet amount, object index
    string name; //Keeps track if user name is already entered
    
    //Class Object Variable Array
    Player player[RECSIZE] = {Player(), Player(), Player(),Player(),Player()};
    //Create record files if none exist
    string txtFile = "VideoPokerRecords.dat";
    string binFile = "BinaryPokerRecords.dat";
    fileCreateIfNoExist(txtFile);
    binCreateIfNoExist(binFile);
    getRecords(txtFile, player);//Grabs records if player name already exists
    do{
        displayMenu(player, menu, index); //Displays Menu

        switch(menu)//Switch for menu options
        {
            case 1:
                clearScreen(); //clears screen to keep things clean
                hand(player, index, name); //function that creates hand
                dealHand(player, index); //function that displays hand
                betAmt = betAmount(player, index); //function that determines bet amount
                player[index].loseCredits(betAmt); //adjust credits for bet amount
                discard(player, index); //function that allows user to discard cards
                dealHand(player, index); //display new discarded hand
                winConditions(player, betAmt, index); //function that handles win cond.
                recordUpdate(txtFile, player); //updates file with new records
                menuReturn();
                break;
            case 2:
                
                menuReturn();
                break;
            case 3:
                cout << "\nCurrent credits are: " << player[index].getCredits() << endl;
                menuReturn();
                break;
            case 4:
                cout << "You have quit, better luck next time!" << endl;
                break;
            default:
                cout << "Please enter a valid menu option: ";
        }
    }while(menu != 4 && player[index].getCredits() != 0); //Loops until out of credits or player quits
    if(player[index].getCredits() == 0){
        cout << "You have ran out of credits, better luck next time!" << endl;
    }
    return 0;
}
//Functions
/**
 * Clears the screen to make things neat
 */
void clearScreen(){
    int size = 40;
    for(int i = 0; i < size; i++){
        cout << "\n";
    }
}
/**
 * Displays menu and tracks credits
 * @param a - class object with credits
 * @param menu - menu option variable
 */
void displayMenu(const Player *a, int &menu, int index){
    int input;
    do{
        clearScreen(); //Clears screen to keep things clean
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
    }while((input > 4 || input < 1) && a[index].getCredits() != 0); //Error checking for credits & menu
    if(a[index].getCredits() == 0)//If user runs out of credits
    {
        cout << "You have ran out of credits, better luck next time!" << endl;
    }
}
/**
 * Pseudo Pause for screen clearing and menu return
 */
void menuReturn()
{
    char rtnMenu;
    cout << "\nType any key to clear screen and return to menu!";
    cin >> rtnMenu;
}
/**
 * Finds records and displays stats
 * @param a
 * @param name
 */
Player *hand(Player *a, int &index, string &name)
{
    string plcHld = "Name";
    while (a[index].getName() == plcHld )
    {
        cout << "Will record stats up to 5 players!" << endl;
        cout << "Please enter your user name that is 4 chars long: ";
        cin >> name;
        a[index].setName(name);
        while (name.size() != 4)
        {
            cout << "Please enter your user name that is 4 chars long: ";
            cin >> name;
            a[index].setName(name);
        }

        for (int i = 0; i < RECSIZE; i++)
        {
            if (a[index].getName() == name)
            {
                index = i;
                break;
            }
            else if (a[index].getName() == plcHld)
            {
                a[index].setName(name);
                index = i;
                break;
            }
        }
    }
    a[index].setInitialHand();//Sets Random Face/Suit card hand
    return a;
}
/**
 * Displays struct hand/suit to player
 * @param a
 */
void dealHand(const Player *a, const int index)
{
    cout << "\n*******Your Hand*******" << endl;
    cout << "-------Card*Suit-------" << endl;
    cout << "-----------------------" << endl;
    cout << "   ";
    for (int i = 0; i < HSIZE; i++)//Displays struct hand array
    {
        cout << a[index].getFaceArray()[i] << "   ";
    }
    cout << endl;
    cout << "   ";
    for (int i = 0; i < HSIZE; i++)//Displays struct hand array
    {
        cout << a[index].getSuitArray()[i] << "   ";
    }
    cout << endl;
}
/**
 * Determines bet amount 1-5 from user
 * @param a
 * @return bet amount
 */
int betAmount(const Player *a, const int index)
{
    int betAmt;
    cout << "\n\nCurrent credits: " << a[index].getCredits() << endl; //Display credits
    cout << "**Higher bet = increased pay outs**" << endl; //Announce bet payouts
    cout << "Choose your starting bet amount 1-5: ";
    cin >> betAmt;

    while (betAmt < 1 || betAmt > 5 || a[index].getCredits() < betAmt)//Error checking for bet
    {
        cout << "\n\nCurrent credits: " << a[index].getCredits() << endl;
        cout << "Please enter a valid bet amount 1-5 or no more then current credits: ";
        cin >> betAmt;
        if (a[index].getCredits() == 0)//If player has no credits
        {
            cout << "You have ran out of credits";
            break;
        }
    }

    return betAmt;
}
/**
 * Determines if user wants to discard card, replaces discarded cards if yes
 * @param a
 */
void discard(Player *a, const int index)
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
        replaceDiscard(a, num, index);
    }
    else//player chose not to discard
    {
        cout << "You have chose not to discard any cards!" << endl;
    }
}
/**
 * Replaces discarded cards hand/suit
 * @param a
 * @param num
 */
void replaceDiscard(Player *a, int num, const int index)
{
    int discard[num]; //Array to hold index of cards to discard
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
        while (i != 0 && val - 1 == discard[i - 1])//Error checking for duplicate discard
        {
            cout << "Please choose a card you have not discarded yet: " << endl;
            cout << "Card " << cardNum << ": ";
            cin >> val;
        }
        discard[i] = val - 1; //val - 1 since index starts at 0
        cardNum++;
        a[index].setFaceHand(val - 1); //Replace discarded cards
        a[index].setSuitHand(val - 1); //Replace suits for new cards
    }
}
/**
 * Sorts player hand for checking win conditions, determines win conditions and payout
 * @param a
 * @param bet
 * @param index
 */
void winConditions(Player *a, int bet, const int index)
{
    //Dynamic arrays of card/suit hand to sort for easier way of tracking winning hands
    string *tempCrd = new string[HSIZE];
    string *tempSut = new string[HSIZE]; //C-String array
    //Booleans for win conditions and winningAmt function
    bool rFlush, sFlush, fourKnd, fHouse, flsh, strt, thrKnd, twoKnd, jacks;

    sortCards(tempCrd, a, tempSut, index); //Assigns card hand to new sorted dynamic array 
    cout << endl;

    royalFlush(tempCrd, tempSut, rFlush); //Functions to check if winning hand
    straightFlush(tempCrd, tempSut, sFlush);
    fourKind(tempCrd, fourKnd);
    fullHouse(tempCrd, fHouse);
    flush(tempSut, flsh);
    straight(tempCrd, strt);
    threeKind(tempCrd, thrKnd);
    twoKind(tempCrd, twoKnd);
    jacksOrBetter(tempCrd, jacks);
    winningAmt(rFlush, sFlush, fourKnd, fHouse, flsh, strt, thrKnd, twoKnd, jacks,
            bet, a, index); //Function to adjust earnings and display winnings
    delete[] tempCrd; //De-Allocate memory for temp sorted array
    delete[] tempSut; //De-Allocate memory for temp sorted array
}
void sortCards(string *card, const Player *b, string *suit, const int index)
{
    for (int i = 0; i < HSIZE; i++)
    {
        card[i] = b[index].getFaceArray()[i];
        suit[i] = b[index].getSuitArray()[i];
    }

    for (int i = 0; i < HSIZE; i++)//Nested for loop for bubble sorting
    {
        for (int j = 0; j < HSIZE - 1; j++)
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
/**
 * Swap function for sorting hand
 * @param a
 * @param b
 */
void swap(string *a, string *b)
{
    string *temp = a;
    a = b;
    b = temp;
}
/**
 * Determines if hand is royal flush
 * @param card
 * @param suit
 * @param cond
 * @param a
 */
void royalFlush(const string *card, const string *suit, bool &cond)
{
    int count = 1;
    for (int i = 0; i < HSIZE - 1; i++)//Checks for consec. suit
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
/**
 * Determines if hand is straight flush
 * @param card
 * @param suit
 * @param cond
 * @param a
 */
void straightFlush(const string *card, const string *suit, bool &cond)
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, count = 1;
    bool noFace = true;
    for (int i = 0; i < HSIZE; i++)//Check for non face cards for int conv bool
    {
        if (card[i] == "J" || card[i] == "Q" || card[i] == "K" || card[i] == "A")
        {
            noFace = false;
        }
    }
    for (int i = 0; i < HSIZE - 1; i++)//Check consec. suits
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
    //Determines order of cards that include non numerical cards
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
/**
 * Determines if hand is four of a kind
 * @param card
 * @param cond
 */
void fourKind(const string *card, bool &cond)
{
    //Determines if there is 4 same cards
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
/**
 * Determines if hand is full house
 * @param card
 * @param cond
 */
void fullHouse(const string *card, bool &cond)
{
    //Checks if there is 3 then 2 of a kind
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
/**
 * Determines if hand is flush
 * @param suit
 * @param cond
 * @param a
 */
void flush(const string *suit, bool &cond)
{
    int count = 1;

    for (int i = 0; i < HSIZE - 1; i++)//Check consec. suits
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
/**
 * Determines if hand is straight
 * @param card
 * @param cond
 * @param a
 */
void straight(const string *card, bool &cond)
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
    bool noFace = true;
    for (int i = 0; i < HSIZE; i++)//Check for non face cards for int conv bool
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
    //Determines order if hand has non numerical cards
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
/**
 * Determines if hand has 3 of a kind
 * @param card
 * @param cond
 */
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
/**
 * Determines if hand has 2 of a kind
 * @param card
 * @param cond
 * @param a
 */
void twoKind(const string *card, bool &cond)
{
    int count = 0, pair = 0;
    for (int i = 0; i < HSIZE - 1; i++)
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
/**
 * Determines if hand has a pair of jacks or better
 * @param card
 * @param cond
 * @param a
 */
void jacksOrBetter(const string *card, bool &cond)
{
    int count = 1;
    for (int i = 0; i < HSIZE - 1; i++)
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
/**
 * Determines winning amount based off bool of winning hand type, if bool is true
 * each hand has its specified pay out amount based off bet amount, winnings are added
 * to current credits and records of credits won, credits lost, hand won, hand lost
 * @param Rf
 * @param Sf
 * @param frK
 * @param fHous
 * @param Flus
 * @param Strt
 * @param thrK
 * @param twoK
 * @param jcks
 * @param bet
 * @param a
 * @param index
 */
void winningAmt(bool Rf, bool Sf, bool frK, bool fHous, bool Flus, bool Strt,
        bool thrK, bool twoK, bool jcks, int bet, Player *a, const int index)
{
    int winAmt = 0;
    if (Rf)
    {
        cout << "You hit a Royal Flush!" << endl;
        if (bet == 1)
        {
            winAmt = 250;
            a[index] = ++a[index];//Overloaded class operator for hand win
            a[index].winCredits(winAmt);//Add winning credits to total credits
            a[index].setCreditsWon(winAmt);//Add winning credits to player record
        }
        if (bet == 2)
        {
            winAmt = 500;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 3)
        {
            winAmt = 750;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 4)
        {
            winAmt = 1000;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 5)
        {
            winAmt = 4000;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a[index].getCredits() << endl;
    }
    else if (Sf)
    {
        cout << "You hit a Straight Flush!" << endl;
        if (bet == 1)
        {
            winAmt = 50;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 2)
        {
            winAmt = 100;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 3)
        {
            winAmt = 150;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 4)
        {
            winAmt = 200;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 5)
        {
            winAmt = 250;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a[index].getCredits() << endl;
    }
    else if (frK)
    {
        cout << "You hit a Four of a Kind!" << endl;
        if (bet == 1)
        {
            winAmt = 25;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 2)
        {
            winAmt = 50;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 3)
        {
            winAmt = 75;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 4)
        {
            winAmt = 100;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 5)
        {
            winAmt = 125;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a[index].getCredits() << endl;
    }
    else if (fHous)
    {
        cout << "You hit a Full House!" << endl;
        if (bet == 1)
        {
            winAmt = 9;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 2)
        {
            winAmt = 18;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 3)
        {
            winAmt = 27;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 4)
        {
            winAmt = 36;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 5)
        {
            winAmt = 45;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a[index].getCredits() << endl;
    }
    else if (Flus)
    {
        cout << "You hit a Flush!" << endl;
        if (bet == 1)
        {
            winAmt = 6;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 2)
        {
            winAmt = 12;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 3)
        {
            winAmt = 18;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 4)
        {
            winAmt = 24;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 5)
        {
            winAmt = 30;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a[index].getCredits() << endl;
    }
    else if (Strt)
    {
        cout << "You hit a Straight!" << endl;
        if (bet == 1)
        {
            winAmt = 4;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 2)
        {
            winAmt = 8;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 3)
        {
            winAmt = 12;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 4)
        {
            winAmt = 16;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 5)
        {
            winAmt = 20;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a[index].getCredits() << endl;
    }
    else if (thrK)
    {
        cout << "You hit a Three of a Kind!" << endl;
        if (bet == 1)
        {
            winAmt = 3;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 2)
        {
            winAmt = 6;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 3)
        {
            winAmt = 9;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 4)
        {
            winAmt = 12;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 5)
        {
            winAmt = 15;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a[index].getCredits() << endl;
    }
    else if (twoK)
    {
        cout << "You hit a Two of a Kind!" << endl;
        if (bet == 1)
        {
            winAmt = 2;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 2)
        {
            winAmt = 4;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 3)
        {
            winAmt = 6;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 4)
        {
            winAmt = 8;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 5)
        {
            winAmt = 10;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a[index].getCredits() << endl;
    }
    else if (jcks)
    {
        cout << "You hit a Pair of Jacks or better!" << endl;
        if (bet == 1)
        {
            winAmt = 1;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 2)
        {
            winAmt = 2;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 3)
        {
            winAmt = 3;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 4)
        {
            winAmt = 4;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        if (bet == 5)
        {
            winAmt = 5;
            a[index] = ++a[index];
            a[index].winCredits(winAmt);
            a[index].setCreditsWon(winAmt);
        }
        cout << "You have won " << winAmt << " credits!" << endl;
        cout << "Current credits = " << a[index].getCredits() << endl;
    }
    else
    {
        cout << "You did not have a winning hand!" << endl;
        cout << "       0 credits earned" << endl;
        cout << "    Current credits = " << a[index].getCredits() << endl;
        a[index] = --a[index];
        a[index].setCreditsLost(bet);
    }
}
/**
 * Determines if string can be turned into an int, if not returns numerical amount
 * of face card values
 * @param card
 * @return returns numerical value of all cards in deck
 */
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
/**
 * Creates non binary file if none exist
 * @param fileName
 */
void fileCreateIfNoExist(string fileName)
{
    fstream fileIn, fileOut;
    string frstLine = "VideoPokerRecords";
    string name = "Name";
    int rcdSize = 5;
    int statSz = 4;
    fileIn.open(fileName, ios::in);
    if (fileIn.fail())
    {
        fileIn.close();
        fileOut.open(fileName, ios::out);
        fileOut << frstLine << endl;
        for (int i = 0; i < rcdSize; i++)
        {
            fileOut << name << endl;
            for (int j = 0; j < statSz; j++)
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
/**
 * Creates binary file if non exists
 * @param fileName
 */
void binCreateIfNoExist(string fileName)
{
    fstream fileIn, fileOut;
    fileIn.open(fileName, ios::in | ios::binary);
    if (fileIn.fail())
    {
        fileIn.close();
        fileOut.open(fileName, ios::out | ios::binary);

        fileOut.close();
    }
    else
    {
        fileIn.close();
    }
}
/**
 * Updates non binary file with records stats array 
 * @param fileName
 * @param a
 */
void recordUpdate(string fileName, Player *a)
{
    fstream fileOut;
    string frstLine = "VideoPokerRecords";
    bool stop = true;
    fileOut.open(fileName, ios::out);
    fileOut << frstLine << endl;
    while (!fileOut.eof() && stop)
    {
        for (int i = 0; i < RECSIZE; i++)
        {
            fileOut << a[i].getName() << endl;
            fileOut << a[i].getCreditsWon() << endl;
            fileOut << a[i].getCreditsLost() << endl;
            fileOut << a[i].getHandWon() << endl;
            fileOut << a[i].getHandLost() << endl;
        }
        stop = false;
    }
    fileOut.close();
}
/**
 * Gets records from non binary file and updates Class array with info
 * @param fileName
 * @param a
 */
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
        for (int i = 0; i < RECSIZE; i++)
        {
            getline(fileIn, nxtLine);
            a[i].setName(nxtLine);
            getline(fileIn, nxtLine);
            a[i].setCreditsWon(stoi(nxtLine));
            getline(fileIn, nxtLine);
            a[i].setCreditsLost(stoi(nxtLine));
            getline(fileIn, nxtLine);
            a[i].setHandWon(stoi(nxtLine));
            getline(fileIn, nxtLine);
            a[i].setHandLost(stoi(nxtLine));
        }
        stop = false;
    }
    fileIn.close();
}
