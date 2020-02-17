#include <iostream>

using namespace std;

Player::Player(){
    bet = 0;
    total = 0;
}

int Player::getBet(){
    return bet;
}

int Player::getTotal(){
    return total;
}

void Player::setBet(int b){
    bet =  b;
}