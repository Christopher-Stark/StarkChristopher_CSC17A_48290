/* 
 * File:   structs.h
 * Author: cbsbn
 *
 * Created on October 18, 2022, 8:17 AM
 */

#ifndef STRUCTS_H
#define STRUCTS_H

struct BankAct
{
    int actNum;
    string name;
    string address;
    float mntBal;
    float mntChk[50];
    float mntDep[50];
};

#endif /* STRUCTS_H */

