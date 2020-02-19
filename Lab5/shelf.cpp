#include <iostream>
#include "shelf.h"

using namespace std;

Shelf::setCurrentAmount(int c){
    currentAmount = c;
}

Shelf::getCurrentAmount(){
    return currentAmount;
}
