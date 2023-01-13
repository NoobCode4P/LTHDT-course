#include "Employee.h"

Employee::Employee(){}

Employee::Employee(string id, string fullname, string addr){
	this->id = id;
	this->fullname = fullname;
	this->address = addr;
}

Employee::Employee(const Employee& a){
	id = a.id;
	fullname = a.fullname;
	address = a.address;
}

Employee::Employee(string fullname, string addr){
	this->id = "01";
	this->fullname = fullname;
	this->address = addr;
}

Employee::Employee(string fullname){
	this->id = "01";
	this->fullname = fullname;
	this->address = "Q5";
}

void Employee::input(){
	string ID, fname, addr;
	cout << "Enter ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Enter your fullname: ";
	getline(cin, fname);
	cout << "Enter address: ";
	getline(cin, addr);

	id = ID;
	fullname = fname;
	address = addr;
}

void Employee::output(){
	cout << "ID: " << id << endl;
	cout << "Fullname: " << fullname << endl;
	cout << "Address: " << address << endl;
}

ull Employee::salary(){
	return 0;
}