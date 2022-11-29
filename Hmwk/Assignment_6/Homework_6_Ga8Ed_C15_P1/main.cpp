/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 20, 2022, 11:50 AM
 * Purpose: Creates Employee Class than derived ProdWrk Class and creates object
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//User Defined Libraries
#include "Employee.h"
#include "ProductionWorker.h"
//Global Constants

//Function Prototypes
void getData();
//Execution begins here!
int main(int argc, char** argv) 
{
    //Variables
    string name, hDate;
    int eNum, shift;
    float pay = 0.00f;
    //Get Data
    cout << "Please enter employees name: ";
    getline(cin, name);
    cout << "Please enter employees hire date mm/dd/yyyy format: ";
    getline(cin, hDate);
    cout << "Please enter employees Id Number: ";
    cin >> eNum;
    cout << "Please enter employees rate of pay: ";
    cin >> pay;
    
    do{
       cout << "Please enter employees shift, 1 for day 2 for night: ";
       cin >> shift;
    }while(shift != 1 && shift !=2);
    //Object Variable
    ProductionWorker test(shift, pay);
    test.setName(name);
    test.setHireDate(hDate);
    test.setEmpNum(eNum);
    //Display
    cout << "\n\nEmployee Name: " << test.getName() << endl;
    cout << "Employee ID Number: " << test.getEmpNum() << endl;
    cout << "Employee Hire Date: " << test.getHireDate() << endl;
    cout << "Employee Pay Rate: " << fixed << setprecision(2) << "$" << test.getPayRate() << endl;
    cout << "Employee Shift Type: " << test.getShift() << endl;
    
    return 0;
}

