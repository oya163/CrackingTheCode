#pragma once
#ifndef __CIRCULARLINKEDLIST_h__
#define __CIRCULARLINKEDLIST_h__

struct Node {
	int data;
	Node* next;

	Node() : data(NULL), next(NULL) {}
	Node(int d) : data(d), next(NULL) {}
	Node(int d, Node* next) : data(d), next(next) {}
	int getValue() { return data; }
	Node* getNext() { return next; }
};

class CircularLinkedList
{
private:
	Node* head;
	Node* tail;
	int size = 0;

public:
	CircularLinkedList();
	CircularLinkedList(int val);
	virtual ~CircularLinkedList();
	Node* insert(int val);
	Node* append(int val);
	Node* remove(int val);
	void display();
	int getSize();
};
#endif // !__CIRCULARLINKEDLIST_h__



