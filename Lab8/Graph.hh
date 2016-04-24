#ifndef Graph_HH
#define Graph_HH

#include "List.hh"
#include "IGraph.hh"

struct Vertex
{
public:
	int position;
	Vertex()
	{
		position = -1;
	}
	Vertex(int x)
	{
		position = x;
	}
};

struct Edge
{
public:
	int leftVertex;
	int rightVertex;
	int weight;
	Edge()
	{
		leftVertex = -1;
		rightVertex = -1;
		weight = 0;
	}
	Edge(int x, int y, int w)
	{
		leftVertex = x;
		rightVertex = y;
		weight = w;
	}
};

class Graph : IGraph
{
private:
	int size;
	int ** adjacentMatrix;
	List<Vertex> *V;
	List<Edge> *E;
public:
	Graph(int newSize)
	{
		size = newSize;
		adjacentMatrix = new int * [size];
		for(int i = 0; i < size; i++)
		{
			adjacentMatrix[i] = new int [size];
		}
		
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				adjacentMatrix[i][j] = 0;
			}
		}
		
		V = new List<Vertex>();
		E = new List<Edge>();
			
	}
	~Graph()
	{
		for(int i = 0; i < size; i++)
		{
			delete [] adjacentMatrix[i];
		}
	}
	virtual void AddVertex(int x)
	{
		V->Add(Vertex(x));
	}
	
	virtual void AddEdge(int x, int y, int w)
	{
		E->Add(Edge(x,y,w));
		adjacentMatrix[x][y] = 1*w;
	}
	
	virtual void RemoveVertex(int x)
	{
		// NIE ROBIC
	}
	
	virtual void RemoveEdge(int x, int y)
	{
		// NIE ROBIC
	}
	
	/*virtual List<Vertex> GetNeighbors(int x)
	{
		List<Vertex> v;
		for(int i = 0; i < size; i++)
		{
			if(x != i && adjacentMatrix[x][i] != 0)
			{
				v.Add(Vertex(i));
			}
		}
		return v;
	}*/
	
	void AllVertices()
	{
		for(int i = 0; i < V->Size(); i++)
		{
			cout << "V" << V->Get(i).position << endl;
		}
		
		/*for(int i = 0; i < size; i++)
		{
			if()
		}*/
		
		
	}
	
	void AllEdges()
	{
		for(int i = 0; i < E->Size(); i++)
		{
			cout << "E(" << E->Get(i).leftVertex << "," << E->Get(i).rightVertex << ")" << endl;
		}
	}
};


#endif