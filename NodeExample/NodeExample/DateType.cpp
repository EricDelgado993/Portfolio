#include "DateType.h"

DateType::DateType()
{
	month = 0;
	day = 0;
	year = 0;
}

DateType::~DateType()
{

}

void DateType::Initialize(int newMonth, int newDay, int newYear)
{
	month = newMonth;
	day = newDay;
	year = newYear;
}

RelationType DateType::comparedTo(DateType someDate)
{
	//Pre: Self and someDate have been initialized.
	//Post: Function value = LESS, if self comes before someDate.
	//					   = EQUAL, if self is the same as someDate.
	//					   = GREATER, if self comes after someDate.
	if (year < someDate.year)
		return LESS;
	else if (year > someDate.year)
		return GREATER;
	else if (month < someDate.month)
		return LESS;
	else if (month > someDate.month)
		return GREATER;
	else if (day > someDate.day)
		return GREATER;
	else if (day < someDate.day)
		return LESS;
	else
		return EQUAL;
}

int DateType::getDay() const
{
	return day;
}

int DateType::getMonth() const
{
	return month;
}

int DateType::getYear() const
{
	return year;
}