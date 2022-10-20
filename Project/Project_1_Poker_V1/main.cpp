/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 18, 2022, 3:26 PM
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

//Function Prototypes
void dealHands(string crd, string suit);
void menu(int credits);
//Execution begins here!

int main(int argc, char** argv)
{
    const int crdStrt = 200, dckSize = 14, sSize = 4;
    string cards[dckSize] = {"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string suits[sSize] = {"D", "H", "S", "C"};
    int credits = crdStrt;

    menu(credits);


    return 0;
}
//Functions

void menu(int credits)
{
    int menu;
    do
    {
        cout << setw(20) << left;
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
        switch(menu)
        {
            case 1:
                cout << "Current credits are " << credits << endl;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout << "You have quit, better luck next time!" << endl;
                break;
            default:
                cout << "Please enter a valid menu option: ";
        }while(menu != 4);

    }
    while (credits != 200);
    }

void dealHands(string crd, string suit)
{

}

