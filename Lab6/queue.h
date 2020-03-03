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
    T data[10];
public:
    int defaul = 10;
    int back = 0;
    Queue<T>(int size);
    void Enqueue(int inVal);
    int Dequeue();
    T peek();
    int length();
    bool isEmpty();
    bool isFull();
    void makeEmpty();
    class Overflow {};
    class Underflow {};
};

#include "queue.tpp"

#endif
#pragma once
    