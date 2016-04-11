#ifndef EmptyQueueException_HH
#define EmptyQueueException_HH

#include <iostream>

class EmptyQueueException
{
public: 
	EmptyQueueException(){}
	void Show() { cout << "Empty Queue Exception" << endl; }
};

#endif