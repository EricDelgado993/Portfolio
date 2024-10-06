#ifndef RATIONAL_NUMBER_H_
#define RATIONAL_NUMBER_H_

#include <iostream>

class Rational
{
public:

	Rational();
	Rational(int n, int d);

	Rational operator+ (const Rational& n) const;

	void printNum();

private:
	int n, d; // numerator, demoninator
};

#endif