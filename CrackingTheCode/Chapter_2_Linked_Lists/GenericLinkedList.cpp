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

public:
	LinkedList() {
		head->data = " ";
		head->next = NULL;
	}

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
	}

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
	}

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
	}

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
	}

	void display() {
		Node<T>* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};

int main() {
	string inputString = "  ";
	int inputInt = 1;
	LinkedList<string> myList;
	while (!inputString.empty()) {
		getline(cin, inputString);
		myList.insert(inputString);
		myList.display();
		getline(cin, inputString);
		myList.append(inputString);
		myList.display();
		getline(cin, inputString);
		cin >> inputInt;
		myList.insertAt(inputString, inputInt);
		myList.display();

	}
	myList.~LinkedList();
}