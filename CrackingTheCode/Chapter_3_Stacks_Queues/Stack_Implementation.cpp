/*
	Implementation of Stack
	12/21/2016
	Oyashi
*/

#include <iostream>
#include <string>
#include "GenericStack.h"

using namespace std;

int main() {
	GenericStack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	stack.display();

	cout << "Top item = ";
	stack.peek();

	stack.pop();
	stack.display();
	stack.~GenericStack();
}