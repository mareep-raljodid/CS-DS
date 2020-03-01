/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */
#include "stack.h"
 
using namespace std;
template <class T>
Stack<T>::Stack(int s){
    
    defaul = s;
}

template <class T>
void Stack<T>::push(T *inPtr){
    if(!isFull()){
        data[top] =  inPtr;
        top++;
    } 
    else{
        throw StackOverlfow();
    }
    
}

template <class T>
T *Stack<T>::pop(){
    if(!isEmpty()){
        return data[top--];
    }
    else{
        throw StackUnderflow();
    }
}

template <class T>
T *Stack<T>::Top(){
    if(!isEmpty()){
        return data[top];
    }   
    else{
        throw StackUnderflow();
    }   
}

template <class T>
int Stack<T>::length(){
    return top;
}

template <class T>
void Stack<T>::makeEmpty(){
    for(int i= 0;i < top; i++){
        delete data[i];
    top = 0;
    }
}

template <class T>
bool Stack<T>::isFull(){
    return top == defaul;
}

template <class T>
bool Stack<T>::isEmpty(){
    return top == 0;
}
