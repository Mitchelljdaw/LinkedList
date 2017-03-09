// console application to practice for 2420

#include "stdafx.h"
#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void print(Node* p);
void main()
{
	string file;
	string number;
	List newList;
	List doubleList;
	//Print your name, class (i.e. CS 2420), section number, and program number 
	cout << "|Mitchell Daw|CS 2420|Section:|Program 2: Linked List|" << endl;
	//Prompt the user for the file name and open the file, if the file cannot be open, handle the error appropriately
	cout << "Please enter the file you want to open:";
	cin >> file;
	ifstream readFile;
		readFile.open(file);
		while (readFile.fail()) {
			system("cls");
			cout << "file does not exist. Please try again" << endl;
			cout << "Please enter the file you want to open:";
			cin >> file;
			readFile.open(file);
		}
		//Read all of the integers and insert them into the single linked list until end of file is reached
		while (!readFile.eof()) {
			getline(readFile, number);
			newList.addNode(stoi(number));
		}
		readFile.close();
		//Traverse the single linked list node by node, for each node in the single linked list
		newList.tranverse(newList.getHead());
		//Insert the integer from the node of the single linked list into the double linked list in ascending order
		doubleList.createDouble(newList.getHead());
		//Print single linked list using tranversePrint function
		cout << "-Single Linked list-" << endl;
		newList.tranversePrint(&print);
		//Print double linked list using tranversePrint function
		cout << "-Double Linked list-" << endl;
		doubleList.tranversePrint(&print);
	system("PAUSE");
}


//Function name:Print
//Purpose: will print out data from a linked list
//Parameters: One Node pointer. 
void print(Node* p)
{
	cout << p->data << endl;
}
