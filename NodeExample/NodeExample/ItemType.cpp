#include <iostream>
#include <fstream>
#include "ItemType.h"

ItemType::ItemType()
{
	value = 0;
}

ItemType::~ItemType()
{

}

RelationType ItemType::comparedTo(ItemType item) const
{
	if (value < item.value)
		return LESS;

	else if (value > item.value)
		return GREATER;

	else
		return EQUAL;
}

void ItemType::initialize(int num)
{
	value = num;
}

void ItemType::Print(std::ofstream& out)
// Pre: out has been opened.
// Post: value has been sent to the stream out.
{
	out << value << " ";
}

bool ItemType::operator==(ItemType item)
{
	return (value == item.value);
}

int ItemType::getValue()
{
	return value;
}