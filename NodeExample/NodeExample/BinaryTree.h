#ifndef BINARYTREE_
#define BINARYTREE_

#include <iostream>
#include <string>
#include "TNode.h"

using namespace std;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void addNode(int key);
	void deleteNode(int key);
	void printTree(const string& prefix, const TNode* root, bool isLeft);
	bool isEmpty();
	bool searchKey(int key);
	const TNode* getRoot();

private:
	TNode* root;
};

#endif