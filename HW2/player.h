#include <iostream>

using namespace std;

class Player{
public:
    Player();
    void setBet(int b);
    void incrementTotal(int a);
    void decrementTotal(int c);
    int releaseBall();
    int getBet();
    int getTotal();
    void showCurrentTotal();
private:
    Wheel wheel;
    int bet;
    int total;
};