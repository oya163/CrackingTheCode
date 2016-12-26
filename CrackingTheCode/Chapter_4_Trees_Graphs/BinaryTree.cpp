/*
	Implementation of Binary Tree
	12/23/2016
	Oyashi
*/

#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree<int> binaryTree;

	binaryTree.insert(10);
	binaryTree.insert(6);
	binaryTree.insert(14);
	binaryTree.insert(5);
	binaryTree.insert(8);
	binaryTree.insert(11);
	binaryTree.insert(18);

	cout << "In Order Traversal : ";
	binaryTree.inOrderTraverse();
	cout << endl;
	
	cout << "Pre Order Traversal : ";
	binaryTree.preOrderTraverse();
	cout << endl;

	cout << "Post Order Traversal : ";
	binaryTree.postOrderTraverse();
	cout << endl;

	cout << "Find node 21" << endl;
	binaryTree.find(21);

	cout << "Level Order Traversal : ";
	binaryTree.levelOrderTraverse();

	cout << endl;
	cout << "Remove node 10" << endl;
	binaryTree.remove(10);
	cout << endl;

	cout << "After node removal, Level Order Traversal : " << endl;
	binaryTree.levelOrderTraverse();
	cout << endl;
	
	binaryTree.findMin();
	binaryTree.findMax();

	binaryTree.~BinaryTree();

}