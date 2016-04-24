#ifndef IGraph_HH
#define IGraph_HH

#include "Graph.hh"
#include "List.hh"

class IGraph
{
public:
	virtual void AddVertex(int x) = 0;
	virtual void AddEdge(int x, int y, int w) = 0;
	virtual void RemoveVertex(int x) = 0;
	virtual void RemoveEdge(int x, int y) = 0;
	//virtual List<Vertex> GetNeighbors(int x) = 0;
};


#endif