/*
	Write code to partition a linked list around a value x, such that all nodes less than x
	come before alt nodes greater than or equal to x.
	11/05/2016
	Oyashi
*/

#include <iostream>
#include "Node\LinkedNode.h"

using namespace std;

//Returns merged list after partition at given value
template <class T>
LinkedNode<T>* linkPartition(Node<T>* &head, int x) {
	LinkedNode<T>* lowerList = new LinkedNode<T>();
	LinkedNode<T>* greaterList = new LinkedNode<T>();
	LinkedNode<T>* equalList = new LinkedNode<T>();
	LinkedNode<T>* mergedList = new LinkedNode<T>();

	Node<T>* current = head;
	while (current) {
		if (current->data < x) {
			lowerList->append(current->data);
		}
		else if (current->data == x) {
			equalList->append(current->data);
		}
		else {
			greaterList->append(current->data);
		}
		current = current->next;
	}
	mergedList = mergedList->mergeList(lowerList, equalList);
	return mergedList->mergeList(mergedList, greaterList);
}

int main() {
	Node<int>* head = new Node<int>(5);
	LinkedNode<int>* newList = new LinkedNode<int>(head);
	LinkedNode<int>* finalList = new LinkedNode<int>();
	int partAt = 0;

	newList->append(7);
	newList->append(8);
	newList->append(2);
	newList->append(3);
	newList->append(5);
	newList->append(6);

	cout << "Initial list: " << endl;
	newList->display();

	cout << "Input the x: "; cin >> partAt;

	cout << "After partition and merge list: " << endl;
	if (newList->getIndexOf(head, partAt) >= 0) {
		finalList = linkPartition(head, partAt);
		finalList->display();
	}
}