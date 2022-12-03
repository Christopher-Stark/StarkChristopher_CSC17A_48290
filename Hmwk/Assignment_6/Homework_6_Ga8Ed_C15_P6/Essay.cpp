/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 29, 2022, 5:18 PM
 * Purpose: Uses Gaddis GradedActivity class and derived Essay Class to det. grade
 */

#include "GradedActivity.h"
#include "Essay.h"

//Mutator
void Essay::setGrammerScore(float g){
    graScr = g;
}
void Essay::setSpellingScore(float sp){
    spelScr = sp;
}
void Essay::setLengthScore(float l){
    lenScr = l;
}
void Essay::setContentScore(float c){
    cntScr = c;
}
//Accesssors
float Essay::getGrammerScore() const{
    return graScr;
}
float Essay::getSpellingScore() const{
    return spelScr;
}
float Essay::getLengthScore() const{
    return lenScr;
}
float Essay::getContentScore() const{
    return cntScr;
}
//Member Function
void Essay::getEssayGrade(){
    float finScr = graScr + spelScr + lenScr + cntScr;
    setScore(finScr);
}