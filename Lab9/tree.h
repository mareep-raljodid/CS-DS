#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Class for tree
class Node {
public:
	int data;
	Node* left, * right;

	
	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};



#pragma once
