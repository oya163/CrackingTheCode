#pragma once
/*
	Implementation of Generic Linked List
	11/04/2016
	Oyashi
*/

#ifndef __GENERICLINKEDLIST_h__
template <class T>
struct Node
{
	T data;
	Node<T> *next;
	Node<T>() : data(), next() {}
	Node<T>(T d) : data(d), next() {}
};

template <class T>
class GenericLinkedList {
private:
	Node<T>* head = new Node<T>();
	int size = 0;

public:
	GenericLinkedList();
	GenericLinkedList(T val);
	~GenericLinkedList();
	void insert(T val);
	void append(T val);
	void insertAt(T val, int pos);
	void display();
	T find_K_Element(int k);

};
#endif // !__GENERICLINKEDLIST_h__

//Default Constructor
template <class T>
inline GenericLinkedList<T>::GenericLinkedList() {
	//Uncomment below section if string type is used
	//head->data = " ";
	//Comment below section if int type is used
	head->data = NULL;
	head->next = NULL;
}

//Constructor with parameter
template <class T>
inline GenericLinkedList<T>::GenericLinkedList(T val) {
	Node<T>* newNode = new Node<T>(val);
	newNode->data = val;
	if (head == NULL) {
		head = newNode;
		head->next = NULL;
	}
	else {
		Node<T>* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

//Destructor
template <class T>
inline GenericLinkedList<T>::~GenericLinkedList() {
	Node<T>* current = head;
	Node<T>* temp = head;
	while (current) {
		temp = current->next;
		delete current;
		current = temp;
	}
	head = NULL;
}

//Insert the given item in head of the list
template <class T>
inline void GenericLinkedList<T>::insert(T val) {
	Node<T>* newNode = new Node<T>(val);
	if (head == NULL) {
		head = newNode;
	}
	else {
		Node<T>* temp = head;
		newNode->next = temp;
		head = newNode;
	}
	size++;
}

//Append the given item into the list
template <class T>
inline void GenericLinkedList<T>::append(T val) {
	Node<T>* newNode = new Node<T>(val);
	if (head == NULL) {
		head = newNode;
	}
	else {
		Node<T>* current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = newNode;
	}
	size++;
}

//Inserts at certain location
template <class T>
inline void GenericLinkedList<T>::insertAt(T val, int pos) {
	Node<T>* newNode = new Node<T>(val);
	int currPos = 0;
	if (head == NULL) {
		head = newNode;
	}
	else if (pos == 0) {
		insert(val);
	}
	else {
		Node<T>* left = head;
		Node<T>* right = head;
		while (right) {
			if (currPos == pos) {
				left->next = newNode;
				newNode->next = right;
			}
			left = right;
			right = right->next;
			currPos++;
		}
	}
	size++;
}

//Prints the entire list
template <class T>
inline void GenericLinkedList<T>::display() {
	Node<T>* curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

//Returns Kth to the last element
template <class T>
inline T GenericLinkedList<T>::find_K_Element(int k) {
	Node<T>* current = head;
	int currPos = 0;
	if (k < size) {
		int findOn = size - k;
		while (current) {
			if (currPos == findOn) {
				return current->data;
			}
			current = current->next;
			currPos++;
		}
	}
	return NULL;
}