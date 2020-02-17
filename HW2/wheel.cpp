#include <iostream>
#include "wheel.h"

using namespace std;

srand ( time(NULL) );    


Wheel::Wheel(){
    startVal = 1;
    endVal = 10;
}

int Wheel::setStartVal(int start){
    startVal = start;
}

int Wheel::setEndVal(int end){
    endVal = end;
}

int Wheel::spin(){
    int x = (rand() % endVal) + startVal;
    return x;
})

