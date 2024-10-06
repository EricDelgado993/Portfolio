#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{

}

bool LinkedList::isEmpty()
{
	return (head == NULL);
}

void LinkedList::insertNode(int key)
{
	LinkedNode* newNode = new LinkedNode();
	LinkedNode* temp = new LinkedNode();

	newNode->key = key;
	newNode->next = NULL;

	if (isEmpty())
	{
		head = newNode;
	}

	else
	{
		temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}
}

void LinkedList::deleteNode(int key)
{
	LinkedNode* temp = new LinkedNode();
	LinkedNode* prev = new LinkedNode();

	temp = head;
	prev = NULL;

	if (isEmpty())
	{
		return;
	}

	else
	{
		while (temp != NULL && key != temp->key)
		{
			prev = temp;
			temp = temp->next;
		}
	}

	if (temp == NULL)
	{
		return;
	}

	else if (prev == NULL)
	{
		if (temp->next == NULL)
		{
			head = NULL;
		}

		else
		{
			head = temp->next;
		}
	}

	else if (temp->next == NULL)
	{
		prev->next = NULL;
	}

	else
	{
		prev->next = temp->next;
		temp->next = NULL;
	}

}

void LinkedList::printList()
{
	if (isEmpty())
	{
		return;
	}

	else
	{
		LinkedNode* temp = new LinkedNode();
		temp = head;

		while (temp != NULL)
		{
			std::cout << temp->key << " ";
			temp = temp->next;
		}

		std::cout << std::endl;
	}

}