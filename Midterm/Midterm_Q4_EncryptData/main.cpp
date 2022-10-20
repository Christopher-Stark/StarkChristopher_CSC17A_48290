/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 19, 2022, 11:49 AM
 * Purpose:Encrypt data from user then decrypt data and print back
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes0
bool errorCheck(int &num, bool &error);
void encrypt(int &num);
void decrypt(int &num);
int reverseMod(int remain, int mod, int a);
//Execution begins here!

int main(int argc, char** argv)
{
    int num;
    bool redo = false; //Bool for error checking

    cout << "Please enter a 4 digit number (0-7's only) that you want encrypted: ";
    cin >> num; //Int entry from user


    errorCheck(num, redo); //Error checking function
    encrypt(num); //Encrypts num data
    cout << "The number after encryption is: " << num << endl;
    decrypt(num);
    cout << "The number after decryption is: " << num << endl;




    return 0;
}
//Functions

/**
 * Error checking for negative integer, integer > 7 and 4 digit values only
 * @param num
 * @param error
 * @return 
 */
bool errorCheck(int &num, bool &error)
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
                num < 1000 || num > 7777)
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
void encrypt(int &num)
{
    int num1, num2, num3, num4;

    num4 = num % 10; //Breaks down each individual digit using modulus math
    num3 = num / 10 % 10;
    num2 = num / 100 % 10;
    num1 = num / 1000 % 10;

    num1 = (num1 + 6) % 8; //Replace each digit 1234
    num2 = (num2 + 6) % 8;
    num3 = (num3 + 6) % 8;
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