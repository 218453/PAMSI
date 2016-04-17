#ifndef TreeElement_HH
#define TreeElement_HH

class TreeElement
{
private:
	int value;
	TreeElement *parent;
	TreeElement *leftChild;
	TreeElement *rightChild;
	
public:
	TreeElement()
	{
		value = 0;
		parent = NULL;
		leftChild = NULL;
		rightChild = NULL;
	}
	TreeElement(int newValue, TreeElement *newParent, TreeElement *newLeftChild, TreeElement *newRightChild)
	{
		parent = NULL;
		leftChild = NULL;
		rightChild = NULL;
	}
	bool HasParent()
	{
		if(GetParent() != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool HasLeftChild()
	{
		if(GetLeftChild() != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool HasRightChild()
	{
		if(GetRightChild() != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int GetValue()
	{
		return value;
	}
	TreeElement & GetParent()
	{
		return parent;
	}
	TreeElement & GetLeftChild()
	{
		return leftChild;
	}
	TreeElement & GetRightChild()
	{
		return rightChild;
	}
	void SetParent(TreeElement *treeElement)
	{
		parent = treeElement;
	}
	void SetLeftChild(TreeElement *treeElement)
	{
		leftChild = treeElement;
	}
	void SetRightChild(TreeElement *treeElement)
	{
		rightChild = treeElement;
	}
	
};

#endif