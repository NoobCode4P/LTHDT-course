#include "Fraction.h"

void Fraction::input(){
	int tu, mau;
	cout << "Tu = ";
	cin >> tu;
	do{
		cout << "Mau khac 0: ";
		cin >> mau;
	} while (mau == 0);

	this->numer = tu;
	this->denom = mau;
}

void Fraction::output(){
	if (denom == 0){
		cout << "Error!" << endl;
		return;
	}
	reduce();
	cout << numer << "/" << denom << endl;
}

int gcd(int a, int b){
	if (a == 0 || b == 0)
		return a + b;
	while (b != 0){
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

Fraction Fraction::add(Fraction b){
	Fraction res;
	res.numer = numer * b.denom + b.numer * denom;
	res.denom = denom * b.denom;
	res.reduce();
	return res;
}

Fraction Fraction::subtract(Fraction b){
	Fraction res;
	res.numer = numer * b.denom - b.numer * denom;
	res.denom = denom * b.denom;
	res.reduce();
	return res;
}

Fraction Fraction::multiply(Fraction b){
	int num = numer * b.numer;
	int den = denom * b.denom;
	int ucln = gcd(num, den);
	return{ num / ucln, den / ucln };
}

Fraction Fraction::divide(Fraction b){
	if (b.isZero())
		return{};
	int num = numer * b.denom;
	int den = denom * b.numer;
	int ucln = gcd(num, den);
	return{ num / ucln, den / ucln };
}

void Fraction::reduce(){
	int ucln = gcd(numer, denom);
	numer /= ucln;
	denom /= ucln;
	if (numer >= 0 && denom < 0){
		numer = -numer;
		denom = -denom;
	}
	else if (numer < 0 && denom < 0){
		numer = -numer;
		denom = -denom;
	}
}

int Fraction::compare(Fraction b){
	float valA = (float)numer / denom;
	float valB = (float)b.numer / b.denom;
	if (valA > valB)
		return 1;
	else if (valA < valB)
		return -1;
	return 0;
}

bool Fraction::isPositive(){
	return (numer * denom > 0);
}

bool Fraction::isNegative(){
	return (numer * denom < 0);
}

bool Fraction::isZero(){
	return numer == 0;
}