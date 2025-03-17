#include <string>


using namespace std;

class Usuari
{

private:
	// considerar usar un struct, tal vez nos puede interesar para pasar los datos por parémetro a la función de querySql...
	/*
	struct usuari{
		string idUsuari;
		string nom;
		string cognom;
		string email;
		string contrasenya;
	}
	*/

	string idUsuari;
	string nom;
	string cognom;
	string email;
	string contrasenya;

	/*

		Desde ForntEnd el usuario introduce datos.
		Los datos son enviados a BackEnd, los recibimos y dichos datos son tratados en su respectivo metodo implementado
		Tras terminar de tratar, se llama desde el mismo metodo, al archivo queryUsuari.hpp el cual tiene de rol
		realizar llamadas a la BBDD



		*/
public:
	Usuari();
	Usuari(string idUsuari, string nom, string cognom, string email, string contrasenya);

	void registrarUsuari();
	void iniciarSessio();
	void consultarUsuari(string idUsuari); // a�adir esta operaci�n al modelo de clases (se me olv�do a�adirlo)
	void modificarUsuari();
	void eliminarUsuari();

	// implementar getters y setters?
};