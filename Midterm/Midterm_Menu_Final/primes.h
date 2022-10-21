/* 
 * File:   primes.h
 * Author: Chris Stark
 *
 * Created on October 21, 2022, 10:55 AM
 */

#ifndef PRIMES_H
#define PRIMES_H

struct Prime
{
    unsigned short prime;
    unsigned char power;
};

struct Primes
{
    unsigned char nPrimes;
    Prime *prime;
};


#endif /* PRIMES_H */

