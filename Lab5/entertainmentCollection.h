#include <iostream>
#include "Item.h"
#define MAX_SIZE 10

class entertainmentCollection {
public:
    unsigned index;
    Item shelf[MAX_SIZE];
    entertainmentCollection();
    void setCurrentAmount(int c);
    int getCurrentAmount();
    void addShow(Item& s);
    Item removeShow();

private:
    int currentNumOfShows;
};
