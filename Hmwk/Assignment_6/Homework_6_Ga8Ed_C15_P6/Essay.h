/* 
 * File:   main.cpp
 * Author: Christopher Stark
 * Created on November 29, 2022, 5:18 PM
 * Purpose: Uses Gaddis GradedActivity class and derived Essay Class to det. grade
 */

#include "GradedActivity.h"
#ifndef ESSAY_H
#define ESSAY_H

class Essay : public GradedActivity {
private:
    float graScr;
    float spelScr;
    float lenScr;
    float cntScr;
public:
    //Constructor

    Essay() {
        graScr = 0.0;
        spelScr = 0.0;
        lenScr = 0.0;
        cntScr = 0.0;
    }
    //Constructor using base class constructor, added all scores for the one variable
    Essay(float g, float sp, float l, float c) : GradedActivity(g+sp+l+c) {
        graScr = g;
        spelScr = sp;
        lenScr = l;
        cntScr = c;
    }
    //Mutator
    void setGrammerScore(float);
    void setSpellingScore(float);
    void setLengthScore(float);
    void setContentScore(float);
    //Accesssors
    float getGrammerScore() const;
    float getSpellingScore() const;
    float getLengthScore() const;
    float getContentScore() const;
    //Member Functions
    void getEssayGrade();
};


#endif /* ESSAY_H */

