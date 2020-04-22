#ifndef DIRGRAPH
#define DIRGRAPH
#include <iostream>
using namespace  std;

struct node{
    int value;
    node* next;
};

class DirectedGraph{
    public:
        int numVertices;
        node** graph;
        DirectedGraph(int v){
            this->numVertices  = v;
            graph = new node*[v]();

            for(int i = 0; i < v; i++){
                graph[i] = NULL;
            }
        }

        node* getAdjListnode(int dest, node* head){
            node* newnode = new node;
            newnode->value = dest;
            newnode->next = head;
            return newnode;
	    }

        void addEdge(int root, int destination){
            node* newnode = getAdjListnode(destination, graph[root]);
            graph[root] = newnode;
        }

        void removeEdge(int root, int destination){
            node* temp;
            int i =0;
            temp = graph[root];
            while(temp != NULL){
                if ( (temp->value == destination) && (temp->next != NULL) ){
                    temp->value = temp->next->value;
                    temp->next = temp->next->next;
                    return;
                }
                else if ( (temp->next == NULL) && (temp->value == destination) && (i==0)){
                    delete(temp);
                    graph[root]= NULL;
                    return;
                }
                else if ( (temp->next == NULL) && (temp->value == destination) && (i!=0)){
                    node* t = temp;
                    delete(t);
                    temp = NULL;
                }
                else temp = temp->next;
                i++;
            }
        }

        bool isEdge(int root, int destination){
            node* temp;
            int i =0;
            temp = graph[root];
            while(temp != NULL){
                if ( (temp->value == destination) && (temp->next != NULL) ){
                    return false;
                }
                else if ( (temp->next == NULL) && (temp->value == destination) && (i==0)){
                    return true;
                }
                else if ( (temp->next == NULL) && (temp->value == destination) && (i!=0)){
                    return true;
                }
                else temp = temp->next;
                i++;
            }
        }

        void printList(node* ptr){
	        while (ptr != NULL){
                cout << " -> " << ptr->value << " ";
                ptr = ptr->next;
	        }
	        cout << endl;
        }

        ~DirectedGraph() {
		for (int i = 0; i < numVertices; i++)
			delete[] graph[i];
		delete[] graph;
	}   

};
#endif
