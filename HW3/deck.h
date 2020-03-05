/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#ifndef DECK
#define DECK



class Deck{
public:
    Deck();
    int takeTopCard();
    void addCardtoBottom(int card);
    int sizeOfDeck();


    bool deckEmpty();

    class deckIsEmpty {};
private:
    int numOfCards;

};
#endif