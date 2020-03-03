/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */
#include "queue.h"

using namespace std;
template <class T>
Queue<T>::Queue(int s) {

    defaul = s;
}

template <class T>
void Queue<T>::Enqueue(T inVal) {
    if(isFull()){
        throw Overflow();
    }
    else{
        data[back] = inVal;
        back++;
    }
}


template <class T>
int Queue<T>::Dequeue() {
    if (isEmpty())throw Underflow();
    int retVal = data[0];
    back--;
    for (int i = 0; i < back; i++) {
        data[i] = data[i + 1];
    }
    return retVal;
}

template <class T>

T Queue<T>::peek() {
    return data[0];
}

template <class T>
int Queue<T>::length() {
    return back;
}

template <class T>

bool Queue<T>::isEmpty() {
    return back == 0;
}

template <class T>
bool Queue<T>::isFull(){
    return back == defaul;
}

template <class T>
void Queue<T>::makeEmpty() {
    back = 0;
}
template <class T>
T Queue<T>::viewItems(int iter){
    return data[iter];
}