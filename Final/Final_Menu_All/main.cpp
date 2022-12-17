/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 15, 2022, 2:57 PM
 * Purpose: Final All Problems Menu
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

//User Defined Libraries
#include "Random.h"
#include "Sorting.h"
#include "Table.h"
#include "TableInherit.h"
#include "Savings.h"
#include "Employee.h"
//Global Constants

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
//Problem 6 Function Prototype
void displayConversions();
//Execution begins here!
int main(int argc, char** argv) 
{
    srand(time(0));
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;
        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='6');
    return 0;
}
//Functions
/**
 * Menu Function
 */
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1 - Random Sequence"<<endl;
    cout<<"Type 2 for Problem 2 - Sorting Arrays"<<endl;
    cout<<"Type 3 for Problem 3 - Augment Table"<<endl;   
    cout<<"Type 4 for Problem 4 - Savings Account"<<endl;
    cout<<"Type 5 for Problem 5 - Employee Data"<<endl;
    cout<<"Type 6 for Problem 6 - Conversion/NASA/IEEE754 Format results"<<endl;
    cout<<"Type 7 to exit program!"<<endl<<endl;
}
/**
 * Problem 1 Random Sequence Main
 */
void prblm1(){
    cout<<"****Problem 1 - Random Sequence Class****"<<endl;
    char n = 5;
    char rndseq[] = {19, 34, 57, 79, 126};
    int ntimes = 100000;
    Prob1Random a(n, rndseq);
    for(int i = 1; i <= ntimes; i++){
        a.randFromSet();
    }
    int *x = a.getFreq();
    char *y = a.getSet();
    for(int i = 0; i < n; i++){
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
}

/**
 * Problem 2 Sorting Arrays Main
 */
void prblm2(){
    cout<<"****Problem 2 - Sorting Arrays****"<<endl;
    cout<<"*****NOT WORKING AS INTENDED CODE IS LEFT FOR EVALUATION*****" << endl;
    cout<<"***  COMMENTED OUT CODE THAT CAUSES BUILD/RUN ERRORS    ***" << endl;
    cout<<"***HAD ISSUES WITH THE NEW LINE CHARACTERS IN THE ARRAY!***" << endl;
    cout << "The start of Problem 2, the sorting problem" << endl;
    Prob2Sort<char> rc;
    bool ascending = true;
    ifstream infile;
    infile.open("Problem2.txt", ios::in);
    char *ch2 = new char[10 * 16];
    char *ch2p = ch2;
    while(infile.get(*ch2)){
        cout << *ch2;
        ch2++;
    }
    infile.close();
    cout << endl;
    cout << "Sorting on which column" << endl;
    int column;
    cin>>column;
    //char *zc = rc.sortArray(ch2p, 10, 16, column, ascending);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 16; j++){
            //cout << zc[i * 16 + j];
        }
    }
    //delete []zc;
    cout << endl;
}

/**
 * Problem 3 Augment Table Main
 */
void prblm3(){
    cout<<"****Problem 3 - Augment Table****"<<endl;
    cout << "Entering problem number 3" << endl;
    int rows = 5;
    int cols = 6;
    Prob3TableInherited<int> tab("Problem3.txt", rows, cols);
    const int *naugT = tab.getTable();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << naugT[i * cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    const int *augT = tab.getAugTable();
    for(int i = 0; i <= rows; i++){
        for(int j = 0; j <= cols; j++){
            cout << augT[i * (cols + 1) + j] << " ";
        }
        cout << endl;
    }
}

/**
 * Problem 4 Savings Account Main
 */
void prblm4(){
    cout<<"****Problem 4 - Savings Account****"<<endl;
    SavingsAccount mine(-300);
    for(int i = 1; i <= 10; i++){
        mine.Transaction((float) (rand() % 500)*(rand() % 3 - 1));
    }
    mine.toString();
    cout << "Balance after 7 years given 10% interest = "
            << mine.Total((float) (0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = "
            << mine.TotalRecursive((float) (0.10), 7)
            << " Recursive Calculation " << endl;
}
/**
 * Problem 5 Employee Data Main
 */
void prblm5(){
    cout<<"****Problem 5 - Employee Data****"<<endl;
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
}
/**
 * Problem 6 Conversion/NASA/IEEE754 Format Main
 */
void prblm6(){
    cout<<"****Problem 6 - Conversion/NASA/IEEE754 Format results****"<<endl;
    displayConversions();
    float num1 = 5.75, num2 = .9, num3 = 99.7, num4 = 7;
    unsigned char value = num4; 
    unsigned char binary = 0b10111000;
    unsigned short octal = 0160000; 
    unsigned int hex = 0xC76600;
    unsigned int result;
    cout << num1 << " in Scaled Binary = " << static_cast<int>(binary) << endl;
    cout << num2 << " in Scaled Octal = " << static_cast<int>(octal) << endl;
    cout << num3 << " in Scaled Hex = " << static_cast<int>(hex) << endl;
    result = value*binary;
    result >>= 11;
    cout << "\nBinary result after shift: " << result << endl;
    result = value*octal;
    result >>= 19;
    cout << "Octal result after shift: " << result << endl;
    result = value*hex;
    result >>= 27;
    cout << "Hex result after shift: " << result << endl;
}
//Function for Displaying Problem 6 Conversions Base 10,2,8,16
void displayConversions(){
    cout << "Base 10 = 5.75 in Base 2 = 101.11, Base 8 = 5.6, Base 16 = 5.C" << endl;
    cout << "Nasa Format = 5C000003, IEEE 754 Format = 40B80000" << endl;
    cout << "\nBase 10 = .9 in Base 2 = .11100 Rep., Base 8 = .71463 Rep., "
            "Base 16 = .E6 Rep." << endl;
    cout << "Nasa Format = 73333300, IEEE 754 Format = 3F666666" << endl;
    cout << "\nBase 10 = 99.7 in Base 2 = 1100011.10110011 Rep., Base 8 = 143.54631 "
            "Rep., Base 16 = 63.B3 Rep." << endl;
    cout << "Nasa Format = 63B33307, IEEE 754 Format = 42C76666" << endl << endl;
}
