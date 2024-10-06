#pragma once

enum RelationType {LESS, EQUAL, GREATER};

class DateType
{
public:
	DateType();
	~DateType();
	void Initialize(int newMonth, int newDay, int newYear);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	RelationType comparedTo(DateType someDate);

private:
	int year;
	int month;
	int day;
};