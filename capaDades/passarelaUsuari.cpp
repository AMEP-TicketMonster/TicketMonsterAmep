#include "passarelaUsuari.hpp"
//codi generat amb chatGPT, caldrà revisar el que està bé i el que no...

PassarelaUsuari::PassarelaUsuari() 
    : idUsuari(""), nom(""), cognom(""), email(""), contrasenya("") {}

// Constructor con parámetros
PassarelaUsuari::PassarelaUsuari(string id, const std::string& nomU, const std::string& cognomU, 
                                 const std::string& emailU, const std::string& contrasenyaU) 
    : idUsuari(id), nom(nomU), cognom(cognomU), email(emailU), contrasenya(contrasenyaU) {}

string PassarelaUsuari::obteIdUsuari() const {
    return idUsuari;
}

std::string PassarelaUsuari::obteNom() const {
    return nom;
}

std::string PassarelaUsuari::obteCognom() const {
    return cognom;
}

std::string PassarelaUsuari::obteEmail() const {
    return email;
}

std::string PassarelaUsuari::obteContrasenya() const {
    return contrasenya;
}

void PassarelaUsuari::posaIdUsuari(string id) {
    idUsuari = id;
}

void PassarelaUsuari::posaNom(const std::string& nomU) {
    nom = nomU;
}

void PassarelaUsuari::posaCognom(const std::string& cognomU) {
    cognom = cognomU;
}

void PassarelaUsuari::posaEmail(const std::string& emailU) {
    email = emailU;
}

void PassarelaUsuari::posaContrasenya(const std::string& contrasenyaU) {
    contrasenya = contrasenyaU;
}

// Inserción en la base de datos
void PassarelaUsuari::insereix() const {
    std::unique_ptr<sql::Connection> conn(conectaDB());
    if (!conn) {
        std::cerr << "No se pudo conectar a la base de datos." << std::endl;
        return;
    }

    try {
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::string query = "INSERT INTO usuari (idUsuari, nom, cognom, email, contrasenya) VALUES ('" +
                            idUsuari + "', '" + nom + "', '" + cognom + "', '" + email + "', '" + contrasenya + "')";
        stmt->executeUpdate(query);
    } catch (sql::SQLException& e) {
        std::cerr << "Error SQL en insereix(): " << e.what() << std::endl;
    }
}

// Eliminación de un usuario en la base de datos
void PassarelaUsuari::esborrar() const {
    std::unique_ptr<sql::Connection> conn(conectaDB());
    if (!conn) {
        std::cerr << "No se pudo conectar a la base de datos." << std::endl;
        return;
    }

    try {
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::string query = "DELETE FROM usuari WHERE idUsuari = '" + idUsuari + "'";
        stmt->executeUpdate(query);
    } catch (sql::SQLException& e) {
        std::cerr << "Error SQL en esborrar(): " << e.what() << std::endl;
    }
}

// Modificación de datos de un usuario
void PassarelaUsuari::modifica() const {
    std::unique_ptr<sql::Connection> conn(conectaDB());
    if (!conn) {
        std::cerr << "No se pudo conectar a la base de datos." << std::endl;
        return;
    }

    try {
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::string query = "UPDATE usuari SET nom = '" + nom + 
                            "', cognom = '" + cognom + 
                            "', email = '" + email + 
                            "', contrasenya = '" + contrasenya + 
                            "' WHERE idUsuari = '" + idUsuari + "'";
        stmt->executeUpdate(query);
    } catch (sql::SQLException& e) {
        std::cerr << "Error SQL en modifica(): " << e.what() << std::endl;
    }
}