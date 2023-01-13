#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Fraction{
	int numer, denom;

	void reduce();
public:
	Fraction();
	Fraction(int);
	Fraction(int, int);
	Fraction(string);
	~Fraction(){};

	friend istream& operator >> (istream& in, Fraction &);
	friend ostream& operator << (ostream& out, const Fraction&);
	Fraction& operator = (const Fraction&);

	void readFile(string file);
	void saveFile(string file);

	Fraction operator +(const Fraction&);

	int compare(const Fraction&);
	bool isPositive();
	bool isNegative();
	bool isZero();

};
int gcd(int, int);