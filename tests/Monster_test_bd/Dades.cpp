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

void Dades::afegeix_disponibilitat_sala(const DisponibilitatSala& dispo) {
    // TODO: potser faltaria veure si aquesta disponibilitat ja existia (no overlap)
    try {
        int idSala = get_IDSala(dispo.nom_sala);
        int idDataSala = afegeix_dataSala(idSala, dispo.dia, dispo.hora_inici, dispo.hora_fi);

        string sql = "INSERT INTO DisponibilitatSales(idSala, idDataSala, idEstatSala)"
            "VALUES (" + to_string(idSala) + ", " + to_string(idDataSala) + ", " + to_string(EstatSala::Disponible) + ")";
        bd_.executa(sql);
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

void Dades::afegeix_assaig(const Assaig& assaig) {
    int idGrupMusical = get_IDGrupMusical(assaig.nom_grup_musical);
    if (idGrupMusical != -1) {
        cout << "id de " << assaig.nom_grup_musical << " es " << idGrupMusical << endl;
        int idSala = get_IDSala(assaig.nom_sala);
        if (idSala != -1) {
            cout << "id de " << assaig.nom_sala << " es " << idSala << endl;
            int idDataSala = get_IDDataSala(idSala, assaig.dia, assaig.hora_inici, assaig.hora_fi);
            if (idDataSala != -1) {
                cout << "id de DataSala es " << idDataSala << endl;
                bool salaDisponible = estaSalaDisponible(idSala, idDataSala);
                if (salaDisponible) {
                    do_afegeix_assaig(idGrupMusical, idSala, idDataSala);
                    cout << "despres afegeix assaig" << endl;
                    modifica_disponibilitat(EstatSala::Reservada, idSala, idDataSala);
                    cout << "despres modfica dispon" << endl;
                }
                cout << "estat sala " << to_string(salaDisponible);
            }
            else {
                cout << "error idDataSala no existeix " << endl;
            }
        }
        else {
            cout << "error sala " << assaig.nom_sala << " no existeix " << endl;
        }
    }
    else {
        cout << "error grup musical " << assaig.nom_grup_musical << " no existeix " << endl;
    }
}

// 
// Post: aquesta funció retorna el ID del registre afegit a DataSala. Si la entrada ja existeix no fa res
int Dades::afegeix_dataSala(int idSala, const string& dia, const string& hora_inici, const string& hora_fi) {
    int ret = -1;
    try {
        string sql = "INSERT INTO DataSala(idSala, dia, hora_inici, hora_fi)"
            "Values(" + to_string(idSala) + ", '" + dia + "', '" + hora_inici + "', '" + hora_fi + "')";
        string check_sql = "SELECT COUNT(*) FROM DataSala WHERE idSala = " + to_string(idSala) +
            " AND dia = '" + dia + "' AND hora_inici = '" + hora_inici + "' AND hora_fi = '" + hora_fi + "'";
        sql::ResultSet* res = bd_.consulta(check_sql);
        if (res->next() && res->getInt(1) == 0) {
            bd_.executa(sql);
            sql = "SELECT LAST_INSERT_ID()";
            sql::ResultSet* res = bd_.consulta(sql);
            if (res->next()) {
                ret = res->getInt("LAST_INSERT_ID()");
            }
        }
        else {
            cout << "Error: Duplicate entry detected!" << endl;
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

int Dades::get_IDGrupMusical(const std::string& nom_grup) {
    int ret = -1;
    try {
        string sql = "SELECT idGrup FROM GrupsMusicals WHERE nomGrup = '" + nom_grup + "'";
        sql::ResultSet* res = bd_.consulta(sql);
        if (res->next()) {
            ret = res->getInt("idGrup");
        }
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
    return ret;
}

int Dades::get_IDDataSala(const int idSala, const std::string& dia, const std::string& hora_inici, const std::string& hora_fi) {
    int ret = -1;
    try {
        string sql = "SELECT idDataSala FROM DataSala WHERE idSala = " + to_string(idSala)
                     + " AND dia = '" + dia + "' AND hora_inici = '" + hora_inici + "' AND hora_fi = '" + hora_fi + "'";
        sql::ResultSet* res = bd_.consulta(sql);
        if (res->next()) {
            ret = res->getInt("idDataSala");
        }
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
    return ret;
}

bool Dades::estaSalaDisponible(const int idSala, const int idDataSala) {
    bool ret = false;
    try {
        string sql = "SELECT idEstatSala FROM DisponibilitatSales WHERE idSala = " + to_string(idSala)
            + " AND idDataSala = " + to_string(idDataSala);
        sql::ResultSet* res = bd_.consulta(sql);
        if (res->next()) {
            int estat = res->getInt("idEstatSala");
            if (estat == EstatSala::Disponible) {
                cout << "Disponible" << endl;
                ret = true;
            }
            else {
                cout << "No Disponible" << endl;
            }
        }
        else
            cout << "no res next" << endl;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
    return ret;
}


void Dades::do_afegeix_assaig(const int idGrupMusical, const int idSala, const int idDataSala) {
    try {
        string sql = "INSERT INTO Assajos(idGrup, idSala, idDataSala) VALUES ("
            + to_string(idGrupMusical)
            + "," + to_string(idSala)
            + "," + to_string(idDataSala) + ")";
        bd_.executa(sql);
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

void Dades::modifica_disponibilitat(const EstatSala estat, const int idSala, const int idDataSala) {
    try {
        string sql = "UPDATE DisponibilitatSales SET idEstatSala = " + to_string(estat)
            + " WHERE idSala = " + to_string(idSala) + " AND idDataSala = " + to_string(idDataSala);
        bd_.executa(sql);
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}