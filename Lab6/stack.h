/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */
#ifndef STACK
#define STACK

#include <iostream>
template <class T>
class Stack {

public:
    int defaul;
    int top = 0;
    Stack<T>(int size);
    void push(T *inPtr);
    T* pop();
    T* Top();

    int length();
    void makeEmpty();
    bool isFull();
    bool isEmpty();

    class StackOverlfow{};
    class StackUnderflow{};
private:
    T *data[];
}; 

#include "stack.tpp"

#endif

