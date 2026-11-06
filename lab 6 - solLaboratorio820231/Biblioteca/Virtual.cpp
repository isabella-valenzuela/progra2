//
// Created by anaro on 28/05/2026.
//
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Virtual.h"

Virtual::Virtual()
{
    inicializa();
}

Virtual::~Virtual()
{
    if (licencia) delete[] licencia;
}

void Virtual::inicializa()
{
    licencia = nullptr;
    total = 100;
}

Virtual::Virtual(const class Virtual& orig)
{
    inicializa();
    *this = orig;
}

void Virtual::operator=(const Virtual& orig)
{
    Alumno::operator=(orig);
    if (orig.licencia != nullptr)
        setLicencia(orig.licencia);
    total = orig.total;
}

void Virtual::setLicencia(const char* licen)
{
    if (licencia) delete[] licencia;
    licencia = new char[strlen(licen) + 1];
    strcpy(licencia, licen);
}

void Virtual::setTotal(double total)
{
    this->total = total;
}

void Virtual::getLicencia(char* lic) const
{
    if (licencia == nullptr) lic[0] = 0;
    else strcpy(lic, licencia);
}

double Virtual::getTotal() const
{
    return total;
}

void Virtual::leerDatos(ifstream& in)
{
    Alumno::leerDatos(in);
    char licen[30];
    in.getline(licen, 30, '\n');  //verifica el fin de linea
    setLicencia(licen);
}

void Virtual::actualiza(double precio)
{
    Alumno::setTotal(precio + total);
}

void Virtual::mostrarDatos(ofstream& out)
{
    Alumno::mostrarDatos(out);
    out << left << setw(15) << licencia << setw(10) <<
           right << Alumno::getTotal() << endl;
}

