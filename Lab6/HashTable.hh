#ifndef HashTable_HH
#define HashTable_HH

#include "IHashTable.hh"
#include <iostream>
#include <string>
using namespace std;

class HashEntry
{
private:
	string key;
	int value;
public:
	HashEntry(string newKey, int newValue)
	{
		key = newKey;
		value = newValue;
	}
	string GetKey()
	{
		return key;
	}
	int GetValue()
	{
		return value;
	}
};

class HashTable : public IHashTable
{
private:
	int tableSize;
	HashEntry **table;
public:
	HashTable(int size)
	{
		tableSize = size;
		table = new HashEntry*[tableSize];
		for(int i = 0; i < tableSize; i++)
		{
			table[i] = NULL;
		}
	}
    ~HashTable() 
    {
    	for (int i = 0; i < tableSize; i++)

    	{
    		if (table[i] != NULL)
    		{
    			delete table[i];
    		}	
    	}
        delete[] table;
    }
	virtual int Hash(string key)
	{	
		int sum = 0;
		for(int i=0; i < key.length(); i++)
		{
			sum += key[i];
		}
		return sum % tableSize;
	}
	virtual int Get(string key)
	{
		int hash = Hash(key);
		cout << "GET_HASH:" << hash << endl;
        while (table[hash] != NULL && table[hash]->GetKey() != key)
        {
        	hash = (hash + 1) % tableSize;
        	cout << "GET_NEXT_HASH:" << hash << endl;
        }
        if (table[hash] == NULL)
        {
        	return -1;	
        }
        else
        {
        	return table[hash]->GetValue();
        }
	}
	virtual void Put(string key, int value)
	{
		int hash = Hash(key);
		cout << "PUT_HASH:" << hash << endl;
		while (table[hash] != NULL && table[hash]->GetKey() != key)
		{
			hash = (hash + 1) % tableSize;
			cout << "PUT_NEXT_HASH:" << hash << endl;
		}
		if (table[hash] != NULL)
		{
			delete table[hash];
		}
		table[hash] = new HashEntry(key, value);
	}	
};


#endif