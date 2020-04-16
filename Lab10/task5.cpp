#include <iostream>
#include "hash.h"
#include "item.h"
#include "chained.h"
#include <vector>

using namespace std;

vector<int> randomNumbers() {
    vector<int> r;
    int i =0;
    while(i < 250){
        r.push_back(rand() % 250 + 1);
        i++;
    }
    return r;
}

int main(){
    HashTable<int, Item>* h = new HashTable<int, Item>(250);
    HashList<int, Item>* hl = new HashList<int, Item>(250);

    cout << "Generating 250 random items" << endl;

    vector<int> randomNums = randomNumbers();

    unsigned SKU;
    string descrp = "description";
    unsigned price = 100;
    string UOM  = "lb";
    unsigned qoh = 50;

    for(int i = 0; i<250; i++){
        SKU = randomNums[i];
        Item* ptrItem = new Item(SKU, price, descrp, UOM, qoh);
        h->addItem(SKU, *ptrItem);
        hl->addItem(SKU, *ptrItem);
    }

    cout << "\n\n";
    cout << "Added 250 items, showing stats ----------------------" << endl;
    cout << "Operations Time for Linear Probing Hash Table: " << h->operations << endl;
    cout << "Operations Time for Chained Hash Table: " << hl->operations << endl;
    return 0;
}