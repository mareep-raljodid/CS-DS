#include <iostream>
#include "show.h"
#define MAX_SIZE 10
#ifndef SHELFF
#define SHELFF


class Shelf{
public:
    unsigned index;
    Show shelf[MAX_SIZE] = {};
    Shelf();
    int getCurrentAmount();
    void addShow(Show &s);
    void removeShow();
    class FullShelf {};
    class EmptyShelf {};

private:
    int currentNumOfShows;
};
#endif
