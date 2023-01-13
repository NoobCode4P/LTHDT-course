#include "Company.h"

Company::~Company(){
	while(!list.empty()){
		Employee* tmp = list.back();
		list.pop_back();
		delete tmp;
	}
}

void Company::inputList(){
	int n; 
	cout << "Nhap so luong nhan vien: "; cin >> n;

	for (int i = 0; i < n; i++){
		int type;
		do{
			cout << "Nhap loai nhan vien (1 - nvvp, 2 - cnsx): ";
			cin >> type;
		} while (type != 1 && type != 2);

		Employee *p = NULL;

		switch (type){
		case 1:
			p = new OfficeEmployee;
			break;
		case 2:
			p = new Worker;
			break;
		}
		p->input();
		list.push_back(p);
	}
}

void Company::printList(){
	for (int i = 0; i < list.size(); i++){
		cout << "=========Nhan vien thu " << i + 1  << "==========="<< endl;
		list[i]->output();
	}
}

ull Company::totalSalary(){
	ull res = 0;
	for (int i = 0; i < list.size(); i++)
		res += list[i]->salary();
	return res;
}

void Company::printEmployeeWithHighestSalary(){
	ull max = 0;
	for (Employee* x : list)
		if (x->salary() > max)
			max = x->salary();

	for (Employee* x : list)
		if (x->salary() == max){
			x->output();
			cout << "=========" << endl;
		}
}