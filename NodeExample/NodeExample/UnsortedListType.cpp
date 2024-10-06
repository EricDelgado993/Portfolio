#include "UnsortedListType.h"

UnsortedListType::UnsortedListType()
{
	length = 0;
	listData = NULL;
}

UnsortedListType::~UnsortedListType()
{
	NodeType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		tempPtr->next = NULL;
		delete tempPtr;
	}
}

void UnsortedListType::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	NodeType* temp = new NodeType();

	while (listData != NULL)
	{
		temp = listData;
		listData = temp->next;
		temp->next = NULL;
		delete temp;
	}

	length = 0;
}

bool UnsortedListType::IsFull() const
// Returns true if there is no room for another ItemType
// on the free store; false otherwise
{
	NodeType* location;

	try
	{
		location = new NodeType();
		delete location;
		return false;
	}

	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int UnsortedListType::GetLength() const
{
	return length;
}

ItemType UnsortedListType::GetItem(ItemType item, bool& found)
{
	NodeType* location = new NodeType();
	location = listData;
	found = false;
	bool moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (item.comparedTo(location->info))
		{
		case LESS		:

		case GREATER	: location = location->next;
					      moreToSearch = (location != NULL);
						  break;

		case EQUAL		: found = true;
						  item = location->info;
						  break;
		}
	}

	return item;
}

void UnsortedListType::PutItem(ItemType item)
{
	// Allocate space for new item.
	NodeType* location = new NodeType();

	// Put new item into the allocated space.
	location->info = item;
	location->next = listData;

	// listData now points to the new node (location)
	listData = location;

	// Increment length of the list.
	length++;
}

void UnsortedListType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//		 An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
	NodeType* location = new NodeType();
	NodeType* tempLocation = new NodeType();
	location = listData;

	if (item == listData->info)
	{
		tempLocation = location;
		listData = listData->next;
	}

	else
	{
		while (item.comparedTo(location->next->info) != EQUAL)
		{
			location = location->next;

			// Delete node at location->next
			tempLocation = location->next;
			location->next = (location->next)->next;
		}

		tempLocation->next = NULL;
		delete tempLocation;
		length--;
	}
}

void UnsortedListType::ResetList()
{
	currentPos = NULL;
}

ItemType UnsortedListType::GetNextItem()
// Pre:  No transformer has been executed since last call
// Post: A copy of the next item in the list is returned.
//		 When the end of the list is reached, currentPos
//		 is reset to begin again.
{
	if (currentPos == NULL)
	{
		currentPos = listData;
	}

	else
	{
		currentPos = currentPos->next;
	}

	return currentPos->info;
}