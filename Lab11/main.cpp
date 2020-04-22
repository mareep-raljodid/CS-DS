#include "graph.h"
#include <iostream>

using namespace std;

void print(int n, DirectedGraph& dirGraph) {
    for (int i = 0; i < n; i++){
        if(dirGraph.graph[i] != NULL){
            cout << "[" << i << "]" << " <HEAD> ";
           dirGraph.printList(dirGraph.graph[i]);
        }
    }
}

int main(){
    cout << "Enter the number of vertices: ";
    int n; 
    cin>>n;
    DirectedGraph dirGraph(n);

top:
    cout << "Here are your options:" << endl;
    cout << "Press 1 to add an edge to graph." << endl;
    cout << "Press 2 remove an edge from graph." << endl; 
    cout << "Press 3 Find an edge in the graph." << endl;
    cout << "Press 4 Find the out edges of a vertices" << endl;
    cout << "Press 5 Find the in edges of a vertices" << endl;
    cout << "Press 6 to quit." << endl;

    cout << "Your choice: ";
    char ch;
    cin>>ch;
    int a,b;
    switch(ch) {

        case 1:
            cout << "Enter the edge parameter (2 integers): ";
            cin >> a >> b;
            dirGraph.addEdge(a,b);
            cout << "\nAdded! " << endl;
            break;

        case 2:
            cout << "Enter the edge parameter (2 integers): ";
            cin >> a >> b;
            dirGraph.removeEdge(a,b);
            cout << "\nRemoved! " << endl;
            break;

        case 3:
            cout << "Enter the edge parameter (2 integers): ";
            cin >> a >> b;
            dirGraph.addEdge(a,b);
            cout << "\nAdded! " << endl;
            break;

        case 4:
            cout << "Enter the edge parameter (2 integers): ";
            cin >> a >> b;
            dirGraph.addEdge(a,b);
            cout << "\nAdded! " << endl;
            break;

        case 5:
            cout << "Enter the edge parameter (2 integers): ";
            cin >> a >> b;
            dirGraph.addEdge(a,b);
            cout << "\nAdded! " << endl;
            break;

       case 6:
            cout << "Exitting!";
            exit(0);

       default:
            cout << "Wrong choice, try again!" << endl;
            goto top;

        
    }
}
