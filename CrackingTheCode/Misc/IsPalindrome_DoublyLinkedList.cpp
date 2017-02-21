/*
	Check whether the given doubly linked list
	is palindrome or not
	02/21/2017
	Oyashi
*/

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next, *prev;
};

class DoublyLinkedList {
private:
	Node *head = NULL;

public:
	DoublyLinkedList(int val) {
		if (head == NULL) {
			head = new Node;
			head->data = val;
			head->next = NULL;
			head->prev = NULL;
		}
		else {
			Node *newNode = new Node;
			Node *curr = head;
			while (curr->next != NULL) {
				curr = curr->next;
			}
			newNode->prev = curr;
			newNode->next = NULL;
			newNode->data = val;
			curr->next = newNode;
		}
	}

	void insert(int val) {
		Node *newNode = new Node;
		Node *curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		newNode->prev = curr;
		newNode->next = NULL;
		newNode->data = val;
		curr->next = newNode;
	}

	bool isPalindrome() {
		Node *curr = head, *tail = head;
		if (curr == NULL) return false;
		if (curr->next == NULL) return false;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		while (curr != tail) {
			if (curr->data != tail->data) {
				return false;
			}
			else {
				curr = curr->next;
				tail = tail->prev;
			}
		}
		return true;
	}
};

int main() {
	DoublyLinkedList dll = DoublyLinkedList(5);
	dll.insert(7);
	dll.insert(5);
	dll.insert(9);
	if (dll.isPalindrome())
		cout << "Yes palindrome" << endl;
	else
		cout << "Not palindrome" << endl;
}