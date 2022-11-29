/* 
 * File:   Employee.h
 * Author: Chris Stark
 *
 * Created on November 28, 2022, 7:17 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <cstdlib>
#include <string>
using namespace std;

class Employee{
private:
    string name;
    int eNum;
    string hDate;
    
public:
    //Constructors
    Employee();
    Employee(string, int, string);
    //Mutators
    void setName(string);
    void setEmpNum(int);
    void setHireDate(string);
    //Accessors
    string getName() const;
    int getEmpNum() const;
    string getHireDate() const;
    
};

#endif /* EMPLOYEE_H */

