/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 5, 2022, 6:01 PM
 * Purpose: Get data for stuct speakers Bureau
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries

struct SpkBure
{
    string name;
    int number;
    string topic;
    float fee;
};

//Global Constants

//Function Prototypes
void getData(SpkBure a[], int index);
void menu(SpkBure a[]);
void display (const SpkBure a[], int index);
//Execution begins here!

int main(int argc, char** argv)
{
    int index, size = 10;
    //Allocate struct object
    SpkBure person[size];
    //Control Menu with user index
    menu(person);


    return 0;
}
//Functions
/**
 * Gets all data for specified index of array
 * @param array
 * @param index
 */
void getData(SpkBure a[], int index)
{
    cout << "Please enter name:";
    cin.ignore();
    getline(cin, a[index].name);
    cout << "Please enter number:";
    cin >> a[index].number;
    cout << "Please enter topic:";
    cin.ignore();
    getline(cin, a[index].topic);
    cout << "Please enter fee:";
    cin >> a[index].fee;
    while (a[index].fee < 0)
    {
        cout << "Please select a non negative fee:";
        cin >> a[index].fee;
    }
}
/**
 * Gets specified data for specified index 
 * @param array
 * @param index
 * @param info - data to change
 */
void getData(SpkBure a[], int index, string info)
{
    int num;
    float fee;
    string input;
    if (info == "name")
    {
        cout << "Please enter name:";
        cin.ignore();
        getline(cin, a[index].name);
    }
    else if (info == "number")
    {
        cout << "Please enter number:";
        cin >> num;
        a[index].number = num;
    }
    else if (info == "topic")
    {
        cout << "Please enter topic:";
        cin.ignore();
        getline(cin, a[index].topic);
    }
    else
    {
        cout << "Please enter fee:";
        cin >> fee;
        a[index].fee = fee;
        while (fee < 0)
        {
            cout << "Please enter a non negative fee:";
            cin >> fee;
            a[index].fee = fee;
        }
    }
}
/**
 * Menu options
 * @param array
 */
void menu(SpkBure a[])
{
    int option;
    string info;
    cout << "         **Menu**           " << endl;
    cout << "1)Enter new speaker data" << endl;
    cout << "2)Change data" << endl;
    cout << "3)Display information" << endl;
    cout << "4)Quit Menu!" << endl;
    cout << "Please select an option:";
    cin >> option;
    do
    {
        switch (option)
        {
            case 1:
                cout << "Please enter which index to store this data 1-10:";
                cin >> option;
                option -= 1;
                getData(a, option);
                break;
            case 2:
                cout << "Which index would you like to change 1-10:";
                cin >> option;
                option -= 1;
                cout << "Which *exact* info would you like to change name, number, topic, or fee?";
                cin >> info;
                getData(a, option, info);
                break;
            case 3:
                cout << "Which index would you like to display:";
                cin >> option;
                option -= 1;
                display(a,option);
                break;
            default:
                cout << "Please choose an option:";
                cin >> option;
        }
    }
    while (option != 4);
}
/**
 * Displays data for specified index
 * @param array
 * @param index
 */
void display (const SpkBure a[], int index)
{
    cout << "All data from index " << index + 1 << " is:" << endl;
    cout << left;
    cout << setw(8) << "Name:" << a[index].name << endl;
    cout << setw(8) << "Number:" << a[index].number << endl;
    cout << setw(8) << "Topic:" << a[index].topic << endl;
    cout << setw(8) << fixed << setprecision(2) << "Fee: $" << a[index].fee << endl;
}
