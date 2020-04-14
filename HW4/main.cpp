#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "hashTable.h"
#include "bst.h"
#include "gtest/gtest.h"
#include "test.h"


using namespace std;

vector<int> randomNumbers() {
    vector<int> r;
    int i =0;
    while(i < 100){
        r.push_back(rand() % 100 + 1);
        i++;
    }
    return r;
}


int main(){ 

    testing::InitGoogleTest();
    cout << RUN_ALL_TESTS();

	HashTable *ht = new HashTable; 
	BinaryTree *tree = new BinaryTree;

    cout << "Generating 100 random numbers" << endl;

    vector<int> random = randomNumbers();


    for (int i =0; i <50; i++){
        ht->addItem(random[i]);
        tree->insert(random[i]);
    }
    cout << "\n\n\n";
    cout << "Added 50 items, showing stats ----------------------" << endl;
    cout << "Operations Time for Binary Tree: " << ht->operations << endl;
    cout << "Operations Time for Hash Map: " << tree->operations << endl;

    cout << "\n";
    cout << "Resetting Operations Counter" << endl;
    ht->resetOp();
    tree->resetOp();

    cout << "\n\n\n";
    cout << "Removing values whose %7 is 0 (a.k.a 7 multiples)" << endl;
    for (int i =0; i <50; i++) 
        if(random[i]%7 == 0) {
            ht->removeItem(random[i]);
            tree->remove(random[i]);
        }
    cout << "\n";
    cout << "Done, printing the stats ---------------------------" << endl;
    cout << "Operations Time for Binary Tree: " << ht->operations << endl;
    cout << "Operations Time for Hash Map: " << tree->operations << endl; 
    
    cout << "\n";
    cout << "Resetting Operations Counter" << endl;
    ht->resetOp();
    tree->resetOp();

    for (int i =0; i <50; i++){
          ht->addItem(random[i]);
          tree->insert(random[i]);
      }   
      
     cout << "\n\n\n";
     cout << "Added another 50 items, showing stats -------------" << endl;
     cout << "Operations Time for Binary Tree: " << ht->operations << endl;
     cout << "Operations Time for Hash Map: " << tree->operations << endl;
  
     cout << "\n";
     cout << "Resetting Operations Counter" << endl;
     ht->resetOp();
     tree->resetOp();
  
     cout << "\n\n\n";
     cout << "Removing values whose %9 is 0 (a.k.a 9 multiples)" << endl;
     for (int i =0; i <100; i++) 
         if(random[i]%9 == 0) {
             ht->removeItem(random[i]);
             tree->remove(random[i]);
         }   
     cout << "\n";
     cout << "Done, printing the stats --------------------------" << endl;
     cout << "Operations Time for Binary Tree: " << ht->operations << endl;
     cout << "Operations Time for Hash Map: " << tree->operations << endl;

	return 0; 
} 
