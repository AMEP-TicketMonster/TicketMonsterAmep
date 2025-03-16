
#pragma once
#include <string>

class USUARI
{

private:
	std::string ID;
	std::string Nom;
	std::string cognom;
	std::string email;
	std::string contrasenya;

public:
	void registrarUsuari();
	void iniciarSessio();
	void consultarUsuari(); //a�adir esta operaci�n al modelo de clases (se me olv�do a�adirlo)
	void modificarUsuari();
	void eliminarUsuari();

};