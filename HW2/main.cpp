#include <iostream>
#include <string>
#include "wheel.h"
#include "player.h"

using namespace std;

int main(){
    
    Player player
    Player house;
    char selection;
    char changeWager;
    int wagerChoice;
    int currentBet;
    int playerBall;
    int ball1;
    int ball2;
    
    cout << "Welcome to the Roulette game!" << endl;
    
    do{
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
            cout << "Enter 1 for double, or 2 for halve.";
            cin >> wagerChoice;
            
            cout << "The house will now have two chances to beat you." << endl;
            ball1 = house.releaseBall();
            ball2 = house.releaseBall();
            
            if(wagerChoice == 1){
                currentBet = currentBet *2;
                if(ball1 > playerBall || ball2 > playerBall){
                    player.incrementTotal(currentBet);
                }
                else{
                    player.decrementTotal(currentBet);
                }
            }
            else if(wagerChoice == 2){
                currentBet = currentBet / 2;
                if(ball1 > playerBall && ball2 > playerBall){
                    player.incrementTotal(currentBet);
                } 
                else{
                    player.decrementTotal(currentBet);
                }
            }
        }
        
        
        
        
        
        
        
        
        
    }while(selection == 'y' || player.getTotal() != 0)
    
    
    
    
    
    
    
    
    return 0;
}
