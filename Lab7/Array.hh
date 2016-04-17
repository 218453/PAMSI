#ifndef Array_HH
#define Array_HH

#include <iostream>
#include "IArray.hh"
using namespace std;

enum ExpandingType
{
	by_one,
	two_times,
	by_hundred,
	one_and_half_times
};

template < typename type >
class Array : public IArray<type>
{
protected:
	long int arraySize;
	long int numberOfElements;
	type * array;
	type * ptr;	
	
	public : Array()
	{
		numberOfElements = 0;
		arraySize = 10;
		array = new type[arraySize];
		ptr = array;
	}
	
	public : ~Array()
	{
		delete [] array;
	}
	
	public : virtual void Add(type value)
	{
		Add2(value);
	}

	public : virtual type Get(int index)
	{
		return array[index];
	}
	
	public : virtual void Set(type item, int index)
	{
		array[index] = item;
	}
	
	public : virtual int GetNumberOfElements()
	{
		return numberOfElements;
	}
	
	private : void Add1(type value)
	{
		if(numberOfElements < arraySize)
		{
			*ptr = value;
			ptr++;
		}
		else
		{
			arraySize++;
			type * tempArray = new type[arraySize];
			for(int i = 0; i < arraySize-1; i++)
			{
				tempArray[i] = array[i];
			}
			tempArray[arraySize-1] = value;
			delete [] array;
			array = tempArray;
			ptr = &tempArray[arraySize];
		}
		numberOfElements++;
	}

	private : void Add2(type value)
	{
		if(numberOfElements < arraySize)
		{
			*ptr = value;
			ptr++;
		}
		else
		{
			arraySize*=2;
			type * tempArray = new type[arraySize];
			for(int i = 0; i < (arraySize/2); i++)
			{
				tempArray[i] = array[i];
			}
			delete [] array;
			array = tempArray;
			ptr = &array[(arraySize/2)];
			*ptr = value;
			ptr++;
		}
		numberOfElements++;
	}

	private : void Add3(type value)
	{
		if(numberOfElements < arraySize)
		{
			*ptr = value;
			ptr++;
		}
		else
		{
			arraySize += 100;
			type * tempArray = new type[arraySize];
			for(int i = 0; i < arraySize-100; i++)
			{
				tempArray[i] = array[i];
			}
			delete [] array;
			array = tempArray;
			ptr = &tempArray[arraySize-100];
			*ptr = value;
			ptr++;
		}
		numberOfElements++;
	}
	
	private : void Add4(type value)
		{
			if(numberOfElements < arraySize)
			{
				*ptr = value;
				ptr++;
			}
			else
			{
				arraySize*=1.5;
				type * tempArray = new type[arraySize];
				for(int i = 0; i < (arraySize/2); i++)
				{
					tempArray[i] = array[i];
				}
				delete [] array;
				array = tempArray;
				ptr = &array[(arraySize/2)];
				*ptr = value;
				ptr++;
			}
			numberOfElements++;
		}


	public : void Add(ExpandingType expandingType, type value)
	{
		switch (expandingType)
		{
		case by_one:
			Add1(value);
			break;
		case two_times:
			Add2(value);
			break;
		case by_hundred:
			Add3(value);
			break;
		case one_and_half_times:
			Add4(value);
			break;
		default:
			cout << "Wrong expanding type!" << endl;
			break;
		}
	}
};

#endif