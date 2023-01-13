#pragma once
#include "Employee.h"

class Worker : public Employee{
	int numOfItem;
public:
	Worker();
	Worker(string id, string fullname, string addr);
	Worker(string id, string fullname, string addr, int numOfItem);
	Worker(const Employee&);
	Worker(const Worker&);

	void input();
	void output();
	ull salary();
};