#include <iostream>
#include "item.h"
#define MAX_SIZE 10
#ifndef SHELF
#define SHELF

template <typename T>
class entertainmentCollection {
public:
    unsigned index;
    T entertainmentcollection[MAX_SIZE] = {};

    entertainmentCollection();

    int getCurrentAmount();

    void addItem(T &s);

    void removeItem();

    bool compareNul(T &s) {
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
