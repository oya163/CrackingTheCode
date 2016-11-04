/*
	Basic implementation of Linked Lists
	11/1/2016
	Oyashi
*/

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

class LinkedList {
private:
	Node *head = new Node();
	int size = 0;

public:
	//Constructor with no parameter
	LinkedList() {
		head->data = 0;
		head->next = NULL;
	}

	//Constructor with parameter
	LinkedList(int val) {
		head->data = val;
		head->next = NULL;
		size++;
	}

	//Destructor
	~LinkedList() {
		Node* current = head;
		Node* temp = head;
		while (current != NULL) {
			temp = current->next;
			delete current;
			current = temp;
		}
		head = NULL;
	}

	//Insert element at beginning
	bool insert(int val) {
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
	bool appendList(int val) {
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
	bool insertAt(int val, int pos) {
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
	bool removeAt(int pos) {
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
	int getSize() {
		return size;
	}


	//Returns the value of element at specified index
	int getValueOf(int index) {
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
	void displayList() {
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
};

int main() {
	int input = 1;
	int position;
	LinkedList list(input);
	list.displayList();

	//Keep on adding the list until input < 0
	while (input >= 0) {
		cout << "Please enter the element to append :"; cin >> input;
		if (input >= 0) {
			list.appendList(input);
			list.displayList();
		}
	}

	cout << "Please enter the index to remove element :"; cin >> position;
	list.removeAt(position);
	list.displayList();

	cout << "Please enter the index to check its value :"; cin >> position;
	cout << list.getValueOf(position) << endl;
	list.~LinkedList();
}