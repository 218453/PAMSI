#ifndef ITree_HH
#define ITree_HH

class ITree
{
public:
	virtual void Add(int value) = 0;
	virtual int Get(int value) = 0;
};

#endif