#include "Queue.h"
#pragma once

Queue::Queue()
{
	front = NULL;
	rear = NULL;
}

Queue::~Queue()
{

}

bool Queue::isEmpty()
{
	if (front = rear = NULL)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void Queue::enqueue(int n)
{
	QNode* temp = new QNode();
	temp->key = n;
	temp->next = NULL;

	if (isEmpty())
	{
		front = rear = temp;
	}

	else
	{
		rear->next = temp;
		rear = temp;
	}
}

void Queue::dequeue()
{
	if (isEmpty())
	{
		return;
	}

	else if (front == rear)
	{
		front = rear = NULL;
	}

	else
	{
		QNode* temp = new QNode();
		temp = front;

		front = temp->next;
		temp->next = NULL;
		delete temp;
	}
}