#include "stdafx.h"
#include "List.h"
#include "Node.h"
#include <iostream>
using namespace std;

List::List()
{
	head = nullptr;
}


//Function Name:addNode
//Purpose: creates a linked list with data type of interger read from a file chosen by the user.
//Parameters: one int 
void List::addNode(const int &data)
{
	if (head == nullptr)
	{
		head = new Node(nullptr, data);
		size++;
	}
	else if (head->next == nullptr)
	{
		head->next = new Node(nullptr, data);
		size++;
	}
	else
	{
		Node *cursor = head;
		while (cursor->next != nullptr)
		{
			cursor = cursor->next;
		}
			cursor->next = new Node(nullptr, data);
			size++;
	}
}




void List::tranverse(Node* _head)
{
	Node* p = _head;
	if (p == nullptr) {
		cout << "The list is empty there is nothing to print out." << endl;
	}
	else {
		while (p != nullptr) {
			p = p->next;
		}
	}
}

void List::insertOrderedList(int sData, Node* current) 
{
	if(sData<current->data && current == head)
	{
		Node* temp = new Node(head, sData, nullptr);
		head->prev = temp;
		head = temp;
		size++;
	}
	else if(sData<current->data && current != head)
	{
		Node* temp = new Node(current, sData, current->prev);
		current->prev->next = temp;
		current->prev = temp;
		size++;
	}
	else if(sData>current->data)
	{
		if (current->next == nullptr) {
			current->next = new Node(nullptr, sData, current);
			size++;
		}
		else
		{
			insertOrderedList(sData, current->next);
		}
	}
}

void List::tranversePrint(void(*print)(Node* p)) 
{
	Node* p;
	p = head;
	while (p != nullptr) 
	{
		(*print)(p);
		p = p->next;
	}
}
void List::createDouble(Node* single)
{
	if (single == nullptr) {
		cout << "List is empty nothing can be copied." << endl;
	}
	else if (single->next == nullptr)
	{
		head = new Node(nullptr, single->data, nullptr);
		size++;
	}
	else
	{

		head = new Node(nullptr, single->data, nullptr);
		size++;
		Node* p = single->next;
		while (p != nullptr)
		{
			insertOrderedList(p->data, head);
			p = p->next;
		}
	}
}


void List::print(Node* p) 
{
	cout << p->data << endl;
}

int List::getSize() 
{
	return size;
}

Node* List::getHead() 
{
	return head;
}


List::~List()
{
}
