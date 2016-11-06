/*
	You have two numbers represented by a linked list, where each node contains a
	single digit. The digits are stored in reverse order, such that the 1 's digit is at the data
	of the list. Write a function that adds the two numbers and returns the sum as a
	linked list.
	FOLLOW UP
	Suppose the digits are stored in forward order. Repeat the above problem.

	11/05/2016
	Oyashi
*/

#include <iostream>
#include "Node\LinkedNode.h"

using namespace std;

//Add the node when the numbers are 
//stored in reverse order
template <class T>
Node<T>* addEachNode (const Node<T>* const&firstList, const Node<T>* const&secondList, T carry){
	Node<T>* result = new Node<T>(0);

	if (firstList == NULL && secondList == NULL && carry == 0) {
		return result;
	}

	T value = carry;
	if (firstList != NULL) {
		value += firstList->data;
	}

	if (secondList->data != NULL) {
		value += secondList->data;
	}

	result->data = (value % 10);

	if (firstList != NULL || secondList != NULL) {
		Node<T>* next = addEachNode(firstList == NULL ? NULL : firstList->next,
			secondList == NULL ? NULL : secondList->next, (value / 10));
		result->setNext(next);
	}
	return result;
}

int main() {
	Node<int>* firstList = new Node<int>(7);
	firstList->next = new Node<int>(1);
	firstList->next->next = new Node<int>(6);

	Node<int>* secondList = new Node<int>(5);
	secondList->next = new Node<int>(9);
	secondList->next->next = new Node<int>(2);

	Node<int>* result = addEachNode(firstList, secondList, 0);

	while (result) {
		cout << result->data << "->";
		result = result->next;
	}
}
