#include "../include/txConsultaUsuari.hpp"

    /*
        breve introducción:
        1.- capa de presentación, usuario quiere consultar datos. y llama a la capa de dominio -> consultarUsuari.cpp

        2.-Tratamos los datos en la capa de dominio y hacemos una llamada a usuariMapper(capa Dades).
        3.- Usuari mapper llama a la consulta que toque (usuariConsulta o como se llame)
        4.- se ejecuta la consulta, se devuelven unos datos que se tratan con el data mapper y se transforman en un UsuariDTO
        5.- los datos se devuelven enviando UsuariDTO (o un struct, pero tal vez sería redundante...)
        /importante: no podemos enviar un dto entero a la capa de presentación, hay que tratar los datos
    */

    TxConsultaUsuari::TxConsultaUsuari() {
       
    };
    

    void TxConsultaUsuari::executar(){
        string id, nom, cognom, email, password;
        try{
            //obté instancia (singleton)
            TicketMonster &ticketMonster = TicketMonster::getInstance();

            //obté usuari de la sessió
            usuari = ticketMonster.obteUsuari();
            id = usuari.obteIdUsuari();
            nom = usuari.obteNom();
            cognom = usuari.obteCognom();
            email = usuari.obteEmail();
            password = usuari.obteContrasenya();

            //transforma en DTO:
            //probablemente no deberíamos pasar datos cómo la contraseña
            //revisar.
            resultat = UsuariDTO(id,nom,cognom,email,password);

        }catch (const std::exception& e) {
            std::cerr << "Error en TxConsultaUsuari::executar(): " << e.what() << std::endl;
        }
     
    };

    UsuariDTO TxConsultaUsuari::obteResultat() const {
        return resultat;
    };

    PassarelaUsuari TxConsultaUsuari::obteUsuari() const {
        return usuari;
    }