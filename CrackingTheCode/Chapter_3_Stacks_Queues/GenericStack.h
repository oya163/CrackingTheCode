/*
	Header file for Generic Stack
	12/21/2016
	Oyashi
*/

#pragma once
#ifndef __GENERICSTACK_h__
#define __GENERICSTACK_h__

//Node struct
template <class T>
struct Node {
	T data;
	Node<T>* next;
	int nodeSize = 0;

	Node<T>() : data(NULL), next(NULL) {}
	Node<T>(T d) : data(d), next(NULL) {}
};

//Generic Stack class
template <class T>
class GenericStack
{
private:
	Node<T>* head = new Node<T>();
	int size = 0;

public:
	GenericStack();
	GenericStack(T val);
	void push(T val);
	T peek();
	void pop();
	void display();
	~GenericStack();
};

#endif // !__GENERICSTACK_h__

//Default Constructor
template <class T>
inline GenericStack<T>::GenericStack()
{
	head = NULL;
}

//Constructor with parameter
template <class T>
inline GenericStack<T>::GenericStack(T val)
{
	head->data = val;
	head->next = NULL;
}

//Push value into stack
template <class T>
inline void GenericStack<T>::push(T val) {
	Node<T>* curr = head;
	if (head == NULL) {
		head = new Node<T>(val);
	}
	else {
		Node<T>* newNode = new Node<T>(val);
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
	
}

//Return top node of stack
template <class T>
inline T GenericStack<T>::peek() {
	Node<T>* curr = head;
	while (curr->next) {
		curr = curr->next;
	}
	return curr->data;
}

//Remove the top node of stack
template <class T>
inline void GenericStack<T>::pop() {
	Node<T>* curr = head;
	while (curr->next->next) {
		curr = curr->next;
	}
	delete curr->next;
	curr->next = NULL;
}

//Display an entire stack
template <class T>
inline void GenericStack<T>::display() {
	Node<T>* curr = head;
	while (curr) {
		cout << curr->data << "->";
		curr = curr->next;
	}
	cout << endl;
}

//Destructor of stack
template <class T>
inline GenericStack<T>::~GenericStack(){
	Node<T>* curr = head;
	Node<T>* temp = head;
	while (curr) {
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	head = 0;
}