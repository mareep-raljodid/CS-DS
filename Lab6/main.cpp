/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */
 
#include <iostream>
#include "stack.cpp"
using namespace std;
 
int main(){
    int arrSize;
    cout << "Enter the size of the array: ";
    cin >> arrSize;
    Stack<int> stack(arrSize);
    
    int *numPtr; 
    int *outPtr;  
    
    try{
        cout << "Pushing a pointer to the stack" << endl;
        stack.push(numPtr);
        cout << "Push successful" << endl;
    } catch(Stack<int>::StackOverlfow){
        cout << "Error: Stack Overflow." << endl;
    }
    try{
        cout << "Popping a pointer off the stack" << endl;
        outPtr = stack.pop();
        cout << "Pop successful" << endl;
        cout << outPtr;
    } catch(Stack<int>::StackUnderflow){
        cout << "Stack Underflow" << endl;
    }
    return 0;
}