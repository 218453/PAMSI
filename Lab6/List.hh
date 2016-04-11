#ifndef List_HH
#define ListHH

#include "IList.hh"
#include "Array.hh"
#include "IndexOutOfRangeException.hh"

template < typename type >
class List : public IList<type>
{
protected:
	Array<type>* listArray;
	int size;
	
public: 
	List()
	{
		listArray = new Array<type>();
		size = 0;
	}
	
	~List()
	{
		delete [] listArray;
	}
	
	virtual void Add(type item, int index)
	{
		if(index >= 0 && index <= size)
		{
			if(index == size && size == listArray->GetNumberOfElements())
			{
				listArray->Add(item);
			}
			else if(index == size && size < listArray->GetNumberOfElements())
			{
				listArray->Set(item, index);
			}
			else
			{
				Array<type>* tempArray = new Array<type>();
				for(int i = 0; i < size+1; i++)
				{
					if(i < index)
					{
						tempArray->Add(Get(i));
					}
					else if(i == index)
					{
						tempArray->Add(item);
					}
					else if (i > index)
					{
						tempArray->Add(Get(i-1));
					}
				}
				delete listArray;
				listArray = tempArray;
			}
			size++;
		}
		else
		{
			throw IndexOutOfRangeException();
		}
	}
	
	virtual void Remove(int index)
	{
		if(index >= 0 && index <= size)
		{
			if(index < size-1)
			{
				Array<type>* tempArray = new Array<type>();
				for(int i = 0; i < size-1; i++)
				{
					if(i < index)
					{
						tempArray->Add(Get(i));
					}
					else if (i >= index)
					{
						tempArray->Add(Get(i+1));
					}
				}
				delete listArray;
				listArray = tempArray;
			}
			size--;
		}
		else
		{
			throw IndexOutOfRangeException();
		}
	}
	
	virtual type Get(int index)
	{
		return listArray->Get(index);
	}
	
	virtual int Size()
	{
		return size;
	}
	
	virtual bool IsEmpty()
	{
		return (size == 0);
	}
	
	void ShowList()
	{
		for(int i = 0; i < size; i++)
		{
			cout << "Element" << i << ":" << Get(i) << endl;
		}
	}
	
};


#endif