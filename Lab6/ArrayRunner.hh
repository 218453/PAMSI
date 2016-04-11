#ifndef ArrayRunner_HH
#define ArrayRunner_HH

#include <iostream>
#include "IRunnable.hh"
#include "Array.hh"
using namespace std;

class ArrayRunner : public Array<int>, public IRunnable
{	
public : 
	virtual bool Prepare(int size);
	virtual bool Run();
};

#endif