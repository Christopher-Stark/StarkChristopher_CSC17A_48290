/* 
 * File:   data.h
 * Author: Chris Stark
 *
 * Created on November 9, 2022, 3:11 PM
 */

#ifndef DATA_H
#define DATA_H

class PersonData {
private:
    string name;
    string addrs;
    string age;
    string pNum;

public:
    //Mutator
    void setName(string);
    void setAddress(string);
    void setAge(string);
    void setPhoneNum(string);
    //Accessor
    string getName() const;
    string getAddress() const;
    string getAge() const;
    string getPhoneNume() const;
};
//Member Functions

void PersonData::setName(string n) {
    name = n;
}

void PersonData::setAddress(string a) {
    addrs = a;
}

void PersonData::setAge(string a) {
    age = a;
}

void PersonData::setPhoneNum(string p) {
    pNum = p;
}

string PersonData::getName() const {
    return name;
}

string PersonData::getAddress() const {
    return addrs;
}

string PersonData::getAge() const {
    return age;
}

string PersonData::getPhoneNume() const
{
    return pNum;
}
#endif /* DATA_H */

