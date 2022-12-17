/* 
 * File:   Employee.h
 * Author: Chris Stark
 *
 * Created on December 12, 2022, 1:34 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Employee {
public:
    Employee(char[], char[], float); //Constructor
    float CalculatePay(float, int); //Procedure
    float getGrossPay(float, int); //Procedure
    float getNetPay(float); //Procedure
    void toString(); //Procedure
    int setHoursWorked(int); //Procedure
    float setHourlyRate(float); //Procedure
private:
    double Tax(float); //Utility Procedure
    char MyName[20]; //Property
    char JobTitle[20]; //Property
    float HourlyRate; //Property
    int HoursWorked; //Property
    float GrossPay; //Property
    float NetPay; //Property 
} ;
#endif /* EMPLOYEE_H */

