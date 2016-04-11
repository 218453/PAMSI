#ifndef Stack_HH
#define Stack_HH

#include "IStack.hh"
#include "Array.hh"
#include "EmptyStackException.hh"

template < typename type >
class Stack : public IStack<type>
{
protected:
	Array<type> *stackArray;
	int actualIndex;
	
public: 
	Stack()
	{
		stackArray = new Array<type>();
		actualIndex = -1;
	}
	
	~Stack()
	{
		delete stackArray;
	}
	
	virtual void Push(type item)
	{
		if(Size() < stackArray->GetNumberOfElements())
		{
			actualIndex++;
			stackArray->Set(item, actualIndex);
		}
		else
		{
			actualIndex++;
			stackArray->Add(item);			
		}
	}
	
	virtual type Pop() throw(EmptyStackException)
	{
		if(!IsEmpty())
		{
			type tempItem = Top();
			actualIndex--;
			return tempItem;
		}
		else
		{
			throw EmptyStackException();
		}
	}
	
	virtual type Top() throw(EmptyStackException)
	{
		if(!IsEmpty())
		{
			type tempItem = stackArray->Get(actualIndex);
			return tempItem;
		}
		else
		{
			throw EmptyStackException();
		}
	}
	
	virtual int Size()
	{
		return actualIndex+1;
	}
	
	virtual bool IsEmpty()
	{
		return (actualIndex < 0);
	}
	
	void ShowStack()
	{
		for(int i=0; i<Size(); i++)
		{
			cout << "Element" << i << " : " << stackArray->Get(i) << endl;
		}
	}
};

#endif