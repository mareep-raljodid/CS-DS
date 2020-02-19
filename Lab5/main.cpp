#include <iostream>
#include "shelf.h"
#include "show.h"
using namespace std;

int main(){

    Shelf shelf;
    Show show;
    
    cout << "Press 1 to add a board game to the shelf." << endl;
    cout << "Press 2 remove a board game from the shelf." << endl; 
    cout << "Press 3 see how many board games are currently on the shelf." << endl;
    cout << "Press 4 to quit." << endl;
    
    unsigned ch;
    
    while(ch != 4){
        if (ch == 1) {
        cout << "Adding a Game to the shelf" << endl;
        shelf.addShow(new show);
        }
    
        if(ch == 2){
            cout << "Removing a game from the shelf"  << endl;
            cout << shelf.removeShow();
        }
        if(ch == 3){
            cout << "Seeing how many board games are currently on the shelf. " << endl;
            cout << shelf.getCurrentAmount();
        }
    }
    return 0;
}
