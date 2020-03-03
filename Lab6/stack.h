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
    int top = 0;
    T* arr;

public:
    int defaul;
    Stack<T*>(int size);
    void push(T);
    T pop();
    T Top();

    int length();
    void makeEmpty();
    bool isFull();
    bool isEmpty();

    class StackOverlfow {};
    class StackUnderflow {};
private:
    T* data[];
};
#include "stack.tpp"
#endif

#pragma once
