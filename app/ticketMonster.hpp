#include <iostream>
#include "../capaDades/passarelaUsuari.hpp"


class TicketMonster {

	private:
		PassarelaUsuari usuari;
		TicketMonster() {
		}

	public:
		static TicketMonster& getInstance() {
			static TicketMonster instance;
			return instance;
		}

		PassarelaUsuari obteUsuari();

		void IniciaSessio(PassarelaUsuari u);

		void TancaSessio();
};

