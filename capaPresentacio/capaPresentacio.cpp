#include "capaPresentacio.hpp"
CapaPresentacio::CapaPresentacio() {
    
};


void CapaPresentacio::viewConsultaUsuari()
{
    //cargar vista (con la libreria que sea)
    //según la librería podríamos separar las vistas por componentes y así no repetir tanto código.

    //cómo por ahora no hay vistas, simulo que el usuario ha le ha dado al botón de ver perfil p.e.
    //hago la consulta por idUsuario a la base de datos

    //si lo devuelve vacio es porque el dto está en default vacio.
    TxConsultaUsuari domUsuari;
    domUsuari.executar();
    UsuariDTO user = domUsuari.obteResultat();
    cout << endl;
    cout << "=== INFORMACIÓ DE L'USUARI ===" << endl;
    cout << "ID: " << user.getIdUsuari() << endl;
    cout << "Nom: " << user.getNom() << endl;
    cout << "Cognom: " << user.getCognom() << endl;
    cout << "Email: " << user.getEmail() << endl;
    cout << "Contrasenya: " << user.getContrasenya() << endl;
    cout << "=================================" << endl;

};