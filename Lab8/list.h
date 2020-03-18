#include <cstddef>
#include <utility>

template <typename T>
class List
{
    struct node {
        T value;
        node* prev;
        node* next;
    };

    node* head = NULL;
    node* cursor = head;
    unsigned length = 0;

    List() {}

    node* makeNode(T elem) {

        node* temp = new node;
        temp->value = elem;
        temp->prev = NULL;
        temp->next = NULL;
        return temp;
    }

    void insert(T elem, bool at_tail = true) {
        if (at_tail) {
            node* temp = makeNode(elem);
            if (head == NULL) {
                head = temp;
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
            node* temp = makeNode(elem);
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

    node* getItem(T elem) {

        node* temp = head;
        node* to_be_deleted = NULL;
        if (temp == NULL)
            return NULL;

        while (temp != NULL)
            if (temp->value == elem)
                to_be_deleted = temp;

        T val = to_be_deleted->value;

        if (to_be_deleted == NULL)
            return NULL;

        if (to_be_deleted == head)
            head = to_be_deleted->next;

        if (to_be_deleted->next != NULL)
            to_be_deleted->next->prev = to_be_deleted->prev;

        if (to_be_deleted->prev != NULL)
            to_be_deleted->prev->next = to_be_deleted->next;

        free(to_be_deleted);
        length--;
        return val;
    }

    bool inList(T elem) {
        node* temp = head;

        if (temp == NULL)
            return false;

        while (temp != NULL) {
            if (temp->value == elem)
                return true;
        }

        return false;
    }

    bool isEmpty() {
        return ((length == 0) && (head == NULL));
    }

    unsigned size() {
        return length;
    }

    T seeNext() {

        if (head == NULL) throw head;

        T val = cursor->value;
        cursor = cursor->next;
        return val;
    }

    T seePrev() {

        if (head == NULL) throw head;

        T val = cursor->value;
        cursor = cursor->prev;
        return val;
    }

    T seeAt(unsigned pos) {

        if (head == NULL) throw head;

        if (pos > length) throw pos;
        T val;
        for (int i = 0; i <= pos; i++) {
            val = cursor->value;
            cursor = cursor->next;
        }
        cursor = cursor->prev;
        return val;
    }

    void reset() {
        cursor = head;
    }

    ~List() {
        node* temp = head->next;
        head->data = temp->data;
        head->next = temp->next;
        free(temp);
        length = 0;
        cursor = NULL;
    }

    void display() {
        cout << "----------------" << endl;
        cout << "| SKU: " << SKU << endl;
        cout << "| Price: " << price << endl;
        cout << "| Quantity: " << quantity << endl;
        cout << "| Descriotion: " << desc << endl;
        cout << "----------------" << endl;
        cout << "      |   |  " << endl;
        cout << "      |   | " << endl;
        cout << "      \   /  " << endl;
        cout < "        \ / " << endl;

    }
};

template<typename T>
bool operator < (List<T> const& obj1, List<T> const& obj2) { return obj1->value < obj2->value; }
template<typename T>
bool operator > (List<T> const& obj1, List<T> const& obj2) { return obj1->value > obj2->value; }
template<typename T>
bool operator == (List<T> const& obj1, List<T> const& obj2) { return obj1->value == obj2->value; }
#pragma once
