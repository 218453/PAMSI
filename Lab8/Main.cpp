#include <iostream>

#include "Graph.hh"

using namespace std;

int main()
{
	Graph *g = new Graph(10);
	
	cout << "GRAPH" << endl;
	
	g->AddVertex(0);
	g->AddVertex(1);
	g->AddVertex(2);
	
	g->AddEdge(0,1,1);
	g->AddEdge(1,2,1);
	
	g->AllVertices();
	cout << endl;
	g->AllEdges();
	
}