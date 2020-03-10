/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include "sidePile.h"
#include <stddef.h>
#include <stdlib.h>
#include <ctime> 

using namespace std;

SidePile::SidePile(){
    srand(time(NULL));
    for(int i = 0; i < 5; i++){  //sets random cards for sidepile
        int x = rand() % 52 + 1;
        pile[i] = x;
    }
}

void SidePile::addCard(int c){  //adding card to stack
    if(pileFull()){
        throw PileFull();
    }
    else{
        pile[top] = c;
        top++;
    }
}

int SidePile::removeCard(){  //removing card from stack
    if(pileEmpty()){
        throw PileEmpty();
    }
    else{
        top--;
        return pile[top];
    }
}

int SidePile::numCardsLeft(){   //returns number of cards left in the side pile
    return MAX_SIZE - top;
}

bool SidePile::pileEmpty(){  //checks if pile is empty
    return MAX_SIZE - top == 0;
}

bool SidePile::pileFull(){  //checks if pile is full
    return top == MAX_SIZE - 1;
}