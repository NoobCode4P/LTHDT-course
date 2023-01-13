#include "Cinema.h"

Cinema::~Cinema(){
	while (!list.empty()){
		Ticket* tmp = list.back();
		list.pop_back();
		delete tmp;
	}
}

void Cinema::inputList(){
	int n;
	cout << "Nhap so luong: ";
	cin >> n;

	for (int i = 0; i < n; i++){
		int loai;
		do{
			cout << "Nhap 1-Regular Ticket, 2-Combo Ticket: ";
			cin >> loai;
		} while (loai != 1 && loai != 2);
		cin.ignore();
		Ticket *t = NULL;
		switch (loai){
		case 1:
			t = new RegularTicket;
			break;
		case 2:
			t = new ComboTicket;
			break;
		}

		t->input();
		list.push_back(t);
	}
}

void Cinema::sortList(){
	for (int i = 0; i < list.size() - 1; i++){
		for (int j = i + 1; j < list.size(); j++){
			if (list[i]->getFactor() > list[j]->getFactor())
				swap(list[i], list[j]);
			else if (list[i]->getFactor() == list[j]->getFactor()){
				if (list[i]->ticketPrice() < list[j]->ticketPrice())
					swap(list[i], list[j]);
			}
		}
	}
}

void Cinema::saveList(string filename){
	ofstream out(filename);
	if (!out){
		cout << "Unable to open file" << endl;
		return;
	}

	for (int i = 0; i < list.size(); i++){
		list[i]->output(out);
		out << endl;
	}
	out.close();
}

void Cinema::comboList(){
	for (int k = 0; k < 24; k++){
		cout << "=====" << k << endl;
		int count = 0;
		for (int i = 0; i < list.size(); i++){
			if (list[i]->getFactor() == 1.5 && list[i]->getTime() == k)
				count++;
		}
		cout << count << endl;
	}
}