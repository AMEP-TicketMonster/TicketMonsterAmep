#include "consultaUsuari.hpp"

std::vector<std::vector<std::string>> queryUsuaris() {
    std::vector<std::vector<std::string>> resultados;
    sql::Connection* conn = conectaDB(); 

    if (!conn) {
        std::cerr << "No se pudo conectar a la base de datos." << std::endl;
        return resultados;
    }

    try {
        sql::Statement* stmt = conn->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM usuari");

        while (res->next()) {
            resultados.push_back({
                res->getString("idUsuari"),
                res->getString("nom"),
                res->getString("cognom"),
                res->getString("email"),
                res->getString("contrasenya")
            });
        }
        conn->close();
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    
    return resultados;
}
