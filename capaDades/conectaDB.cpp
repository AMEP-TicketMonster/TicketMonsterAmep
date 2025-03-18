#include <iostream>
#include "conectaDB.hpp"

using namespace std;

// dependencia: MySQL Connector -> paquete: libmysqlcppconn-dev


string DB_HOST="127.0.0.1:3306";    //introducir manualmente el puerto (este es el mio por defecto, mirad donde teneis el mariadb)
string DB_NAME = "";    //el nombre de la base de datos (nombre en mariadb)
string DB_USERNAME="";  //usuario mariadb
string DB_PASSWORD= ""; //contraseña mariadb

sql::Connection* conectaDB() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* conn = driver->connect(DB_HOST, DB_USERNAME, DB_PASSWORD);
        conn->setSchema(DB_NAME);
        return conn;
    } catch (sql::SQLException& e) {
        std::cerr << "Error en la conexión a la base de datos: " << e.what() << std::endl;
        return nullptr;
    }
}