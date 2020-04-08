#include <iostream>
using namespace std; 

template<typename K, typename T> 

struct HashItem 
{ 
	public: 
	T data; 
	K key; 
	
	HashItem(K key, T data) 
	{ 
		this->data = data; 
		this->key = key; 
	} 
}; 

template<typename K, typename T> 

class HashTable{ 
	HashItem<K,T> **table; 
	int maxSize; 
	int size;
	int numChecks;

	public: 
	HashTable(int newSize){ 
		maxSize = newSize; 
		size=0; 
        numChecks = 0;
		table = new HashItem<K,T>*[maxSize]; 
		
		for(int i=0 ; i < maxSize ; i++) 
			table[i] = NULL; 
	} 

	int hashCode(K key){ 
		return key % maxSize; 
	} 
	
	void addItem(K key, T data) { 
		HashItem<K,T> *tempHash = new HashItem<K,T>(key, data); 
		
		int index = hashCode(key); 

		while(table[index] != NULL && table[index]->key != key){ 
			index++; 
			index %= maxSize;
		} 
		
		if(table[index] == NULL) 
			size++; 
		table[index] = tempHash; 
	} 
	
	T removeItem(int key) { 
		int index = hashCode(key); 
		
		while(table[index] != NULL) 
		{ 
			if(table[index]->key == key) 
			{ 
				HashItem<K,T> *tempHash = table[index]; 
				
				table[index] = NULL; 
				
				size--; 
				return tempHash->data; 
			} 
			index++; 
			index %= maxSize; 

		} 
		
		return NULL; 
	} 
	
	T findItem(int key) { 
		int index = hashCode(key); 
		int counter=0; 
		while(table[index] != NULL) 
		{ int counter =0; 
			if(counter++>maxSize) //to avoid infinite loop 
				return NULL;		 
			if(table[index]->key == key) 
				return table[index]->data; 
			index++; 
			index %= maxSize; 
		} 
		
		return NULL; 
	} 
	
	int sizeofMap(){ 
		return size; 
	} 

	int getNumChecks(){
		return numChecks;
	}

    // void incrementNumChecks(){
    //     numChecks++;
    // }
	
	bool isEmpty(){ 
		return size == 0; 
	} 
	
	void printOut(){ 
		for(int i=0 ; i<maxSize ; i++){ 
			if(table[i] != NULL) 
				cout << "key = " << table[i]->key 
					<<" data = "<< table[i]->data << endl; 
		} 
	} 
}; 