#ifndef RBTreeTest_HH
#define RBTreeTest_HH

#include <iostream>
#include <cstdlib>
#include <string>
#include "IRunnable.hh"
#include "RBTree.hh"

using namespace std;

class RBTreeTest : IRunnable
{
private:
	RBTree *tree;
	int valueToFind;
	
public:
	virtual bool Prepare(int problemSize)
	{
		if(tree != NULL)
		{
			delete tree;
		}
		tree = new RBTree;
		
		for(int i = 0; i < problemSize; i++)
		{
			tree->Add(i);
		}
		srand(time(NULL));
		//valueToFind = rand() & problemSize;
		valueToFind = problemSize-1;
		return true;
	}
	
	virtual bool Run()
	{
		int value = tree->Get(valueToFind);
		if(value == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
};

#endif