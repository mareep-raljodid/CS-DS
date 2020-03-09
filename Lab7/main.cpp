#include "list.h"
#include "middleOut.h"

#include <stdlib.h>
#include <ctime>  
#include <iostream>

using namespace std;
using std::cin;
int *x; //random number x to be added

void add(List<int*> l){     //generates random x and calls addItem method
    x = new int;
    *x = rand () % 10 + 1;
    l.addItem(x);
}

void remove(List<int*> l){  //calls removeItem method
    int choice;
    cout << "Enter the position you would like to remove from: "; 
    cin >> choice;
    l.removeItem(choice);
}

int main(){
    srand(time(NULL));
    int choice;    //holds choice of position to remove from
    int selector;   //holds value to select whether add or remove is called
    List<int*> list1;
    ListMOut<int*> list2;
    ListInsertOrdered<int*> list3;
    
    unsigned int addCount = 0;    //counts number of times add is called
    unsigned int removeCount = 0;    //counts number of times remove is called

    int* item1;
    int* item2;
    int* item3;

    int position;
    int pos2;
    
    for(int i=0; i < 5; i++){
        while(addCount < 30 && removeCount < 20){
            selector = rand () % 2;
            switch (selector){
                case 0:
                    try{
                        item1 = new int;
                        cout << "What value would you like to add: ";
                        cin >> *item1;
                        list1.addItem(item1);
                        addCount++;
                    }
                    catch(List<int*>::ListIsFull){
                        cout << "Cannot add item. List is full." << endl;
                    }
                    break;
                
                case 1:
                    try{
                        cout << "What position in the array would you like to remove from? ";
                        cin >> position;
                        list1.removeItem(position);
                        removeCount++;
                    }
                    catch(List<int*>::ItemDoesntExist){
                        cout << "Cannot remove item. Item does not exist." << endl;
                    }
                    break;
                }
        }
    }

    for(int i=0; i < 5; i++){
        try{
            item2 = new int;
            cout << "What value would you like to add: ";
            cin >> *item2;
            list2.addItem(item2);
            addCount++;
        }
        catch(ListMOut<int*>::ListIsFull){
            cout << "Cannot add item. List is full." << endl;
        }
    }

    for(int i=0; i < 5; i++){
        while(addCount < 30 && removeCount < 20){
            selector = rand () % 2;
            switch (selector){
                case 0:
                    try{
                        item3 = new int;
                        cout << "What value would you like to add: ";
                        cin >> *item3;

                        cout << "What position would you like to add to? "; 
                        cin >> pos2;
                        list3.addItem(item3, pos2);
                        addCount++;
                    }
                    catch(ListInsertOrdered<int*>::ListIsFull){
                        cout << "Cannot add item. List is full." << endl;
                    }
                    break;
                
                case 1:
                    try{
                        cout << "What position in the array would you like to remove from? ";
                        cin >> position;
                        list3.removeItem(position);
                        removeCount++;
                    }
                    catch(ListInsertOrdered<int*>::ItemDoesntExist){
                        cout << "Cannot remove item. Item does not exist." << endl;
                    }
                    break;
                }
        }
    }
    
    // cout << "Add operation total: " << addCount << endl;
    // cout << "Remove operation total: " << removeCount << endl;

    list1.showFinalCounts();
    list2.showFinalCounts();
    list3.showFinalCounts();
    
    return 0;
}
