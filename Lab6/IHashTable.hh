#ifndef IHashTable_HH
#define IHashTableHH

#include <iostream>
#include <string>
using namespace std;

class IHashTable
{
public:
	virtual int Hash(string key) = 0;
	virtual int Get(string key) = 0;
	virtual void Put(string key, int value) = 0;	
};

#endif