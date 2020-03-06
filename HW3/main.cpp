/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include "sidePile.h"
#include "deck.h"
#include <iostream>

using namespace std;

void display(){
    cout << "Your options are: " << endl;
    cout << "(1) Draw from sidepile" << endl;
    cout << "(2) Peek at top card in Deck " << endl;
    cout << "Enter any other number to do nothing" << endl;
}

int main(){


    cout << "Welcome to the War card game!" << endl;
    cout << "This game will be played by playing 10 rounds. The player with the highest number of wins at the end will win. " << endl;
    cout << "At the beginning of each round, a card will be drawn from your and your opponent's deck. Before a card is drawn, you may perform one of the following actions: "<< endl;
    display();

    int startNum = 1; 

    Deck playerDeck;
    Deck computerDeck;

    SidePile playerSidePile;
    SidePile computerSidePile;

    int numRounds = 0;
    int playerWins;
    int computerWins;

    int playerDrawnCard;
    int computerDrawnCard;

    cout << "Press 1 to begin: "; 
    cin >> startNum;
    
    if(startNum == 1){
        while(numRounds < 11 || (!playerDeck.deckEmpty() || !playerSidePile.pileEmpty())){
            int action = 0;
            int playerRoundTotal = 0;

            playerDrawnCard = playerDeck.takeTopCard();
            computerDrawnCard = computerDeck.takeTopCard();

            char viewDeck;

            cout << "Would you like to see how many cards the computer has left in their deck? Enter y for yes and n for no: ";
            cin >> viewDeck;

            if(viewDeck == 'y'){
                cout << "The computer has " << computerDeck.sizeOfDeck() << " cards in their deck. " << endl;
            }

            display();
            cout << "Please enter in your choice: "; 
            cin >> action;

            if(action == 1){
                try{
                    int sidePileCard = playerSidePile.removeCard();
                    playerRoundTotal = playerDrawnCard + sidePileCard;
                }
                catch(SidePile::PileEmpty){
                    cout << "Side pile is empty. Cannott draw from side pile." << endl;
                }
                
            }
            if(action == 2){
                char doAction;
                int peekCard = playerDeck.peekAtTop();
                cout << "Would you like to keep this card or move it to your side pile?  Enter y for yes and n for no: "; 
                cin >> doAction;
                if(doAction == 'y'){
                    playerSidePile.addCard(peekCard);
                    cout << "Card was added to side pile." << endl;
                    cout << "Now drawing you a new card from your deck" << endl;
                    playerDrawnCard = playerDeck.takeTopCard();
                    playerRoundTotal = playerDrawnCard;
                }
            }
            // else{
            //     cout << "Invalid input. Please enter in a valid choice: ";
            //     cin >> action;
            // }

            if(playerRoundTotal > computerDrawnCard){
                cout << "You have won this round!" << endl;
                playerWins++;
            }
            else{
                cout << "The computer won this round. " << endl;
                computerWins++;
            }
        }
        
    }
    else{
        cout << "Invalid input. Please enter 1 to begin: ";
        cin >> startNum;
    }

    return 0;
}