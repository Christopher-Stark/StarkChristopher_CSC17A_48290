/* 
 * File:   numbers.h
 * Author: Chris Stark
 *
 * Created on November 11, 2022, 11:50 AM
 */

#ifndef NUMBERS_H
#define NUMBERS_H

#include <valarray>

class Numbers {
private:
    int number;
    string lessThan20[20] = {"zero", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine", "ten", "eleven", "twelve",
        "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
        "eighteen", "nineteen"};
    string hundred = "hundred";
    string thousand = "thousand";
    string tens[10] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty",
        "seventy", "eighty", "ninety"};
public:
    //Constructors
    Numbers();
    Numbers(int);
    //Display
    void print();
};
//Member Functions

Numbers::Numbers() {
    number = 0;
}

Numbers::Numbers(int n) {
    number = n;
}

void Numbers::print() {
    int num = number;

    num = number / 1000;
    cout << "The number " << number << " in english form is: ";
    if (num > 0) {
        cout << lessThan20[num] << " " << thousand << " ";
    }
    number %= 1000;
    num = number / 100;

    if (num > 0) {
        cout << lessThan20[num] << " " << hundred << " ";
    }
    number %= 100;
    if (number >= 20) {
        num = number / 10;
        if (num > 0) {
            cout << tens[num] << " ";
        }
    } else if (number >= 10) {
        cout << lessThan20[number] << " ";
        return;
    }
    number %= 10;
    if (number > 0) {
        cout << lessThan20[number];
    }
}

#endif /* NUMBERS_H */

