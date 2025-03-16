
#pragma once
#include <string>
#include "queryUsuari.hpp"
class USUARI
{

private:

	//cambiar a struct
	// ALGO algo;
	std::string ID;
	std::string Nom;
	std::string cognom;
	std::string email;
	std::string contrasenya;
	/*
	
	Desde ForntEnd el usuario introduce datos.
	Los datos son enviados a BackEnd, los recibimos y dichos datos son tratados en su respectivo metodo implementado
	Tras terminar de tratar, se llama desde el mismo metodo, al archivo queryUsuari.hpp el cual tiene de rol
	realizar llamadas a la BBDD
	
	
	
	*/
public:
	void registrarUsuari();
	void iniciarSessio();
	void consultarUsuari(); //añadir esta operación al modelo de clases (se me olvído añadirlo)
	void modificarUsuari();
	void eliminarUsuari();

};