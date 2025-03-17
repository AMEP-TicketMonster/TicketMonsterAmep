#include <string>
// datos de conexión
//#include "../.env.cpp"




// dependencia: MySQL Connector -> paquete: libmysqlcppconn-dev
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <locale>

sql::Connection* conectaDB();