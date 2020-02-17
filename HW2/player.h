#include <iostream>

using namespace std;

class Player{
public:
    Player();
    int setBet(int b);
    int getBet();
    int getTotal();
private:
    Wheel wheel;
    int bet;
    int total;
};