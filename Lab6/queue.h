/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */
#ifndef QUEUE
#define QUEUE

#include <iostream>
template <class T>
class Queue {
private:
    T* data[10];
public:
    int defaul = 10;
    int back = 0;
    Queue<T>(int size);
    void Enqueue(int inVal);
    int Dequeue();
    int peek();
    int length();
    bool isEmpty();
    void makeEmpty();
    class Underflow {};
};

#endif
#pragma once
    