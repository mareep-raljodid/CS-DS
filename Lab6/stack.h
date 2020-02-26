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
class Stack{
private:
    T *data[10];
public:
    int defaul = 10;
    int top = 0;
    Stack<T>(int size);
    void push(T *inPtr);
    T *pop();
    void Top();
    int length();
    void makeEmpty();
    bool isFull();
    bool isEmpty();
    class StackOverlfow{};
    class StackUnderflow{};
}; 
#endif