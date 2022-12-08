/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on December 6, 2022, 1:02 PM
 * Purpose: Take the Simplevector class and add push/pop functions
 */

//System Level Libraries
//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants

//Function prototypes
void fillVec(SimpleVector<unsigned char> &);
void prntVec(SimpleVector<unsigned char> &,char);
vector<unsigned char> pushBack(SimpleVector<unsigned char> &obj, unsigned char inp);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned char size=100, input;
    SimpleVector<unsigned char> sv(size);
    
    //Fill the Vector
    fillVec(sv);
    
    //Prchar the Vector
    cout<<"Original Random Dynamic Array derived Simple Vector"<<endl;
    prntVec(sv,10);
    
    //Copy the Vector
    SimpleVector<unsigned char> copysv(sv);
    
    //Print the Vector
    cout<<"Copied Random Dynamic Array derived Simple Vector"<<endl;
    prntVec(copysv,10);
    
    //Push Back
    cout << "Now we will be adding an element to the copied vector!" << endl;
    cout << "Please enter an element to add to vector: ";
    cin >> input;
    copysv.pushBack(copysv, input);
    prntVec(copysv,10);
    
    //Pop Back
    cout << "\nNow we will be removing an element to the copied vector!" << endl;
    copysv.popBack(copysv);
    prntVec(copysv,10);
    return 0;
}

void prntVec(SimpleVector<unsigned char> &sv,char perLine){
    cout<<endl;
    for(unsigned char i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<unsigned char> &sv){
    for(unsigned char i=0;i<sv.size();i++){
        sv[i]=rand()%26+65;
    }
}




