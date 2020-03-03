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
            cout << "Making a stack" << endl;
            int arrSize;
            cout << "Enter the size of the array: ";
            cin >> arrSize;
            Stack<int> stack(arrSize);

            int* numPtr;
            int* outPtr;
            int num;

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
                        cin >> num;
                        cout << "Pushing the num pointer to stack" << endl;
                        numPtr = &num;
                        stack.push(numPtr);
                        cout << "Push successful" << endl;

                    }
                    catch (Stack<int>::StackOverlfow) {
                        cout << "Error: Stack Overflow." << endl;
                    }
                    break;

                case 2:
                    try {
                        cout << "Popping a pointer off the stack" << endl;
                        outPtr = stack.pop();
                        cout << "Pop successful" << endl;
                        cout << *outPtr;
                    }
                    catch (Stack<int>::StackUnderflow) {
                        cout << "Stack Underflow" << endl;
                    }
                    break;

                case 3:
                    cout << stack.length();
                    break;
                case 4:
                    cout << "Exit";
                    break;

                }
            }

        }

        if (option == '2') {
            cout << "Making a Queue" << endl;
            int queueSize;
            cout << "Enter size of Queue:" << endl;
            cin >> queueSize;
            Queue<int> queue(queueSize);
            cout << endl;
            cout << endl;
            cout << endl;
            int choice, num;
            cout << "Enter your action for the queue: " << endl;
            cout << "1: enqueue" << endl;
            cout << "2: dequeue" << endl;
            cout << "3: Peek" << endl;
            cout << "4: Exit" << endl;

            cin >> choice;

            switch (choice) {
            case 1:
                cout << "What number would you like to enqueu" << endl;
                cin >> num;
                queue.Enqueue((int)(num));

                cout << "Number in queue" << endl;
                

            case 2:
                try {
                    cout << "Dequeue in process" << endl;
                    queue.Dequeue();
                    cout << "dequeue successful" << endl;
                }
                catch (Queue<int>::Underflow) {
                    cout << "Error: Underflow." << endl;
                }
                
                

            case 3:

                cout << queue.peek() << endl;
                

            case 4:
                cout << "Exit!" << endl;
            }
        
        }

        if (option == '3') {
            cout << "Would you like to parse a file to demonstrate the";
            cout << " stack and quque usage? (y/n)" << endl;
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
                while (daFile >> delim) wordArr.push_back(delim);
                parse(wordArr);

                daFile.close();
            }
            
        }

        else {
            cout << "Exit" << endl;
            exit(0);
        }
    }
    return 0;
}
