#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	delete root;
}

void BinaryTree::addNode(int key)
{
	TNode* newNode = new TNode();
	TNode* temp = new TNode();
	TNode* parent = new TNode();

	newNode->key = key;

	if (root == NULL)
	{
		root = newNode;
	}

	else
	{
		temp = root;
		parent = NULL;
	}

	while (temp != NULL)
	{
		if (newNode->key == temp->key)
		{
			return;
		}

		else if (newNode->key < temp->key)
		{
			parent = temp;
			temp = temp->left;
		}

		else
		{
			parent = temp;
			temp = temp->right;
		}
	}

	if (newNode->key < parent->key)
	{
		parent->left = newNode;
	}

	else
	{
		parent->right = newNode;
	}

	newNode = NULL;
	temp = NULL;
	parent = NULL;

	delete newNode;
	delete temp;
	delete parent;
}

void BinaryTree::deleteNode(int key)
{
	TNode* temp = new TNode();
	TNode* back = new TNode();
	TNode* max = new TNode();
	TNode* maxParent = new TNode();

	temp = root;
	back = NULL;

	// Preform search operation
	// Locate node to be deleted
	while ((temp != NULL) && key != (temp->key))
	{
		back = temp;

		if (key < temp->key)
		{
			temp = temp->left;
		}

		else
		{
			temp = temp->right;
		}
	}

	// Node not found in tree or empty tree
	if (temp == NULL)
	{
		return;
	}

	// Case 1: Leaf node
	if (temp->left == NULL && temp->right == NULL)
	{
		if (temp == root)
		{
			root = NULL;
		}

		else if (temp == back->left)
		{
			back->left = NULL;
		}

		else
		{
			back->right = NULL;
		}
		delete temp;
	}

	// Case 2: Node with one child on right
	else if (temp->left == NULL)
	{
		if (temp == root)
		{
			root = temp->right;
		}

		else if (temp == back->left)
		{
			back->left = temp->right;
		}

		else
		{
			back->right = temp->right;
		}

		temp->right = NULL;
		delete temp;
	}

	// One child on left
	else if (temp->right == NULL)
	{
		if (temp == root)
		{
			root = temp->left;
		}

		else if (temp == back->left)
		{
			back->left = temp->left;
		}

		else
		{
			back->right = temp->left;
		}

		temp->left = NULL;
		delete temp;
	}

	// Case 3: Node with two children
	else
	{
		maxParent = temp;
		max = temp->right;

		while (max->left != NULL)
		{
			maxParent = max;
			max = max->left;
		}

		if (maxParent != temp)
		{
			maxParent->left = max->right;
			max->right = temp->right;
		}

		max->left = temp->left;

		if (temp == root)
		{
			root = max;
		}

		else if (temp == back->left)
		{
			back->left = max;
		}

		else
		{
			back->right = max;
		}

		temp->left = NULL;
		temp->right = NULL;
		delete temp;
	}

	back = NULL;
	max = NULL;
	maxParent = NULL;

	delete back;
	delete max;
	delete maxParent;
}

void BinaryTree::printTree(const string& prefix, const TNode* root, bool isLeft)
{
	if (root != NULL)
	{
		cout << prefix;

		cout << (isLeft ? "\u00C3\u00C4\u00C4" : "\u00C0\u00C4\u00C4");

		cout << root->key << endl;

		printTree(prefix + (isLeft ? "\u00B3   " : "    "), root->right, true);
		printTree(prefix + (isLeft ? "\u00B3   " : "    "), root->left, false);
	}
}

bool BinaryTree::isEmpty()
{
	return root == NULL;
}

bool BinaryTree::searchKey(int key)
{
	TNode* temp = new TNode();

	temp = root;

	while (temp != NULL)
	{
		if (key == temp->key)
		{
			return true;
		}

		else if (key < temp->key)
		{
			temp = temp->left;
		}

		else
		{
			temp = temp->right;
		}
	}

	temp = NULL;
	delete temp;
	return false;
}

const TNode* BinaryTree::getRoot()
{
	return root;
}