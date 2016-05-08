#ifndef IGraph_HH
#define IGraph_HH

#include "Graph.hh"
#include "List.hh"
#include "Vertex.hh"

class IGraph
{
public:
	virtual void AddVertex(int x) = 0;
	virtual bool AddEdge(int x, int y, int w) = 0;
	virtual void RemoveVertex(int x) = 0;
	virtual void RemoveEdge(int x, int y) = 0;
	virtual List<Vertex<int> > GetNeighbors(int x) = 0;
};


#endif