#include <iostream>
#include "shelf.h"
#include "show.h"

using namespace std;

Shelf::Shelf() {
    Show def;
    for (unsigned i = 0; i < MAX_SIZE; i++) {
        shelf[i] = def;
    }
}

int Shelf::getCurrentAmount() {
    unsigned s = 0;
    for (unsigned i = 0; i < 10; i++) {
        if (compareNul(shelf[i]))
            return s + 1;
        else
            s++;
    }

}

void Shelf::addShow(Show& s) {
    if (getCurrentAmount() == MAX_SIZE) {
        throw FullShelf();
    }
    else {
        shelf[index] = s;
        shelf[index + 1] = new Show(true);
    }
}

void Shelf::removeShow() {
    if (getCurrentAmount() == 0) {
        throw EmptyShelf();
    }
    else {
        shelf[getCurrentAmount()].details();
    }

}
