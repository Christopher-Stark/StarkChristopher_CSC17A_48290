/* 
 * File:   GradedActivity.h
 * Author: Chris Stark
 *
 * Created on November 29, 2022, 5:08 PM
 */
#include <cstdlib>
#include <string>
using namespace std;

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity{
private:
    float score;
public:
    //Constructors
    GradedActivity(){
        score = 0.0;
    }
    GradedActivity(float s){
        score = s;
    }
    //Mutators
    void setScore(float s){
        score = s;
    }
    //Accessors
    float getScore() const{
        return score;
    }
    
    char getLetterGrade() const;
};

#endif /* GRADEDACTIVITY_H */

