#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class BasketballPlayer {

    private:
    string name;
    int shotsTaken;
    int shotsMade;
    int passesAttempted;
    int passesMade;

    public:
    
    bool PassBall (){                                       //pass ball function
        passesAttempted += 1;
        int r = rand() % 100 + 1;
        if(r > ((passesMade/(passesAttempted-1))*100)){
            passesMade += 1;
            return true;
        }
        else{
            passesMade += 0;
            return false;
        }
    }
    
    int TakeShot(int worth) {                               //take shot function
        int shootingPercentage = shotsMade / shotsMade;
        int pointsReceived;
        if (worth == 1) {
            shotsTaken++;
            int num = rand() % 80 + 1;
            if (num < shootingPercentage) {
                shotsMade++;
                pointsReceived = worth;
            }
            else{
                pointsReceived = 0;
            }
        }
        else if (worth == 2) {
            shotsTaken++;
            int num = rand() % 100 + 1;
            if (num < shootingPercentage) {
                shotsMade++;
                pointsReceived = worth;
            }
            else{
                pointsReceived = 0;
            }
        }
        else if (worth == 3){
            shotsTaken++;
            int num = rand() % 120 + 1;
            if (num < shootingPercentage) {
                shotsMade++;
                pointsReceived = worth;
            }
            else{
                pointsReceived = 0;
            }
        }
        else {
            shotsTaken++;
            pointsReceived = 0;
        }
        return pointsReceived;
    }

    BasketballPlayer (){
        passesAttempted = 8; //default info so passing and shooting percentages can be calculated.
        passesMade = 4;
        shotsMade = 5;
        shotsTaken = 7;
    }
    
    void setName(string n) {
        name = n;
    }

    string getName(){
        return name;
    }

    int getShotsMade() {
        return shotsMade;
    }

    int getShotsTaken() {
       return shotsTaken;
    }

    int getPassesMade() {
        return passesMade;
    }

    int getPassesAttemoted() {
        return passesAttempted;
    }
    
};

bool team2_takeshot(){                  //function to determine chance of team two making a shot
    bool a = (rand() % 100) < 60;
    if (a == true)
        return true;                    // if first attempt is not successful, other team has 50% to regain possession
    else
        cout << "The first attempt was not successful. The other team will now have a shot at a rebound. " << endl;
        return (rand() % 100) > 50;
}

int main() {
    srand ( time(NULL) );               //seeding random numbers
    BasketballPlayer players[5];
//#RIP KOBE
    players[0].setName("Kobe1");        // initializing player names
    players[1].setName("Kobe2");
    players[2].setName("Kobe3");
    players[3].setName("Kobe4");
    players[4].setName("Kobe5");

    int teamOnePosessions = 0;
    int teamTwoPossesions = 0;
    
    int teamOneScore = 0;
    int teamTwoScore = 0;
    
    cout << "Welcome to the game!" << endl;
    cout << "You will now be assigned a random player." << endl;
    cout << endl;
    
    int randNum = (rand() % 5) + 1;
    BasketballPlayer currentPlayer = players[randNum];  //setting random current player
    
    cout << "You are " << currentPlayer.getName() << "." << endl;
    cout << endl;
    
    while(teamOnePosessions < 20 || teamTwoPossesions < 20){

        int playerToPass;
        int secondRandNum;

        char option;
        int pointOption;
        int teamTwoPoints;
        bool passStatus;
        bool teamTwoStatus;
        
        cout << "You can perform one of the following actions: " << endl;  //presenting user options
        cout << " (s) Shoot" << endl;
        cout << " (p) Pass" << endl;
        cout << " (t) See Player Stats" << endl;
        cout << " (c) See Score" << endl;
        
        cout << "Which would you like to do? Enter s for shoot, p for pass, t for statistics, and c for score: ";
        cin >> option;
        cout << endl;

        switch (option){
        case 's':                   //code implemented if user decides to take a shot
            cout << "You have chosen to take a shot. How many points would you like to shoot for? Enter 1, 2, or 3: ";
            cin >> pointOption;
            
            teamOnePosessions += 1;

            if(currentPlayer.TakeShot(pointOption) == 0){
                cout << "The shot was not successful. You will now have a chance to regain possession." << endl;
                cout << endl;
                secondRandNum = (rand() % 2) + 1;
                if(secondRandNum == 1){
                    teamOnePosessions += 1;
                    cout << "You have regained possession. " << endl;
                    cout << "You will now take another shot. How many points would you like to shoot for? Enter 1, 2, or 3: ";
                    cin >> pointOption;
                    if(currentPlayer.TakeShot(pointOption) != 0){
                        cout << "Shot successful." << endl;
                        cout << endl;
                        teamOneScore = teamOneScore + currentPlayer.TakeShot(pointOption);
                    }
                    else{
                        cout << "You have missed." << endl;
                        cout << endl;
                    }
                }
                else{
                    cout << "You have not regained possession." << endl;
                    cout << "The other team will now have a chance to take a shot." << endl;
                    
                    teamTwoStatus = team2_takeshot();
                    teamTwoPossesions +=1;
                    if(teamTwoStatus == true){
                        
                        teamTwoPoints = (rand() % 3) + 1;
                        teamTwoScore = teamTwoScore + teamTwoPoints;
                        
                        cout << "The other team's shot was successful. They scored " << teamTwoPoints <<  " points." << endl;
                        cout << endl;
                        
                    }
                    else{
                        cout << "The other team's shot was not successful. " << endl;
                        cout << endl;
                    }
                }
            }
            else{
                cout << "Shot successful" << endl;
                cout << endl;
                teamOneScore = teamOneScore + currentPlayer.TakeShot(pointOption);
            }
            break;
        case 'p':                           //code implemented if user decides to pass
            cout << "You are " << currentPlayer.getName() << endl;
            cout << "Who would you like to pass to? " << endl;
            cout << "Enter 0 for Kobe1, 1 for Kobe2, 2 for Kobe3, 3 for Kobe4, or 4 for Kobe 5: " << endl;
            cin >> playerToPass;
                
            passStatus = currentPlayer.PassBall();

            if(passStatus){
                cout << "Pass successful" << endl;
                cout << endl;
                teamOnePosessions += 1;
                currentPlayer = players[playerToPass];
            }
            else{
                cout << "The pass was not successful. Possesion will change to team two." << endl;
                cout << endl;
                
                teamTwoPossesions += 1;
                
                teamTwoStatus = team2_takeshot();
                teamTwoPossesions +=1;
                if(teamTwoStatus == true){
                    
                    teamTwoPoints = (rand() % 3) + 1;
                    teamTwoScore = teamTwoScore + teamTwoPoints;
                    
                    cout << "The other team's shot was successful. They scored " << teamTwoPoints <<  " points." << endl;
                    cout << endl;
                    
                }
                else{
                    cout << "The other team's shot was not successful. " << endl;
                    cout << endl;
                }
                
            }
            break;
        case 't':                       //code implemented if user decides to view player stats
            cout << "Player stats for " << currentPlayer.getName() << endl;
            cout << "___________________________________________" << endl;
            cout << "Shots taken: " << currentPlayer.getShotsTaken() << endl;
            cout << "Shots made: " << currentPlayer.getShotsMade() << endl;
            cout << "Passess attempted: " << currentPlayer.getPassesAttemoted() << endl;
            cout << "Passess made: " << currentPlayer.getShotsMade() << endl;
            cout << endl;
            break;
        case 'c':                       //code implemented if user decides to view scores
            cout << "Total Scores" << endl;
            cout << "Team 1 score: " << teamOneScore << endl;
            cout << "Team 2 score: " << teamTwoScore << endl;
            cout << "Team 1 possesions:  " << teamOnePosessions << endl;
            cout << "Team 2 possessions: " << teamTwoPossesions << endl;
            cout << endl;
            break;
        default:
            break;
        }
    }
    cout << "_________________________________________________" << endl;    //end of game, final scores printed
    cout << "The game is now over. Here are the final scores:" << endl;
    cout << "Team 1 score: " << teamOneScore << endl;
    cout << "Team 2 score: " << teamTwoScore << endl;
    
    return 0;
}
