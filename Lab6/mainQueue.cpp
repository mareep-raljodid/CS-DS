/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include <iostream>
#include "queue.h"
#include "stack.h"
#include "parse.h"
using namespace std;

void stackf(){

            cout << "Making a stack" << endl;
            int arrSize;
            cout << "Enter the size of the array: ";
            cin >> arrSize;
            Stack<int*> stack(arrSize);

            int* numPtr;
            int* outPtr;
            int* num;

            int choice = 1;

            while (choice != 4) {
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "Enter your action for the stack: " << endl;
                cout << "1: Push a pointer to the stack" << endl;
                cout << "2: Pop a pointer from the stack" << endl;
                cout << "3: See size of stack" << endl;
                cout << "4: Exit" << endl;

                cin >> choice;

                switch (choice) {
                case 1:
                    try {
                        cout << "What pointer would you like to add?" << endl;
                        num = new int;
                        cin >> *num;
                        cout << "Pushing the num pointer to stack" << endl;
                        stack.push(num);
                        cout << "Push successful" << endl;

                    }
                    catch (Stack<int*>::StackOverlfow) {
                        cout << "Error: Stack Overflow." << endl;
                    }
                    break;

                case 2:
                    try {
                        cout << "Popping a pointer off the stack" << endl;
                        outPtr = stack.pop();
                        cout << "Pop successful" << endl;
                        cout << "Result of pop: " << *outPtr;
                    }
                    catch (Stack<int*>::StackUnderflow) {
                        cout << "Stack Underflow" << endl;
                    }
                    break;

                case 3:
                    cout << "Length: " << stack.length();
                    break;
                case 4:
                    cout << "Exit";
                    break;

                }
            }

        }

void queuef(){
            cout << "Making a Queue" << endl;
            int queueSize;
            cout << "Enter size of Queue:" << endl;
            cin >> queueSize;
            Queue<int> queue(queueSize);
            cout << endl;
            cout << endl;
            cout << endl;
            int choice, num;

            while (choice != 4){
                cout << "Enter your action for the queue: " << endl;
                cout << "1: enqueue" << endl;
                cout << "2: dequeue" << endl;
                cout << "3: Peek" << endl;
                cout << "4: Exit" << endl;

                cin >> choice;

                switch (choice) {
                    case 1:
                        try{
                            cout << "What number would you like to enqueu" << endl;
                            cin >> num;
                            queue.Enqueue(num);

                            cout << "Number in queue" << endl;
                        }
                        catch(Queue<int>::Overflow){
                            cout << "Error: Overflow"  << endl;
                        }
                        break;

                    case 2:
                        try {
                            cout << "Dequeue in process" << endl;
                            queue.Dequeue();
                            cout << "dequeue successful" << endl;
                        }
                        catch (Queue<int>::Underflow) {
                            cout << "Error: Underflow." << endl;
                        }
                        break;
                    case 3:

                        cout << "Result of peek: " <<  queue.peek() << endl;
                        break;
                        
                    case 4:
                        cout << "Exit!" << endl;
                        break;
                }
            }
            
        
        }

void prse(){
            cout << "Would you like to parse a file to demonstrate the";
            cout << " stack and queue usage? (y/n)" << endl;
            char yy;
            cout << "Your choice: ";
            cin >> yy;
            string fl;

            if ((yy == 'y') || (yy == 'Y')) {
                cout << "Enter filename: ";
                cin >> fl;
                vector<string> wordArr;
                ifstream daFile(fl);

                string delim;
                while (daFile >> delim) {
                    wordArr.push_back(delim);
                }

                daFile.close();
                parse(wordArr);
            }
            
        }

int main() {
    
    char option = '1';
    while (option != '4') {
        cout << "Stack or Queue?" << endl;
        cout << "1: Stack" << endl;
        cout << "2: Queue" << endl;
        cout << "3: Parse a file" << endl;
        cout << "4: Quit" << endl;

        cin >> option;

        if (option == '1'){
            stackf();
        }
            
        if (option == '2'){
            queuef();
        } 

        if (option == '3'){
            prse();
        } 

        else {
            exit(0);
        }
    }
    return 0;
}
