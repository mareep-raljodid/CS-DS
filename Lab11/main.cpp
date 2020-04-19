#include "graph.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Enter the number of vertices: ";
    int n; 
    cin>>n;
    DirectedGraph dirGraph(n);
    dirGraph.addEdge(0, 1);
    dirGraph.addEdge(0, 4);
    dirGraph.addEdge(1, 2);
    dirGraph.addEdge(1, 3);
    dirGraph.addEdge(1, 4);
    dirGraph.addEdge(2, 3);
    dirGraph.addEdge(3, 4);


    for (int i = 0; i < n; i++){
		cout << i << " --";
		dirGraph.printList(dirGraph.graph[i]);
    }


    return 0;
}