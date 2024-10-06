#include "Stack.h"

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{

}

bool Stack::isEmpty()
{
	if (top == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void Stack::push(int n)
{
	StackNode* temp = new StackNode();
	temp->key = n;
	temp->next = NULL;

	if (isEmpty())
	{
		top = temp;
	}

	else
	{
		temp->next = top;
		top = temp;
	}
}

void Stack::pop()
{
	if (isEmpty())
	{
		return;
	}

	else
	{
		StackNode* temp = new StackNode();
		temp = top;
		top = temp->next;
		temp->next = NULL;
		delete temp;
	}
}

void Stack::printStack()
{
	if (isEmpty())
	{
		return;
	}

	else
	{
		StackNode* temp = new StackNode;
		temp = top;

		while (temp != NULL)
		{
			std::cout << temp->key << std::endl;
			temp = temp->next;
		}
	}
}

int Stack::peek()
{
	if (isEmpty())
	{
		return NULL;
	}
	
	else
	{
		return top->key;
	}
}