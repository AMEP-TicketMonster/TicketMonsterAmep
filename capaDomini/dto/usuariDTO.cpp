#include <iostream>
#include <string>

using namespace std;

class UsuariDTO
{
private:
    string idUsuari;
    string nom;
    string cognom;
    string email;
    string contrasenya;

public:
    UsuariDTO(string idUsuari, string nom, string cognom, string email, string contrasenya)
    {
        this->idUsuari = idUsuari;
        this->nom = nom;
        this->cognom = cognom;
        this->email = email;
        this->contrasenya = contrasenya;
        // tal vez hay que modificar los campos de la BD y nos falten cosas cómo fecha de registro, etc.
    }

    // Getters
    string getIdUsuari()
    {
        return idUsuari;
    }
    string getNom()
    {
        return nom;
    }
    string getCognom()
    {
        return cognom;
    }

    string getEmail()
    {
        return email;
    }
    string getContrasenya()
    {
        return contrasenya;
    }

    // setters

    void setIdUsuari(string idUsuari)
    {
        // Hay que poner algunos checks de los sets... to do...
        if (idUsuari.length() > 1)
        {
            this->idUsuari = idUsuari;
        }
    }
    void setNom(string nom)
    {
        this->nom = nom;
    }
    void setCognom(string cognom)
    {
        this->cognom = cognom;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setContrasenya(string contrasenya)
    {
        this->contrasenya = contrasenya;
    }
};
