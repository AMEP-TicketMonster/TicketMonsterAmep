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

        cout << "Entra sala: ";
        string sala;
        getline(cin, sala);
        cout << "Vols afegir disponibilitat (S/N): ";
        string resposta;
        cin >> resposta;
        while (resposta != "S" && resposta != "N") {
            cin >> resposta;
        }
        std::cin.ignore();
        if (resposta == "S") {
            // Afegir disponibilitat
            cout << "Afegim disponibilitat" << endl;
            DisponibilitatSala dispo;
            dispo.nom_sala = sala;

            cout << "Entra el dia: " << endl;
            getline(cin, dispo.dia);
            cout << "Entra hora_inici: " << endl;
            getline(cin, dispo.hora_inici);
            cout << "Entra hora_fi: " << endl;
            getline(cin, dispo.hora_fi);

            //dispo.dia = "2025-05-15";
            //dispo.hora_inici = "16:00";
            //dispo.hora_fi = "21:00";
            dades.afegeix_disponibilitat_sala(dispo);

        } else {
            // No afegir disponibilitat
            cout << "Fem una reserva" << endl;
            cout << "Entra el nom del grup musical: " << endl;
            Assaig assaig;
            getline(cin, assaig.nom_grup_musical);
            cout << "Entra el nom de la sala: " << endl;
            getline(cin, assaig.nom_sala);
            cout << "Entra el dia: " << endl;
            getline(cin, assaig.dia);
            cout << "Entra hora_inici: " << endl;
            getline(cin, assaig.hora_inici);
            cout << "Entra hora_fi: " << endl;
            getline(cin, assaig.hora_fi);
            dades.afegeix_assaig(assaig);

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

}

