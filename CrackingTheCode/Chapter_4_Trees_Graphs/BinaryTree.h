#pragma once
#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include <queue>

template <class T>
struct Node {
	T data;
	Node<T>* left;
	Node<T>* right;

	Node<T>() {
		data = NULL;
		left = NULL;
		right = NULL;
	}

	Node<T>(T val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

template <class T>
class BinaryTree {
private:
	Node<T>* root;
	void insertNode(Node<T>* &root, T val);
	void destroyTree(Node<T>* root);
	void inOrder(Node<T>* root);
	void preOrder(Node<T>* root);
	void postOrder(Node<T>* root);
	void levelOrder(Node<T>* root);
	Node<T>* searchTree(Node<T>* root, T val);
	Node<T>* removeNode(Node<T>* root, T val);
	Node<T>* findMin(Node<T>* root);
	Node<T>* findMax(Node<T>* root);

public:

	BinaryTree();
	~BinaryTree();
	Node<T>* create(T val);
	void insert(T val);
	void inOrderTraverse();
	void preOrderTraverse();
	void postOrderTraverse();
	void levelOrderTraverse();
	void find(T val);
	void findMin();
	void findMax();
	void remove(T val);
	
};
#endif // !__BINARYTREE_H__

template <class T>
inline BinaryTree<T>::BinaryTree() {
	root = NULL;
}

template <class T>
inline BinaryTree<T>::~BinaryTree() {
	if (root == NULL) return;
	destroyTree(root);
}

template <class T>
inline void BinaryTree<T>::destroyTree(Node<T>* root) {
	if (root) {
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
	}
}

template <class T>
inline Node<T>* BinaryTree<T>::create(T val) {
	root->data = val;
	root->left = NULL;
	root->right = NULL;
	return root;
}

template <class T>
inline void BinaryTree<T>::insert(T val) {
	insertNode(root, val);
}

template <class T>
inline void BinaryTree<T>::insertNode(Node<T>* &root, T val) {
	if (root == NULL) {
		Node<T>* newNode = new Node<T>(val);
		root = newNode;
	}
	else if (val < root->data) {
		insertNode(root->left, val);
	}
	else {
		insertNode(root->right, val);
	}
}

template <class T>
inline void BinaryTree<T>::inOrderTraverse() {
	inOrder(root);
}

template <class T>
inline void BinaryTree<T>::inOrder(Node<T>* root) {
	if (root == NULL) return;
	inOrder(root->left);
	cout << root->data << "->";
	inOrder(root->right);
}

template <class T>
inline void BinaryTree<T>::preOrderTraverse() {
	preOrder(root);
}

template <class T>
inline void BinaryTree<T>::preOrder(Node<T>* root) {
	if (root == NULL) return;
	cout << root->data << "->";
	preOrder(root->left);
	preOrder(root->right);
}

template <class T>
inline void BinaryTree<T>::postOrderTraverse() {
	postOrder(root);
}

template <class T>
inline void BinaryTree<T>::postOrder(Node<T>* root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << "->";
}

template <class T>
inline void BinaryTree<T>::find(T val) {
	Node<T>* foundNode = searchTree(root, val);
	if (foundNode)
		cout << "Node found\n";
	else
		cout << "Node not found\n";
}

template <class T>
inline Node<T>* BinaryTree<T>::searchTree(Node<T>* root, T val) {
	if (root == NULL) return NULL;
	if (val == root->data) return root;
	if (val < root->data)
		return searchTree(root->left, val);
	else
		return searchTree(root->right, val);
}

template <class T>
inline void BinaryTree<T>::levelOrderTraverse() {
	levelOrder(root);
}

template <class T>
inline void BinaryTree<T>::levelOrder(Node<T>* root) {
	queue<Node<T>*> bfs;
	if (root) bfs.push(root);
	while (!bfs.empty()) {
		Node<T>* temp = bfs.front();
		bfs.pop();
		cout << temp->data << "->";
		if (temp->left) bfs.push(temp->left);
		if (temp->right) bfs.push(temp->right);
	}
}

template <class T>
inline void BinaryTree<T>::remove(T val) {
	Node<T>* removedNode = removeNode(root, val);
	if (removedNode) {
		cout << "Node removed successfully" << endl;
	}
	else {
		cout << "Node not found" << endl;
	}
}

template <class T>
inline Node<T>* BinaryTree<T>::removeNode(Node<T>* root, T val) {
	//Lookup for the node to be removed recursively
	if (root == NULL && searchTree(root, val) == NULL) { return NULL; }
	else if (val < root->data) { root->left = removeNode(root->left, val); }
	else if (val > root->data) { root->right = removeNode(root->right, val); }
	//When the node is found
	else {
		//First case: when the node has no childs
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Second case: when the node has only right child
		else if (root->left == NULL) {
			Node<T>* temp = root;
			root = root->right;
			delete temp;
		}
		//Second case: when the node has only left child
		else if (root->right == NULL) {
			Node<T>* temp = root;
			root = root->left;
			delete temp;
		}
		//Third case: when the node has both child
		else {
			Node<T>* min = findMin(root->right);
			root->data = min->data;
			root->right = removeNode(root->right, min->data);
		}
	}
	return root;
}

template <class T>
inline Node<T>* BinaryTree<T>::findMin(Node<T>* root) {
	if (root == NULL) return NULL;
	while (root->left != NULL) {
		root = findMin(root->left);
	}
	return root;
}

template <class T>
inline void BinaryTree<T>::findMin() {
	Node<T>* minNode = findMin(root);
	if (minNode) {
		cout << "Minimum node value = " << minNode->data << endl;
	}
}

template <class T>
inline Node<T>* BinaryTree<T>::findMax(Node<T>* root) {
	if (root == NULL) return NULL;
	while (root->right != NULL) {
		root = findMax(root->right);
	}
	return root;
}

template <class T>
inline void BinaryTree<T>::findMax() {
	Node<T>* maxNode = findMax(root);
	if (maxNode) {
		cout << "Maximum node vale = " << maxNode->data << endl;
	}
}