#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define ull unsigned long long
#define ui unsigned int

class MortgagePayment{
	ull loan;
	double rate;
	ui year;
	string cusName;
public:
	MortgagePayment();
	MortgagePayment(ull loan, double rate, ui year, string name);

	friend istream& operator >> (istream&, MortgagePayment&);
	friend ostream& operator << (ostream&, const MortgagePayment&);

	ull getLoan();
	double getRate();
	string getName();

	void setLoan(ull);
	void setRate(double);
	void setYear(ui);
	ull monthlyPayment();
	ull totalPaid();
};

bool checkValidInput(string loan, string rate, string year);