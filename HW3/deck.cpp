/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */
#include <iostream>>
#include <stddef.h>
#include <stdlib.h>
#include <ctime> 
#include "deck.h"

using namespace std;


class node {
    int data;
    Node* next;

};


Deck::Deck() {
    srand(time(NULL));
    for (int i = 0; i < 25; i++) {  //uhhhh how many cards need to be in the pile in the beginning
        int x = rand() % 52 + 1;
        mainDeck[i] = new Node();
    }
}

void Deck::takeTopCard() {
  
}

void Deck::addCardtoBottom(int card) {

}


int Deck::sizeOfDeck() {
    
}

bool Deck::deckEmpty() {
    return topCard == NULL;
}

