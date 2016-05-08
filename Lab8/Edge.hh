#ifndef Edge_HH
#define Edge_HH

#include "Vertex.hh"

template <typename type>
class Edge
{
public:
	int Position;
	Vertex<type> * LeftVertex;
	Vertex<type> * RightVertex;
	int Weight;
	LabelState Label;
	Edge()
	{
		Position = 0;
		LeftVertex = 0;
		RightVertex = 0;
		Weight = 0;
	}
	Edge(int _position, Vertex<type> * _leftVertex, Vertex<type> * _rightVertex, int _weight)
	{
		Position = _position;
		LeftVertex = _leftVertex;
		RightVertex = _rightVertex;
		Weight = _weight;
	}
	~Edge()
	{
	}
};

#endif