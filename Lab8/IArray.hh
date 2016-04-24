#ifndef IArray_HH
#define IArray_HH

template < typename type >
class IArray
{
public: 
	virtual void Add(type item) = 0;
	virtual type Get(int index) = 0;
	virtual void Set(type item, int index) = 0;
	virtual int GetNumberOfElements() = 0;
};

#endif