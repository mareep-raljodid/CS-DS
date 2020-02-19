#include <iostream>
#include "show.h"
#define MAX_SIZE 10
#ifndef SHELF
#define SHELF


class Shelf{
public:
    unsigned index;
    Show shelf[MAX_SIZE] = {};
    Shelf();
    int getCurrentAmount();
    void addShow(Show &s);
    void removeShow();
    bool compareNul(Show &s){
        if ((s.getTitle() == "") && (s.getDesc() == ""))
            return true;
        return false;
    }

private:
    int currentNumOfShows;
};
#endif
