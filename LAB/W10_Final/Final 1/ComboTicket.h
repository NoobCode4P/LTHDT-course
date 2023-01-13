#pragma once
#include "Ticket.h"

class ComboTicket : public Ticket{

public:
	void input();
	ll ticketPrice();
	double getFactor();
	void output(ostream&);
};