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
	int size = 0;

public:
	LinkedNode<T>();
	~LinkedNode<T>();
	void insert(Node<T>* &head, T val);
	void display(Node<T>* &head);
	bool removeNode(Node<T>* &node);
	void append(Node<T>* head, T val);
	int nthToLast(Node<T>* head, int k);
};

#endif 

template <class T>
inline LinkedNode<T>::LinkedNode() {
	this->head = NULL;
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
inline void LinkedNode<T>::display(Node<T>* &head) {
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
inline void LinkedNode<T>::append(Node<T>* head, T val) {
	if (head == NULL) {
		head->data = val;
		head->next = NULL;
	}
	else {
		Node<T>* current = head;
		Node<T>* newNode = new Node<T>(val);
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


