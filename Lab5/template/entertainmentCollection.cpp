#include <iostream>
#include "entertainmentCollection.h"
#include "item.h"

using namespace std;

template <class Item>
entertainmentCollection<Item>::entertainmentCollection() {
    Item def(true);
    entertainmentcollection[0] = def;
}

template <class Item>
int entertainmentCollection<Item>::getCurrentAmount() {
   return index;
    
}

template <class Item>
void entertainmentCollection<Item>::addItem(Item &s) {
    if (getCurrentAmount() == MAX_SIZE) {
        throw FullententertainmentCollection();
    }
    else {
        entertainmentcollection[getCurrentAmount()] = s;
        index ++;
    }

}

template <class Item>
void entertainmentCollection<Item>::removeItem() {
    if (getCurrentAmount() == 0) {
         throw EEmptyShelf();
     }
     else {
         entertainmentcollection[getCurrentAmount()].details();
         index --;
     }
}
