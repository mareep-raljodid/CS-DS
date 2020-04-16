#ifndef LISTI
#define LISTI
#include "hash.h"
#include "list.h"
#include <cstddef>
#include <utility>
#include <vector>

template<typename K, typename T>
struct HashItem_ptr {
    public:
        List<T>* data = new List<T>;
        K key;

        HashItem_ptr<K,T>(K key, T dat) {
            data->insert(dat);
            this->data = data;
            this->key = key;
        }

        HashItem_ptr<K,T>(){
        this->data = data;
        this->key = '\0';
        }
};

template <typename K, typename T>
class HashList : public HashItem_ptr<K, T>, HashTable<K, T>, List<T>{

private:
    int maxSize;
    vector<HashItem_ptr<K, T>*> hl;
    int size;
    int numChecks;
    int hash(string word) {
        int asciiSum;
        for (int i = 0; word[i] != '\0'; i++) {
            asciiSum = asciiSum + word[i];
        }
        return asciiSum % maxSize;
    }
public:
    int operations = 0;
    HashList<K,T>(int newSize) {
        maxSize = newSize;
        size = 0;
        numChecks = 0;
        operations++;

        for (int i = 0; i < maxSize; i++){
            hl.push_back(new HashItem_ptr<K,T>());
            operations++;
        }
    }

    int hashCode(K key) {
        operations++;
        return HashTable<K,T>::hashCode(key);
    }

    void addItem(K key, T data) {
        operations++;

        string hashKey = to_string(key);
        int index = hash(hashKey);

        if (hl[index]->data->top == NULL)
            size++;
        operations++;
        hl[index]->data->insert(data, true);
        hl[index]->key = key;
    }

    string removeItem(int key) {
        operations++;
        string hashKey = to_string(key);
        int index = hash(hashKey);

        while (hl[index]->data->top != NULL)
        {
            operations++;
            if (hl[index]->key == key)
            {
                operations++;
                HashItem_ptr<K, T>* tempHash = hl[index];
                hl[index]->data->~List();
                hl[index]->data = new List<T>();
                size--;
                delete(tempHash);
                hl[index]->key =0;
            }
            index++;
            index %= maxSize;

        }

        return "";
    }

    string findItem(int key, int val=0) {
        operations++;
        string hashKey = to_string(key);
        int index = hash(hashKey);

        while (hl[index]->data->top != NULL)
        {
            operations++;
            int counter = 0;
            if (counter++ > maxSize) //to avoid infinite loop
                return "";
            if (hl[index]->key == key){
                operations++;
                if(hl[index]->data->inList(val)){
                    return "Exists";
                }
                else if(val ==0)
                    return "Key exists with possible multiple values";
            }
            index++;
            index %= maxSize;
        }
        return "";
    }

    int getSize() {
        operations++;
        return HashTable<K,List<T> >::getSize();
    }

    void printOut() {
        operations++;
        for (int i = 0; i < maxSize; i++) {
            operations++;
            if (hl[i] != NULL){
                operations++;
                cout << "K: " << hl[i]->key
                << " V: " << endl;
                hl[i]->data->display();
            }
        }
    }

};
#endif
