#include "FractionArray.h"

int main(){
	Fraction a;
	Fraction b(-99);
	Fraction c(128,-1024);
	Fraction d("3/-4");

	/* cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	cout << "b + c = " << b + c;

	if (!a.isZero())
		cout << "==> " << (a.isPositive() ? "a is positive" : "a is negative") << endl;
	else
		cout << "==> a is zero" << endl;

	if (!b.isZero())
		cout << "==> " << (b.isNegative() ? "b is negative" : "b is positive") << endl;
	else
		cout << "==> b is zero" << endl;

	c.saveFile("Phanso.txt");

	Fraction ex;
	ex.readFile("Phanso.txt");
	cout << ex; */

	/* Fraction mang[4] = { a, b, c, d };
	vector <Fraction> Vfrac = { d, c, b, a }; */

	/* FractionArray fracA1;
	FractionArray fracA2(5);

	FractionArray fracA3(mang, 4);
	FractionArray fracA4(Vfrac); */
	FractionArray fracA5("5/6 99/-2 89/12 5/2");

	/* cout << "A1: " << fracA1;
	cout << "A2: " << fracA2;
	cout << "A3: " << fracA3;
	cout << "A4: " << fracA4; */
	cout << "A5: " << fracA5 << endl;

	string fileArray = "MangPhanSo.txt";
	fracA5.saveFile(fileArray);

	FractionArray fracA6;
	fracA6.loadFile(fileArray);
	cout << "A6: " <<  fracA6 << endl;

	Fraction Sum;
	Sum = fracA5.sumAll();
	cout << "Sum of all fraction in the array: " << Sum << endl;
	
	Fraction Max;
	Max = fracA5.findMax();
	cout << "The maximum fraction in the array: " << Max << endl;

	int countPos = fracA5.countPositive();
	int countNeg = fracA5.countNegative();
	int countZero = fracA5.countZero();

	cout << "Number of positve fractions: " << countPos << endl;
	cout << "Number of negative fractions: " << countNeg << endl;
	cout << "Number of zero: " << countZero << endl;

	return 0;
}