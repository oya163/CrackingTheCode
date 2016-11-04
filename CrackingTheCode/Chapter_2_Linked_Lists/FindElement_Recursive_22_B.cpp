/*
	Fine kth to the last element in the list
	using recursive method
	11/03/2016
	Oyashi
*/

#include <iostream>
#include <string>

using namespace std;

//Generic struct for node
template <class T>
struct Node
{
	T data;
	Node<T> *next;
	Node<T>() : data(), next() {}

	Node<T>(T d) {
		this->data = d;
		this->next = NULL;
	}
};

//Generic class for recursive method
//uses Nodes as parameter
template <class T>
class RecursiveMethod {
private:
	int size = 0;

public:
	//Appends the list
	void append(Node<T>* head, T val) {
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
	int nthToLast(Node<T>* head, int k) {
		if (head == NULL) {
			return 0;
		}
		int i = nthToLast(head->next, k) + 1;
		if (i == k) {
			cout << head->data << endl;
		}
		return i;
	}

	//Prints the values of list
	void display(Node<T>* head) {
		Node<T>* curr = head;
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};


int main() {
	int input = 1;
	int k = 0;

	RecursiveMethod<int> recur;
	Node<int>* newNode = new Node<int>();
	
	//Builds the list with the inputs
	while (input > 0) {
		cin >> input;
		recur.append(newNode, input);
		recur.display(newNode);
	}

	cout << "Please enter the kth position :"; cin >> k;
	if (k >= 0) {
		int counter = recur.nthToLast(newNode,k);
	}
	delete newNode;
}