#include <iostream>
#ifndef HASHTABLE
#define HASHTABLE
using namespace std; 

struct HashItem { 
	public: 
	int data; 
	//int key; 
	
	HashItem(int data) 
	{ 
		this->data = data; 
		//this->key = key; 
	} 
}; 

class HashTable{ 
	HashItem **table; 
	int maxSize; 
	int size;
	int insertChecks;
	int removeChecks;
	int findChecks;


	public:
	HashTable(){ 
		maxSize = 15; 
		size=0; 
        insertChecks = 1;
		removeChecks = 1;
		findChecks = 1;
		table = new HashItem *[maxSize]; 
		
		for(int i=0 ; i < maxSize ; i++) 
			table[i] = NULL; 
	} 

	int hash(int num){ 
		return num % maxSize; 
	} 
	
	void addItem(int data) { 
		 
		int index = hash(data); 
		HashItem *tempHash = new HashItem(data);

		while(table[index] != NULL && table[index]->data != data){ 
			index++; 
			index %= maxSize;
			insertChecks++;
		} 
		
		if(table[index] == NULL) 
			size++; 
		table[index] = tempHash; 
		cout << "Item added successfully" << endl;
	} 
	
	void removeItem(int num) { 
		int index = hash(num); 
		
		while(table[index] != NULL){ 
			if(table[index]->data == num){ 
				HashItem *tempHash = table[index]; 
				
				table[index] = NULL; 
				
				size--; 
				delete(tempHash); 
				cout << "Item removed succesfully" << endl;  
			} 
			index++; 
			index %= maxSize; 
			removeChecks++;

		} 
	} 
	
	int findItem(int num) { 
		int index = hash(num); 
		int counter=0; 
		while(table[index] != NULL){ 
			int counter =0; 
			if(counter++>maxSize) //to avoid infinite loop 
				return NULL;		 
			if(table[index]->data == num) 
				return table[index]->data; 
			index++; 
			index %= maxSize; 
			findChecks++;
		} 
		return NULL; 
	} 

	int getInsertChecks(){
		return insertChecks;
	}
	int getRemoveChecks(){
		return removeChecks;
	}
	int getFindChecks(){
		return findChecks;
	}

	void printOut(){ 
		cout << "______________________" << endl;
		cout << "ITEMS IN HASH TABLE: " << endl;
		for(int i=0 ; i<maxSize ; i++){ 
			if(table[i] == NULL)
				cout << "EMPTY" << endl;
			else 
				cout << " data = "<< table[i]->data << endl; 
		} 
		cout << "______________________" << endl;
	} 

	void empty(){
		for(int i = 0; i < maxSize; i++){
			table[i] == NULL;
		}
	}
}; 
#endif