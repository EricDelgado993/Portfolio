#include <iostream>
#include "Rational.h"
using namespace std;

// Edit the file!!
int main()
{
	Rational ratNum(1, 5);
	Rational ratNum2(1, 2);
	Rational ratNum3(1,0);

	ratNum3 = ratNum + ratNum2;

	cout << "break" << endl;
}

/*
class Shape
{
public:
	virtual double area(double x, double y) = 0;
};

class Square : public Shape
{
public:
	double area(double x, double y) override
	{
		return x * y;
	}
};

class Triangle : public Shape
{
public:
	double area(double x, double y) override
	{
		return .5 * x * y;
	}
};

template <typename T>
T Max(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{
	Square* a = new Square();
	Triangle* b = new Triangle();

	cout << a->area(2.5, 10) << endl;

	cout << b->area(2.5, 10) << endl;

	cout << Max('a', 'z') << endl;
}
*/