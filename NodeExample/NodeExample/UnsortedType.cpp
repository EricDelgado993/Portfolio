#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
	length = 0;
}

bool UnsortedType::isFull() const
{
	return (length == MAX_ITEMS);
}

int UnsortedType::getLength() const
{
	return length;
}

ItemType UnsortedType::getItem(ItemType item, bool& found)
// Pre: Key member(s) of the item is initialized.
// Post: If found, item's key matches an elemen's key in the
//		 list and a copy of that element has been returned;
//       otherwise, item is returned.
{
	bool moreToSearch;
	int location = 0;
	found = false;

	moreToSearch = (location < length);

	while (moreToSearch && !found)
	{
		switch (item.comparedTo(info[location]))
		{
		case LESS		:
		case GREATER	: location++;
						  moreToSearch = (location < length);
						  break;
		case EQUAL		: found = true;
					      item = info[location];
					      break;
		}
	}

	return item;
}

void UnsortedType::makeEmpty()
{
	length = 0;
}

void UnsortedType::putItem(ItemType item)
{
	info[length] = item;
	length++;
}

void UnsortedType::deleteItem(ItemType item)
// Pre:  item's key has been initialized.
//		 An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
	int location = 0;

	while (item.comparedTo(info[location]) != EQUAL)
		location++;

	info[location] = info[length - 1];
	length--;
}

void UnsortedType::resetList()
// Post: currentPos has been initialized
{
	currentPos = -1;
}

ItemType UnsortedType::getNextItem()
// Pre:  ResetList was called to initialized iteration.
//		 No transformer has been executed since last call.
//		 currentPos is defined.
// Post: item is current item.
//		 Current position has been updated.
{
	currentPos++;
	return info[currentPos];
}

void UnsortedType::printList()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << info[i].getValue() << " ";
	}

	std::cout << std::endl;
}
