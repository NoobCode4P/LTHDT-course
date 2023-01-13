#pragma once
#include "Ticket.h"

class RegularTicket : public Ticket{

public:
	void input();
	ll ticketPrice();
	double getFactor();
	void output(ostream&);
};