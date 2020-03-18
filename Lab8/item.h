#ifndef ITEM
#define ITEM

#include "list.h"
#include <string>
#include <iostream>
using namespace std;

class Item {

private:
    unsigned sku, price, qoh, leadtime;
    string description;
    string uom;

public:
    Item(unsigned sku, unsigned price, string description, string uom, unsigned qoh = 0) {
        this->sku = sku;
        this->price = price;
        this->description = description;
        this->uom = uom;
        this->qoh = qoh;
    }



    string getPartInfo() { return to_string(sku) + description; }

    unsigned getPrice() { return price; }

    unsigned getSku() { return sku; }

    bool inStock() { return (qoh > 0); }

    bool available(unsigned date) {
        if (qoh > 0)
            if (date > leadtime)
                return true;
        return false;
    }

    void displ() {
        cout << "----------------" << endl;
        cout << "| SKU: " << sku << endl;
        cout << "| Price: " << price << endl;
        cout << "| Quantity: " << qoh << endl;
        cout << "| Description: " << description << endl;
        cout << "----------------" << endl;
        cout << "      |   |  " << endl;
        cout << "      |   | " << endl;
        cout << "       | |  " << endl;
        cout << "        * " << endl;
    }

};

bool operator < (Item& obj1, Item& obj2) { return obj1.getSku() < obj2.getSku(); }
bool operator > (Item& obj1, Item& obj2) { return obj1.getSku() > obj2.getSku(); }
bool operator == (Item& obj1, Item& obj2) { return obj1.getSku() == obj2.getSku(); }


#endif

#pragma once
