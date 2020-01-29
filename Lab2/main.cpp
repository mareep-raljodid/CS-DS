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

    BasketballPlayer (){
        passesAttempted = 4;
        passesMade = 8;
        shotsMade = 5;
        shotsTaken = 7;
    }
	
    void setName(string n) {
        string name = n;
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


int main() {
	BasketballPlayer players[5];
	
    players[0].setName("Kobe1");
    players[1].setName("Kobe2");
    players[2].setName("Kobe3");
    players[3].setName("Kobe4");
    players[4].setName("Kobe5");

	return 0;
}
