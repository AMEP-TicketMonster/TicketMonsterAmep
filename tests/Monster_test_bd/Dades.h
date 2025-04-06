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
    void afegeix_disponibilitat_sala(const DisponibilitatSala& dispo);

    void afegeix_assaig(const Assaig& assaig);

private:
    ConnexioBD bd_;

    int afegeix_dataSala(int idData, const std::string& dia, const std::string& hora_inici, const std::string& hora_fi);
    int get_IDSala(const std::string& nom);
    int get_IDGrupMusical(const std::string& nom_grup);
    int get_IDDataSala(const int idSala, const std::string& dia, const std::string& hora_inici, const std::string& hora_fi);
    bool estaSalaDisponible(const int idSala, const int idDataSala);
    void do_afegeix_assaig(const int idGrupMusical, const int idSala, const int idDataSala);
    void modifica_disponibilitat(const EstatSala estat, const int idSala, const int idDataSala);
};

