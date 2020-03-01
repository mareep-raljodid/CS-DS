#include <iostream>
#include <fstream>

#include "parse.h"
#include "stack.h"
using namespace std;

int main() {

    //vector<string> wordArr;
    //ifstream daFile("a.txt");
    
    //string delim;
    //while (daFile >> delim) wordArr.push_back(delim);
    //parse(wordArr);

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

    

   
        
    return 0;
}
