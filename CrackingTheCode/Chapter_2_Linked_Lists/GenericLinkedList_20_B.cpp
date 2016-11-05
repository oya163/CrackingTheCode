/*
	Basic Implementation of Generic Linked List
	11/03/2016
	Oyashi
*/

#include <iostream>
#include <string>
#include "Node\GenericLinkedList.h"

using namespace std;

int main() {
	string inputString = " ";
	int inputInt = 1;
	GenericLinkedList<string> myList;

	//Keeps on requesting input, until space is provided
	while (!inputString.empty()) {
		cout << "Input the string to insert into the list: ";
		getline(cin, inputString);
		myList.insert(inputString);
		myList.display();
		cout << "Input the string to append into the list: ";
		getline(cin, inputString);
		myList.append(inputString);
		myList.display();
		cout << "Input the string and position to insert at certain position into the list: ";
		getline(cin, inputString);
		cin >> inputInt;
		myList.insertAt(inputString, inputInt);
		myList.display();
	}
	myList.~GenericLinkedList();
}