#include "Rational.h"

Rational::Rational()
{
	n = 0;
	d = 1;
}

Rational::Rational(int n, int d)
{
	this->n = n;
	this->d = d;
}

Rational Rational::operator+ (const Rational& n) const
{
	Rational newRational;

	newRational.n = (this->n * n.d) + (n.n * this->d);
	newRational.d = this->d * n.d;

	return newRational;
}
