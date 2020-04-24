#ifndef DIRGRAPH
#define DIRGRAPH
#include <iostream>
#include <vector>
#include <algorithm>
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
            for (unsigned i = 0; i < outEd.size(); i++) {
                cout << outEd[i] << " ";
            }

            cout << endl;
            
            return outEd;
        }

        vector<int> inEdges(int i) {
            vector<int> inEd;
            node* curr = graph[i];

            while (curr != NULL && curr->value) {
                inEd.push_back(curr->value);
                curr = curr->next;
            }

            for (unsigned k = 0; k < inEd.size(); k++) {
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
        vector<int> v;
        void dfs_d(int search, bool visited[]) {
            visited[search]  = true;
            v.push_back(search);
            if(graph[search] == NULL) return;
            
            node* temp = graph[search];
            temp = temp->next;
            for (; temp != NULL; temp = temp->next){
                if (!visited[temp->value]) 
                    dfs_d(temp->value, visited);
            }
            return;
        }

        bool dfs(int search) {

            cout << "                                  ## NOTE ## " << endl;
            cout << " 0 in nodes may mean either extra spots (unfilled), or undeclared edges" << endl;
            cout << " If it is the latter, please add the edge with root ad the missing node" << endl;
            cout << " #########                                                    #########\n\n" << endl;
            cout << "Printing Dept-First Traversal" << "(with begining node " << search << "): " << endl;
            cout << "<HEAD>(" << search << ") ";
            if (graph[search] == NULL) {
                cout << "<Connection to other NODES Doesn't Exists>" << endl;
                return false;
            }
            bool *visited = new bool[numVertices];
            for (int i = 0; i < numVertices+1; i++)
                visited[i] = false;
            bool rr = false;
            dfs_d(search, visited);
            for(int i = 0; i < numVertices; i++){
                cout << "-> " << v[i] << " ";
                if(v[i] == search)
                    rr = true;
            }
            return rr;
        }

        ~DirectedGraph() {
		for (int i = 0; i < numVertices; i++)
			delete[] graph[i];
		delete[] graph;
	    }   

};
#endif
