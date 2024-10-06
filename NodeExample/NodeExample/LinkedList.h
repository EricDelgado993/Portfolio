#include <iostream>
#include "LinkedNode.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
private:
	LinkedNode* head;

public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
	void insertNode(int key);
	void deleteNode(int key);
	bool search(int key);
	void printList();

};

#endif