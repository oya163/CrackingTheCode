#pragma once
/*
Linked List header file
11/04/2016
Oyashi
*/

#ifndef __LINKEDLIST_h__
#define __LINKEDLIST_h__

struct Node {
	int data;
	Node *next;

	Node() : data(), next() {}
	Node(int d) : data(d), next(NULL) {}
};


class LinkedList
{
private:
	Node *head = new Node();
	int size = 0;

public:
	LinkedList();
	LinkedList(int val);
	~LinkedList();
	bool insert(int val);
	bool appendList(int val);
	bool insertAt(int val, int pos);
	bool removeAt(int pos);
	int getSize();
	int getValueOf(int index);
	void displayList();
};
#endif // !__LINKEDLIST_h__




