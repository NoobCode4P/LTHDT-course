#include "MortgagePayment.h"

bool checkValidInput(string loan, string rate, string year){
	bool checkLoan = true, checkRate = true, checkYear = true;

	for (int i = 0; i < loan.size(); i++)
		if (loan[i] < '0' || loan[i] > '9'){
			checkLoan = false;
			break;
		}
	bool setPeriod = false;
	for (int i = 0; i < rate.size(); i++){
		if (rate[i] < '0' || rate[i] > '9'){
			if (rate[i] == '.'){
				if (!setPeriod)
					setPeriod = true;
				else{
					checkRate = false;
					break;
				}
			}
			else{
				checkRate = false;
				break;
			}
		}
	}

	for (int i = 0; i < year.size(); i++)
		if (year[i] < '0' || year[i] > '9'){
			checkYear = false;
			break;
		}
	return checkLoan && checkRate && checkYear;
}

MortgagePayment::MortgagePayment(){
	loan = 0;
	rate = 0.0;
	year = 0;
}

MortgagePayment::MortgagePayment(ull loan, double rate, ui year){
	setLoan(loan);
	setRate(rate);
	setYear(year);
}

istream& operator >> (istream& in, MortgagePayment& a){
	string loan;
	string rate;
	string year;
	do{
		cout << "Enter the amount of loan: "; in >> loan;
		cout << "Enter the interest rate: "; in >> rate;
		cout << "Enter the number of years of the loan: "; in >> year;
	} while (!checkValidInput(loan, rate, year));
	
	a.setLoan(stoull(loan));
	a.setRate(stod(rate));
	a.setYear(stoul(year));
	return in;
}

void MortgagePayment::setLoan(ull loan){
	this->loan = loan;
}

void MortgagePayment::setRate(double rate){
	this->rate = rate;
}

void MortgagePayment::setYear(ui year){
	this->year = year;
}

ull MortgagePayment::monthlyPayment(){
	double term = pow(1 + rate / 12, 12 * year);
	ull Payment = (ull)(loan * (rate / 12) * term) / (term - 1);
	return Payment;
}

ull MortgagePayment::totalPaid(){
	ull total = (ull)monthlyPayment() * 12 * year;
	return total;
}

