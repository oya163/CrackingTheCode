/*
	Finding kth to the last element in the List
	using iterative method
	11/03/2016
	Oyashi
*/

#include <iostream>
#include <string>
#include "Node\GenericLinkedList.h"

using namespace std;

int main() {
	int input = 1;
	int k = 0;
	GenericLinkedList<int> myList;

	//Builds the list with the inputs
	while (input > 0) {
		cin >> input;
		myList.insert(input);
		myList.display();
	}

	cout << "Please enter the kth position :"; cin >> k;
	if (k >= 0) {
		cout << "The kth element from the last is :" << myList.find_K_Element(k) << endl;
	}
	myList.~GenericLinkedList();
}