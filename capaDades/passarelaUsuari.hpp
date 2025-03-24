#pragma once
#include <string>
#include "conectaDB.hpp"

using namespace std;

class PassarelaUsuari
{
private:
    string idUsuari;
    string nom;
    string cognom;
    string email;
    string contrasenya;

public:
    PassarelaUsuari();
    PassarelaUsuari(string id, const string &nomU, const string &cognomU,
                    const string &emailU, const string &contrasenyaU);

    // getters
    string obteIdUsuari() const;
    string obteNom() const;
    string obteCognom() const;
    string obteEmail() const;
    string obteContrasenya() const;

    // setters
    void posaIdUsuari(string id);
    void posaNom(const string &nomU);
    void posaCognom(const string &cognomU);
    void posaEmail(const string &emailU);
    void posaContrasenya(const string &contrasenyaU);

    // gateway bd ->caldra crear els respectius arxius de query i gateway per organitzar aixó..-.
    void insereix() const;
    void esborrar() const;
    void modifica() const;
};

