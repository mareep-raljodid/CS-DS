#include <iostream>
#include "hashTable.h"
#include "bst.h"

using namespace std;

int main(){ 
	HashTable<int, int> *h = new HashTable<int, int>(10); 
	h->addItem(1,1); 
    cout << "CHECKS: ";
    cout << h->getNumChecks() << endl;
	h->addItem(2,2); 
    cout << "CHECKS: ";
    cout << h->getNumChecks() << endl;
	h->addItem(2,3); 
    cout << "CHECKS: ";
    cout << h->getNumChecks() << endl;
	h->printOut(); 
	cout << h->sizeofMap() << endl; 
	cout << h->removeItem(2) << endl; 
	cout << h->sizeofMap() <<endl; 
	cout << h->isEmpty() << endl; 
	cout << h->findItem(2); 
	return 0; 
} 