#include "pch.h"
#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;

void CppCLRWinFormsProject::Form1::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ username = this->textBox1->Text;
    String^ password = this->textBox2->Text;

    // Aqu� pots afegir la l�gica per validar l'usuari i la contrasenya
    if (username == "admin" && password == "password") {
        MessageBox::Show("Login correcte", "�xit", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else {
        MessageBox::Show("Nom d'usuari o contrasenya incorrectes", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}