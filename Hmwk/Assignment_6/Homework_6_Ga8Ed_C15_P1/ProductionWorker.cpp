/* 
 * File:   ProductionWorker.h
 * Author: Chris Stark
 *
 * Created on November 28, 2022, 8:20 PM
 */

#include "Employee.h"
#include "ProductionWorker.h"

//Constructors
ProductionWorker::ProductionWorker(){
    
}
ProductionWorker::ProductionWorker(int s, float p){
    shift = s;
    pRate = p;
}
//Mutators

void ProductionWorker::setShift(int s){
    shift = s;
}

void ProductionWorker::setPayRate(float p){
    pRate = p;
}
//Accessors

int ProductionWorker::getShift() const{
    return shift;
}

float ProductionWorker::getPayRate() const{
    return pRate;
}
