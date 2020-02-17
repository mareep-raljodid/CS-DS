#include <iostream>
#include <string>
#include "player.h"

using namespace std;

int main(){
    
    Player player;
    Player house;
    char selection = 'y';
    char changeWager;
    char show;
    int wagerChoice;
    int currentBet;
    int playerBall;
    int ball1;
    int ball2;
    int first;
    int last;
    
    cout << "Welcome to the Roulette game!" << endl;
    
    while(selection == 'y' || player.getTotal() != 0){
        
        cout << "Enter the starting and ending values for the range of the wheel: " << endl;
        cout << "Starting value: "; 
        cin >> first;
        
        cout << "Ending value: ";
        cin >> last;
        
        player.setWheel(first, last);
        
        cout << "Please enter how much you would like to bet: ";
        cin >> currentBet;
        
        player.setBet(currentBet);
        
        cout << "You will now release your ball."  << endl;
        cout << "Your ball landed on " << player.releaseBall() << endl;
        playerBall = player.releaseBall();
        
        cout << "You now have the chance to double, halve, or keep the same wager. Would you like to change it?" << endl;
        cout << "Enter y for yes and n for no: "; 
        
        cin >> changeWager;
        
        if(changeWager == 'y'){
            cout << "You have decided to change your wager. You can either double or halve it." << endl;
            cout << "Enter 1 for double, or 2 for halve: ";
            cin >> wagerChoice;
            
            cout << "The house will now have two chances to beat you." << endl;
            ball1 = house.releaseBall();
            ball2 = house.releaseBall();
            
            if(wagerChoice == 1){
                currentBet = currentBet *2;
                if(ball1 < playerBall || ball2 < playerBall){
                    cout << "You won the turn!" << endl;
                    player.incrementTotal(currentBet);
                }
                else{
                    cout << "You lost the turn." << endl;
                    player.decrementTotal(currentBet);
                }
            }
            else if(wagerChoice == 2){
                currentBet = currentBet / 2;
                if(ball1 < playerBall && ball2 < playerBall){
                    cout << "You won the turn!" << endl;
                    player.incrementTotal(currentBet);
                } 
                else{
                    cout << "You lost the turn." << endl;
                    player.decrementTotal(currentBet);
                }
            }
        }
        
        cout << "Would you like to view your current total? Enter y for yes and n for no: ";
        cin >> show;
        
        if(show == 'y'){
            player.showCurrentTotal();
            cout << endl;
        }
        
        cout << "Would you like to roll again? Enter y to continue or n to stop: ";
        cin >> selection;
        
    }

    return 0;
}
