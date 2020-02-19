#include <iostream>
#include "show.h"
#define MAX_SIZE 10

class Shelf{
public:
    Show shelf[MAX_SIZE];
    void setCurrentAmount(int c);
    int getCurrentAmount();

private:
    int currentAmount;
};