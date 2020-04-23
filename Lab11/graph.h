#ifndef DIRGRAPH
#define DIRGRAPH
#include <iostream>
#include <vector>
using namespace std;

struct node{
    int value;
    node* next;
};

class DirectedGraph{
    public:
        int numVertices;
        bool exists;
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
            temp = graph[root];
            exists = false;
            while(temp != NULL){
                if (temp->value == destination){
                    exists = true;
                }
                else if(temp->value == destination && temp->next == NULL)
                    exists = true;
                temp = temp->next;
            }
            return exists;
        }

        vector<int> outEdges(int x) {
            vector<int> outEd;

            node* ptr = graph[x];

            while (ptr != NULL) {
                outEd.push_back(ptr->value);
                ptr = ptr->next;
            }
            reverse(outEd.begin(), outEd.end());
            for (int i = 0; i < outEd.size(); i++) {
                cout << outEd[i] << " ";
            }

            cout << endl;
            
            return outEd;
        }

        vector<int> inEdges(int i) {
            vector<int> inEd;
            int j = 1;
            node* curr = graph[i];

            while (curr != NULL && curr->value) {
                inEd.push_back(curr->value);
                curr = curr->next;
            }

            for (int k = 0; k < inEd.size(); k++) {
                cout << inEd[k] << " ";
            }
            cout << endl;
            return inEd;
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
