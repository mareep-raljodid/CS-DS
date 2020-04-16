#ifndef LISTI
#define LISTI
#include "hash.h"
#include "list.h"
#include <cstddef>
#include <utility>

template<typename K, typename T>
struct HashItem_ptr {
    public:
        T* data;
        K key;

        HashItem_ptr<K,T>(K key, List<T> data) {
            this->data = data;
            this->key = key;
        }

        HashItem_ptr<K,T>(){}
};

template <typename K, typename T>
class HashList : public HashItem_ptr<K, T>, HashTable<K, T>, List<T>{

private:
    HashItem_ptr<K, List<T>>** hl;
    int maxSize;
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
    HashList<K,T>(int newSize) {
        maxSize = newSize;
        size = 0;
        numChecks = 0;
        hl = new HashItem_ptr<K, List<T>> * [maxSize];

        for (int i = 0; i < maxSize; i++)
            hl[i]->data = new List<T>;
    }

    int hashCode(K key) {
        return HashTable<K,T>::hashCode(key);
    }

    void addItem(K key, T data) {
        
        HashItem_ptr<K, List<T>>* tempHash = new HashItem_ptr<K, List<T>>(key, data);

        string hashKey = to_string(key);
        int index = hash(hashKey);

        while (hl[index].seeAt(0) != NULL && hl[index].seeAt(0)->key != key) {
            index++;
            index %= maxSize;
            numChecks++;
        }

        if (hl[index].seeAt(0) == NULL)
            size++;
        hl[index].insert(tempHash, true);
    }

    string removeItem(int key) {
        string hashKey = to_string(key);
        int index = hash(hashKey);

        while (hl[index]->data.val != NULL)
        {
            if (hl[index]->key == key)
            {
                HashItem_ptr<K, List<T>>* tempHash = hl[index];
                hl[index].~List();
                hl[index]->data.val = NULL;
                size--;
                return toString(tempHash->data);
                delete(tempHash);
            }
            index++;
            index %= maxSize;

        }

        return "";
    }

    string findItem(int key, int val=0) {
        string hashKey = to_string(key);
        int index = hash(hashKey);

        while (hl[index]->data.val != NULL)
        {
            int counter = 0;
            if (counter++ > maxSize) //to avoid infinite loop
                return "";
            if (hl[index]->key == key){
                if(hl[index]->data.inList(val)){
                    cout << "Exists" << endl;
                    return "Exists";
                }
            }
            index++;
            index %= maxSize;
        }
        return "";
    }

    int getSize() {
        return HashTable<K,List<T>>::getSize();
    }

    void printOut() {
        for (int i = 0; i < maxSize; i++) {
            if (hl[i] != NULL){
                cout << "key = " << hl[i]->key
                << " data : " << endl;
                hl[i]->data.display();
            }
        }
    }

};
#endif
