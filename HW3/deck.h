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
    int peekAtTop();
    bool deckEmpty();
    class deckIsEmpty {};
    void decrementCardCount();
private:
    int numOfCards = 52;

};
#endif