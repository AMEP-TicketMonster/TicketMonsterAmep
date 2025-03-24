#include "ticketMonster.hpp"


PassarelaUsuari TicketMonster::obteUsuari() {
	PassarelaUsuari u = usuari;
	return u;
}

void TicketMonster::IniciaSessio(PassarelaUsuari u) {
	usuari = u;
}

void TicketMonster::TancaSessio() {
	usuari = PassarelaUsuari();
}
