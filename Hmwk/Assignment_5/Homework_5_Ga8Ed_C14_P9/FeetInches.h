/* 
 * File:   FeetInches.h
 * Author: Chris Stark
 * Class copied from C++ Control structures to objects Gaddis 8th Edition Ch.14
 * and modified to Ch.14 Problem Challenge 9 
 * Created on November 27, 2022, 7:13 PM
 */

#ifndef FEETINCHES_H
#define FEETINCHES_H

class FeetInches {
private:
    int feet;
    int inches;
    void simplify();
public:
    //Constructor
    FeetInches(int f = 0, int i = 0) {
        feet = f;
        inches = i;
        simplify();
    }
    //Mutator
    void setFeet(int f) {
        feet = f;
    }

    void setInches(int i) {
        inches = i;
        simplify();
    }
    //Accessors
    int getFeet() const {
        return feet;
    }

    int getInches() const {
        return inches;
    }
    bool operator<=(const FeetInches &);//Overloaded operators
    bool operator>=(const FeetInches &);
    bool operator!=(const FeetInches &);
};
//Member Functions

void FeetInches::simplify() {
    if (inches >= 12) {
        feet += (inches / 12);
        inches = inches % 12;
    } else if (inches < 0) {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

bool FeetInches::operator<=(const FeetInches &a) {
    bool status;

    if (feet <= a.feet) {
        status = true;
    } else if (feet <= a.feet && inches <= a.inches) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

bool FeetInches::operator>=(const FeetInches &a) {
    bool status;

    if (feet >= a.feet) {
        status = true;
    } else if (feet >= a.feet && inches >= a.inches) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

bool FeetInches::operator!=(const FeetInches &a) {
    bool status;

    if (feet != a.feet && inches != a.inches) {
        status = true;
    } else {
        status = false;
    }
    return status;
}
#endif /* FEETINCHES_H */

