#include "Fraction.h"

int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void Fraction::reduce(){
	int ucln = gcd(num, den);
	num /= ucln;
	den /= ucln;
	if (num >= 0 && den < 0){
		num = -num;
		den = -den;
	}
	else if (num < 0 && den < 0){
		num = -num;
		den = -den;
	}
}

void Fraction::Input(){
	int tu, mau;
	cout << "Tu = ";
	cin >> tu;
	do{
		cout << "Mau khac 0: ";
		cin >> mau;
	} while (mau == 0);

	this->num = tu;
	this->den = mau;
}

ostream& operator <<(ostream &out, const Fraction &b){
	if (b.den == 0){
		out << "Error!" << endl;
		return out;
	}
	Fraction tmp;
	tmp = b;
	tmp.reduce();
	out << tmp.num << "/" << tmp.den << endl;
	return out;
}

//===================
Fraction Fraction::operator + (const Fraction &b){
	Fraction res;
	res.den = den * b.den;
	res.num = num * b.den + b.num * den;
	res.reduce();
	return res;
}

Fraction Fraction::operator - (const Fraction &b){
	Fraction res;
	res.den = den * b.den;
	res.num = num * b.den - b.num * den;
	res.reduce();
	return res;
}

Fraction Fraction::operator * (const Fraction &b){
	Fraction res;
	res.den = den * b.den;
	res.num = num * b.num;
	res.reduce();
	return res;
}

Fraction Fraction::operator / (const Fraction &b){
	if (b.num == 0)
		return{};
	Fraction res;
	res.den = den * b.num;
	res.num = num * b.den;
	res.reduce();
	return res;
}

Fraction& Fraction::operator = (const Fraction &b){
	this->num = b.num;
	this->den = b.den;
	return *this;
}

//===================
bool Fraction::operator == (const Fraction &b){
	Fraction tmp;
	tmp = b;
	tmp.reduce();
	return (num == tmp.num && den == tmp.den);
}

bool Fraction::operator != (const Fraction &b){
	return !(*this == b);
}

bool Fraction::operator >= (const Fraction &b){
	float valA = (float)num / den;
	float valB = (float)b.num / b.den;
	return (valA >= valB);
}

bool Fraction::operator > (const Fraction &b){
	float valA = (float)num / den;
	float valB = (float)b.num / b.den;
	return (valA > valB);
}

bool Fraction::operator <= (const Fraction &b){
	float valA = (float)num / den;
	float valB = (float)b.num / b.den;
	return (valA <= valB);
}

bool Fraction::operator < (const Fraction &b){
	float valA = (float)num / den;
	float valB = (float)b.num / b.den;
	return (valA < valB);
}

//==================
Fraction& Fraction::operator += (const Fraction &b){
	*this = *this + b;
	return *this;
}

Fraction& Fraction::operator -= (const Fraction &b){
	*this = *this - b;
	return *this;
}

Fraction& Fraction::operator *= (const Fraction &b){
	*this = *this * b;
	return *this;
}

Fraction& Fraction::operator /= (const Fraction &b){
	*this = *this / b;
	return *this;
}

//==================
Fraction& Fraction::operator ++ (){
	Fraction tmp;
	tmp.num = 1;
	tmp.den = 1;
	*this += tmp;
	return *this;
}

Fraction& Fraction::operator -- (){
	Fraction tmp;
	tmp.num = 1;
	tmp.den = 1;
	*this -= tmp;
	return *this;
}

Fraction Fraction::operator ++(int){
	Fraction tmp;
	tmp = *this;
	++ *this;
	return tmp;
}

Fraction Fraction::operator --(int){
	Fraction tmp;
	tmp = *this;
	-- *this;
	return tmp;
}

//=================
Fraction Fraction::operator + (int n){
	Fraction tmp;
	tmp.num = n;
	tmp.den = 1;
	return *this + tmp;
}

Fraction Fraction::operator - (int n){
	Fraction tmp;
	tmp.num = n;
	tmp.den = 1;
	return *this - tmp;
}

Fraction Fraction::operator * (int n){
	Fraction tmp;
	tmp.num = n;
	tmp.den = 1;
	return *this * tmp;
}

Fraction Fraction::operator / (int n){
	Fraction tmp;
	tmp.num = n;
	tmp.den = 1;
	return *this / tmp;
}

//================
Fraction operator + (int x, const Fraction &b){
	Fraction res;
	Fraction tmp;
	tmp.num = x;
	tmp.den = 1;
	res = tmp + b;
	return res;
}

Fraction operator - (int x, const Fraction &b){
	Fraction res;
	Fraction tmp;
	tmp.num = x;
	tmp.den = 1;
	res = tmp - b;
	return res;
}

Fraction operator * (int x, const Fraction &b){
	Fraction res;
	Fraction tmp;
	tmp.num = x;
	tmp.den = 1;
	res = tmp * b;
	return res;
}

Fraction operator / (int x, const Fraction &b){
	Fraction res;
	Fraction tmp;
	tmp.num = x;
	tmp.den = 1;
	res = tmp / b;
	return res;
}

Fraction::operator float() const{
	float res = (float)num / den;
	return res;
}