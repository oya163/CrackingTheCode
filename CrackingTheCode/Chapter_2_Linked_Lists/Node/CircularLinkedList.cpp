#include <iostream>
#include "CircularLinkedList.h"

//Constructor with no parameter
CircularLinkedList::CircularLinkedList()
{
	head = NULL;
	tail = NULL;
}

//Constructor with value parameter
CircularLinkedList::CircularLinkedList(int val)
{
	head = tail = new Node(val);
}

//Destructor
CircularLinkedList::~CircularLinkedList()
{
	Node* curr = head;
	while (curr != tail) {
		Node* temp = curr->next;
		delete curr;
		curr = temp;
	}
	head = 0;
}

//Inserts the value at the head of the list
Node* CircularLinkedList::insert(int val) {
	Node* newNode = new Node(val);
	if (head == NULL || tail == NULL) {
		CircularLinkedList(val);
	}
	else {
		newNode->next = head;
		tail->next = newNode;
		head = newNode;
	}
	return head;
}

//Appends the value at the tail of the list
Node* CircularLinkedList::append(int val) {
	Node* newNode = new Node(val);
	if (head == NULL || tail == NULL) {
		CircularLinkedList(val);
	}
	else {
		tail->next = newNode;
		newNode->next = head;
		tail = newNode;
	}
	return head;
}

//Removes the value from the list
Node* CircularLinkedList::remove(int val) {
	if (head == NULL || tail == NULL) {
		return NULL;
	}
	else {
		Node* left = head;
		Node* right = head;
		while (right != tail) {
			if (right->data == val) {
				left->next = right->next;
				delete right;
				right = left->next;
			}
			left = right;
			right = right->next;
		}
	}
	return head;
}

//Displays the entire list
void CircularLinkedList::display() {
	Node* curr = head;
	while (curr != tail) {
		std::cout << curr->data << " ";
		curr = curr->next;
	}
	std::cout << curr->data << std::endl;
}

//Returns the size of the list
int CircularLinkedList::getSize() {
	return size;
}