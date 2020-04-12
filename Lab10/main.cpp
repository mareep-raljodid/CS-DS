#include <iostream>
#include "hash.h"

using namespace std;

int main(){
    HashTable<int, int> *h = new HashTable<int, int>(10); 

    h->addItem(1,2);
    h->addItem(2,4);
    h->addItem(2,5);
    h->addItem(3,8);   
    h->printOut();
    return 0;
}