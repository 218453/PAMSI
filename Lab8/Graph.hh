#ifndef Graph_HH
#define Graph_HH

#include <iostream>
#include "IGraph.hh"
#include "List.hh"
#include "Vertex.hh"
#include "Edge.hh"
#include <stddef.h>
using namespace std;

class Graph : IGraph
{
private:
	int size;
	Edge<int> *** adjacentMatrix;
public:
	List<Vertex<int> > *V;
	List<Edge<int> > *E;
	Graph(int newSize)
	{
		size = newSize;
		adjacentMatrix = new Edge<int> ** [size];
		for(int i = 0; i < size; i++)
		{
			adjacentMatrix[i] = new Edge<int>* [size];
		}
		
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				adjacentMatrix[i][j] = 0;
			}
		}
		
		V = new List<Vertex<int> >();
		E = new List<Edge<int> >();
			
	}
	~Graph()
	{
		for(int i = 0; i < size; i++)
		{
			//delete [] adjacentMatrix[i];
			for(int j = 0; j < size; j++)
			{
				delete adjacentMatrix[i][j];
			}
		}
	}
	virtual void AddVertex(int x)
	{
		V->Add(Vertex<int>(x,x));
	}
	
	virtual bool AddEdge(int x, int y, int w)
	{
		Edge<int> *e = new Edge<int>(E->Size(), &V->GetReference(x),&V->GetReference(y),w);
		if(adjacentMatrix[x][y] == NULL)
		{
			E->Add(*e);
			adjacentMatrix[x][y] = e;
			adjacentMatrix[y][x] = e;	
			return true;
		}
		else
		{
			delete e;
			return false;
		}
	}
	
	virtual void RemoveVertex(int x)
	{
		// NIE ROBIC
	}
	
	virtual void RemoveEdge(int x, int y)
	{
		// NIE ROBIC
	}
	
	virtual List<Vertex<int> > GetNeighbors(int x)
	{
		List<Vertex<int> > v;
		for(int i = 0; i < size; i++)
		{
			if(x != i && adjacentMatrix[x][i] != NULL)
			{
				v.Add(Vertex<int>(i,i));
			}
		}
		return v;
	}
	
	List<Edge<int>* > IncidentEdges(int x)
	{
		List<Edge<int>* > e;
		for(int i = 0; i < size; i++)
		{
			if(x != i && adjacentMatrix[x][i] != NULL)
			{
				e.Add(adjacentMatrix[x][i]);
			}
		}
		return e;
	}
	
	void AllVertices()
	{
		for(int i = 0; i < V->Size(); i++)
		{
			cout << "V" << V->GetReference(i).Position  << ", label:" << 
					LabelToString(V->GetReference(i).Label) << endl;
		}		
	}
	
	string LabelToString(LabelState label)
	{
		if(label == visited)
		{
			return "visited";
		}
		else if(label == notVisited)
		{
			return "notVisited";
		}
		else if(label == found)
		{
			return "found";
		}
		else if(label == returned)
		{
			return "returned";
		}
		else
		{
			return "";
		}
	}
	
	void AllEdges()
	{
		for(int i = 0; i < E->Size(); i++)
		{
			cout << "E(" << E->GetReference(i).LeftVertex->Position << 
					"," << E->GetReference(i).RightVertex->Position << ")" << 
					", label:" << LabelToString(E->GetReference(i).Label) << endl;
		}
	}
	
	void Neighbors(int x)
	{
		List<Vertex<int> > list = GetNeighbors(x);
		cout << "Neighbors of " << x << ":" << endl;
		for(int i = 0; i < list.Size(); i++)
		{
			cout << "V" << list.GetReference(i).Position << endl;
		}
	}
};


#endif