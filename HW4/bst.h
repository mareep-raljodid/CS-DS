#include<iostream>
#include <vector>
#ifndef BINARYTREE
#define BINARYTREE
using namespace std;

 class BinaryTree{
    public:
        int operations = 0;
        void resetOp() { operations = 0; }
        struct Node{
            public:
                int data;
                int height;
                Node * left;
                Node * right;
                Node(int k){
                    height = 1;
                    data = k;
                    left = NULL;
                    right = NULL;
                }
        };

        Node* root = NULL;
        vector<int> ascendingOrder;
        vector<int> descendingOrder;

        void insert(int x){
            root=insertNode(root, x);
        }
        void remove(int x){
            root=removeNode(root, x);
            ascendingOrder.clear();
            descendingOrder.clear();
        }
        Node * search(int x){
            return findNode(root,x);
        }
        void getAllAscending(){
            ascending(root);
            for(int i = 0; i < ascendingOrder.size(); i++){
                cout << ascendingOrder.at(i) << " ";
            }
            cout << endl;
        }

        int getAllAscendingTEST(){
            ascending(root);
            int x=0;
            for(int i = 0; i < ascendingOrder.size(); i++){
                x = x+ascendingOrder.at(i);
                x = x*10;
            }
            return x;
        }

        int getAllDescendingTEST(){
            descending(root);
            int x =0;
            for(int i = 0; i < descendingOrder.size(); i++){
                x = x+descendingOrder.at(i);
                x = x*10;
            }
            return x;
        }

        void getAllDescending(){
            descending(root);
            for(int i = 0; i < descendingOrder.size(); i++){
                cout << descendingOrder.at(i) << " ";
            }
            cout << endl;
        }

        void emptyTree(){
            cout << "EMPTYING TREE" << endl;
            deleteAllItems(root);
        }

        // ~BinaryTree(){ emptyTree(); };
    private:
        int height(Node* head){
            if(head==NULL) return 0;
            return head->height;
        }
        Node* rotateRight(Node* head){
            operations++;
            Node* headNode = head->left;
            head->left = headNode->right;
            headNode->right = head;
            head->height = 1+max(height(head->left), height(head->right));
            headNode->height = 1+max(height(headNode->left), height(headNode->right));
            return headNode;
        }

        Node* rotateLeft(Node* head){
            operations++;
            Node* headNode = head->right;
            head->right = headNode->left;
            headNode->left = head;
            head->height = 1+max(height(head->left), height(head->right));
            headNode->height = 1+max(height(headNode->left), height(headNode->right));
            return headNode;
        }

        void ascending(Node* head){
            operations++;
            if(head==NULL) return ;
            ascending(head->left);
            ascendingOrder.push_back(head->data);
            ascending(head->right);
            
        }

        void descending(Node* head){
            operations++;
            if(head==NULL) return ;
            descending(head->right);
            descendingOrder.push_back(head->data);
            descending(head->left);
            
        }

        Node* insertNode(Node* head, int num){
            if(head==NULL){
                operations++;
                Node * temp = new Node(num);
                return temp;
            }
            operations++;
            if(num < head->data) head->left = insertNode(head->left, num);
            else if(num > head->data) head->right = insertNode(head->right, num);
            head->height = 1 + max(height(head->left), height(head->right));
            int balance = height(head->left) - height(head->right);
            operations++;
            if(balance>1){
                if(num < head->left->data){
                    operations++;
                    return rotateRight(head);
                }else{
                    head->left = rotateLeft(head->left);
                    operations++;
                    return rotateRight(head);
                }
            }else if(balance<-1){
                if(num > head->right->data){
                    operations++;
                    return rotateLeft(head);
                }else{
                    operations++;
                    head->right = rotateRight(head->right);
                    return rotateLeft(head);
                }
            }
            return head;
        }
        Node* removeNode(Node* head, int num){
            operations++;
            if(head==NULL) return NULL;
            if(num < head->data){
                head->left = removeNode(head->left, num);
            }else if(num > head->data){
                head->right = removeNode(head->right, num);
            }else{
                Node * r = head->right;
                if(head->right==NULL){
                    Node * l = head->left;
                    delete(head);
                    head = l;
                }else if(head->left==NULL){
                    delete(head);
                    head = r;
                }else{
                    while(r->left!=NULL) r = r->left;
                    head->data = r->data;
                    head->right = removeNode(head->right, r->data);
                }
            }
            operations++;
            if(head==NULL) return head;
            head->height = 1 + max(height(head->left), height(head->right));
            int balance = height(head->left) - height(head->right);
            operations++;
            if(balance>1){
                if(num > head->left->data){
                    operations++;
                    return rotateRight(head);
                }else{
                    operations++;
                    head->left = rotateLeft(head->left);
                    return rotateRight(head);
                }
            }else if(balance < -1){
                if(num < head->right->data){
                    operations++;
                    return rotateLeft(head);
                }else{
                    operations++;
                    head->right = rotateRight(head->right);
                    return rotateLeft(head);
                }
            }
            return head;
        }
        Node* findNode(Node* head, int num){
            operations++;
            if(head == NULL) return NULL;
            operations++;
            int key = head->data;
            if(key == num) return head;
            operations++;
            if(key > num) return findNode(head->left, num);
            operations++;
            if(key < num) return findNode(head->right, num);
        }

        void deleteAllItems(Node* head){
            operations++;
            if(head == NULL) return;
            operations++;
            deleteAllItems(head->left);
            operations++;
            deleteAllItems(head->right);
            operations++;
            delete(head);
        }
};
#endif
