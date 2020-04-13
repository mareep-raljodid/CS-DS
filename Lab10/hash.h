#include <iostream>
#include <string>
#include "item.h"
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
	HashTable(int newSize) {
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
		}

		if (table[index] == NULL)
			size++;
		table[index] = tempHash;
	}

	T removeItem(int key) {
		string hashKey = to_string(key);
		int index = hash(hashKey);

		while (table[index] != NULL)
		{
			if (table[index]->key == key)
			{
				HashItem<K, T>* tempHash = table[index];
				table[index] = NULL;
				size--;
				return tempHash->data;
				delete(tempHash);
			}
			index++;
			index %= maxSize;

		}

		return NULL;
	}

	T findItem(int key) {
		string hashKey = to_string(key);
		int index = hash(hashKey);
		int counter = 0;
		while (table[index] != NULL)
		{
			int counter = 0;
			if (counter++ > maxSize) //to avoid infinite loop 
				return NULL;
			if (table[index]->key == key)
				return table[index]->data;
			index++;
			index %= maxSize;
		}

		return NULL;
	}

	int getSize() {
		return size;
	}

	int getNumChecks() {
		return numChecks;
	}

	// void incrementNumChecks(){
	//     numChecks++;
	// }

	void printOut() {
		for (int i = 0; i < maxSize; i++) {
			if (table[i] != NULL)
				cout << "key = " << table[i]->key
				<< " data = " << table[i]->data << endl;
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
