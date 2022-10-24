/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 18, 2022, 8:11 AM
 * Purpose: Get bank account monthly data and track overdraft fee if applied
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

//User Defined Libraries
#include "bank.h"//Struct header file
//Global Constants

//Function Prototypes
void bnkDat(BankAct *a, int &chkSize, int &depSize, float &nwBlnc);
void nwBalance(float &balance);
void dataDisplay(const BankAct *a, const int chkDep, const int chkWt);
//Execution begins here!

int main(int argc, char** argv)
{
    int chkSize = 0, depSize = 0; //Size for check & deposit array
    float nwBlnc = 0.00; //Keeps track of new balance
    BankAct *person = nullptr; //Pointer for struct
    person = new BankAct; //Dynamic Struct

    bnkDat(person, chkSize, depSize, nwBlnc); //Function to adjust Bank struct object
    dataDisplay(person, depSize, chkSize); //Displays struct data
    nwBalance(nwBlnc); //Takes balance after deposits/Withdraws and determines OD Fee

    delete person; //Deletes dynamic struct
    return 0;
}
//Functions

/**
 * Enters struct bank object data
 * @param a - struct object
 * @param chkSize - size of check array
 * @param depSize - size of deposit array
 */
void bnkDat(BankAct *a, int &chkSize, int &depSize, float &nwBlnc)
{
    int actNum;//Account number string
    string actStr;
    float *checks = new float[chkSize]; //Dynamic Array for checks
    float *deposits = new float[depSize]; //Dynamic Array for deposits
    string actName, addrs; //Account name and address
    float blnc, chckDep, chckWtd; // Monthly Balance, amnt of check, amnt of deposit
    
    cout << "Enter account# five digits or less: ";
    cin >> actStr;
    actNum = stoi(actStr);
    while (actNum > 99999 || actNum < 0 || actStr.size() > 5)//Error checking for 5 digits and positive#
    {
        cout << "Enter account# five digits or less: ";
        cin >> actStr;
        actNum = stoi(actStr);
    }
    a->actNum = actStr;

    cout << "What is the name on the account: ";
    cin.ignore();
    getline(cin, actName); //Getline for spaces
    a->name = actName;

    cout << "What is the address for the account: ";
    getline(cin, addrs);
    a->address = addrs;

    cout << "What is the monthly starting balance: ";
    cin >> blnc;
    a->mntBal = blnc;
    nwBlnc = blnc;

    cout << "How many checks have you written this month?: ";
    cin >> chkSize; //Sets size of check array
    for (int chks = 0; chks < chkSize; chks++)
    {
        cout << "What was the amount of written check " << chks + 1 << ": ";
        cin >> chckWtd;
        checks[chks] = chckWtd;
        a->mntChk[chks] = checks[chks];
        nwBlnc -= chckWtd;
    }

    cout << "How many deposits did you have this month: ";
    cin >> depSize; //Sets size of deposit array
    for (int chks = 0; chks < depSize; chks++)
    {
        cout << "What was the amount of deposit " << chks + 1 << ": ";
        cin >> chckDep;
        deposits[chks] = chckDep;
        a->mntDep[chks] = deposits[chks];
        nwBlnc += chckDep;
    }
    delete[] checks;
    delete[] deposits;
}

/**
 * Determines new balance after withdraw/deposits
 * @param balance
 */
void nwBalance(float &balance)
{
    int drfFee = 35; //Overdraft fee
    cout << "\nThe new balance after deposits/withdraws is: $" << balance << endl;
    if (balance < 0)
    {
        cout << "Your account is overdrawn and will be charged a $35 overdraft fee." << endl;
        balance -= drfFee; //Fee deducted from balance
        cout << "Your balance after the $35 overdraft fee is: $" << balance;
    }
}

/**
 * Displays struct bank data
 * @param a
 * @param depSize
 * @param chkSize
 */
void dataDisplay(const BankAct *a, const int depSize, const int chkSize)
{
    cout << "\nAccount #: " << a->actNum << endl;
    cout << "Name: " << a->name << endl;
    cout << "Address: " << a->address << endl;
    cout << "Monthly balance: $" << fixed << setprecision(2) << a->mntBal << endl;
    cout << "Checks written: ";
    if (chkSize == 0)
    {
        cout << "$0.00";
    }
    for (int chks = 0; chks < chkSize; chks++)
    {
        cout << fixed << setprecision(2) << "$" << a->mntChk[chks];
        if (chkSize > 1 && chks < chkSize - 1)
        {
            cout << ", ";
        }
    }

    cout << "\nDeposit amounts: ";
    if (depSize == 0)
    {
        cout << "$0.00";
    }
    for (int chks = 0; chks < depSize; chks++)
    {
        cout << fixed << setprecision(2) << "$" << a->mntDep[chks];
        if (depSize > 1 && chks < depSize - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}