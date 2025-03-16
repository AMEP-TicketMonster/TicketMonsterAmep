#include "usuari.hpp"

#include <iostream>

using namespace std;

// Constructor vacio
Usuari::Usuari()
{
   
}

//constructor principal
/*
    to do:
        - comprovar datos de entrada
*/
Usuari::Usuari(string idUsuari, string nom, string cognom, string email, string contrasenya) {
    idUsuari = idUsuari;
    nom = nom;
    cognom = cognom;
    email = email;
    contrasenya = contrasenya;
}