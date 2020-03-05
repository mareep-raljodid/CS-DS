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
    Node* head;

    Node(int d) {
        data = d;
        next = NULL;
    }

};


Deck::Deck() {
    Node *topCard, *bottomCard;
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {  
        int x = rand() % 52 + 1;
        Node* temp = new Node(x);
        bottomCard->next = temp;
        bottomCard = temp;

    }
}

void Deck::takeTopCard() {
    if (deckEmpty()) {
        throw deckIsEmpty
    }
    else {

    }
  
}

void Deck::addCardtoBottom(int card) {
    Node* temp = new Node(card);
    bottomCard->next = temp;
    bottomCard = temp;

}


int Deck::sizeOfDeck() {
    
}

bool Deck::deckEmpty() {
    return topCard == NULL;
}

