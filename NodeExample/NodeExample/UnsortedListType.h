#include "NodeType.h"

#ifndef UNSORTEDLISTTYPE_H
#define UNSORTEDLISTTYPE_H

class UnsortedListType
{
public:
	UnsortedListType();
	~UnsortedListType();
	void MakeEmpty();
	bool IsFull() const;
	int GetLength() const;
	ItemType GetItem(ItemType item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();

private:
	NodeType* listData;
	int length;
	NodeType* currentPos;
};

#endif // UNSORTEDLISTTYPE_H