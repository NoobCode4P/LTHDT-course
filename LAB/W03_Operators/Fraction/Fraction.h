#include <iostream>
using namespace std;

class Fraction{
	int num, den;

	void reduce();

public:
	void Input();
	friend ostream& operator << (ostream&, const Fraction&);

	bool operator == (const Fraction&);
	bool operator != (const Fraction&);
	bool operator >= (const Fraction&);
	bool operator > (const Fraction&);
	bool operator <= (const Fraction&);
	bool operator < (const Fraction&);

	Fraction operator + (const Fraction&);
	Fraction operator - (const Fraction&);
	Fraction operator * (const Fraction&);
	Fraction operator / (const Fraction&);
	Fraction& operator = (const Fraction&);
	
	Fraction& operator += (const Fraction&);
	Fraction& operator -= (const Fraction&);
	Fraction& operator *= (const Fraction&);
	Fraction& operator /= (const Fraction&);

	Fraction& operator ++();	//pre
	Fraction operator ++(int);	//post
	Fraction& operator --();	//pre
	Fraction operator --(int); //post

	Fraction operator + (int n);
	Fraction operator - (int n);
	Fraction operator * (int n);
	Fraction operator / (int n);

	friend Fraction operator + (int, const Fraction &);
	friend Fraction operator - (int, const Fraction &);
	friend Fraction operator * (int, const Fraction &);
	friend Fraction operator / (int, const Fraction &);

	operator float() const;

};
int gcd(int, int);