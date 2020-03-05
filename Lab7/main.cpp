#include "list.h"
#include <stdlib.h>
#include <time.h>  
#include <iostream>

using namespace std;
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
    int choice;     //holds choice of position to remove from
    int selector;   //holds value to select whether add or remove is called
    List<int*> list1;
    
    int addCount;    //counts number of times add is called
    int removeCount;    //counts number of times remove is called
    
    for(int i=0; i < 100;i++){
        while(addCount < 30 && removeCount < 20){
        selector  = rand() % 2;
        if(selector == 0){
            try{
                add(list1);
                addCount++;
            }
            catch(List<int*>::ListIsFull){
                cout << "Cannot add item. List is full." << endl;
            }
        }
        if(selector == 1){
            try{
                remove(list1);
                removeCount++;
            }
            catch(List<int*>::ItemDoesntExist){
                cout << "Cannot remove item. Item does not exist." << endl;
            }
        }
    }
    }
    
    cout << "Add operation total: " << addCount << endl;
    cout << "Remove operation total: " << removeCount << endl;
    
    return 0;
}