#include <iostream>
using namespace std;

class Fraction{
	int numer, denom;
	
	void reduce();
public:
	void input();
	void output();
	Fraction add(Fraction);
	Fraction subtract(Fraction);
	Fraction multiply(Fraction);
	Fraction divide(Fraction);
	int compare(Fraction);
	bool isPositive();
	bool isNegative();
	bool isZero();
};
int gcd(int, int);