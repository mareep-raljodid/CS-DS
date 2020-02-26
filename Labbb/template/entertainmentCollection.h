#include <iostream>
#include "item.h"
#define MAX_SIZE 10
#ifndef SHELF
#define SHELF

class entertainmentCollection {
public:
    unsigned index;
    T<int> entertainmentcollection[MAX_SIZE] = {};

    entertainmentCollection();

    int getCurrentAmount();

    void addItem(T<void> &s);

    void removeItem();

    bool compareNul(T<int> &s) {
        if ((s.getTitle() == "") && (s.getDesc() == "")) {

            return true;
        }
        else {
            return false;
        }
    }

    class FullententertainmentCollection {};

private:
    int currentNumOfItems;
};


#endif
