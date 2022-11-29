/* 
 * File:   ProductionWorker.h
 * Author: Chris Stark
 *
 * Created on November 28, 2022, 8:20 PM
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"

class ProductionWorker:public Employee{
private:
    int shift;
    float pRate;
public:
    //Constructors
    ProductionWorker();
    ProductionWorker(int, float);
    //Mutators
    void setShift(int);
    void setPayRate(float);
    //Accessors
    int getShift() const;
    float getPayRate() const;
};


#endif /* PRODUCTIONWORKER_H */

