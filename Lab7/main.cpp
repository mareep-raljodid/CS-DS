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

    unsigned int addCount2 = 0;
    unsigned int removeCount2 = 0;

    int* item1;
    int* item2;
    int* item3;

    int position;
    int pos2;
    
    for(int i=0; i < 100; i++){
        while(addCount < 30 && removeCount < 20){
            selector = rand () % 2;
            switch (selector){
                case 0:
                    try{
                        item1 = new int;
                        *item1 = rand() % 100;
                        list1.addItem(item1);
                        addCount++;
                    }
                    catch(List<int*>::ListIsFull){
                        cout << "Cannot add item. List is full." << endl;
                    }
                    break;
                
                case 1:
                    try{
                        position = rand() % 10 + 1;
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

    for(int i=0; i < 100; i++){
        for(int j = 0; j < 30; j++){
            try{
                item2 = new int;
                *item2 = rand() % 100;
                list2.addItem(item2);
                addCount++;
            }
            catch(ListMOut<int*>::ListIsFull){
                cout << "Cannot add item. List is full." << endl;
            }
        }
    }

    for(int i=0; i < 100; i++){
        while(addCount2 < 30 && removeCount2 < 20){
            selector = rand () % 2;
            switch (selector){
                case 0:
                    try{
                        item3 = new int;
                        *item3 = rand() % 100;

                        pos2 = rand() % 10 + 1;

                        list3.addItem(item3, pos2);
                        addCount2++;
                    }
                    catch(ListInsertOrdered<int*>::ListIsFull){
                        cout << "Cannot add item. List is full." << endl;
                    }
                    break;
                
                case 1:
                    try{
                        position = rand() % 10 + 1;
                        list3.removeItem(position);
                        removeCount2++;
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

    cout << "___________________________________________"  << endl;

    list1.showFinalCounts();
    list2.showFinalCounts();
    list3.showFinalThirdCounts();
    
    return 0;
}
