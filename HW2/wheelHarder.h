#ifndef WHH
#define WHH

#include <iostream>
#include "wheel.h"
using namespace std;

class WheelH : public Wheel {
    
    public:
    bool playerWon = false;

    int spin(bool playerWon){
        srand (time(NULL));  
        int x;
        if (playerWon)
            x = (rand() % Wheel::endVal+5) + Wheel::startVal+5;
        else
            x = (rand() % Wheel::endVal) + Wheel::startVal;

        return x;

    }

};

#endif
