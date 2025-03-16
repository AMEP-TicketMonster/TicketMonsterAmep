#include <iostream>
#include <sstream>
#include <string>


// dependencia: MySQL Connector -> paquete: libmysqlcppconn-dev


// el programa principal no debería instanciar la clase usuario. Solo debe de iniciar el programa y llamar a "la capa de presentación"
// este código del main solo son pruebas y debe ser configurado futuramente en un archivo tests.cpp.
#include "include/usuari.hpp"

using namespace std;
int main()
{

    // TEST:

    Usuari user1;
    user1.consultarUsuari("AMEP2025");
}

/*
void main()
{
    // to do...
}
    */