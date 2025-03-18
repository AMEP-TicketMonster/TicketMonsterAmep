#include "usuariDTO.hpp"

UsuariDTO::UsuariDTO(string idUsuari, string nom, string cognom, string email, string contrasenya)
{
    this->idUsuari = idUsuari;
    this->nom = nom;
    this->cognom = cognom;
    this->email = email;
    this->contrasenya = contrasenya;
    // tal vez hay que modificar los campos de la BD y nos falten cosas cómo fecha de registro, etc.
}

// Getters
string UsuariDTO::getIdUsuari()
{
    return idUsuari;
}
string UsuariDTO::getNom()
{
    return nom;
}
string UsuariDTO::getCognom()
{
    return cognom;
}

string UsuariDTO::getEmail()
{
    return email;
}
string UsuariDTO::getContrasenya()
{
    return contrasenya;
}

// setters

void UsuariDTO::setIdUsuari(string idUsuari)
{
    // Hay que poner algunos checks de los sets... to do...
    if (idUsuari.length() > 1)
    {
        this->idUsuari = idUsuari;
    }
}
void UsuariDTO::setNom(string nom)
{
    this->nom = nom;
}
void UsuariDTO::setCognom(string cognom)
{
    this->cognom = cognom;
}
void UsuariDTO::setEmail(string email)
{
    this->email = email;
}
void UsuariDTO::setContrasenya(string contrasenya)
{
    this->contrasenya = contrasenya;
}
