
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
	void consultarUsuari(); //añadir esta operación al modelo de clases (se me olvído añadirlo)
	void modificarUsuari();
	void eliminarUsuari();

};