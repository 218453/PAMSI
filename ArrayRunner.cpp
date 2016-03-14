#include "ArrayRunner.hh"

bool ArrayRunner::Prepare(int size)
{
	numberOfElements = 0;
	arraySize = 10;
	array = new int[arraySize];
	ptr = array;
	Size = size;
	return true;
}

bool ArrayRunner::Run()
{
	for(int i = 0; i < Size; i++)
	{
		Add(i);
		//cout << "Element" << i << " " << Get(i) << endl;
	}
	delete [] array;
	return true;
}