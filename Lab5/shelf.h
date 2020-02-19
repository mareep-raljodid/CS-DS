#include <iostream>
#include "show.h"
#define MAX_SIZE 10

class Shelf{
public:
    unsigned index;
    Show shelf[MAX_SIZE];
    Shelf();
    void setCurrentAmount(int c);
    int getCurrentAmount();
    void addShow(Show &s);
    Show removeShow();

private:
    int currentNumOfShows;
};