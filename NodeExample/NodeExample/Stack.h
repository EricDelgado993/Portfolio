#include <iostream>
#include "StackNode.h"
#pragma once

class Stack
{
private:
	StackNode* top;

public:
	Stack();
	~Stack();
	void push(int n);
	void pop();
	bool isEmpty();
	void printStack();
	int peek();
};