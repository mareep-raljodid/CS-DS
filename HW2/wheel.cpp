#include <iostream>
#include "wheel.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

srand ( time(NULL) );    


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
    int x = (rand() % endVal) + startVal;
    return x;
})

