// fer include dels controladors de la capa de domini
#include "../capaDomini/casosUsuari/include/txConsultaUsuari.hpp"

class CapaPresentacio
{
private:
    CapaPresentacio();

public:
    static CapaPresentacio &getInstance()
    {
        static CapaPresentacio instance;
        return instance;
    }

    void viewConsultaUsuari();

    void viewTancaSessio();

    void viewRegistraUsuari();

    void viewIniciaSessio();

    void viewModificaUsuari();

	void viewEsborraUsuari();


};