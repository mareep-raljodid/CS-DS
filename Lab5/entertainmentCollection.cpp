#include <iostream>
#include "entertainmentCollection.h"

using namespace std;

 entertainmentCollection::entertainmentCollection() {
    shelf[index] = {};
}

int entertainmentCollection::getCurrentAmount() {

}

void entertainmentCollection::setCurrentAmount(int c) {

}

void entertainmentCollection::addShow(Item& s) {
    shelf[index] = s;
    index++;

}

Item entertainmentCollection::removeShow() {

}
