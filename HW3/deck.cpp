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
node *topCard, *bottomCard;

struct node {
    int data;
    node* next;
    node* head;

    node(int d) {
        data = d;
        next = NULL;
    }

};

Deck::Deck() {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {  
        int x = rand() % 52 + 1;
        node* temp = new node(x);
        bottomCard->next = temp;
        bottomCard = temp;

    }
}

int Deck::takeTopCard() {
    if (deckEmpty()) {
        throw deckIsEmpty();
    }
    else {
        return topCard->data;
        numOfCards--;
    }
}

void Deck::addCardtoBottom(int card) {
    node* temp = new node(card);
    bottomCard->next = temp;
    bottomCard = temp;
    numOfCards++;
}


int Deck::sizeOfDeck() {
    return numOfCards;
}

bool Deck::deckEmpty() {
    return topCard == NULL;
}

