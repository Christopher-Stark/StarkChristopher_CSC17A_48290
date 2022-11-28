/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 9, 2022, 3:07 PM
 * Purpose: Create class for personal data: name, address, age and ph.# 
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//User Defined Libraries
#include "data.h"
//Global Constants

//Function Prototypes
void setData(PersonData &);
void display(const PersonData, const PersonData, const PersonData);
//Execution begins here!
int main(int argc, char** argv) 
{
    //Declarations
    PersonData self;
    PersonData frnd;
    PersonData fam;
    //Set Data per instance
    cout << "Self information!" << endl;
    setData(self);
    cout << "Friend information!" << endl;
    setData(frnd);
    cout << "Family information!" << endl;
    setData(fam);
    //Display data
    display(self, frnd, fam);
    
    return 0;
}
//Functions
void setData(PersonData &a)
{
    string name, addres, age, phNum;
    
    cout << "Please enter name: ";
    getline(cin,name);
    a.setName(name);
    cout << "Please enter address: ";
    getline(cin,addres);
    a.setAddress(addres);
    cout << "Please enter age: ";
    getline(cin,age);
    a.setAge(age);
    cout << "Please enter Phone #: ";
    getline(cin,phNum);
    a.setPhoneNum(phNum);
    cout << endl;
}
void display(const PersonData a, const PersonData b, const PersonData c)
{
   cout << "Self data:" << endl;
   cout << "Name: " << a.getName() << endl;
   cout << "Address: " << a.getAddress() << endl;
   cout << "Age: " << a.getAge() << endl;
   cout << "Phone #: " << a.getPhoneNume() << endl << endl;
   
   cout << "Friend data:" << endl;
   cout << "Name: " << b.getName() << endl;
   cout << "Address: " << b.getAddress() << endl;
   cout << "Age: " << b.getAge() << endl;
   cout << "Phone #: " << b.getPhoneNume() << endl << endl;
   
   cout << "Family data:" << endl;
   cout << "Name: " << c.getName() << endl;
   cout << "Address: " << c.getAddress() << endl;
   cout << "Age: " << c.getAge() << endl;
   cout << "Phone #: " << c.getPhoneNume() << endl << endl;
}
