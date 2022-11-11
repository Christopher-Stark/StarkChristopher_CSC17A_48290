/* 
 * File:   item.h
 * Author: Chris Stark
 *
 * Created on November 10, 2022, 10:40 AM
 */

#ifndef ITEM_H
#define ITEM_H

class RetailItem {
private:
    string descri;
    int units;
    float price;

public:
    //Constructor
    RetailItem(string, int, float);
    //Mutators
    void setDescri(string);
    void setUnits(int);
    void setPrice(float);
    //Accessors
    string getDescri() const;
    int getUnits() const;
    float getPrice() const;




};
//Member Functions

RetailItem::RetailItem(string desc, int unt, float prc) {
    descri = desc;
    units = unt;
    price = prc;
}

void RetailItem::setDescri(string s) {
    descri = s;
}

void RetailItem::setUnits(int u) {
    units = u;
}

void RetailItem::setPrice(float p) {
    price = p;
}

string RetailItem::getDescri() const {
    return descri;
}

int RetailItem::getUnits() const {
    return units;
}

float RetailItem::getPrice() const {
    return price;
}


#endif /* ITEM_H */

