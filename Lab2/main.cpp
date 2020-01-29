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
    
    bool PassBall (){
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
	
    int TakeShot(int worth) {
        int shootingPercentage = shotsMade / shotsMade;
        if (worth == 1) {
            shotsTaken++;
            int num = rand() % 80 + 1;
            if (num < shootingPercentage) {
                shotsMade++;
                return worth;
            }
        }
        if (worth == 2) {
            shotsTaken++;
            int num = rand() % 100 + 1;
            if (num < shootingPercentage) {
                shotsMade++;
                return worth;
            }
        }
        if (worth == 3){
            shotsTaken++;
            int num = rand() % 120 + 1;
            if (num < shootingPercentage) {
                shotsMade++;
                return worth;
            }
        }
        else {
            shotsTaken++;
            return 0;
        }
    }

    BasketballPlayer (){
        passesAttempted = 4;
        passesMade = 8;
        shotsMade = 5;
        shotsTaken = 7;
    }
	
    void setName(string n) {
        string name = n;
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

bool team2_takeshot(){
    bool a = (rand() % 100) < 60;
    if (a == true)
        return true;
    else
        return (rand() % 100) > 50;
}

int main() {
	BasketballPlayer players[5];
//#RIP KOBE
    players[0].setName("Kobe1");
    players[1].setName("Kobe2");
    players[2].setName("Kobe3");
    players[3].setName("Kobe4");
    players[4].setName("Kobe5");

    int teamOnePosessions, teamTwoPossesions;

    while(teamOnePosessions != 20 || teamTwoPossesions != 20){

        int randNum = rand() % 5 + 1;
        int playerToPass;

        BasketballPlayer currentPlayer = players[randNum];

        char option;
        int pointOption;
        bool passStatus;
        int teamOneScore, teamTwoScore;

        switch (option){
        case 's':
            cout << "You have chosen to take a shot. How many points would you like to shoot for? Enter 1, 2, or 3.";
            cin >> pointOption;
            teamOneScore = teamOneScore + currentPlayer.TakeShot(pointOption);
            teamOnePosessions += 1;
            break;
        case 'p':
            passStatus = currentPlayer.PassBall();

            cout << "You are " << currentPlayer.getName() << endl;
            cout << "Who would you like to pass to? " << endl;
            cout << "Enter 0 for Kobe1, 1 for Kobe2, 2 for Kobe3, 3 for Kobe4, or 4 for Kobe 5: " << endl;
            cin >> playerToPass;

            if(passStatus){
                teamOnePosessions += 1;
                currentPlayer = players[playerToPass];
            }
            else{
                cout << "The pass was not successful. You will now have a chance to regain possesion. " << endl;
                int randNum = rand() % 1;
                if(randNum == 0){
                    teamOnePosessions += 1;
                    passStatus = currentPlayer.PassBall();

                    cout << "You are " << currentPlayer.getName() << endl;
                    cout << "Who would you like to pass to? " << endl;
                    cout << "Enter 0 for Kobe1, 1 for Kobe2, 2 for Kobe3, 3 for Kobe4, or 4 for Kobe 5: " << endl;
                    cin >> playerToPass;
                }
                else{
                    teamTwoPossesions += 1;
                }
            }
            break;
        case 't':
            cout << "Player stats for " << currentPlayer.getName() << endl;
            cout << "___________________________________________" << endl;
            cout << "Shots taken: " << currentPlayer.getShotsTaken << endl;
            cout << "Shots made: " << currentPlayer.getShotsMade << endl;
            cout << "Passess attempted: " << currentPlayer.getPassesAttemoted << endl;
            cout << "Passess made: " << currentPlayer.getShotsMade << endl;
            break;
        case 'c':
            cout << "Total Scores" << endl;
            cout << "Team 1 score: " << teamOneScore << endl;
            cout << "Team 2 score: " << teamTwoScore << endl;
            cout << "Team 1 possesions:  " << teamOnePosessions << endl;
            cout << "Team 2 possessions: " << teamTwoPossesions << endl;
            break;
        default:
            break;
        }
    }
i
	return 0;
}
