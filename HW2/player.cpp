#include <iostream>
#include "player.h"

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

int Player::releaseBall(){
    return wheel.spin();
}

void Player::setWheel(int f, int e){
    wheel.setStartVal(f);
    wheel.setEndVal(e);
}

void Player::showCurrentTotal(){
    cout << "Your current total is $" << total;
}

void Player::setBet(int b){
    bet =  b;
}

void Player::incrementTotal(int a){
    total = total + a;
}

void Player::decrementTotal(int c){
    total = total - c;
}

PlayerH::PlayerH(){
    bet = 0;
    total = 0;
}

int PlayerH::getBet(){
    return bet;
}

int PlayerH::getTotal(){
    return total;
}

int PlayerH::releaseBall(bool playerWon){
    return wheel.spin(playerWon);
}

void PlayerH::setWheel(int f, int e){
    wheel.setStartVal(f);
    wheel.setEndVal(e);
}

void PlayerH::showCurrentTotal(){
    cout << "Your current total is $" << total;
}

void PlayerH::setBet(int b){
    bet =  b;
}

void PlayerH::incrementTotal(int a){
    total = total + a;
}

void PlayerH::decrementTotal(int c){
    total = total - c;
}
