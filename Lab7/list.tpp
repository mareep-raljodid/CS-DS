#include "list.h"
#include <stddef.h>
#include <iostream>

using namespace std;

template <class T>
List<T>::List(){}

template <class T>
void List<T>::makeEmpty(){
    for(int i = 0; i < 10; i++){
        data[i] = NULL;
    }
}

template <class T>
void List<T>::addItem(T t){
    if(!isFull()){
        for(int i = 0; i < 10; i++){
        if(data[i] == NULL){
            data[i] = &t;
            moveCount++;
            break;
            }
        }  
    }
    else{
        throw ListIsFull();
    }
}

template <class T>
void List<T>::removeItem(int pos){
    pos -= 1;
    if ((pos < 10) && (pos > -1) && (data[pos] != NULL)){
        comparisonCount++;
        data[pos] = NULL;
        if(pos != 9)
            for(int i = pos; i < 10; i++){
                data[i] = data[i+1];
                moveCount++;
                if (i == (10-pos+1))
                    data[i] = NULL;
            }
    }
    
    else
        throw ItemDoesntExist();
}


template <class T>
bool List<T>::isFull(){
    for(int i = 0; i < 10; i ++){
        if(data[i] == NULL){
            return false;
        }
    }
    return true;
}

template <class T>
bool List<T>::isEmpty(){
    for(int i = 0; i < 10; i++){
        if(data[i] != NULL){
            return false;
        }
    }
    return true;
}

template <class T>
void List<T>::showFinalCounts(){
    cout << "COUNTS FOR 1ST CLASS VERSION:" << endl;
    cout << "Final move count: " << moveCount << endl;
    cout << "Final comparison count: " << comparisonCount << endl;
    cout << "___________________________________________"  << endl;
}
