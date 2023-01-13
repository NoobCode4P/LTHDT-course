#pragma once
#include "Employee.h"

class OfficeEmployee : public Employee{
	int workingDays;
public:
	OfficeEmployee();
	OfficeEmployee(string id, string fullname, string addr);
	OfficeEmployee(string id, string fullname, string addr, int workingDays);
	OfficeEmployee(const Employee&);
	OfficeEmployee(const OfficeEmployee&);

	void input();
	void output();
	ull salary();
};