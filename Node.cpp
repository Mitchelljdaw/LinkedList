#include "stdafx.h"
#include "Node.h"


Node::Node()
{
	next = nullptr;
	prev = nullptr;
	data = 0;
}


Node::Node(Node* p, const int _data, Node* _prev)
{
	next = p;
	prev = _prev;
	data = _data;
}



Node::~Node()
{
}
