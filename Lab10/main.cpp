#include <iostream>
#include "hash.h"
#include "item.h"

using namespace std;

int main() {
    HashTable<int, Item>* h = new HashTable<int, Item>(10);

    //h->addItem(1, 2);
   // h->addItem(2, 4);
    //h->addItem(2, 5);
   // h->addItem(3, 8);
   // h->printOut();
ttop:

    string option = "1";
    while (option != "7") {
        cout << "Hash Table Options: " << endl;
        cout << "1: Add Item" << endl;
        cout << "2: Remove Item" << endl;
        cout << "3: Find Item" << endl;
        cout << "4: Is Empty" << endl;
        cout << "5: Size" << endl; 
        cout << "6: Display" << endl;
        cout << "7: Quit" << endl;

        cin >> option;


        if (option == "1") {
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

            Item* ptrItem = new Item(SKU, price, descrp, UOM, qoh = 0);

            h->addItem(SKU, *ptrItem);
        }


        if (option == "2") {

            unsigned SKU;
            string descrp;
            unsigned price;
            string UOM;
            unsigned qoh;
            cout << "Which Item would you like to Remove? Enter Item" << endl;
            cout << "Please enter the SKU" << endl;

            cin >> SKU;
            cout << "Please enter the Description" << endl;
            cin >> descrp;
            cout << "Please enter price" << endl;
            cin >> price;
            cout << "Please enter Unit of Measure" << endl;
            cin >> UOM;

            Item* ptrItem = new Item(SKU, price, descrp, UOM, qoh = 0);

            

            h->removeItem(SKU);
        }

        if (option == "3") {

            cout << "Checking to see if it is in List" << endl;
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

            Item* ptrItem = new Item(SKU, price, descrp, UOM, qoh = 0);
            if (h->findItem(SKU))
                cout << "Exists in list" << endl;
            else
                cout << "Doesn't exist in list" << endl;


        }
        if (option == "4") {
            cout << "Checking to see if its empty" << endl;
            if (h->getSize() == 0) {
                cout << "Empty" << endl;
            }
            else {
                cout << "Not Empty" << endl;
            }
        }
        if (option == "5") {
            cout << "Checking size" << endl;
            cout << h->getSize() + 1;
        }
        if (option == "6") {
            cout << "Displaying" << endl;
            h->printOut();
            goto ttop;
        }
        if (option == "7") {
            cout << "Quitting" << endl;
            break;
        }

    }
    return 0;
}
