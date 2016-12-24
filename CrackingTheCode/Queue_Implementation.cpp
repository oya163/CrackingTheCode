/*
	Generic Queue Implementation
	Oyashi
	12/22/2016
*/

#include <iostream>
#include "GenericQueue.h"

using namespace std;

int main() {
	Queue<int> queue;
	queue.enqueue(5);
	queue.enqueue(6);
	queue.enqueue(7);
	queue.display();

	queue.dequeue();
	queue.display();
	queue.~Queue();
}