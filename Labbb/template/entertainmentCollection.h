#include <iostream>
#include "item.h"
#define MAX_SIZE 10
#ifndef EBNT
#define EBNT

template <class Item> class entertainmentCollection {
public:


    unsigned index;
    Item entertainmentcollection[MAX_SIZE] = {};

    entertainmentCollection();

    int getCurrentAmount();

    void addItem(Item &s);

    void removeItem();

    class FullententertainmentCollection {};
    class EEmptyShelf {};


private:
    int currentNumOfItems;
};


#endif
