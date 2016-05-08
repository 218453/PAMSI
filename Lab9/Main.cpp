#include <iostream>
#include <fstream>
#include "TimeCounter.hh"
#include "GraphTest.hh"
#include "Graph.hh"
#include "BranchAndBound.hh"

using namespace std;

void DumpToFile(int times[11][6], char * fileName)
{
	ofstream myfile;
	myfile.open(fileName);
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			myfile << times[i][j] << ";";
		}
		myfile << "\n";
	}
}

int main()
{
	Graph g(10);
	BranchAndBound bb;
	
	g.AddVertex(0);
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddEdge(0,1,1);
	g.AddEdge(0,2,3);
	
	bb.FindPath(g,0,1);
	bb.ShowAllPaths();
	
	cout << "MAIN" << endl;
	
}