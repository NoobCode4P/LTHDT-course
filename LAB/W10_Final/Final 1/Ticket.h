#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

class Ticket{
protected:
	string title;
	int time;
	string roomName;
	ll priceFD;
	double factor;
public:
	virtual void input();
	int getTime();
	virtual ll ticketPrice() = 0;
	virtual double getFactor() = 0;
	virtual void output(ostream&);
};