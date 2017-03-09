#pragma once
#include "Node.h"
class List
{
private:
	Node* head;
	int size;
public:
	List();
	void addNode(const int &data);
	void tranverse(Node* _head);
	void tranversePrint(void(*visit)(Node* p));
	void print(Node* p);
	void createDouble(Node* single);
	Node* getHead();
	void insertOrderedList(int sData, Node* current);
	int getSize();
	~List();
};

