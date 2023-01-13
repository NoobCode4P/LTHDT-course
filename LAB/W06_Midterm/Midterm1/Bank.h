#include "MortgagePayment.h"
#include <vector>
#include <fstream>

class Bank{
	string name;
	vector <MortgagePayment> list;
public:
	Bank();
	void addInfo(MortgagePayment);
	void input();
	ull totalMoney();
	int countInterest();
	void sortList();
	void saveInfo(string file);
};