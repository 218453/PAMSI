#ifndef BranchAndBound_HH
#define BranchAndBound_HH

#include <iostream>
#include "Graph.hh"
#include "Path.hh"
#include "Vertex.hh"
#include "List.hh"
using namespace std;

class BranchAndBound
{
private:
	Vertex<int> startPoint;
	Vertex<int> endPoint;
	List<Path> listOfPaths;
	
public:
	void FindPath(Graph g, int startPos, int endPos)
	{
		Path path1, path2;
		path1.AddVertexToPath(g.V->GetReference(startPos), 0);
		path2.AddVertexToPath(g.V->GetReference(startPos), 0);
		listOfPaths.AddNext(path1);
		listOfPaths.AddNext(path2);
		for(int i = 0; i < g.IncidentEdges(startPos).Size(); i++)
		{
			Vertex<int> *oposite;
			if(g.IncidentEdges(startPos).GetReference(i)->LeftVertex->Position == startPos)
			{
				oposite = g.IncidentEdges(startPos).GetReference(i)->RightVertex;
			}
			else
			{
				oposite = g.IncidentEdges(startPos).GetReference(i)->LeftVertex;
			}
			
			listOfPaths.GetReference(i).AddVertexToPath(g.V->GetReference(oposite->Position),
					g.IncidentEdges(startPos).GetReference(i)->Weight);
		}
	}
	
	void Expand(Graph g, int vertexPos, Path currentPath)
	{
		
	}
	
	void ShowAllPaths()
	{
		for(int i = 0; i < listOfPaths.Size(); i++)
		{
			cout << "Path " << i << " length: " << listOfPaths.GetReference(i).GetTotalLength() << endl;
		}
	}
};


#endif
