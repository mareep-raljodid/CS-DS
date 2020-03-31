#ifndef TREE
#define TREE
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;
template <typename T>
struct Node{
	T data;
    Node
 *left;
    Node
 *right;

	Node
(T data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// Class for tree
template <typename T>
class Tree {
public:
	
	void insert(T element){
		Node
	 *nn = new Node
	(element);
            if (root == null){
                root = nn;
                return;
            }
            Node
		 *curr = root;
            while(curr->left != null || curr->right = null){
                if(d < curr->data){
					curr = curr->left
                }
                else{
                    curr = curr->right
                }
        }
	}

	void storeBSTNode
s(Node
 *head, vector<Node
> &Node
s){ 
    // Base case 
    if (head==NULL) 
        return; 

    // Store Node
s in Inorder (which is sorted 
    // order for BST) 
    storeBSTNode
s(head->left, Node
s); 
    Node
s.push_back(head); 
    storeBSTNode
s(head->right, Node
s); 
} 

/ Recursive function to construct binary tree /
Node buildTreeUtil(vector<Node> &Nodes, int start, 
                   int end) 
{ 
    // base case 
    if (start > end) 
        return NULL; 

    / Get the middle element and make it root */
    int mid = (start + end)/2; 
    Node
 root = Node
s[mid]; 

    / Using index in Inorder traversal, construct 
       left and right subtress /
    root->left  = buildTreeUtil(Node
s, start, mid-1); 
    root->right = buildTreeUtil(Node
s, mid+1, end); 

    return root; 
} 

// This functions converts an unbalanced BST to 
// a balanced BST 
Node buildTree(Node* root) 
{ 
    // Store Node
s of given BST in sorted order 
    vector<Node
 *> Node
s; 
    storeBSTNode
s(root, Node
s); 

    // Constucts BST from Node
s[] 
    int n = Node
s.size(); 
    return buildTreeUtil(Node
s, 0, n-1); 
}

};
#endif
