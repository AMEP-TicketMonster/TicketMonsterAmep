#include <string>
// datos de conexión
//#include "../.env.cpp"




// dependencia: MySQL Connector -> paquete: libmysqlcppconn-dev
#include <cppconn/driver.h>
#include <cppconn/exception.h>
//según he leido, statement no es seguro del todo ya que permite SQL Injection, hay que cambiarlo más adelante si toca.
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <locale>

sql::Connection* conectaDB();