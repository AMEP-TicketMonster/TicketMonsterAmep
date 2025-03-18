// fer include dels controladors de la capa de domini
#include "capaDomini/include/txConsultaUsuari.hpp";


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
    // void iniciaSessio(), ...registre...
}