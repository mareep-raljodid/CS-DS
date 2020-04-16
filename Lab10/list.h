#ifndef LIST
#define LIST

#include <cstddef>
#include <utility>
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    Node() {}  
    T value;
    Node* prev;
    Node* next;
};

template <typename T>
class List
{
public:

    List() {}

    Node<T>* top = NULL;
    Node<T>* head = NULL;
    Node<T>* cursor = head;
    unsigned length = 0;

    Node<T>* makeNode(T elem) {

        Node<T>* temp = new Node<T>;
        temp->value = elem;
        temp->prev = NULL;
        temp->next = NULL;
        return temp;
    }

    void insert(T elem, bool at_tail = true) {
        if (at_tail) {
            Node<T>* temp = makeNode(elem);
            if (head == NULL) {
                head = temp;
                top = head;
                return;
            }
            else {
                head->next = temp;
                temp->prev = head;
                head = temp;
            }
            length++;
        }

        else {
            Node<T>* temp = makeNode(elem);
            if (head == NULL) {
                head = temp;
                return;
            }
            else {
                head->prev = temp;
                temp->next = head;
                head = temp;
            }
            length++;
        }

    }

    T getItem(T elem) {

        Node<T>* temp = top;
        Node<T>* to_be_deleted = NULL;
        if (temp == NULL)
            return NULL;

        while (temp != NULL)
            if (temp->value == elem)
                to_be_deleted = temp;

        T val = to_be_deleted->value;

        if (to_be_deleted == NULL)
            return NULL;

        if (to_be_deleted == top)
            top = to_be_deleted->next;

        if (to_be_deleted->next != NULL)
            to_be_deleted->next->prev = to_be_deleted->prev;

        if (to_be_deleted->prev != NULL)
            to_be_deleted->prev->next = to_be_deleted->next;

        free(to_be_deleted);
        length--;
        return val;
    }

    bool inList(T elem) {
        Node<T>* temp = top;

        if (temp == NULL)
            return false;

        while (temp != NULL) {
            if (temp->value == elem)
                return true;
            else temp = temp->next;
        }

        return false;
    }

    bool isEmpty() {
        return ((length == 0) && (head == NULL));
    }

    unsigned size() {
        if(top == NULL)
            return -1;
        return length;
    }

    T seeNext() {

        if (top == NULL) throw "Empty List";

        T val = cursor->value;
        cursor = cursor->next;
        return val;
    }

    T seePrev() {

        if (head == NULL) throw "Empty List";

        T val = cursor->value;
        cursor = cursor->prev;
        return val;
    }

    T seeAt(unsigned pos) {

        if (top == NULL){
            return NULL;
        }

        if (pos > length) throw "Out of Range Error";
        T val;
        for (int i = 0; i <= pos; i++) {
            val = cursor->value;
            cursor = cursor->next;
        }
        cursor = cursor->prev;
        return val;
    }

    void display() {
        Node<T>* temp = top;

        if (temp == NULL) cout << "[]" <<endl;
       
        while (temp != NULL){
            cout <<" |-" << temp->value << endl;
            temp = temp->next;
        }
        cout << "__" << endl;

    }

    void reset() {
        cursor = top;
    }

    ~List(void) {
        
        Node<T>* temp = top;
        while( temp != NULL ) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
        length = 0;
        cursor = NULL;
        head = NULL;
        top = NULL;
    }

};

template<typename T>
bool operator < (List<T> const& obj1, List<T> const& obj2) { return *(obj1->value) < *(obj2->value); }
template<typename T>
bool operator > (List<T> const& obj1, List<T> const& obj2) { return *(obj1->value) > * (obj2->value); }
template<typename T>
bool operator == (List<T> const& obj1, List<T> const& obj2) { return *(obj1->value) == *(obj2->value); }


#endif
