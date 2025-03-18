
// #include "../include/usuari.hpp"
// #include "../pasarelaDB/queryUsuari.hpp"
#include <iostream>
#include "../../dto/usuariDTO.hpp"
// incluir pasarela
class TxConsultaUsuari
{
private:
    UsuariDTO usuari;
    //GatewayUsuari pasarelaUsuari;

    /*
        breve introducción:
        1.- capa de presentación, usuario quiere consultar datos. y llama a la capa de dominio -> consultarUsuari.cpp

        2.-Tratamos los datos en la capa de dominio y hacemos una llamada a usuariMapper.
        3.- Usuari mapper llama a la consulta que toque (usuariConsulta o como se llame)
        4.- se ejecuta la consulta, se devuelven unos datos que se tratan con el data mapper y se transforman en un UsuariDTO
        5.- los datos se devuelven enviando UsuariDTO (o un struct, pero tal vez sería redundante...)
        /importante: no podemos enviar un dto entero a la capa de presentación, hay que tratar los datos
    */
public:
    TxConsultaUsuari(){

    };

    void executar();

    UsuariDTO obteResultat();
    
}
