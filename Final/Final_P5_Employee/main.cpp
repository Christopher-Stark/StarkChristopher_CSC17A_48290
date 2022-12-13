/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 12, 2022, 1:33 PM
 * Purpose: Final Problem 5 - Employee Class + pay/tax rates
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include "Employee.h"
//Global Constants

//Function Prototypes

//Execution begins here!

int main(int argc, char** argv){
    Employee Mark("Mark", "Boss", 215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0), Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0), Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0), Mark.setHoursWorked(25));
    Mark.toString();
    Employee Mary("Mary", "VP", 50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(60));
    Mary.toString();
    return 0;
}
//Functions

