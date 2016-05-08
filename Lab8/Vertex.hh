#ifndef Vertex_HH
#define Vertex_HH

#include <string>
using namespace std;

enum LabelState
{
	notVisited,
	visited,
	found,
	returned,
	cross
};

template <typename type>
class Vertex
{
public:
	int Position;
	type Value;
	LabelState Label;
	Vertex()
	{
		Position = 0;
	}
	Vertex(int _position, type _value)
	{
		Position = _position;
		Value = _value;
	}
	~Vertex()
	{
	}
};
#endif