#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

int main(){
    BinaryTree<int> t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.getAllAscending();
    t.getAllDescending();
    t.remove(5);
    t.remove(6);
    t.remove(7);
    t.getAllAscending();
    t.getAllDescending();
    t.emptyTree();
}
