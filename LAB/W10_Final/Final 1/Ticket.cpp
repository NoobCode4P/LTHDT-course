#include "Ticket.h"

void Ticket::input(){
	string tenPhim, tenPhong;
	int tgian;
	ll giaAnUong;
	cout << "Nhap ten phim: ";
	getline(cin, tenPhim);
	cout << "Nhap Gio bat dau: ";
	cin >> tgian;
	cin.ignore();
	cout << "Nhap ten phong: ";
	getline(cin, tenPhong);
	cout << "Nhap gia thuc an, do uong: ";
	cin >> giaAnUong;

	title = tenPhim;
	time = tgian;
	roomName = tenPhong;
	priceFD = giaAnUong;
}

int Ticket::getTime() {
	return time;
}

void Ticket::output(ostream& out){
	out << title << endl;
	out << time << endl;
	out << roomName << endl;
	out << priceFD << endl;
}