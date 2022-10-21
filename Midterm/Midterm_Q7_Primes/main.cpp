/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 21, 2022, 10:50 AM
 * Purpose: Factor an int into it's prime #'s
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

//User Defined Libraries
#include "primes.h"
//Global Constants

//Function Prototypes
Primes *factor(int num, int &index);
void prntPrm(Primes *a, int num, int index);
//Execution begins here!

int main(int argc, char** argv)
{
    int num, index = 0;
    Primes *data;
    cout << "Please enter a positive # between 2-265000 to factor it's primes: ";
    cin >> num;
    while (num < 0)
    {
        cout << "Please enter a positive # between 2-265000 to factor it's primes: ";
        cin >> num;
    }

    data = factor(num, index);
    prntPrm(data, num, index);

    delete data;
    return 0;
}
//Functions

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

