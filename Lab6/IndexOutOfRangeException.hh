#ifndef IndexOutOfRangeException_HH
#define IndexOutOfRangeException_HH

#include <iostream>

class IndexOutOfRangeException
{
public: 
	IndexOutOfRangeException() {}
	void Show()
	{ 
		cout << "Index Out Of Range Exception" << endl; 
	}
};

#endif