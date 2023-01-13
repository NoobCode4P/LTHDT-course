#include "Bank.h"

int main(){
	Bank obj;
	for (int i = 0; i < 3; i++)
		obj.input();
	
	cout << "Total money of monthly payment: " << obj.totalMoney() << endl;
	int numOfcus = obj.countInterest();
	cout << "Number of customers applying the input interest: " << numOfcus << endl;

	obj.saveInfo("bank.txt");

	return 0;
}