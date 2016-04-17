#ifndef AssociativeArrayTest_HH
#define AssociativeArrayTest_HH

#include <iostream>
#include <cstdlib>
#include <string>
#include "IRunnable.hh"
#include "AssociativeArray.hh"
using namespace std;

class AssociativeArrayTest: AssociativeArray, IRunnable
{
private:

	int arraySize;
	string *wordsArray;
public:
	virtual bool Prepare(int size)
	{
		arraySize = size;
		if(wordsArray != NULL)
		{
			delete [] wordsArray;
		}
		wordsArray = new string[arraySize];
		
		int HashTableSlots [] = {2, 11, 101, 1019, 10007, 100151};
		int slot = 0;
		for(int i = 0; i < 6; i++)
		{
			slot = i;
			if(HashTableSlots[slot] > (arraySize/10))
			{
				break;
			}
		}
		//hashTable = new HashTable(HashTableSlots[slot]);
		hashTable = new HashTable(arraySize);
		//cout << "HashTAbleSlots: " << HashTableSlots[slot] << endl;
		
		static char Signs[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
				'q','r','s','t','u','v','w','x','y','z'};
		const unsigned SignCount=sizeof(Signs)/sizeof(*Signs);
		const unsigned Count=6;
		unsigned Tb[Count]={0};
		int counter = 0;
		string tempWord;
		while(counter < arraySize)
		{
			tempWord = "";
			for(unsigned i=0;i<Count;++i)
			{
				tempWord += Signs[Tb[i]];
			}
			wordsArray[counter] = tempWord;
			counter++;
			unsigned p=Count;
			while(p--)
			{
				if(++Tb[p]<SignCount)
				{
					break;
				}
				Tb[p]=0;
			}
			if(p>=Count)
			{
				break;
			}
		}
		return true;
	}
	virtual bool Run()
	{
		srand(time(NULL));
		for(int i = 0; i < arraySize; i++)
		{
			Put(wordsArray[i], rand() & 1000000);
		}
		return true;
	}
	virtual bool RunPut()
	{
		srand(time(NULL));
		for(int i = 0; i < arraySize; i++)
		{
			Put(wordsArray[i], rand() & 1000000);
		}
		return true;
	}
	virtual bool RunRemove()
	{
		for(int i = 0; i < arraySize; i++)
		{
			Remove(wordsArray[i]);
		}
		return true;
	}
	
	void ShowLists()
	{
		//hashTable->ShowLists();
		cout << "Average Lists size: " << hashTable->AverageListSize() << endl;
	}
	
	void ShowAll()
	{
		hashTable->ShowAll();
	}
};

#endif