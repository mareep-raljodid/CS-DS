#include<iostream>
#include <vector>
#ifndef BINARYTREE
#define BINARYTREE
using namespace std;

template <typename T>
class BinaryTree{
    public:
        struct Node{
            public:
                T data;
                int height;
                Node * left;
                Node * right;
                Node(T k){
                    height = 1;
                    data = k;
                    left = NULL;
                    right = NULL;
                }
        };

        Node* root = NULL;
        vector<T> ascendingOrder;
        vector<T> descendingOrder;

        void insert(T x){
            root=insertNode(root, x);
        }
        void remove(T x){
            root=removeNode(root, x);
            ascendingOrder.clear();
            descendingOrder.clear();
        }
        Node * search(T x){
            return findNode(root,x);
        }
        void getAllAscending(){
            ascending(root);
            for(int i = 0; i < ascendingOrder.size(); i++){
                cout << ascendingOrder.at(i) << " ";
            }
            cout << endl;
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

        ~BinaryTree();
    private:
        int height(Node* head){
            if(head==NULL) return 0;
            return head->height;
        }
        Node* rotateRight(Node* head){
            Node* headNode = head->left;
            head->left = headNode->right;
            headNode->right = head;
            head->height = 1+max(height(head->left), height(head->right));
            headNode->height = 1+max(height(headNode->left), height(headNode->right));
            return headNode;
        }

        Node* rotateLeft(Node* head){
            Node* headNode = head->right;
            head->right = headNode->left;
            headNode->left = head;
            head->height = 1+max(height(head->left), height(head->right));
            headNode->height = 1+max(height(headNode->left), height(headNode->right));
            return headNode;
        }

        void ascending(Node* head){
            if(head==NULL) return ;
            ascending(head->left);
            ascendingOrder.push_back(head->data);
            ascending(head->right);
            
        }

        void descending(Node* head){
            if(head==NULL) return ;
            descending(head->right);
            descendingOrder.push_back(head->data);
            descending(head->left);
            
        }

        Node* insertNode(Node* head, T num){
            if(head==NULL){
                Node * temp = new Node(num);
                return temp;
            }
            if(num < head->data) head->left = insertNode(head->left, num);
            else if(num > head->data) head->right = insertNode(head->right, num);
            head->height = 1 + max(height(head->left), height(head->right));
            int balance = height(head->left) - height(head->right);
            if(balance>1){
                if(num < head->left->data){
                    return rotateRight(head);
                }else{
                    head->left = rotateLeft(head->left);
                    return rotateRight(head);
                }
            }else if(balance<-1){
                if(num > head->right->data){
                    return rotateLeft(head);
                }else{
                    head->right = rotateRight(head->right);
                    return rotateLeft(head);
                }
            }
            return head;
        }
        Node* removeNode(Node* head, T num){
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
            if(head==NULL) return head;
            head->height = 1 + max(height(head->left), height(head->right));
            int balance = height(head->left) - height(head->right);
            if(balance>1){
                if(num > head->left->data){
                    return rotateRight(head);
                }else{
                    head->left = rotateLeft(head->left);
                    return rotateRight(head);
                }
            }else if(balance < -1){
                if(num < head->right->data){
                    return rotateLeft(head);
                }else{
                    head->right = rotateRight(head->right);
                    return rotateLeft(head);
                }
            }
            return head;
        }
        Node* findNode(Node* head, T num){
            if(head == NULL) return NULL;
            T key = head->data;
            if(key == num) return head;
            if(key > num) return findNode(head->left, num);
            if(key < num) return findNode(head->right, num);
        }

        void deleteAllItems(Node* head){
            if(head == NULL) return;
            deleteAllItems(head->left);
            deleteAllItems(head->right);
            delete(head);
        }
};
#endif