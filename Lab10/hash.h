#include <iostream>
#include <string>
#ifndef HASHTABLE
#define HASHTABLE
using namespace std;
template <typename K, typename T>
class HashTable{
    public:
        struct HashItem{
            K key;
            T data;

            HashItem(K k, T d){
                this->key = k;
                this->data = d;
            }
        };
        int size = 0;
        int maxSize = 100;
        HashItem<K, T> *table[maxSize];

        HashTable(int newSize){
            maxSize = newSize;
            for(int i = 0; i < maxSize; i++){
                table[i] == NULL;
            }
        }

        void getHash(string w){
            hash(w);
        }

        void addItem(K key, T data){
            HashItem<K,T> *tempHash = new HashItem<key,data>;
            string hashKey = to_string(key);
            int index = hash(hashKey);
            while(table[index] != NULL && table[index]->key != key 
               && table[index]->key != -1){ 
                index++; 
                index %= maxSize; 
            } 
            if(table[index] == NULL || table[index]->key == -1){
                size++; 
            } 
            table[index] = tempHash;
        }

        T removeItem(K key){
            string hashKey = to_string(key);
            int index = hash(hashKey);
            while(table[index] != NULL){ 
                if(table[index]->key == key){ 
                    HashItem<K,T> *tempHash = table[index]; 
                    table[index] == NULL;
                    size--; 
                    return tempHash->value; 
                    delete(tempHash);
                } 
                index++; 
                index %= maxSize; 
            }
            return NULL; //return null if not found
        }

        T getItem(K key){
            string hashKey = to_string(key);
            int index = hash(hashKey);
            while(table[index] != NULL){ 
                if(table[index]->key == key){ 
                    return table[index]->data;
                } 
                index++; 
                index %= maxSize; 
            }
            return NULL; //return null if not found
        }

        int getLength(){
            return size;
        }

        ~HashTable();
    private:
        int hash(string word){
            int asciiSum;
            for(int i = 0; word[i] != '\0'; i++){
                asciiSum = asciiSum + word[i];
            }
            return asciiSum % maxSize;
        }
};
#endif