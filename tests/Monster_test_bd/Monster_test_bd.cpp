// Monster_test_bd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ConnexioBD.h"
#include <iostream>
#include "Dades.h"
#include <windows.h>

using namespace std;

void buscar_sala() {
    cout << "Entra nom ciutat: ";
    string ciutat;
    getline(cin, ciutat);
    Dades dades;
    vector<Sala> sales;
    if (dades.get_sales(ciutat, sales)) {
        for (int i = 0; i < sales.size(); ++i) {
            cout << "Sala " << i + 1 << endl;
            cout << sales[i].nom << " " << sales[i].ciutat << " " << sales[i].capacitat << endl;
        }
    }
    else {
        cout << "No s'han trobat sales a aquesta ciutat" << endl;
    }
    cout << endl;
}

void show_menu(const vector<string>& opcions) {
    for (int i = 0; i < opcions.size(); i++) {
        cout << i + 1 << ". " << opcions[i] << endl;
    }
    cout << "Entra opció: " << endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    bool sortir = false;
    while (not sortir) {
        cout << "*********************" << endl;
        cout << "    Menú Principal   " << endl;
        cout << "*********************" << endl;

        vector<string> opcions = { "Buscar sala", "Reservar sala", "Sortir" };
        show_menu(opcions);
        string opcio_menu;
        getline(cin, opcio_menu);
        if (opcio_menu == "1") {
            cout << "busquem sala" << endl;
            buscar_sala();
        }
        else if (opcio_menu == "2") {
            cout << "reservem sala" << endl;
        }
        else {
            cout << "sortim" << endl;
            sortir = true;
        }
        
    }

#if 0

    std::cout << "Hola!\n";

    Usuari usuari;
    //usuari.nom = "Sandra";
    //usuari.cognom = "Perez";
    //usuari.correu_electronic = "san@gmail.com";
    //usuari.contrasenya = "san_pwd";

    Dades dades;
    //dades.crea_usuari(usuari);


    dades.get_usuari("Sandra", usuari);

    cout << usuari.nom << endl;
    cout << usuari.cognom << endl;
    cout << usuari.email << endl;
    cout << usuari.contrasenya << endl;


    dades.esborra_usuari("Sandra");

#endif

/*
    ConnexioBD bd;

    bool ret = false;
    string sql = "SELECT * FROM Usuaris";
    // Fem format de data_naixement per tenir (DD/MM/AAAA) 
    // la keyword "BINARY" al WHERE de la SELECT fa que la cerca sigui sensible a majúscules
    sql::ResultSet* res = bd.consulta(sql);
    while (res->next()) {
        cout << "el nom es " << res->getString("nom") << endl;
        cout << "el cognnom es " << res->getString("cognom") << endl;
        cout << "el email es " << res->getString("email") << endl;
        ret = true;
    }
    delete res;
    */

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
