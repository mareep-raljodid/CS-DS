#include <iostream>
#include "shelf.h"
#include "show.h"
using namespace std;

int main() {

    Shelf shelf;
    Show show;
    char continueOn = 'y';
    int ch;
    while (continueOn != 'n') {

        //        cout << "Would you like to perform an action? Enter y for yes and n for no: ";
        //        cin >> continueOn;

        cout << "Press 1 to add a board game to the shelf." << endl;
        cout << "Press 2 remove a board game from the shelf." << endl;
        cout << "Press 3 see how many board games are currently on the shelf." << endl;
        cout << "Press 4 to quit." << endl;
        cout << "Your choice: ";
        cin >> ch;

        switch (ch) {


        case 1:
            cout << "Adding a Game to the shelf" << endl;
            try {
                shelf.addShow(show);
            }
            catch (Shelf::FullShelf) {
                cout << "Cannot add another show, the shelf is full. \n." << endl;

                cout << endl;
            }
            break;

        case 2:
            cout << "Removing a game from the shelf" << endl;
            try {
                shelf.removeShow();
            }
            catch (Shelf::EmptyShelf) {
                cout << "Cannot remove another show, the shelf is empty. \n" << endl;

                cout << endl;
            }
            break;

        case 3:
            cout << "Seeing how many board games are currently on the shelf. " << endl;
            cout << shelf.getCurrentAmount();
            cout << endl;
            break;
        case 4:
            continueOn = 'n';
            break;

        }
    }

return 0;
}
