#ifndef IHashTable_HH
#define IHashTable_HH

#include <iostream>
#include <string>
using namespace std;

class IHashTable
{
public:
	virtual int Hash(string key) = 0;
	virtual int Get(string key) = 0;
	virtual void Put(string key, int value) = 0;
	virtual void Remove(string key) = 0;
};

#endif