/*
	Basic Implementation of Circular Linked List
	11/07/2016
	Oyashi
*/

#include <iostream>
#include "Node\CircularLinkedList.h"

using namespace std;

int main() {
	//Create a Circular Linked List
	CircularLinkedList* circNode = new CircularLinkedList(7);

	//Insert the value in the list at head
	circNode->insert(6);

	//Append the value in the list at tail
	circNode->append(8);
	circNode->append(9);

	//Remove the given value from the list
	circNode->remove(8);

	//Display the entire list
	circNode->display();

	//Destructor
	circNode->~CircularLinkedList();
}