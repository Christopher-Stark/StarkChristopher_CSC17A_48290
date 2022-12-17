/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 2, 2022, 2:57 PM
 * Purpose:Final Problem 4 - Savings account class
 */
#include "Savings.h"

SavingsAccount::SavingsAccount(float n){ //Constructor
    if(n > 0){
        Balance = n;
        FreqWithDraw = 0;
        FreqDeposit = 0;
    }
    else{
        cout << "WithDraw not Allowed" << endl;
        Balance = 0;
        FreqWithDraw = 0;
        FreqDeposit = 0;
    }
}

void SavingsAccount::Transaction(float n){ //Procedure
    if(n > 0){
        Balance += Deposit(n);
    }
    else{
        Balance -= Withdraw(n);
        if(Balance < 0){
            cout << "Insufficient funds for WithDraw!" << endl;
            Balance += n;
            FreqWithDraw--;
        }
    }
}

float SavingsAccount::Total(float s, int t){ //Savings Procedure
    float sTotal = Balance;
    for(int i = 0; i < t; i++){
    sTotal += (sTotal*((1+s))/100);
    }
    return sTotal;
}

float SavingsAccount::TotalRecursive(float s, int t){
    if(t > 0){
        Balance += (Balance*((1+s))/100);
    }
    else{
        return Balance;
    }
    return TotalRecursive(s, t-1);
}

void SavingsAccount::toString(){ //Output Properties
    cout << "Balance=" << Balance << endl;
    cout << "WithDraw=" << FreqWithDraw << endl;
    cout << "Deposit=" << FreqDeposit << endl;
}

float SavingsAccount::Withdraw(float n){ //Utility Procedure
    FreqWithDraw++;
    return n;
}

float SavingsAccount::Deposit(float n){ //Utility Procedure
    FreqDeposit++;
    return n;
}