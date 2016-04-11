#ifndef EmptyStackException_HH
#define EmptyStackException_HH

#include <iostream>

class EmptyStackException
{
public: 
	EmptyStackException(){}
	void Show() { cout << "EmptyStackException" << endl; }
};

#endif