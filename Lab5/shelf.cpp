#include <iostream>
#include "shelf.h"
#include "show.h"

using namespace std;

Shelf::Shelf(){
    Show def(true);
    shelf[0] = def;
}

int Shelf::getCurrentAmount(){
    return index;
}

void Shelf::addShow(Show &s){
    if(index == MAX_SIZE){
        throw FullShelf();
    }
    else{
        shelf[getCurrentAmount()] = s;
        index ++;
    }
}

void Shelf::removeShow(){
    if (getCurrentAmount() == 0) {
        throw EmptyShelf();
    }
    else {
        shelf[getCurrentAmount()].details();
        index --;
    }
}
