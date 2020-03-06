/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */
#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include <ctime> 
#include "deck.h"

using namespace std;

struct node {
    int data;
    node* next;
    node* head;

    node(int d) {
        data = d;
        next = NULL;
    }

};

node *topCard, *bottomCard;

Deck::Deck() {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {  
        int x = rand() % 52 + 1;
        node* temp = new node(x);
        if(bottomCard == NULL){
            topCard = bottomCard = temp;
        }
        bottomCard->next = temp;
        bottomCard = temp;

    }
}

int Deck::takeTopCard() {
    if (deckEmpty()) {
        bottomCard = NULL;
        throw deckIsEmpty();
    }
    else {
        node* temp = topCard;
        topCard = topCard->next;
        return topCard->data;
        delete(temp);
        numOfCards--;
    }
}

void Deck::addCardtoBottom(int card) {
    node* temp = new node(card);
    bottomCard->next = temp;
    bottomCard = temp;
    numOfCards++;
}

int Deck::peekAtTop(){
    return topCard->data;
}

int Deck::sizeOfDeck() {
    return numOfCards;
}

bool Deck::deckEmpty() {
    return topCard == NULL;
}

