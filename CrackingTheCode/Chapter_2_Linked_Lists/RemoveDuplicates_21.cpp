/*
	Write code to remove duplicates from an unsorted linked list.
	FOLLOW UP
	How would you solve this problem if a temporary buffer is not allowed?
	11/02/2016
	Oyashi
*/

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

struct Node {
	char data;
	Node* next;
};

class LinkedList {
private:
	Node* head = new Node;

public:
	LinkedList() {
		head->data = NULL;
		head->next = NULL;
	}

	LinkedList(char val) {
		head->data = val;
		head->next = NULL;
	}

	void appendList(char val) {
		if (head == NULL) {
			head->data = val;
			head->next = NULL;
		}
		else {
			Node* newNode = new Node;
			newNode->data = val;
			newNode->next = NULL;
			Node* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newNode;
		}
	}


	void removeDup(string inputString) {
		for (auto& x : inputString) {
			if(x != ' ')
				appendList(x);
		}

		Node* current = head;
		while (current->next != NULL) {
			Node* ahead = current->next;
			Node* prev = current;
			while (ahead != NULL) {
				if (current->data == ahead->data) {
					prev->next = ahead->next;
					delete ahead;
					ahead = prev->next;
				}
				else {
					prev = ahead;
					ahead = ahead->next;
				}
			}
			current = current->next;
		}
	}

	void display() {
		Node* current = head;
		while (current != NULL) {
			cout << current->data << "->";
			current = current->next;
		}
	}
};



int main() {
	string inputString = "folloooow up";
	//cout << "Input the string: "; 
	//getline(cin, inputString);

	LinkedList newList;
	stable_sort(inputString.begin(), inputString.end());
	newList.removeDup(inputString);
	cout << endl;

	newList.display();
	cout << endl;
}