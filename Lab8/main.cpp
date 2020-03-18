#include "list.h"
#include "item.h"

#include <iostream>

using namespace std;

int main() {

    List<Item> myList;

    int selection;
    char option = '1';
    while (option != '12') {
        cout << "Linked Lists Options: " << endl;
        cout << "1: Add Item" << endl;
        cout << "2: Get Item" << endl;
        cout << "3: Is In List" << endl;
        cout << "4: Is Empty" << endl;
        cout << "5: Size" << endl;
        cout << "6: See Next" << endl;
        cout << "7: See Previous" << endl;
        cout << "8: See At" << endl;
        cout << "9: Display" << endl;
        cout << "10: Reset" << endl;
        cout << "11: Destructor" << endl;
        cout << "12: Quit" << endl;

        cin >> option;


        if (option == '1') {
            unsigned SKU;
            string descrp;
            unsigned price;
            string UOM;
            unsigned qoh;

            cout << "Adding Item" << endl;
            cout << "Please enter the SKU" << endl;
            cin >> SKU;
            cout << "Please enter the Description" << endl;
            cin >> descrp;
            cout << "Please enter price" << endl;
            cin >> price;
            cout << "Please enter Unit of Measure" << endl;
            cin >> UOM;
            Item item(SKU, price, descrp, UOM, qoh = 0);

            myList.insert(item, true);

        }
        if (option == '2') {
            cout << "Which Item would you like to get?" << endl;
            cin >> selection;
            myList.getItem(selection);



        }
        if (option == '3') {
            cout << "Checking to see if it is in List" << endl;
        }
        if (option == '4') {
            cout << "Checking to see if its empty" << endl;
            if (myList.isEmpty() == true) {
                cout << "Empty" << endl;
            }
            else {
                cout << "Not Empty" << endl;
            }
        }
        if (option == '5') {
            cout << "Checking size" << endl;
            myList.size();
        }
        if (option == '6') {
            cout << "Seeing next" << endl;

            myList.seeNext();
        }
        if (option == '7') {
            cout << "Seeing previous" << endl;
            myList.seePrev();
        }
        if (option == '8') {
            cout << "Where would you like to see at?" << endl;
            cin >> selection;

            myList.seeAt(selection);

        }
        if (option == '9') {
            cout << "Displaying" << endl;
            myList.display();
        }
        if (option == '10') {
            cout << "Resetting" << endl;
            myList.reset();
        }
        if (option == '11') {
            cout << "Calling Destructor" << endl;


        }
        if (option == '12') {
            cout << "Quitting" << endl;
            break;
        }

    }
    return 0;
}
