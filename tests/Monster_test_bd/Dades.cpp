#include "Dades.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <algorithm>
using namespace std;

// Pre: Res
// Post: Inicialitza un objecte Dades
Dades::Dades() {

}

// Pre: usuari conté dades vàlides per a un nou usuari
// Post: Registra un nou usuari a la base de dades
void Dades::crea_usuari(const Usuari& usuari) {
    try {
        string sql = "INSERT INTO Usuaris (nom, cognom, email, contrasenya) VALUES ('"
            + usuari.nom
            + "','" + usuari.cognom
            + "','" + usuari.email
            + "','" + usuari.contrasenya + "')";
        bd_.executa(sql);
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}


// PRE: cert
// POST: retorna true si nom existeix a la taula Usuaris i omple l´estructura usuari
bool Dades::get_usuari(const string& nom, Usuari& usuari) {
    try {
        bool ret = false;
        string sql = "SELECT * "
                     "FROM Usuaris WHERE BINARY nom = '" + nom + "'";
        // la keyword "BINARY" al WHERE de la SELECT fa que la cerca sigui sensible a majúscules
        sql::ResultSet* res = bd_.consulta(sql);
        if (res->next()) {
            usuari.nom = res->getString("nom");
            usuari.cognom = res->getString("cognom");
            usuari.contrasenya = res->getString("contrasenya");
            usuari.email = res->getString("email");
            ret = true;
        }
        return ret;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
        return false;
    }
}

bool Dades::get_sales(const std::string& ciutat, std::vector<Sala>& sales) {
    try {
        bool ret = false;
        string sql = "SELECT * "
                     "FROM Sales WHERE BINARY ciutat = '" + ciutat + "'";
        sql::ResultSet* res = bd_.consulta(sql);
        while (res->next()) {
            Sala sala;
            sala.nom = res->getString("nom");
            sala.ciutat = res->getString("ciutat");
            sala.capacitat = res->getString("capacitat");
            sales.push_back(sala);
            ret = true;
        }
        return ret;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
        return false;
    }
}

// Pre: nom conté el nom d'un usuari existent
// Post: Elimina l'usuari de la base de dades
void Dades::esborra_usuari(const string& nom) {
    try {
        string sql = "DELETE FROM Usuaris WHERE nom = '" + nom + "';";
        bd_.executa(sql);
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

// Post: aquesta funció retorna el ID del registre afegit a DataSala
int Dades::afegeix_dataSala(const string& dia, const string& hora_inici, const string& hora_fi) {
    int ret = -1;
    try {
        string sql = "INSERT INTO DataSala(dia, hora_inici, hora_fi)"
            "Values('" + dia + "', '" + hora_inici + "', '" + hora_fi + "')";
        bd_.executa(sql);
        sql = "SELECT LAST_INSERT_ID()";
        sql::ResultSet* res = bd_.consulta(sql);
        if (res->next()) {
            ret = res->getInt("LAST_INSERT_ID()");
        }
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
    return ret;
}

int Dades::get_IDSala(const string& nom) {
    int ret = -1;
    try {
        string sql = "SELECT idSala FROM Sales WHERE nom = '" + nom + "'";
        sql::ResultSet* res = bd_.consulta(sql);
        if (res->next()) {
            ret = res->getInt("idSala");
        }
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
    return ret;
}

void Dades::afegeix_disponibilitat_sala(const DisponibilitatSala& dispo) {
    // TODO: potser faltaria veure si aquesta disponibilitat ja existia (no overlap)
    int idDataSala = afegeix_dataSala(dispo.dia, dispo.hora_inici, dispo.hora_fi);
    try {
        int idSala = get_IDSala(dispo.nom_sala);
        string sql = "INSERT INTO DisponibilitatSales(idSala, idDataSala, idEstatSala)"
            "VALUES (" + to_string(idSala) + ", " + to_string(idDataSala) + ", " + to_string(EstatSala::Reservada) + ")";
        bd_.executa(sql);
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

