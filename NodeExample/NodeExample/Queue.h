#include <iostream>
#include "QNode.h"
#pragma once

class Queue
{
private:
	QNode* front;
	QNode* rear;

public:
	Queue();
	~Queue();
	void enqueue(int n);
	void dequeue();
	void showFront();
	bool isEmpty();
};