#ifndef AssociativeArray_HH
#define AssociativeArray_HH

#include "IAssociativeArray.hh"
#include "HashTable.hh"
#include <iostream>
#include <string>
using namespace std;

class AssociativeArray : IAssociativeArray
{
protected:
	int size;
	HashTable *hashTable;
public:
	AssociativeArray()
	{
			
	}
	AssociativeArray(int newSize)
	{
		cout << "contructor associative array" << endl;
		size = newSize;
		hashTable = new HashTable(size);
	}
	~AssociativeArray()
	{
		delete hashTable;
	}
	virtual int Hash(string key)
	{
		return hashTable->Hash(key);
	}
	virtual int Get(string key)
	{
		return hashTable->Get(key);
	}
	virtual void Put(string key, int value)
	{
		hashTable->Put(key, value);
	}
	virtual void Remove(string key)
	{
		hashTable->Remove(key);
	}
	void ShowAll()
	{
		hashTable->ShowAll();
	}
	
	int operator [](string key)
	{
		return Get(key);		
	}
	
	/*HashEntry & operator [](string key)
	{
		
	}*/
};

#endif
