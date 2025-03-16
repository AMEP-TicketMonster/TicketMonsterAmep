#include "../include/usuari.hpp"
#include "../pasarelaDB/queryUsuari.hpp"
#include <iostream>

void Usuari::consultarUsuari(string idUsuari)
{
    if (idUsuari.length() == 0)
    {
        // no hagas nada(solo borra el warning del terminal)
    }
    /*
    esto está hardcodeado' para hacer la prueba
    test con usuario creado a mano en la base de datos con la siguiente info:
        - idUsuari = AMEP2025
        - nom = ruben
        - cognom = apellido
        - main = ruben@upc.com
        - password = test123
    */
    cout << "función consulta_usuari" << endl;




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