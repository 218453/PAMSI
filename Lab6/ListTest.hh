#ifndef ListTest_HH
#define ListTest_HH

#include <iostream>
#include <string>
#include <fstream>
#include "IRunnable.hh"
#include "List.hh"
using namespace std;

class ListTest : public List<string>, public IRunnable
{	
private :
	string * listOfWords;
	int mySize;
	
public : 
	ListTest(string allWords [])
	{
		listArray = new Array<string>();
		listOfWords = allWords;
	}
	
	virtual bool Prepare(int size)
	{
		mySize = size;
		for(int i = 0; i < mySize; i++)
		{
			Add(listOfWords[i],i);
		}
		return true;
	}
	virtual bool Run()
	{
		return true;
	}
	
	bool Run(string word)
	{
		int index = Find(word);
		if(index >= 0)
		{
			cout << "Found at index " << index << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	int Find(string word)
	{
		for(int i = 0; i < mySize; i++)
		{
			if(listOfWords[i] == word)
			{
				return i;
			}
		}
		return -1;
	}
};

#endif