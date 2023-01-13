#include "OfficeEmployee.h"

OfficeEmployee::OfficeEmployee(){}

OfficeEmployee::OfficeEmployee(string id, string fullname, string addr) : Employee(id, fullname, addr){
	workingDays = 0;
}

OfficeEmployee::OfficeEmployee(string id, string fullname, string addr, int workingDays) : Employee(id, fullname, addr){
	this->workingDays = workingDays;
}

OfficeEmployee::OfficeEmployee(const Employee& a) : Employee(a){
	workingDays = 0;
}

OfficeEmployee::OfficeEmployee(const OfficeEmployee& a) : Employee(a){
	workingDays = a.workingDays;
}

void OfficeEmployee::input(){
	Employee::input();
	int wday;
	cout << "Enter number of working days: ";
	cin >> wday;
	workingDays = wday;
}

void OfficeEmployee::output(){
	Employee::output();
	cout << "Number of working days: " << workingDays << endl;
	cout << "Salary per month: " << salary() << endl;
}

ull OfficeEmployee::salary(){
	return Employee::salary() + workingDays * 300000;
}