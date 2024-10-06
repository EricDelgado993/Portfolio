#include <string>
#include "DateType.h"

#pragma once

using namespace std;

class PersonType
{
public:
	void Initialize(string newName, DateType newBirthDate);
	string getName() const;
	DateType getBirthDate() const;

private:
	string name;
	DateType birthDate;
};
