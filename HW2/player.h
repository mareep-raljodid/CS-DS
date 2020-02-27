/* Authors:
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#ifndef PL
#define PL

#include <iostream>
#include "wheel.h"
#include "wheelHarder.h"
using namespace std;

class Player{
public:
    Player();
    void setBet(int b);
    void incrementTotal(int a);
    void decrementTotal(int c);
    void setWheel(int f, int e);
    int releaseBall();
    int getBet();
    int getTotal();
    void showCurrentTotal();
private:
    Wheel wheel;
    int bet;
    int total;
};

class PlayerH{
public:
    PlayerH();
    void setBet(int b);
    void incrementTotal(int a);
    void decrementTotal(int c);
    void setWheel(int f, int e);
    int releaseBall(bool);
    int getBet();
    int getTotal();
    void showCurrentTotal();
private:
    WheelH wheel;
    int bet;
    int total;
};

#endif
