/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on October 5, 2022, 4:26 PM
 * Purpose: Get struct movie data title,dir,year,run time
 */

//System Level Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Defined Libraries
struct MovieData
{
    string title;
    char *dir;
    int year;
    int runTm;
};
struct Movies
{
    int size;
    MovieData *moviedata;//Create pointer to other struct
};
//Global Constants

//Function Prototypes
Movies *getData();
void destroy (Movies *a);
void display(Movies *a);
//Execution begins here!
int main(int argc, char** argv) 
{
    //Declare struct object pointer
    Movies *movie = getData();
    //Display Data
    display(movie);
    //De-allocate dynamic memory
    destroy(movie);
    return 0;
}
//Functions
void destroy (Movies *a)
{
    for (int i = 0; i < a->size; i++)
    {
        //de-allocate dynamic char array
        delete[] a->moviedata[i].dir;
    }
    delete[] a->moviedata;
    delete a;
}
Movies *getData()
{
    Movies *movie = new Movies;
    
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released," 
            " and the Running Time in (minutes)." << endl;
    
    
    cin >> movie->size;//Get size from user
    //Create dynamic pointer to struct using a struct
    movie->moviedata = new MovieData[movie->size];
    
    for(int i = 0; i < movie->size; i++)
    {
        cin.ignore();//Clears buffer
        getline(cin,movie->moviedata[i].title);
        int size = 50;
        movie->moviedata[i].dir = new char[size];
        cin.getline(movie->moviedata[i].dir, size - 1);
        cin >> movie->moviedata[i].year;
        cin >> movie->moviedata[i].runTm;
    }
    
    return movie;
}

void display(Movies *a)
{
    for(int i = 0; i < a->size; i++)
    {
       cout << left << endl;//Left alignment
       cout << setw(11) << "Title:" << a->moviedata[i].title << endl;
       cout << setw(11) << "Director:" << a->moviedata[i].dir << endl;
       cout << setw(11) << "Year:" << a->moviedata[i].year << endl;
       cout << setw(11) << "Length:" << a->moviedata[i].runTm << endl;
    }
}
