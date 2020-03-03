#include "stack.h"

using namespace std;
template <class T>
Stack<T>::Stack(int s) {
    arr = new T[s];
    defaul = s;
}

template <class T>
void Stack<T>::push(T t) {
    if (!isFull()) {
        arr[++top] = t;
    }
    else {
        throw StackOverlfow();
    }
}

template <class T>
T Stack<T>::pop() {
    if (!isEmpty()) {
        return arr[top--];
    }
    else {
        throw StackUnderflow();
    }
}

template <class T>
T Stack<T>::Top() {
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        throw StackUnderflow();
    }
}

template <class T>
int Stack<T>::length() {
    return top + 1;
}

template <class T>
void Stack<T>::makeEmpty() {
    for (int i = 0; i < top; i++) {
        delete data[i];
        top = 0;
    }
}

template <class T>
bool Stack<T>::isFull() {
    return top == defaul;
}

template <class T>
bool Stack<T>::isEmpty() {
    return top == 0;
}
