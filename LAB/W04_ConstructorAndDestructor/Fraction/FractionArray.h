#include "Fraction.h"
#include <vector>

class FractionArray{
	vector <Fraction> array;
	int size;
public:
	FractionArray();
	FractionArray(int n);
	FractionArray(Fraction[], int n);
	FractionArray(vector <Fraction>);
	FractionArray(string s);

	friend istream& operator >> (istream& in, FractionArray&);
	friend ostream& operator << (ostream& out, const FractionArray&);
	

	void loadFile(string file);
	void saveFile(string file);

	Fraction sumAll();
	Fraction findMax();
	
	int countPositive();
	int countNegative();
	int countZero();
};