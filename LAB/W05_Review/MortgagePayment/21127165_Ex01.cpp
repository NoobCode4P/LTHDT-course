#include "MortgagePayment.h"

int main(){
	MortgagePayment a;
	cin >> a;
	cout << "The amount of monthly payment: "<< a.monthlyPayment() << endl;
	cout << "The total amount paid at the end of loan period: "<< a.totalPaid() << endl;
	return 0;
}