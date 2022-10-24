/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 20, 2022, 10:24 AM
 * Purpose: Midterm Final with all problems on switch menu
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>
using namespace std;

//User Libraries
#include "bank.h"//Problem 1 header file
#include "GrossPay.h"//Problem 2 header file
#include "primes.h"//Problem 7 header file
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();
//Problem 1 Functions
void bnkDat(BankAct *a, int &chkSize, int &depSize, float &nwBlnc);
void nwBalance(float &balance);
void dataDisplay(const BankAct *a, const int chkDep, const int chkWt);
//Problem 2 Functions
void employeeData(Employ *a, int size);
void displayData(const Employ *a, int size);
void totalPay(Employ *a, int size);
void romanNumConv(const Employ *a, int index);
//Problem 4 Functions
bool errorCheck(int &num, bool &error, string strNum);
void encrypt(int &num, bool &ldZero);
void decrypt(int &num);
int reverseMod(int remain, int mod, int a);
//Problem 5 Functions
void displayFact();
//Problem 6 Functions

//Problem 7 Functions
Primes *factor(int num, int &index);
void prntPrm(Primes *a, int num, int index);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}
/**
 * Menu Function
 */
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1 - Bank information"<<endl;
    cout<<"Type 2 for Problem 2 - Employee pay"<<endl;
    cout<<"Type 3 for Problem 3 - Stat Function"<<endl;   
    cout<<"Type 4 for Problem 4 - Phone 4 digit encryption"<<endl;
    cout<<"Type 5 for Problem 5 - Highest factorial for data type before incorrect value/error"<<endl;
    cout<<"Type 6 for Problem 6 - Conversion/NASA Format results"<<endl;
    cout<<"Type 7 for Problem 7 - Factor primes of integer"<<endl<<endl;
}
/**
 * Problem 1 Bank information Main
 */
void prblm1(){
    cout<<"****Problem 1 - Bank information****"<<endl;
    int chkSize = 0, depSize = 0; //Size for check & deposit array
    float nwBlnc = 0.00; //Keeps track of new balance
    BankAct *person = nullptr; //Pointer for struct
    person = new BankAct; //Dynamic Struct

    bnkDat(person, chkSize, depSize, nwBlnc); //Function to adjust Bank struct object
    dataDisplay(person, depSize, chkSize); //Displays struct data
    nwBalance(nwBlnc); //Takes balance after deposits/Withdraws and determines OD Fee
    cout << endl;
    delete person; //Deletes dynamic struct
}

/**
 * Problem 2 Employee Pay Main
 */
void prblm2(){
    cout<<"****Problem 2 - Employee pay****"<<endl;
    int size;

    cout << "Please enter how many employees: ";
    cin >> size; //Size for struct array

    Employ *person = nullptr;
    person = new Employ[size]; //Dynamic struct array

    employeeData(person, size); //Gets employee data from user
    totalPay(person, size); //Determines total pay with straight,double,triple adjustments
    displayData(person, size); //Displays struct array data in the form of a check

    delete[] person; //De-allocate dynamic struct array
}

/**
 * Problem 3 Stat - declare location of project
 */
void prblm3(){
    cout<<"****Problem 3 - Stat Function****"<<endl;
    cout << "This problem is included in another project 'Midterm_Q3_Statistics'" << endl;
}

/**
 * Problem 4 Phone/4 digit encryption Main
 */
void prblm4(){
    cout<<"****Problem 4 - Phone 4 digit encryption****"<<endl;
    int num;
    bool ldZero = false;
    string strNum;
    stringstream input;
    bool redo = false; //Bool for error checking

    cout << "Please enter a 4 digit number (0-7's only) that you want encrypted: ";
    cin >> strNum; //Int entry from user
    input << strNum;
    input >> num;

    errorCheck(num, redo, strNum); //Error checking function
    encrypt(num, ldZero); //Encrypts num data
    cout << "The number after encryption is: ";
    if(ldZero)
    {
        cout << "0";
    }
    cout << num << endl;
    decrypt(num);
    cout << "The number after decryption is: " << num << endl;
}
/**
 * Problem 5 Highest Factorial of data type Main
 */
void prblm5(){
    cout<<"****Problem 5 - Highest factorial for data type before incorrect value/error****"<<endl;
    displayFact();//Function for output
}
/**
 * Problem 6 Conversion/NASA Format Main
 */
void prblm6(){
    cout<<"****Problem 6 - Conversion/NASA Format results****"<<endl;
}
/**
 * Problem 7 Factor int into primes Main
 */
void prblm7(){
    cout<<"****Problem 7 - Factor primes of integer****"<<endl;
    int num, index = 0;
    Primes *data;
    cout << "Please enter a positive # between 2-265000 to factor it's primes: ";
    cin >> num;
    while (num < 0 || num > 265000)
    {
        cout << "Please enter a positive # between 2-265000 to factor it's primes: ";
        cin >> num;
    }

    data = factor(num, index);
    prntPrm(data, num, index);
    cout << endl;
    delete data;
}
// ***** My Functions for problem 1 - Bank info *****
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

// ***** My Functions for problem 2 - Employee Pay *****
/**
 * Inputs data into Employee Struct
 * @param a
 * @param size
 */
void employeeData(Employ *a, int size)
{
    //Declared variables for this function
    string cmp = {"Stark Inc."}, name, addrs;
    float hrs, rtPay;

    for (int emp = 0; emp < size; emp++)
    {
        a[emp].comp = cmp; //Company name is static
        cout << "\nWhat is the employees name: ";
        cin.ignore();
        getline(cin, name);
        a[emp].name = name; //Adds name to struct at current index

        cout << "What is " << a[emp].name << "'s address: ";
        getline(cin, addrs);
        a[emp].addrs = addrs; //Adds address to struct at current index

        cout << "How many hours worked: ";
        cin >> hrs;
        while (hrs < 0)//Error checking for positive hours worked
        {
            cout << "Please enter a positive amount of hours worked: ";
            cin >> hrs;
        }
        a[emp].hrs = hrs; //Adds hours worked to struct at current index

        cout << "What is " << a[emp].name << "'s rate of pay: $";
        cin >> rtPay;
        while (rtPay < 0)//Error checking for positive pay rate worked
        {
            cout << "Please enter a positive rate of pay: ";
            cin >> rtPay;
        }
        a[emp].rtPay = rtPay; //Adds rate of pay to struct at current index
    }
    cout << endl;
}

/**
 * Displays struct array data in the form of a check
 * @param a
 * @param size
 */
void displayData(const Employ *a, int size)
{
    for (int emp = 0; emp < size; emp++)
    {
        cout << "\nCompany " << a[emp].comp << endl;
        cout << "Address " << a[emp].addrs << endl;
        cout << "Name: " << a[emp].name << fixed << setprecision(2)
                << " Amount: $" << a[emp].totPay << endl;
        cout << "Amount: ";
        romanNumConv(a, emp); //Roman numeral conversion for check display
        cout << endl;
        cout << "Signature Line:" << endl;
    }
}

/**
 * Determines total pay with adjustments to double and triple time.
 * @param a
 * @param size
 */
void totalPay(Employ *a, int size)
{
    //Remainder when calculating overtime, increase pay rates based off hours
    float remain = 0.00;
    int str = 20, dHrs = 20, trip = 40, dPay = 2, tPay = 3;

    for (int emp = 0; emp < size; emp++)
    {
        if (a[emp].hrs > trip)//Determines straight,double,triple time amounts
        {
            remain = fmod(a[emp].hrs,trip);
            a[emp].totPay += remain * (a[emp].rtPay * tPay);
            a[emp].totPay += dHrs * (a[emp].rtPay * dPay);
            a[emp].totPay += str * a[emp].rtPay;
        }
        else if (a[emp].hrs > str && a[emp].hrs <= trip)//Determines straight,double
        {
            if (a[emp].hrs == trip)
            {
                a[emp].totPay += dHrs * (a[emp].rtPay * dPay);
                a[emp].totPay += str * a[emp].rtPay;
            }
            else
            {
                remain = fmod(a[emp].hrs,str);
                a[emp].totPay += remain * (a[emp].rtPay * dPay);
                a[emp].totPay += str * a[emp].rtPay;
            }
        }
        else//Else just standard straight pay
        {
            a[emp].totPay += a[emp].hrs * a[emp].rtPay;
        }
    }
}

/**
 * Code supplied by Dr.Lehr made minor adjustments to fit my code
 * Converts struct array Total pay into Roman Numeral system for paycheck display
 * @param a
 * @param index
 */
void romanNumConv(const Employ *a, int index)
{
    //Uses struct total pay amount
    if (a[index].totPay >= 1 && a[index].totPay <= 1000000)
    {
        //Takes total pay and determines 1000's, 100's, 10's, 1's
        unsigned int n1000s, n100s, n10s, n1s;
        n1000s = static_cast<int> (a[index].totPay) / 1000; //Shift 3 places to the left
        n100s = static_cast<int> (a[index].totPay) % 1000 / 100; //Remainder of division of 1000 then shift 2 left
        n10s = static_cast<int> (a[index].totPay) % 100 / 10; //Remainder of division of 100 then shift 1 left
        n1s = static_cast<int> (a[index].totPay) % 10; //Remainder of division by 10

        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch (n1000s)
        {
            case 3:cout << 'M';
            case 2:cout << 'M';
            case 1:cout << 'M';
        }

        //Output the number of 100's
        //Using the Ternary Operator
        cout << (n100s == 9 ? "CM" :
                n100s == 8 ? "DCCC" :
                n100s == 7 ? "DCC" :
                n100s == 6 ? "DC" :
                n100s == 5 ? "D" :
                n100s == 4 ? "CD" :
                n100s == 3 ? "CCC" :
                n100s == 2 ? "CC" :
                n100s == 1 ? "C" : "");

        //Output the number of 10's
        //Using Independent If Statements
        if (n10s == 9)cout << "XC";
        if (n10s == 8)cout << "LXXX";
        if (n10s == 7)cout << "LXX";
        if (n10s == 6)cout << "LX";
        if (n10s == 5)cout << "L";
        if (n10s == 4)cout << "XL";
        if (n10s == 3)cout << "XXX";
        if (n10s == 2)cout << "XX";
        if (n10s == 1)cout << "X";

        //Output the number of 1's
        //Using Dependent If Statements
        if (n1s == 9)cout << "IX";
        else if (n1s == 8)cout << "VIII";
        else if (n1s == 7)cout << "VII";
        else if (n1s == 6)cout << "VI";
        else if (n1s == 5)cout << "V";
        else if (n1s == 4)cout << "IV";
        else if (n1s == 3)cout << "III";
        else if (n1s == 2)cout << "II";
        else if (n1s == 1)cout << "I";
    }
}
// ***** My Functions for problem 4 - Phone 4 digit encryption *****
/**
 * Error checking for negative integer, integer > 7 and 4 digit values only
 * @param num
 * @param error
 * @return 
 */
bool errorCheck(int &num, bool &error, string strNum)
{
    do
    {
        int num1, num2, num3, num4;
        int numMax = 7; //Individual number to compare for > 7

        num4 = num % 10; //Breaks down each individual digit using modulus math
        num3 = num / 10 % 10;
        num2 = num / 100 % 10;
        num1 = num / 1000 % 10;
        //Checks for > 7 and 4 digits
        if (num1 > numMax || num2 > numMax || num3 > numMax || num4 > numMax ||
                num < 0 || num > 7777 || strNum.size() > 4)
        {
            error = true;
        }
        else
        {
            error = false;
        }

        if (error)//If errors repeats while loop
        {
            cout << "Please enter a 4 digit number (0-7's only) that you want encrypted: ";
            cin >> num;
        }
    }
    while (error);
}

/**
 * Encrypts user integer using modulus math
 * @param num
 */
void encrypt(int &num, bool &ldZero)
{
    int num1, num2, num3, num4;

    num4 = num % 10; //Breaks down each individual digit using modulus math
    num3 = num / 10 % 10;
    num2 = num / 100 % 10;
    num1 = num / 1000 % 10;

    num1 = (num1 + 6) % 8; //Replace each digit 1234
    num2 = (num2 + 6) % 8;
    num3 = (num3 + 6) % 8;
    if(num3 == 0)
    {
        ldZero = true;
    }
    num4 = (num4 + 6) % 8;

    int temp;
    temp = num1; //Replace 1st digit with 3rd digit
    num1 = num3;
    num3 = temp;

    temp = num2; //Replace 2nd digit with 4th digit
    num2 = num4;
    num4 = temp;
    //Convert individual numbers back into 1 number
    num = num1 * 1000 + num2 * 100 + num3 * 10 + num4;
}

/**
 * Decrypts user integer back into regular form
 * @param num
 */
void decrypt(int &num)
{
    int num1, num2, num3, num4, mod = 8, sumVal = 6;

    num4 = num % 10; //Breaks down each individual digit using modulus math
    num3 = num / 10 % 10;
    num2 = num / 100 % 10;
    num1 = num / 1000 % 10;

    int temp;
    temp = num1; //Replace 1st digit with 3rd digit
    num1 = num3;
    num3 = temp;

    temp = num2; //Replace 2nd digit with 4th digit
    num2 = num4;
    num4 = temp;

    //Function to reverse modulus math
    num1 = reverseMod(num1, mod, sumVal);
    num2 = reverseMod(num2, mod, sumVal);
    num3 = reverseMod(num3, mod, sumVal);
    num4 = reverseMod(num4, mod, sumVal);
    num = num1 * 1000 + num2 * 100 + num3 * 10 + num4; //Number after decryption
}

/**
 * Function that reverses modulus math
 * @param remain
 * @param mod
 * @param a
 * @return 
 */
int reverseMod(int remain, int mod, int a)
{
    if (a < remain)
    {
        return remain - a;
    }
    return mod + remain - a;
}

// ***** My Functions for problem 5 - Highest Factorial for data types *****
void displayFact()
{
    //Highest Factorial before incorrect value
    int val_1 = 12; //Final
    signed int val_2 = 12; //Final
    unsigned int val_3 = 12; //Final
    short val_4 = 7;//Final
    unsigned short val_5 = 8; //Final
    signed short val_6 = 7;//Final
    long val_7 = 20; //Final
    unsigned long val_8 = 20; //Final
    signed long val_9 = 20;
    long long val_10 = 20; //Final
    unsigned long long val_11 = 20; //Final
    signed long long val_12 = 20;
    double val_13 = 20; //Final
    long double val_14 = 20; //Final
    
    cout << "The highest factorial value for int is: " << val_1 << endl;
    cout << "The highest factorial value for signed int is: " << val_2 << endl;
    cout << "The highest factorial value for unsigned int is: " << val_3 << endl;
    cout << "The highest factorial value for short is: " << val_4 << endl;
    cout << "The highest factorial value for unsigned short is: " << val_5 << endl;
    cout << "The highest factorial value for signed short is: " << val_6 << endl;
    cout << "The highest factorial value for long is: " << val_7 << endl;
    cout << "The highest factorial value for unsigned long is: " << val_8 << endl;
    cout << "The highest factorial value for signed long is: " << val_9 << endl;
    cout << "The highest factorial value for long long is: " << val_10 << endl;
    cout << "The highest factorial value for unsigned long long is: " << val_11 << endl;
    cout << "The highest factorial value for signed long long is: " << val_12 << endl;
    cout << "The highest factorial value for double is: " << val_13 << endl;
    cout << "The highest factorial value for long double is: " << val_14 << endl;
}

// ***** My Functions for problem 6 - Conversions to NASA 4 byte float format



// ***** My Functions for problem 7 - Integer Prime Factors
/**
 * Takes structure and stores prime factors of an integer with formula
 * @param num
 * @param index
 * @return 
 */
Primes *factor(int num, int &index)
{
    int start = num, size = sqrt(num);//Size for array
    int cnt = 0;//Counter
    Primes *data = new Primes;
    data->prime = new Prime[size];//Dynamic struct array

    while (start % 2 == 0)//Formula for finding all prime factors
    {
        start = start / 2;
        cnt++;
    }
    if (cnt > 0)
    {
        data->nPrimes += cnt;
        data->prime[index].power = cnt;
        data->prime[index].prime = 2;
        index++;
    }
    for (int i = 3; i <= sqrt(start); i = i + 2)
    {
        cnt = 0;
        while (start % i == 0)
        {
            cnt++;
            start = start / i;
        }
        if (cnt > 0)
        {
            data->nPrimes += cnt;
            data->prime[index].power = cnt;
            data->prime[index].prime = i;
            index++;
        }
    }
    if (start > 2)
    {
        data->nPrimes += cnt;
        data->prime[index].power = 1;
        data->prime[index].prime = start;
    }
    else
    {
        index--;
    }
    return data;//Returns data to object in main
}
/**
 * Displays struct array data
 * @param a
 * @param num
 * @param index
 */
void prntPrm(Primes *a, int num, int index)
{
    cout << "The factor primes of " << num << " = ";
    for (int i = 0; i <= index; i++)
    {
        cout << a->prime[i].prime << "^" << static_cast<int> (a->prime[i].power);
        if (i < index)
        {
            cout << " * ";
        }
    }
}