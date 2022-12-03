/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 29, 2022, 5:18 PM
 * Purpose: Uses Gaddis GradedActivity class and derived Essay Class to det. grade
 */

#include "GradedActivity.h"

char GradedActivity::getLetterGrade() const{
    char letterGrade;
    
    if(score > 89){
        letterGrade = 'A';
    }
    else if(score > 79){
        letterGrade = 'B';
    }
    else if(score > 69){
        letterGrade = 'C';
    }
    else if(score > 59){
        letterGrade = 'D';
    }
    else
        letterGrade = 'F';
    
    return letterGrade;
}
