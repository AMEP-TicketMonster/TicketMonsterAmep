#pragma once
#include "ConnexioBD.h"
#include <string>
#include <vector>
#include "tipus_dades.h"

class Dades
{
public:

    Dades();

    // Crides d'usuari loggejat->gestio_usuaris
    void crea_usuari(const Usuari& usuari);
    bool get_usuari(const std::string& nom, Usuari& usuari);
    void esborra_usuari(const std::string& nom);


    // Assatjos
    bool get_sales(const std::string& ciutat, std::vector<Sala>& sales);

    
private:
    ConnexioBD bd;
};

