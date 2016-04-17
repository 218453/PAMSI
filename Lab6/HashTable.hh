#ifndef HashTable_HH
#define HashTable_HH

#include "IHashTable.hh"
#include "List.hh"
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
	List<HashEntry*> **table;
public:
	HashTable(int size)
	{
		tableSize = size;
		table = new List<HashEntry*>*[tableSize];
		for(int i = 0; i < tableSize; i++)
		{
			table[i] = new List<HashEntry*>();
		}
		
	}
    ~HashTable() 
    {
    	cout << "Hash Table Destructor" << endl;
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
		/*int sum = 0;
		for(int i=0; i < key.length(); i++)
		{
			sum += key[i];
		}
		return sum % tableSize;*/
		const unsigned char *str;
		str = reinterpret_cast<const unsigned char *> (key.c_str());
		unsigned long hash = 0;
		int c;
		while(c = *str++)
		{
			hash = c + (hash << 6) + (hash << 16) - hash;
		}
		return hash % tableSize;
	}
	virtual int Get(string key)
	{
		int hash = Hash(key);
		int tempValue = -1;
		if (table[hash] == NULL)
		{
			return -1;	
		}
		else
		{
			//find element on list
			for(int i = 0; i < table[hash]->Size(); i++)
			{
				if(table[hash]->Get(i)->GetKey() == key)
				{
					tempValue = table[hash]->Get(i)->GetValue();
					//cout << "Get " << key << " from slot " << hash << " at index " << i << endl;
				}
			}
			return tempValue;
		}
	}
	virtual void Put(string key, int value)
	{
		int hash = Hash(key);
		table[hash]->AddNext(new HashEntry(key,value));
		//cout << "Put " << key << " to slot " << hash << endl;
	}
	
	virtual void Remove(string key)
	{
		int hash = Hash(key);
		if (table[hash] == NULL)
		{
			cout << "There is no key " << key << "!!!" << endl;
		}
		else
		{
			//find element on list and remove
			for(int i = 0; i < table[hash]->Size(); i++)
			{
				if(table[hash]->Get(i)->GetKey() == key)
				{
					table[hash]->Remove(i);
					break;
					//cout << "Removed " << key << " from slot " << hash << " at index " << i << endl;
				}
			}
		}
	}
	
	void ShowAll()
	{
		cout << endl;
		for(int i = 0; i < tableSize; i++)
		{
			cout << "Slot number " << i << ": " << endl;
			for(int j = 0; j < table[i]->Size(); j++)
			{
				cout << table[i]->Get(j)->GetKey() << ": " << table[i]->Get(j)->GetValue() <<"; ";
			}
			cout << endl;
		}
	}
	
	void ShowLists()
	{
		cout << endl;
		for(int i = 0; i < tableSize; i++)
		{
			cout << "Slot number " << i << ": ";
			cout << ", List size: " << table[i]->Size() << endl;
			cout << endl;
		}
	}
	
	int AverageListSize()
	{
		int value = 0;
		for(int i = 0; i < tableSize; i++)
		{
			value += table[i]->Size();
		}
		return value/tableSize;
	}
};


#endif