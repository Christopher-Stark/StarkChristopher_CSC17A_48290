/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 12, 2022, 1:33 PM
 * Purpose: Final Problem 5 - Employee Class + pay/tax rates
 */
#include "Employee.h"

Employee::Employee(char name[], char title[], float hRate){ //Constructor
    strcpy(MyName, name);
    strcpy(JobTitle, title);
    HourlyRate = hRate;
    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;
}

float Employee::CalculatePay(float hRate, int hrs){ //Procedure
    GrossPay = 0;
    return getNetPay(getGrossPay(setHourlyRate(hRate),setHoursWorked(hrs)));
}

float Employee::getGrossPay(float hRate, int hrs){ //Procedure
    int hours = hrs;
    if(hours > 50){
        GrossPay += (hRate * 2)*(hours%50);
        hours -= (hours%50);
    }
    if(hours > 40 && hours <= 50){
        GrossPay += (hRate * 1.5)*(hours%40);
        hours -= (hours%40);
    }
    if(hours <= 40){
        GrossPay += (hRate * hours);
    }
    return GrossPay;
}

float Employee::getNetPay(float gPay){ //Procedure
    NetPay = gPay - (gPay * Tax(gPay));
    return NetPay;
}

void Employee::toString(){ //Procedure
    if(HourlyRate < 0 || HourlyRate > 200){
        cout << "Unacceptable Hourly Rate" << endl;
        HourlyRate = 0;
    }
    if(HoursWorked < 0 || HoursWorked > 84){
        cout << "Unacceptable Hours Worked" << endl;
        HoursWorked = 0;
    }
    cout << "Name: " << MyName << " Job Title = " << JobTitle << endl;
    cout << " Hourly Rate = " << HourlyRate << " Hours Worked = " << HoursWorked
            << " Gross Pay = " << GrossPay << " Net Pay = " << NetPay << endl;
}

int Employee::setHoursWorked(int hrs){ //Procedure
    HoursWorked = hrs;
    return HoursWorked;
}

float Employee::setHourlyRate(float hRate){ //Procedure
    HourlyRate = hRate;
    return HourlyRate;
}

double Employee::Tax(float gPay){
    double tax = 0;
    if(gPay <= 500){
        tax = 0.1;
        return tax;
    }
    if(gPay > 500 && gPay <= 1000){
        tax = 0.2;
        return tax;
    }
    else{
        tax = 0.3;
        return tax;
    }
}