#include "list.h"

using namespace std;

template <class T>
List<T>::List(){}

template <class T>
void List<T>::makeEmpty(){
    for(int i = 0; i < 25; i++){
        data[i] = NULL;
    }
}

template <class T>
void List<T>::addItem(T t){
    for(int i = 0; i < 25; i++){
        if(data[i] == NULL){
            data[i] = t;
        }
    }
}

template <class T>
void List<T>::removeItem(int pos){
    pos -= 1;
    data[pos] = NULL;
    if(pos != 24)
        for(int i = pos; i < 25; i++){
            data[i] = data[i+1];
            if (i == (25-pos+1))
                data[i] = NULL;
        }
}

template <class T>
bool List<T>::isFull(){
    for(int i = 0; i < 25; i ++){
        if(data[i] == NULL){
            return false;
        }
    }
    return true;
}

template <class T>
bool List<T>::isEmpty(){
    for(int i = 0; i < 25; i++){
        if(data[i] != NULL){
            return false;
        }
    }
    return true;
}