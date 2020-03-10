/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#ifndef SIDEPILE
#define SIDEPILE

#define MAX_SIZE 5
class SidePile{
public:
    SidePile();
    void addCard(int card);
    int removeCard();
    int numCardsLeft();
    int top = 0;
    
    bool pileFull();
    bool pileEmpty();
    class PileFull{};
    class PileEmpty{};
private: 
    int pile[MAX_SIZE] = {};
};
#endif