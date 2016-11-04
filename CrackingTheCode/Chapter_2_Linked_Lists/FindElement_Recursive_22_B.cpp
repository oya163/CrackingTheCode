/*
	Fine kth to the last element in the list
	using recursive method
	11/03/2016
	Oyashi
*/

#include <iostream>
#include <string>
#include "Node\LinkedNode.h"

using namespace std;

int main() {
	int input = 1;
	int k = 0;

	LinkedNode<int> recur;
	Node<int>* newNode = new Node<int>();
	
	//Builds the list with the inputs
	while (input > 0) {
		cout << "Input to apped into the list: "; cin >> input;
		recur.append(newNode, input);
		recur.display(newNode);
	}

	cout << "Please enter the kth position :"; cin >> k;
	if (k >= 0) {
		int counter = recur.nthToLast(newNode,k);
	}
	delete newNode;
}