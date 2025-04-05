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
        bd.executa(sql);
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
        sql::ResultSet* res = bd.consulta(sql);
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
        sql::ResultSet* res = bd.consulta(sql);
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
        bd.executa(sql);
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}



