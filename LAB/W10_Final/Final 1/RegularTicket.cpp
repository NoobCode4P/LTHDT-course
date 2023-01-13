#include "RegularTicket.h"

void RegularTicket::input(){
	Ticket::input();
	factor = 1.0;
}

ll RegularTicket::ticketPrice(){
	return (ll)((factor * (double)80000) + priceFD);
}

double RegularTicket::getFactor(){
	return factor;
}

void RegularTicket::output(ostream& out){
	Ticket::output(out);
	out << factor << endl;
}