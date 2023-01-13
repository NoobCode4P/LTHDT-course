#pragma once
#include "OfficeEmployee.h"
#include "Worker.h"
#include <vector>

class Company{
	vector <Employee*> list;
public:
	~Company();
	void inputList();
	void printList();
	ull totalSalary();
	void printEmployeeWithHighestSalary();
};