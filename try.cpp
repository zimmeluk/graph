#include <iostream>
#include "AdjMatrix.h"
#include "AdjList.h"

using namespace std;

int main() {
	
	AdjMatrix graph = AdjMatrix(5, false);
	graph.insert(Edge(1, 2));

	graph.print();

	graph.remove(Edge(1, 2));
	graph.add();

	graph.print();
    
    AdjList adjList = AdjList(5, false);
    
    adjList.insert(Edge(1, 2));
    
    adjList.print();

    adjList.remove(Edge(1, 2));
    
    adjList.print();

    adjList.insert(Edge(1, 2));
    
    adjList.print();

	return 0;
}
