#include <iostream>
#include "entertainmentCollection.h"
#include "item.h"

using namespace std;

entertainmentCollection::entertainmentCollection() {
    T<int> def;
    for (unsigned i = 0; i < MAX_SIZE; i++) {
        entertainmentcollection[i] = def;
    }
}

int entertainmentCollection::getCurrentAmount() {
    unsigned s = 0;
    for (unsigned i = 0; i < 10; i++){
        if (compareNul(entertainmentcollection[i])) {
            return s + 1;
        }
        else {
            s++;
        }
    } 
}

void entertainmentCollection::addItem(T<Item> &s) {
    if (getCurrentAmount() == MAX_SIZE) {
        throw FullententertainmentCollection();
    }
    else {
        entertainmentcollection[index] = s;
        entertainmentcollection[index + 1] = new T<Item>(true);
    }

}

void entertainmentCollection::removeItem() {
    entertainmentcollection[getCurrentAmount()].details();

}
