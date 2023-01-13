#include "Fraction.h"

int main(){
	Fraction a, b;
	cout << "**Input a**" << endl;
	a.input();
	cout << "**Input b**" << endl;
	b.input();
	cout << "Output" << endl;
	cout << "a = ";
	a.output();
	if (!a.isZero())
		cout << "==> " << (a.isPositive() ? "a is positive" : "a is negative") << endl;
	else
		cout << "==> a is zero" << endl;

	cout << "b = ";
	b.output();
	if (!b.isZero())
		cout << "==> " << (b.isNegative() ? "b is negative" : "b is positive") << endl;
	else
		cout << "==> b is zero" << endl;

	Fraction sum = a.add(b);
	cout << "a + b = ";
	sum.output();

	Fraction subtraction = a.subtract(b);
	cout << "a - b = ";
	subtraction.output();

	Fraction multi = a.multiply(b);
	cout << "a * b = ";
	multi.output();

	Fraction div = a.divide(b);
	cout << "a / b = ";
	div.output();

	switch (a.compare(b)){
	case 0:
		cout << "a is equal to b" << endl;
		break;
	case 1:
		cout << "a is greater than b" << endl;
		break;
	default:
		cout << "a is less than b" << endl;
	}

	cout << "============" << endl;

	return 0;
}