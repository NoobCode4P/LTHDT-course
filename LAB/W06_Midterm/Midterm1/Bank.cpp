#include "Bank.h"

Bank::Bank(){

}

void Bank::addInfo(MortgagePayment a){
	list.push_back(a);
}

void Bank::input(){
	string ten;
	MortgagePayment tmp;
	cout << "Enter name: "; cin >> ten;
	cin >> tmp;

	this->addInfo(tmp);
	this->name = ten;
}

ull Bank::totalMoney(){
	ull res = 0;
	for (int i = 0; i < list.size(); i++)
		res += list[i].monthlyPayment();
	return res;
}

int Bank::countInterest(){
	double interest;
	cout << "Enter interest: ";
	cin >> interest;

	int count = 0;
	for (int i = 0; i < list.size(); i++)
		if (list[i].getRate() == interest)
			count++;
	return count;
}

void Bank::sortList(){
	for (int i = 0; i < list.size() - 1; i++){
		for (int j = i + 1; j < list.size(); j++){
			if (list[i].getLoan() < list[j].getLoan())
				swap(list[i], list[j]);
			else if (list[i].getLoan() == list[j].getLoan())
				if (list[i].getName() > list[j].getName())
					swap(list[i], list[j]);
		}
	}
}

void Bank::saveInfo(string file){
	ofstream out(file);
	if (!out){
		cout << "Unable to open file" << endl;
		return;
	}
	out << name << endl;
	sortList();
	for (int i = 0; i < list.size(); i++){
		out << list[i];
	}
	out.close();
}