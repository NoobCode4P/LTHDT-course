#include "ComboTicket.h"

void ComboTicket::input(){
	Ticket::input();
	factor = 1.5;
}

ll ComboTicket::ticketPrice(){
	return (ll)((factor * 80000) + ((double)priceFD * 0.8));
}

double ComboTicket::getFactor(){
	return factor;
}

void ComboTicket::output(ostream& out){
	Ticket::output(out);
	out << factor << endl;
}