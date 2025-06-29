#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class Node
{
public:
	int x;
	Node* next;

	void Add(int data, Node& Head, Node& LastNode) {}

	Node Find(int data, Node& Head) {}

	void Newadd(int data, Node p, Node& Head) {}

	void Show_Before(Node& Head) {}

	void Show_After(Node& Head) {}

	Node Find(Node Head, int data) {}

	void DeleteNode(Node& Head, Node OldNode) {}
};

typedef Node* PNode;

void RunTask();

#endif