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
//Execution begins here!

int main(int argc, char** argv){
    srand(time(NULL)); //Set Random Seed
    //Variables
    int recSize = 5;
    int menu, betAmt, index = 0;//Variables for menu, bet amount, object index
    string name; //Keeps track if user name is already entered
    
    //Class Object Variable Array
    Player player[RECSIZE] = {Player(), Player(), Player(),Player(),Player()};
    do{
        displayMenu(player, menu, index); //Displays Menu

        switch(menu)//Switch for menu options
        {
            case 1:
                clearScreen(); //clears screen to keep things clean
                hand(player, index, name); //function that creates hand
                dealHand(player, index); //function that displays hand
                //betAmt = betAmount(player); //function that determines bet amount
                //player->credits -= betAmt; //adjust credits for bet amount
                //discard(player); //function that allows user to discard cards
                //dealHand(player); //display new discarded hand
                //winConditions(player, betAmt, index); //function that handles win cond.
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
