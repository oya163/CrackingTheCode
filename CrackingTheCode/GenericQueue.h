#pragma once
#ifndef __GENERICQUEUE_h__
#define __GENERICQUEUE_h__

template <class T>
struct Node
{
	T data;
	Node<T>* next;

	Node() : data(), next(NULL) {}
	Node(T d) : data(d), next(NULL) {}

};

template <class T>
class Queue {
private:
	Node<T>* head = new Node<T>();

public:
	Queue();
	Queue(T val);
	~Queue();
	void enqueue(T val);
	void dequeue();
	void display();
};
#endif // !__GENERICQUEUE_h__

template <class T>
inline Queue<T>::Queue() {
	head = NULL;
}

template <class T>
inline Queue<T>::Queue(T val) {
	if (head == NULL) {
		head = new Node<T>(val);
	}
	else {
		Node<T>* curr = head;
		Node<T>* newNode = new Node<T>(val);
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

template <class T>
inline Queue<T>::~Queue(){
	if (head != NULL) {
		Node<T>* curr = head;
		while (curr->next) {
			Node<T>* temp = curr->next;
			delete curr;
			curr = temp;
		}
		head = NULL;
	}
}

template <class T>
inline void Queue<T>::enqueue(T val) {
	if (head == NULL) {
		head = new Node<T>(val);
	}
	else {
		Node<T>* curr = head;
		Node<T>* newNode = new Node<T>(val);
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

template <class T>
inline void Queue<T>::dequeue() {
	if (head != NULL) {
		Node<T>* curr = head;
		head = curr->next;
		delete curr;
	}
}

template <class T>
inline void Queue<T>::display() {
	Node<T>* curr = head;
	while (curr) {
		cout << curr->data << "->";
		curr = curr->next;
	}
	cout << endl;
}


