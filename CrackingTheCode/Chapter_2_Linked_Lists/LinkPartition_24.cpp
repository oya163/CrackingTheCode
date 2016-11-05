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
	LinkedNode<T> firstList;
	LinkedNode<T> secondList;

	Node<T>* current = head;
	while (current) {
		if (current->data < x) {
			firstList.append(current, current->data);
		}
		else {
			secondList.append(current, current->data);
		}
		current = current->next;
	}
}

int main() {
	Node<int>* head = new Node<int>(5);
	LinkedNode<int> newList;
	int partAt = 0;

	newList.append(head, 7);
	newList.append(head, 8);
	newList.append(head, 2);
	newList.append(head, 3);
	newList.append(head, 5);
	newList.append(head, 6);

	newList.display(head);

	cout << "Input the x: "; cin >> partAt;

	if (newList.getIndexOf(head, partAt) >= 0) {
		linkPartition(head, partAt);
	}
}