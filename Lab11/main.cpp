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
    char selection = 'y';
    
    dirGraph.addEdge(1,3);
    dirGraph.addEdge(1,5);
    print(n,dirGraph);
    dirGraph.dfs(3) ? cout << "yes" : cout << "no";
/*
top:
    while(selection == 'y'){
      cout << "Here are your options:" << endl;
      cout << "Press 1 to add an edge to graph." << endl;
      cout << "Press 2 remove an edge from graph." << endl; 
      cout << "Press 3 Find an edge in the graph." << endl;
      cout << "Press 4 Find the out edges of a vertices" << endl;
      cout << "Press 5 Find the in edges of a vertices" << endl;
      cout << "Press 6 to quit." << endl;

      cout << "Your choice: ";
      int ch;
      cin>>ch;
      int a,b;
      bool isEdge;
      switch(ch) {
        case 1:
            cout << "Enter the first edge parameter : ";
            cin >> a;
            cout << "Enter the second edge parameter : ";
            cin >> b;
            dirGraph.addEdge(a,b);
            cout << "\nAdded! " << endl;
            break;

        case 2:
            cout << "Enter the first edge parameter : ";
            cin >> a;
            cout << "Enter the second edge parameter : ";
            cin >> b;
            dirGraph.removeEdge(a,b);
            cout << "\nRemoved! " << endl;
            break;

        case 3:
            cout << "Enter the first edge parameter : ";
            cin >> a;
            cout << "Enter the second edge parameter : ";
            cin >> b;
            if(dirGraph.isEdge(a,b)){
              cout << "Edge exists!"  << endl;
            }
            else{
              cout << "Edge does not exist" << endl;
            }
            break;

        case 4:
            cout << "Enter the first edge parameter : ";
            
            cin >> a;
            dirGraph.outEdges(a);

            cout << "Success!" << endl;
            break;

        case 5:
            cout << "Enter the first edge parameter : ";
            
            cin >> a;

            dirGraph.inEdges(a);

            cout << "Success!" << endl;
            break;

        case 6:
              cout << "Exiting!";
              exit(0);

        default:
              cout << "Wrong choice, try again!" << endl;
              goto top;
      }
      cout << "Would you like to make another selection? Enter y for yes and n for no: ";
      cin >> selection;
    }*/
}
