/*
	Write code to partition a linked list around a value x, such that all nodes less than x
	come before alt nodes greater than or equal to x.
	11/05/2016
	Oyashi
*/

#include <iostream>
#include "Node\LinkedNode.h"

using namespace std;

template <class T>
void linkPartition(Node<T>* &head, int x) {
	LinkedNode<T>* firstList = new LinkedNode<T>();
	LinkedNode<T>* secondList = new LinkedNode<T>();

	Node<T>* current = head;
	while (current) {
		if (current->data < x) {
			firstList->append(current->data);
		}
		else {
			secondList->append(current->data);
		}
		current = current->next;
	}
	firstList->display();
	secondList->display();
}

int main() {
	Node<int>* head = new Node<int>(5);
	LinkedNode<int>* newList = new LinkedNode<int>(head);
	int partAt = 0;

	newList->append(7);
	newList->append(8);
	newList->append(2);
	newList->append(3);
	newList->append(5);
	newList->append(6);

	newList->display();

	cout << "Input the x: "; cin >> partAt;

	if (newList->getIndexOf(head, partAt) >= 0) {
		linkPartition(head, partAt);
	}
}