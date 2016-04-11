#ifndef Queue_HH
#define Queue_HH

#include "IQueue.hh"
#include "Array.hh"
#include "EmptyQueueException.hh"

template < typename type >
class Queue : public IQueue<type>
{
protected:
	Array<type> *queueArray;
	int f;
	int r;
	
public: 
	Queue()
	{
		queueArray = new Array<type>();
		f = 0;
		r = 0;
	}
	
	~Queue()
	{
		delete queueArray;
	}
	
	virtual void Enqueue(type item)
	{
		queueArray->Add(item);
		r++;
	}
	
	virtual type Dequeue()
	{
		if(!IsEmpty())
		{
			type tempItem = Front();
			f++;
			return tempItem;
		}
		else
		{
			throw EmptyQueueException();
		}
	}
	
	virtual type Front()
	{
		if(!IsEmpty())
		{
			return queueArray->Get(f);
		}
		else
		{
			throw EmptyQueueException();
		}
	}
	
	virtual int Size()
	{
		return r-f;
	}
	
	virtual bool IsEmpty()
	{
		return (r == f);
	}
	
	void ShowQueue()
	{
		for(int i=f; i<r; i++)
		{
			cout << "Element" << i << " : " << queueArray->Get(i) << endl;
		}
	}
};

#endif