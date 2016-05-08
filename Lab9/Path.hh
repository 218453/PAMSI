#ifndef Path_HH
#define Path_HH

#include "List.hh"
#include "Vertex.hh"

class Path
{
private:
	List<Vertex<int> > listOfVertices;
	int totalLength;
public:
	Path()
	{
		totalLength = 0;
	}
	int GetTotalLength()
	{
		return totalLength;
	}
	
	void AddVertexToPath(Vertex<int> v, int length)
	{
		listOfVertices.AddNext(v);
		totalLength += length;
	}
};


#endif
