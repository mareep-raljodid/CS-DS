#include <iostream>
#include "wheel.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

Wheel::Wheel(){
    startVal = 1;
    endVal = 10;
}

void Wheel::setStartVal(int start){
    startVal = start;
}

void Wheel::setEndVal(int end){
    endVal = end;
}

int Wheel::spin(){
    srand (time(NULL));  
    int x = (rand() % endVal) + startVal;
    return x;
}

