///*
//	You have two numbers represented by a linked list, where each node contains a
//	single digit. The digits are stored in forward order. Write a function that adds the two numbers and returns the sum as a
//	linked list.
//
//	11/06/2016
//	Oyashi
//*/
//
//#include <iostream>
//#include "Node\LinkedNode.h"
//#include "Node\NodeList.h"
//
//using namespace std;
//
////Wrapper class 
//template <class T>
//class PartialSum {
//public:
//	Node<T>* sum = new Node<T>(NULL);
//	int carry = 0;
//};
//
////Add the node when the numbers are 
////stored in reverse order
//template <class T>
//Node<T>* addEachNode(Node<T>* &firstList, Node<T>* &secondList) {
//	int lenFirst = firstList->nodeSize;
//	int lenSecond = secondList->nodeSize;
//
//	//Check whether both lists are of same size
//	//Otherwise, pad the smallest one with zeros
//	if (lenFirst < lenSecond) {
//		firstList = padList(firstList, lenSecond - lenFirst);
//	}else {
//		secondList = padList(secondList, lenFirst - lenSecond);
//	}
//
//	PartialSum<T> Sum = addListsHelper(firstList, secondList);
//
//	//If carry value is left, then insert it as a node in front
//	if (Sum.carry == 0) {
//		return Sum.sum;
//	}else {
//		Node<T>* result = insert(Sum.sum, Sum.carry);
//		return result;
//	}
//}
//
//
////Reach the 1's digit first
////Then keep on adding them recursively
//template <class T>
//PartialSum<T> addListsHelper(Node<T>* const &firstList, Node<T>* const &secondList) {
//	if (firstList == NULL && secondList == NULL) {
//		PartialSum<T> Sum;
//		return Sum;
//	}
//
//	//Reach the 1's digit node at first
//	PartialSum<T> Sum = addListsHelper(firstList->next, secondList->next);
//
//	//Add the node values
//	T val = Sum.carry + firstList->data + secondList->data;
//
//	//Insert the 1's digit of calculated sum 
//	//into the SUM node of wrapper class
//	Node<T>* finalList = insert(Sum.sum, val % 10);
//
//	//Send the sum node and remaining carry to next recursion round
//	Sum.sum = finalList;
//	Sum.carry = val / 10;
//
//	return Sum;
//}
//
////Pad the list with zeros
//template <class T>
//Node<T>* padList(Node<T>* const &list1, int padding) {
//	Node<T>* head = list1;
//	for (int i = 0; i < padding; i++) {
//		Node<T>* newNode = new Node<T>(0);
//		newNode->next = head;
//		head = newNode;
//	}
//	return head;
//}
//
////Insert node in front
//template <class T>
//Node<T>* insert(Node<T>* &head, T data) {
//	Node<T>* newNode = new Node<T>(data);
//	if (head != NULL) {
//		newNode->next = head;
//		head = newNode;
//	}
//	return head;
//}
//
//
//
//int main() {
//	//Initialization FirstList of numbers
//	Node<int>* firstList = new Node<int>(6);
//	firstList->next = new Node<int>(1);
//	firstList->next->next = new Node<int>(7);
//
//	//Initialization SecondList of numbers
//	Node<int>* secondList = new Node<int>(2);
//	secondList->next = new Node<int>(9);
//	secondList->next->next = new Node<int>(5);
//
//	Node<int>* result = addEachNode(firstList, secondList);
//
//	//I have put result->next
//	//because its printing extra 0
//	while (result->next != NULL) {
//		cout << result->data;
//
//		//Just to format the output
//		if (result->next->next != NULL) {
//			cout << "->";
//		}
//		result = result->next;
//	}
//	cout << endl;
//}
