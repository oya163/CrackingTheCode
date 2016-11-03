/*
	Basic Implementation of Generic Linked List
	11/03/2016
	Oyashi
*/

#include <iostream>
#include <string>

using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T> *next;
	Node<T>() : data(), next() {}
	Node<T>(T d) : data(d), next() {}
};

template <class T>
class LinkedList {
private:
	Node<T>* head = new Node<T>();
	int size = 0;

public:
	//Construction without parameter
	LinkedList() {
		head->data = NULL;
		head->next = NULL;
	}


	//Constructor with parameter
	LinkedList(T val) {
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
		size++;
	}

	//Destructor
	~LinkedList() {
		Node<T>* current = head;
		Node<T>* temp = head;
		while (current) {
			temp = current->next;
			delete current;
			current = temp;
		}
		head = NULL;
	}

	//Inserts an element in beginning
	void insert(T val) {
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

	//Appends the list
	void append(T val) {
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
	void insertAt(T val, int pos) {
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
	void display() {
		Node<T>* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}

	//Returns Kth to the last element
	T find_K_Element(int k) {
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
};

int main() {
	int input = 1;
	int k = 0;
	LinkedList<int> myList;

	//Builds the list with the inputs
	while (input > 0) {
		cin >> input;
		myList.insert(input);
		myList.display();
	}

	cout << "Please enter the kth position :"; cin >> k;
	if (k >= 0) {
		cout << myList.find_K_Element(k) << endl;;
	}
	myList.~LinkedList();
}