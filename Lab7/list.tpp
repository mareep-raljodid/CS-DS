#include "list.h"

using namespace std;

template <class T>
List<T>::List(){}

template <class T>
void List<T>::makeEmpty(){
    while(temp != null){
        node *temp = head;
        temp = temp->next;
        delete head;
        head = temp;
    }
}

template <class T>
void List<T>::addItem(T t){
    node *newNode = new node(t);
    if(head == null){
        head = newNode;
        return;
    }
    if(newNode->value < head->value){
        newNode->next = head;
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next != null && temp->next->value < newNode->value){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}