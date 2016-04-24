#include "RBTree.hh"

// Constructor
//-------------------
RBTree::RBTree()
{
  cr = cl = cp = "  ";
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;
  S.color = 'B';
  S.up    = &S;
  S.left  = &S;
  S.right = &S;
  root    = &S;
}

// Destructor
//------------------
RBTree::~RBTree()
{
  Release(root);
}

void RBTree::Release(RBTNode * p)
{
	if(p != &S)
	{
		Release(p->left);
		Release(p->right);
		delete p;
	}
}

void RBTree::PrintRBT(string sp, string sn, RBTNode * p)
{
	string t;
	
	if(p != &S)
	{
		t = sp;
		if(sn == cr)
		{
			t[t.length() - 2] = ' ';
		}
		PrintRBT(t+cp,cr,p->right);
		
		t = t.substr(0,sp.length()-2);
		cout << t << sn << p->color << ":" << p->key << endl;
		
		t = sp;
		if(sn == cl)
		{
			t[t.length() - 2] = ' ';
		}
		PrintRBT(t+cp,cl,p->left);
	}
}

void RBTree::Print()
{
	PrintRBT("","",root);
}

RBTNode * RBTree::FindRBT(int k)
{
	RBTNode * p;
	
	p = root;
	while((p != &S) && (p->key != k))
	{
		if(k < p->key) 
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}		  
	}
	if(p == &S) 
	{
	  return NULL;
	}
	return p;
}

void RBTree::Rot_L(RBTNode * A)
{
	RBTNode * B, * p;
	
	B = A->right;
	if(B != &S)
	{
		p = A->up;
		A->right = B->left;
		if(A->right != &S)
		{
			A->right->up = A;
		}
		
		B->left = A;
		B->up = p;
		A->up = B;
		
		if(p != &S)
		{
			if(p->left == A)
			{
				p->left = B; 
			}
			else 
			{
				p->right = B;
			}
		}
		else root = B;
	}
}

void RBTree::Rot_R(RBTNode * A)
{
	RBTNode * B, * p;
	
	B = A->left;
	if(B != &S)
	{
		p = A->up;
		A->left = B->right;
		if(A->left != &S)
		{
			A->left->up = A;
		}
		
		B->right = A;
		B->up = p;
		A->up = B;
		
		if(p != &S)
		{
			if(p->left == A)
			{
				p->left = B; 
			}
			else
			{
				p->right = B;
			}
		}
		else root = B;
	}
}

void RBTree::InsertRBT(int k)
{
	RBTNode * X, * Y;
	
	X = new RBTNode;
	X->left  = &S;
	X->right = &S;
	X->up    = root;
	X->key   = k;
	if(X->up == &S)
	{
		root = X;
	}
	else
	{
		while(true)
		{
			if(k < X->up->key)
			{
				if(X->up->left == &S)
				{
					X->up->left = X;
					break;
				}
				X->up = X->up->left;
			}
			else
			{
				if(X->up->right == &S)
				{
					X->up->right = X;
					break;
				}
				X->up = X->up->right;
			}
		}
	}
	X->color = 'R';
	while((X != root) && (X->up->color == 'R'))
	{
		if(X->up == X->up->up->left)
		{
			Y = X->up->up->right;
			
			if(Y->color == 'R')  // Case 1
			{
				X->up->color = 'B';
				Y->color = 'B';
				X->up->up->color = 'R';
				X = X->up->up;
				continue;
			}
			if(X == X->up->right) // Case 2
			{
				X = X->up;
				Rot_L(X);
			}
			
			X->up->color = 'B'; // Case 3
			X->up->up->color = 'R';
			Rot_R(X->up->up);
			break;
		}
		else
		{
			Y = X->up->up->left;
			
			if(Y->color == 'R') // Case 4
			{
				X->up->color = 'B';
				Y->color = 'B';
				X->up->up->color = 'R';
				X = X->up->up;
				continue;
			}
		
			if(X == X->up->left) // Case 5
			{
				X = X->up;
				Rot_R(X);
			}
			
			X->up->color = 'B'; // Case 6
			X->up->up->color = 'R';
			Rot_L(X->up->up);
			break;
		}
	}
	root->color = 'B';
}

int RBTree::Height()
{
	Depth(root);
}
	
int RBTree::Depth(RBTNode * root)
{
	if (root == &S)
	{
		return 0;		  
	}
	 
	int left_depth = Depth(root->left);
	int right_depth = Depth(root->right);
	
	return (left_depth > right_depth) ? left_depth + 1 : right_depth + 1;
}
	
void RBTree::Queue(int * queue,char * queueC, RBTNode * root, int index)
{
	if (root == &S)
	{
		return;		  
	}
	 
	if (index == 0)
	{
		queue[0] = root->key;
		queueC[0] = root->color;
	}
	
	if (root->left != NULL)
	{
		queue[2*index + 1] = root->left->key;
		queueC[2*index + 1] = root->left->color;
		Queue(queue, queueC, root->left, 2*index+1);
	}
	if (root->right != NULL)
	{
		queue[2*index + 2] = root->right->key;
		queueC[2*index + 2] = root->right->color;
		Queue(queue, queueC, root->right, 2*index+2);
	}
}

void RBTree::DrawAll()
{
	Draw(root, 4);
}

void RBTree::Draw(RBTNode * root, int block_width)
{
	int depth = Depth(root);
	int max_blocks = pow(2, depth - 1);
	int blocks_count = 0;
	for (int i = 0; i < depth; ++i)
	{
		blocks_count += pow(2,i);
	}
	
	int * queue = new int[blocks_count];
	char * queueC = new char[blocks_count];
	for (int i = 0; i < blocks_count; queue[i++] = -1);
	Queue(queue, queueC, root, 0);
	
	int width = max_blocks * block_width;
	int begin = 0;
	for (int i = 0; i < depth; ++i)
	{
		int current_width = width / pow(2,i);
		for (int j = begin; j < begin+pow(2,i); ++j)
		{
			if (j == begin)
			{
				cout << setw(current_width/2);				
			}
			else
			{
				cout << setw(current_width);				
			}
			 
			if (queue[j] != -1)
			{
				cout << queue[j] << "," << queueC[j];				
			}
			else
			{
				cout << " ";				
			}
		}
		begin += pow(2,i);
		cout << "\n";
	}
}



