/*
	Basic implementation of Linked Lists
	11/1/2016
	Oyashi
*/

#include <iostream>
#include "Node\LinkedList.h"

using namespace std;

int main() {
	int input = 1;
	int position;
	LinkedList list(input);
	list.displayList();

	//Keep on adding the list until input < 0
	while (input >= 0) {
		cout << "Please enter the element to append :"; cin >> input;
		if (input >= 0) {
			list.appendList(input);
			list.displayList();
		}
	}

	cout << "Please enter the index to remove element :"; cin >> position;
	list.removeAt(position);
	list.displayList();

	cout << "Please enter the index to check its value :"; cin >> position;
	cout << list.getValueOf(position) << endl;
	list.~LinkedList();
}