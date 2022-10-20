/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stats.h
 * Author: cbsbn
 *
 * Created on October 19, 2022, 8:12 AM
 */

#ifndef STATS_H
#define STATS_H

struct Stats {
    Array *mode; //Array ADT contains number of modes and the modes themselves
    int modFreq; //Mode Frequency
    float median; //Median of the array
    float avg; //Average of the Array
};


#endif /* STATS_H */

