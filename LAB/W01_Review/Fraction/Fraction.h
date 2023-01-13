#include <iostream>
using namespace std;

struct Fraction{
	int numer, denom;

	void input();
	void output();
	Fraction add(Fraction);
	Fraction subtract(Fraction);
	Fraction multiply(Fraction);
	Fraction divide(Fraction);
	void reduce();
	int compare(Fraction);
	bool isPositive();
	bool isNegative();
	bool isZero();
};