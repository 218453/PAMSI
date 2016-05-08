#ifndef GraphTest_HH
#define GraphTest_HH

#include <iostream>
#include <cstdlib>
#include <string>
#include "Graph.hh"
#include "IRunnable.hh"
#include "Vertex.hh"

class GraphTest : IRunnable
{
private:
	Graph *g;
	int graphSize;
public:
	GraphTest()
	{
		g = NULL;
		srand(time(NULL));
	}
	virtual bool Prepare(int problemSize)
	{
		graphSize = problemSize;
		int edges = 3*graphSize;
		if(g != NULL)
		{
			//delete g;
		}
		g = new Graph(graphSize);
		
		for(int i = 0; i < graphSize; i++)
		{
			g->AddVertex(i);
		}
		
		int edgeCounter = 0;
		while(edgeCounter < edges)
		{
			for(int i = 0; i < graphSize; i++)
			{
				int random = rand() & (graphSize-1);
				if(g->AddEdge(i, random,1))
				{
				}
				edgeCounter++;
				if(edgeCounter >= edges)
				{
					break;
				}
			}			
		}
		return true;
	}
	
	virtual bool Run()
	{
		//DFS(g);
		BFS(g);
		return true;
	}
	
	void ShowAll()
	{
		cout << endl;
		g->AllVertices();
		cout << endl;
		g->AllEdges();
	}
	
	void ShowNeighbors()
	{
		for(int i = 0; i < graphSize; i++)
		{
			cout << endl;	
			g->Neighbors(i);
		}
	}
	
	int Vertices()
	{
		return g->V->Size();
	}
	
	int Edges()
	{
		return g->E->Size();
	}
	
	void DFS(Graph *g)
	{
		for(int i = 0; i < g->V->Size(); i++)
		{
			g->V->GetReference(i).Label = notVisited;
		}
		
		for(int i = 0; i < g->E->Size(); i++)
		{
			g->E->GetReference(i).Label = notVisited;
		}
		
		for(int i = 0; i < g->V->Size(); i++)
		{
			if(g->V->GetReference(i).Label == notVisited)
			{
				DFS(g, &g->V->GetReference(i));
			}
		}
	}
	
	void DFS(Graph *g, Vertex<int> *v)
	{
		v->Label = visited;
		for(int i = 0; i < g->IncidentEdges(v->Position).Size(); i++)
		{
			if(g->IncidentEdges(v->Position).GetReference(i)->Label == notVisited)
			{
				Vertex<int> *w;
				if(g->IncidentEdges(v->Position).GetReference(i)->LeftVertex == v)
				{
					w = g->IncidentEdges(v->Position).GetReference(i)->RightVertex;
				}
				else
				{
					w = g->IncidentEdges(v->Position).GetReference(i)->LeftVertex;
				}
				if(w->Label == notVisited)
				{
					g->IncidentEdges(v->Position).GetReference(i)->Label = found;
					DFS(g, w);
				}
				else
				{
					g->IncidentEdges(v->Position).GetReference(i)->Label = returned;
				}
			}
		}
	}
	
	void BFS(Graph *g)
	{
		for(int i = 0; i < g->V->Size(); i++)
		{
			g->V->GetReference(i).Label = notVisited;
		}
		
		for(int i = 0; i < g->E->Size(); i++)
		{
			g->E->GetReference(i).Label = notVisited;
		}
		
		for(int i = 0; i < g->V->Size(); i++)
		{
			if(g->V->GetReference(i).Label == notVisited)
			{
				BFS(g, &g->V->GetReference(i));
			}
		}
	}
	
	void BFS(Graph *g, Vertex<int> *v)
	{
		Array<List<Vertex<int> >* > L;
		L.Add(new List<Vertex<int> >());
		L.GetReference(0)->AddNext(*v);
		v->Label = visited;
		int i = 0;
		while(!L.GetReference(i)->IsEmpty())
		{
			L.Add(new List<Vertex<int> >());
		
			for(int j = 0; j < L.GetReference(i)->Size(); j++)
			{
				Vertex<int> ver = L.GetReference(i)->GetReference(j);
				for(int k = 0; k < g->IncidentEdges(ver.Position).Size(); k++)
				{
					if(g->IncidentEdges(ver.Position).GetReference(k)->Label == notVisited)
					{
						Vertex<int> *w;
						if(g->IncidentEdges(ver.Position).GetReference(k)->LeftVertex == v)
						{
							w = g->IncidentEdges(ver.Position).GetReference(k)->RightVertex;
						}
						else
						{
							w = g->IncidentEdges(ver.Position).GetReference(k)->LeftVertex;
						}
						if(w->Label == notVisited)
						{
							g->IncidentEdges(ver.Position).GetReference(k)->Label = found;
							w->Label = visited;
							L.GetReference(i+1)->AddNext(*w);
						}
						else
						{
							g->IncidentEdges(ver.Position).GetReference(k)->Label = cross;
						}
					}
				}
			}
			i++;
		}
	}
};

#endif

