/*
	Implement an algorithm to delete a node in the middle of a singly linked list, given
	only access to that node.
	11/03/2016
	Oyashi
*/

#include <iostream>
#include "Node\LinkedNode.h"

using namespace std;

int main() {
	int input = 1;
	LinkedNode<int> node;
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