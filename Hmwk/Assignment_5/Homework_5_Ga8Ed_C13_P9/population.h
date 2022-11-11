/* 
 * File:   population.h
 * Author: Chris Stark
 *
 * Created on November 11, 2022, 9:44 AM
 */

#ifndef POPULATION_H
#define POPULATION_H

class Population {
private:
    int pop;
    int births;
    int deaths;
    float bRate;
    float dRate;

public:
    //Constructors
    Population();
    Population(int, int, int);
    //Mutators
    void setPop(int);
    void setBirths(int);
    void setDeaths(int);
    void setBRate();
    void setDRate();
    //Accessors
    int getPop() const;
    int getBirths() const;
    int getDeaths() const;
    float getBRate() const;
    float getDRate() const;
};
//Member Functions

Population::Population() {
    pop = 0;
    births = 0;
    deaths = 0;
    bRate = 0;
    dRate = 0;
}

Population::Population(int p, int b, int d) {
    pop = p;
    births = b;
    deaths = d;
    setBRate();
    setDRate();
}

void Population::setPop(int p) {
    pop = p;
}

void Population::setBirths(int b) {
    births = b;
}

void Population::setDeaths(int d) {
    deaths = d;
}

void Population::setBRate() {
    bRate = static_cast<float>(births) / static_cast<float>(pop);
}

void Population::setDRate() {
    dRate = static_cast<float>(deaths) / static_cast<float>(pop);
}

int Population::getPop() const {
    return pop;
}

int Population::getBirths() const {
    return births;
}

int Population::getDeaths() const {
    return deaths;
}

float Population::getBRate() const {
    return bRate;
}

float Population::getDRate() const {
    return dRate;
}

#endif /* POPULATION_H */

