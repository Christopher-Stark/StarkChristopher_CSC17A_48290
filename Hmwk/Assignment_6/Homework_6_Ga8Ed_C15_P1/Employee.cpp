/* 
 * File:   Employee.h
 * Author: Chris Stark
 *
 * Created on November 28, 2022, 7:17 PM
 */

#include "Employee.h"

//Constructor
Employee::Employee(){
    
}
Employee::Employee(string n, int e, string d){
    name = n;
    eNum = e;
    hDate = d;
}
//Mutators

void Employee::setName(string n){
    name = n;
}

void Employee::setEmpNum(int n){
    eNum = n;
}

void Employee::setHireDate(string d){
    hDate = d;
}
//Accessors

string Employee::getName() const{
    return name;
}

int Employee::getEmpNum() const{
    return eNum;
}

string Employee::getHireDate() const{
    return hDate;
}

