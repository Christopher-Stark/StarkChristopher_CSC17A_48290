/* 
 * File:   inventory.h
 * Author: Chris Stark
 *
 * Created on November 10, 2022, 12:05 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
private:
    int itemNum;
    int quant;
    float cost;
    float totCost;

public:
    //Default Constructor
    Inventory();
    //Constructor with arguments
    Inventory(int, float, int);
    //Mutators
    void setItemNumber(int);
    void setQuantity(int);
    void setCost(float);
    void setTotalCost();
    //Accessors
    int getItemNumber() const;
    int getQuantity() const;
    float getCost() const;
    float getTotalCost() const;


};
//Member Functions
Inventory::Inventory() {
    itemNum = 0;
    quant = 0;
    cost = 0;
    totCost = 0;
}

Inventory::Inventory(int num, float cst, int quan) {
    itemNum = num;
    cost = cst;
    quant = quan;
    setTotalCost();
}

void Inventory::setItemNumber(int n) {
    itemNum = n;
}

void Inventory::setQuantity(int q) {
    quant = q;
}

void Inventory::setCost(float c) {
    cost = c;
}

void Inventory::setTotalCost() {
    totCost = quant * cost;
}

int Inventory::getItemNumber() const {
    return itemNum;
}

int Inventory::getQuantity() const {
    return quant;
}

float Inventory::getCost() const {
    return cost;
}

float Inventory::getTotalCost() const {
    return totCost;
}

#endif /* INVENTORY_H */

