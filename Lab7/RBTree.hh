#ifndef RBTree_HH
#define RBTree_HH

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include "ITree.hh"

using namespace std;

struct RBTNode
{
  RBTNode * up;
  RBTNode * left;
  RBTNode * right;
  int key;
  char color;
};

class RBTree : ITree
{
  private:
    RBTNode S;
    RBTNode * root;
    string cr,cl,cp;

    void PrintRBT(string sp, string sn, RBTNode * p);

  public:
    RBTree();
    ~RBTree();
    void Release(RBTNode * p);
    void Print();
    RBTNode * FindRBT(int k);
    void Rot_L(RBTNode * A);
    void Rot_R(RBTNode * A);
    void InsertRBT(int k);
    int Height();
	int Depth(RBTNode * root);
	void Queue(int * queue,char * queueC, RBTNode * root, int index);
	void DrawAll();
	void Draw(RBTNode * root, int block_width);
    
    virtual void Add(int value)
    {
    	InsertRBT(value);
    }
    
    virtual int Get(int value)
    {
    	RBTNode *p = FindRBT(value);
    	if(p == NULL)
    	{
    		return -1;
    	}
    	else
    	{
			return p->key;
    		
    	}
    }
};


#endif