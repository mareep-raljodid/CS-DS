#include <iostream>
#include <string>

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



    }

    BasketbalPlayer (){
        passesAttempted = 4;
        passesMade = 8;
        shotsMade = 5;
        shotsAttempted = 7;
    }
};


int main() {
	BasketballPlayer players[5];

	return 0;
}
