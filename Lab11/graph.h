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
                graph[i] == NULL;
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
            for(int i = 0; i<numVertices;  i++){
                
            }
        }

        void printList(node* ptr){
	        while (ptr != nullptr){
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