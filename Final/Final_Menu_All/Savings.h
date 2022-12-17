/* 
 * File:   Savings.h
 * Author: Chris Stark
 *
 * Created on December 11, 2022, 7:50 PM
 */

#ifndef SAVINGS_H
#define SAVINGS_H
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;

class SavingsAccount {
public:
    SavingsAccount(float); //Constructor
    void Transaction(float); //Procedure
    float Total(float = 0, int = 0); //Savings Procedure
    float TotalRecursive(float = 0, int = 0);
    void toString(); //Output Properties
private:
    float Withdraw(float); //Utility Procedure
    float Deposit(float); //Utility Procedure
    float Balance; //Property
    int FreqWithDraw; //Property
    int FreqDeposit; //Property
} ;

#endif /* SAVINGS_H */

