/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 20, 2022, 11:50 AM
 * Purpose:Check what the largest n is for n! - factorial calculation
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
int findMaxValue();
//Execution begins here!

int main(int argc, char** argv)
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

    int loop = 30; //Loop value increment
    int check = 1; //Counter for error then back off by 1

    //For loop for Factorial calculation
    for (int i = 1; i < loop; i++)
    {
        cout << "Check: " << check << "  Value: ";
        check++;
        val_6 *= i;
        cout << val_6 << endl;
    }
    cout << val_6 << endl;
    
    /*int num;
    num = findMaxValue();
    cout << num << endl;*/
    return 0;
}
//Functions

int findMaxValue()
{
    int res = 2;
    
    int val_1 = 11; //Final
    signed int val_2 = 11; //Final
    unsigned int val_3 = 11; //Final
    short val_4 = 6; //Final
    unsigned short val_5 = 8; //Final
    signed short val_6 = 8;
    long val_7 = 20; //Final
    unsigned long val_8 = 20; //Final
    signed long val_9 = 20;
    long long val_10 = 20; //Final
    unsigned long long val_11 = 20; //Final
    signed long long val_12 = 20;
    double val_13 = 20; //Final
    long double val_14 = 20; //Final
    
    while (1)
    {
        // when fact crosses its size,
        // it gives negative value
        if (val_6 < 0)
            break;
        res++;

        // You cannot use fact = fact*res,
        // for overflow negative condition in C++
        // If you use this then it will give
        // an error,
        // "signed integer overflow: 2432902008176640000 * 21
        // cannot be represented in type 'long long' "
        // To avoid this, use the below code.
        // This error won't occur in languages like java, python,
        // JavaScript. as they have garbage collectors for such errors.
        if (val_6 > SHRT_MAX / res)
        {
            break;
        }
        else
        {
            val_6 = val_6*res;
        }
    }
    return res - 1;
}

