#include <iostream>
#include <sstream>
#include <string>
#include "capaPresentacio/capaPresentacio.hpp"

using namespace std;
int main()
{
    CapaPresentacio &presentacio = CapaPresentacio::getInstance();
    //aquí debería haber una pantalla inicial que diga que hacer (por ejemplo login o antes de eso, una página con información)
    //test:
    presentacio.viewConsultaUsuari();
}

/*
void main()
{
    // to do...
}
    */