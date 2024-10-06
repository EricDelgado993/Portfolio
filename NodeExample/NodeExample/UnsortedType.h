#include "ItemType.h"

#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

class UnsortedType
{
private:
	int length;
	ItemType info[MAX_ITEMS];
	int currentPos;

public:
	UnsortedType();
	void makeEmpty();
	bool isFull() const;
	int getLength() const;
	ItemType getItem(ItemType item, bool& found);
	void putItem(ItemType item);
	void deleteItem(ItemType item);
	void resetList();
	ItemType getNextItem();
	void printList();
};

#endif // UNSORTEDTYPE_H