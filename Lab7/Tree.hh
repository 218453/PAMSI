#ifndef Tree_HH
#define Tree_HH

#include "ITree.hh"
#include "TreeElement.hh"

class Tree
{
protected:
	TreeElement *root;
public:
	Tree()
	{
		root = new TreeElement(); 
	}
	
	void AddLeftChild(TreeElement *element)
	{
		
	}
	void AddRightChild(TreeElement *element)
	{
		
	}
	
	virtual void Add(TreeElement *element, int value)
	{
		if(value < element->GetValue)
		{
			// add to left side
			if(!element->HasLeftChild)
			{
				//element->GetLeftChild()
			}
		}
		else
		{
			// add to right side
		}
	}
	virtual int Get(int value)
	{
		
	}
};

#endif