/*
	Implement an algorithm to delete a node in the middle of a singly linked list, given
	only access to that node.
	11/03/2016
	Oyashi
*/

#include <iostream>

using namespace std;

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
class NodeClass {
public:
	void insert(Node<T>* &head, T val) {
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

	void display(Node<T>* &head) {
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

	bool removeNode(Node<T>* &node) {
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

};

int main() {
	int input = 1;
	NodeClass<int> node;
	Node<int>* newNode = new Node<int>();
	while (input > 0) {
		cin >> input;
		node.insert(newNode, input);
		node.display(newNode);
	}
	node.removeNode(newNode);
	node.display(newNode);
	delete newNode;

}