#pragma once
#include <iostream>
#include <string>
using namespace std;

#define ull unsigned long long

class Employee{
	string id;
	string fullname;
	string address;
public:
	Employee();
	Employee(string id, string fullname, string address);
	Employee(const Employee&);
	Employee(string fullname, string address);
	Employee(string fullname);

	virtual void input();
	virtual void output();
	virtual ull salary();
};