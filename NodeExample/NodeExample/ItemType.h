#include <iostream>
#include <fstream>

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
public:
	ItemType();
	~ItemType();
	RelationType comparedTo(ItemType item) const;
	void Print(std::ofstream& out);
	void initialize(int num);
	bool operator==(ItemType item);
	int getValue();

private:
	int value;
};

#endif // ITEMTYPE_H