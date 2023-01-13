#include "Fraction.h"

Fraction::Fraction(){
	numer = 0;
	denom = 1;
}

Fraction::Fraction(int x){
	numer = x;
	denom = 1;
}

Fraction::Fraction(int x, int y){
	if (y == 0){
		cout << "Denominator must not be 0!" << endl;
		exit(0);
	}
	numer = x;
	denom = y;
	reduce();
}

Fraction::Fraction(string s){
	string num = s.substr(0, s.find('/'));
	string den = s.substr(s.find("/") + 1);
	numer = stoi(num);
	denom = stoi(den);
	reduce();
}

istream& operator >> (istream& in, Fraction &a){
	int num, den;
	cout << "Nhap tu: ";
	in >> num;
	do{
		cout << "Nhap mau khac 0: ";
		in >> den;
	} while (den == 0);
	a.numer = num;
	a.denom = den;
	return in;
}

ostream& operator << (ostream& out, const Fraction& a){
	out << a.numer << '/' << a.denom << " ";
	return out;
}

Fraction& Fraction::operator = (const Fraction& a){
	this->numer = a.numer;
	this->denom = a.denom;
	return *this;
}

void Fraction::readFile(string file){
	ifstream in(file);
	if (!in){
		cout << "Unable to open file" << endl;
		return;
	}
	string f;
	getline(in, f);
	in.close();
	Fraction ans(f);
	*this = ans;
}

void Fraction::saveFile(string file){
	ofstream out(file);
	if (!out){
		cout << "Unable to open file" << endl;
		return;
	}
	out << *this;
	out.close();
}

int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
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

Fraction Fraction::operator + (const Fraction& b){
	Fraction res;
	res.numer = numer * b.denom + b.numer * denom;
	res.denom = denom * b.denom;
	res.reduce();
	return res;
}

int Fraction::compare(const Fraction &b){
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
