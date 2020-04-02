#ifndef TREE
#define TREE
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>


using namespace std;
template <typename T>
class Tree {
    
    struct Node{
        T data;
        Node *left;
        Node *right;
  
        Node () {
            this->data = NULL;
            this->right = NULL;
            this->left = NULL;
        }

        Node (T data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }   
    };

    Node *head = new Node();
    unsigned size = 0;

public:
	
	void insert(T element){
		Node *nn = new Node (element);
            if (head == NULL){
                head = nn;
                return;
            }
            Node *curr = head;
            while(curr->left != NULL || curr->right == NULL){
                if(element < curr->data){
		        curr = curr->left;
                size++;
                }
                else{
                    curr = curr->right;
                    size++;
                }
        }
	}

	void storeBSTNodes(Node *head, vector<Node> &Nodes){ 
    
    if (head==NULL) 
        return; 

    storeBSTNodes(head->left, Nodes); 
    Nodes.push_back(head); 
    storeBSTNodes(head->right, Nodes); 
} 

    Node buildTreeUtil(vector<Node> &Nodes, int start, int end) { 
    // base case 
        if (start > end) 
            return NULL; 

        int mid = (start + end)/2; 
        Node head = Nodes[mid]; 

        head->left  = buildTreeUtil(Nodes, start, mid-1); 
        head->right = buildTreeUtil(Nodes, mid+1, end); 

        return head; 
    } 

// This functions converts an unbalanced BST to 
// a balanced BST 
    Node buildTree() { 
   
        vector<Node *> Nodes; 
        storeBSTNodes(head, Nodes); 

        // Constucts BST from Nodes[] 
        int n = Nodes.size(); 
        return buildTreeUtil(Nodes, 0, n-1); 
    }

    Node* find(T key){
        if(head->data == key){
            return head;
        }
        Node *temp = head;

        //while not == key
        while((temp->left != NULL && key < temp->data) || (temp->right != NULL && key > temp->data)){
            if(key < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        if(temp->data == key){
            return temp;
        }else{
            throw ItemNotFound();
        }
    }

    void ItemNotFound(){
        cout << "Item not found";
    };

    int getSize(){       //calculate size of tree
        return size;
    }

    vector<T> getAllAscending(){
        vector<T> ascendingOrder;
        if(head == NULL){
            return;
        }
        Node *temp = head;
        
        getAllAscending(temp->left); 
        if(temp == NULL){
            return;
        } else{
            ascendingOrder.push_back(temp->data);
        }
        getAllAscending(temp->right); 
        
    }

    vector<Node> getAllDescending(){
        vector<Node> descendingOrder;
    }





};
#endif

int main(){
    Tree<int> binaryTree;
    binaryTree.insert(5);
    binaryTree.insert(8);
    binaryTree.insert(6);
    binaryTree.insert(4);
    binaryTree.insert(12);
    binaryTree.insert(1);

    binaryTree.buildTree();
    vector<int> a = binaryTree.getAllAscending();
    for(int i = 0; i < 5; i++){
        cout << a[i];
    }
}