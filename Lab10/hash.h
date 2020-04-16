#include <iostream>
#include <string>
#ifndef HASHTABLE
#define HASHTABLE
using namespace std;

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

class HashTable {
	HashItem<K, T>** table;
	int maxSize;
	int size;
	int numChecks;

public:
 	int operations = 0;
    void resetOp() { operations = 0; }
	HashTable(int newSize =0) {
		maxSize = newSize;
		size = 0;
		numChecks = 0;
		table = new HashItem<K, T> * [maxSize];

		for (int i = 0; i < maxSize; i++)
			table[i] = NULL;
	}

	int hashCode(K key) {
		return key % maxSize;
	}

	void getHash(string w) {
		hash(w);
	}

	void addItem(K key, T data) {
		HashItem<K, T>* tempHash = new HashItem<K, T>(key, data);

		string hashKey = to_string(key);
		int index = hash(hashKey);

		while (table[index] != NULL && table[index]->key != key) {
			index++;
			index %= maxSize;
			numChecks++;
			operations++;
		}

		if (table[index] == NULL)
			size++; operations++;
		table[index] = tempHash;
	}

	string removeItem(int key) {
		string hashKey = to_string(key);
		int index = hash(hashKey);

		while (table[index] != NULL){
			operations++;
			if (table[index]->key == key)
			{
				HashItem<K, T>* tempHash = table[index];
				table[index] = NULL;
				size--;
				return toString(tempHash->data);
				delete(tempHash);
			}
			index++;
			index %= maxSize;

		}

		return "";
	}

	string findItem(int key) {
		string hashKey = to_string(key);
		int index = hash(hashKey);
		
		while (table[index] != NULL){
			operations++;
			int counter = 0;
			if (counter++ > maxSize) //to avoid infinite loop 
				return "";
			if (table[index]->key == key)
				return toString(table[index]->data);
			index++;
			index %= maxSize;
		}
		return "";
	}

	int getSize() {
		return size;
	}

	int getNumChecks() {
		return numChecks;
	}

	void printOut() {
		for (int i = 0; i < maxSize; i++) {
			if (table[i] != NULL)
				cout << "key = " << table[i]->key
				<< " data = " << toString(table[i]->data) << endl;
		}
	}

private:
	int hash(string word) {
		int asciiSum;
		for (int i = 0; word[i] != '\0'; i++) {
			asciiSum = asciiSum + word[i];
		}
		return asciiSum % maxSize;
	}
};
#endif
#pragma once
