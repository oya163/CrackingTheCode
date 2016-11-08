#pragma once
#ifndef __NODELIST_h__
#define __NODELIST_h__

template<class T>
class NodeList {
private:
	T data;
	NodeList<T>* next;
	int size = 0;

public:
	NodeList<T>* head;
	NodeList<T>();
	NodeList<T>(T d);
	~NodeList<T>();
	NodeList<T>* insert(NodeList<T>* &headNode, T val);
	NodeList<T>* remove(NodeList<T>* &headNode, T val);
	NodeList<T>* append(NodeList<T>* &headNode, T val);
	void display(NodeList<T>* const &headNode);
	int getSize(NodeList<T>* const &headNode);
};

#endif // !__NODELIST_h__

template <class T>
inline NodeList<T>::NodeList(){
	head = NULL;
}

template <class T>
inline NodeList<T>::NodeList(T d) {
	data = d;
	next = NULL;
}

template<class T>
inline NodeList<T>::~NodeList(){
	NodeList<T>* current = head;
	while (current) {
		NodeList<T>* temp = current;
		delete current;
		current = current->next;
	}
	head = NULL;
}

template <class T>
inline void NodeList<T>::display(NodeList<T>* const &headNode) {
	NodeList<T>* current = headNode;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
}

template <class T>
inline NodeList<T>* NodeList<T>::insert(NodeList<T>* &headNode, T val) {
	NodeList<T>* newNode = new NodeList(val);
	if (headNode == NULL) {
		headNode = newNode;
	}
	else {
		newNode->next = headNode;
		headNode = newNode;
	}
	size++;
	return headNode;
}

template <class T>
inline int NodeList<T>::getSize(NodeList<T>* const &headNode) {
	return size;
}



