/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on September 13, 2022, 11:52 AM
 * Purpose: Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int srch1(const char sntnce[], const char pattern[], int index); //Search for 1 occurrence
int srchAll(char sntnce[], char pattern[], int match[]); //Search for all occurrences
void print(const char sntnce[]); //Print the character arrays
void printInt(const int match[], int size); //Print the array of indexes where the pattern found

//Program Execution Begins Here

int main(int argc, char** argv)
{
    //Declare all Variables Here
    const int LINE = 81; //Size of sentence or pattern to find
    char sntnce[LINE], pattern[LINE]; //80 + null terminator
    int match[LINE]; //Index array where pattern was found
    int size = 0;


    //Input a sentence and a pattern to match
    cout << "Match a pattern in a sentence." << endl;
    cout << "Input a sentence" << endl;
    cin.getline(sntnce, LINE);
    cout << "Input a pattern." << endl;
    cin.getline(pattern, LINE);

    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce, pattern, match);
    size = srchAll(sntnce, pattern, match);

    //Display the inputs and the Outputs
    cout << endl << "The sentence and the pattern" << endl;
    print(sntnce);
    print(pattern);
    cout << "The positions where the pattern matched" << endl;
    printInt(match, size);

    //Exit
    return 0;
}

int srch1(const char sntnce[], const char pattern[], int index)//Search for 1 occurrence
{
    int sntLen = strlen(sntnce);
    for (int i = index; i < sntLen; i++)
    {
        if (pattern[0] == sntnce[i])
        {
            return i;
        }
    }
    return -1;
}

int srchAll(char sntnce[], char pattern[], int match[])//Search for all occurrences
{
    int size = 0;
    int index = 0;
    int sntLen = strlen(sntnce);
    int patLen = strlen(pattern);
    for (int i = 0; i < sntLen - patLen ; i++)
    {
        int fMatch = srch1(sntnce, pattern, index);
        if (fMatch != -1)
        {
            match[size] = fMatch;
            size++;
            index = fMatch + 1;
        }
    }
    return size;
}

void print(const char sntnce[])//Print the character arrays
{
    for (int i = 0; i < strlen(sntnce); i++)
    {
        cout << sntnce[i];
    }
    cout << endl;
}

void printInt(const int match[], int size) //Print the array of indexes where the pattern found
{
    if (size == 0)
    {
        cout << "None" << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << match[i] << endl;
    }
}