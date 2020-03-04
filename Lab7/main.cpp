#include "list.h"
#include <stdlib.h>
#include <time.h>  
#include <iostream>

using namespace std;
int addCount;
int removeCount;
int *x;

void add(List<int*> l){
    x = new int;
    *x = rand () % 10 + 1;
    l.addItem(x);
    addCount++;
}

void remove(List<int*> l){
    int choice;
    cout << "Enter the position you would like to remove from: "; 
    cin >> choice;
    l.removeItem(choice);
}

int main(){
    srand(time(NULL));
    int choice;
    int selector;
    List<int*> list1;
    
    int addIter;
    int remIter;
    
    while(addIter < 30 && remIter < 20){
        selector  = rand() % 2;
        if(selector == 0){
            add(list1);
        }
        if(selector == 1){
            remove(list1);
        }
    }
    
    
    return 0;
}