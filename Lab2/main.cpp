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
};


int main() {
	BasketballPlayer players[5];

	return 0;
}
