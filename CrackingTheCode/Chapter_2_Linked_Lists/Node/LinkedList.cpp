#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	head->data = 0;
	head->next = NULL;
}


LinkedList::~LinkedList()
{
	Node* current = head;
	Node* temp = head;
	while (current != NULL) {
		temp = current->next;
		delete current;
		current = temp;
	}
	head = NULL;
}

//Constructor with parameter
LinkedList::LinkedList(int val) {
	head->data = val;
	head->next = NULL;
	size++;
}

//Insert element at beginning
bool LinkedList::insert(int val) {
	Node* newNode = new Node();
	newNode->data = val;
	if (head == NULL) {
		head = newNode;
		head->next = NULL;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	size++;
	return true;
}

//Appends element at specified position
bool LinkedList::appendList(int val) {
	Node* newNode = new Node();
	newNode->data = val;
	if (head == NULL) {
		head = newNode;
		head->next = NULL;
	}
	else {
		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
	size++;
	return true;
}

//Inserts element at specified position
bool LinkedList::insertAt(int val, int pos) {
	Node *left, *right;
	left = head;
	right = head;
	if (head == NULL) {
		LinkedList(val);
	}
	else {
		if (pos == 0) {
			insert(val);
		}
		else {
			int currPos = 0;
			Node* newNode = new Node;
			newNode->data = val;
			while (right != NULL) {
				if (currPos == pos) {
					left->next = newNode;
					newNode->next = right;
				}
				left = right;
				right = right->next;
				currPos++;
			}
		}
	}
	size++;
	return true;
}

//Removes element at specified position
bool LinkedList::removeAt(int pos) {
	Node *left, *right;
	left = head;
	right = head;
	if (head == NULL || pos < 0) {
		return false;
	}
	else {
		int currPos = 0;
		while (right != NULL) {
			if (currPos == pos) {
				Node* temp = right->next;
				delete right;
				left->next = temp;
				right = temp;
			}
			left = right;
			right = right->next;
			currPos++;
		}
	}
	size--;
	return true;
}

//Returns the size of the list
int LinkedList::getSize() {
	return size;
}


//Returns the value of element at specified index
int LinkedList::getValueOf(int index) {
	if (head == NULL) {
		return 0;
	}
	else {
		Node* current = head;
		int currPos = 0;
		while (current != NULL) {
			if (currPos == index) {
				return current->data;
			}
			current = current->next;
			currPos++;
		}
	}
}

//Print the whole list
void LinkedList::displayList() {
	if (head->next == NULL) {
		cout << head->data;
	}
	else {
		Node* current = head;
		while (current != NULL) {
			cout << current->data;
			current = current->next;
			if (current)
				cout << "->";
		}
	}
	cout << endl;
	cout << "Size of list = " << getSize() << endl;
}

