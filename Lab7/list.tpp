#include "list.h"

using namespace std;

template <class T>
List<T>::List(){}

template <class T>
void List<T>::makeEmpty(){
}

template <class T>
void List<T>::addItem(T t){
    node *newNode = new node(t);
    if(head == null){
        head = newNode;
        return;
    }
}