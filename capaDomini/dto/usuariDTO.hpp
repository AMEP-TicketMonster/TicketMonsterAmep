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
    // constructor

    UsuariDTO() = default; //parche
    //si está vacio no devuelve nada la txConsultaUsuari

    UsuariDTO(string idUsuari, string nom, string cognom, string email, string contrasenya);

    // getters y setters del dtO
    string getIdUsuari();
    string getNom();
    string getCognom();
    string getEmail();
    string getContrasenya();

    void setIdUsuari(string idUsuari);
    void setNom(string nom);
    void setCognom(string cognom);
    void setEmail(string email);
    void setContrasenya(string contrasenya);
};