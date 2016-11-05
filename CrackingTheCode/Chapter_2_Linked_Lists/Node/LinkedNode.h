#pragma once
#ifndef __LINKEDNODE_h__
#define __LINKEDNODE_h__

template <class T>
struct Node {
	T data;
	Node<T>* next;

	Node<T>() : data(), next() {}
	Node<T>(T d) {
		this->data = d;
		this->next = NULL;
	}
};

template <class T>
class LinkedNode {
private:
	Node<T>* head;
	int size = 1;

public:
	LinkedNode<T>();
	LinkedNode<T>(Node<T>* head);
	~LinkedNode<T>();
	void insert(Node<T>* &head, T val);
	void display();
	bool removeNode(Node<T>* &node);
	void append(T val);
	int nthToLast(Node<T>* head, int k);
	int getIndexOf(Node<T>* &head, T val);
	int getSize();
};

#endif 

template <class T>
inline LinkedNode<T>::LinkedNode() {
	this->head = NULL;
}

template <class T>
inline LinkedNode<T>::LinkedNode<T>(Node<T>* head) {
	this->head = head;
}

template <class T>
inline LinkedNode<T>::~LinkedNode() {
	Node<T>* curr = head;
	while (curr) {
		Node<T>* ahead = curr->next;
		delete curr;
		curr = ahead;
	}
	head = NULL;
}

template <class T>
inline void LinkedNode<T>::insert(Node<T>* &head, T val) {
	Node<T>* newNode = new Node<T>(val);
	if (head == NULL) {
		head->data = val;
		head->next = NULL;
	}
	else {
		Node<T>* temp = head;
		newNode->next = temp;
		head = newNode;
	}
}

template <class T>
inline void LinkedNode<T>::display() {
	if (head == NULL) {
		cout << "Empty list" << endl;
	}
	else {
		Node<T>* curr = head;
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	cout << endl;
}

template <class T>
inline bool LinkedNode<T>::removeNode(Node<T>* &node) {
	if (node == NULL || node->next == NULL) {
		return false;
	}
	else {
		Node<T>* newNode = node->next;
		node->data = newNode->data;
		node->next = newNode->next;
		return true;
	}
}

//Appends the list
template <class T>
inline void LinkedNode<T>::append(T val) {
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

//Returns the counter for recursion times
//And displays nth value from last position
template <class T>
inline int LinkedNode<T>::nthToLast(Node<T>* head, int k) {
	if (head == NULL) {
		return 0;
	}
	int i = nthToLast(head->next, k) + 1;
	if (i == k) {
		cout << "Kth element from the last = " << head->data << endl;
	}
	return i;
}

//Returns the index of given value
template <class T>
inline int LinkedNode<T>::getIndexOf(Node<T>* &head, T val) {
	int index = 0;
	if (head == NULL) {
		return -1;
	}
	else {
		Node<T>* current = head;
		while (current) {
			if (current->data == val) {
				return index;
			}
			index++;
			current = current->next;
		}
	}
	return -1;
}

template <class T>
inline int LinkedNode<T>::getSize() {
	return size;
}