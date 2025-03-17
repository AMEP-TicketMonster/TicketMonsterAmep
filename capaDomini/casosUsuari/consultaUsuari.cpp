
// #include "../include/usuari.hpp"
// #include "../pasarelaDB/queryUsuari.hpp"
#include <iostream>

class ConsultaUsuari{
    /*
        breve introducción:
        1.- capa de presentación, usuario quiere consultar datos. y llama a la capa de dominio -> consultarUsuari.cpp

        2.-Tratamos los datos en la capa de dominio y hacemos una llamada a usuariMapper(capa Dades). 
        3.- Usuari mapper llama a la consulta que toque (usuariConsulta o como se llame)
        4.- se ejecuta la consulta, se devuelven unos datos que se tratan con el data mapper y se transforman en un UsuariDTO
        5.- los datos se devuelven enviando UsuariDTO (o un struct, pero tal vez sería redundante...)
        /importante: no podemos enviar un dto entero a la capa de presentación, hay que tratar los datos
    */
}

/*
void Usuari::consultarUsuari(string idUsuari)
{
    if (idUsuari.length() == 0)
    {
        // no hagas nada(solo borra el warning del terminal)
    }
    
    esto está hardcodeado' para hacer la prueba
    test con usuario creado a mano en la base de datos con la siguiente info:
        - idUsuari = AMEP2025
        - nom = ruben
        - cognom = apellido
        - main = ruben@upc.com
        - password = test123
    
   // cout << "función consulta_usuari" << endl;

    // por ahora es un select *...
    //(código generado por chatGPT)
    
    auto resultados = queryUsuaris();
    for (const auto &fila : resultados)
    {
        for (const auto &dato : fila)
        {
            std::cout << dato << " ";
        }
        std::cout << std::endl;
    }
        
}


*/