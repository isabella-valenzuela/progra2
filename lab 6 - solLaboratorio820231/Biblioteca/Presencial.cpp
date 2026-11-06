//
// Created by anaro on 28/05/2026.
//
#include <fstream>
#include <iomanip>
using namespace std;
#include "Presencial.h"

Presencial::Presencial()
{
    total = 0;
}

void Presencial::setRecargo(double recargo)
{
    this->recargo = recargo;
}

double Presencial::getRecargo() const
{
    return recargo;
}

void Presencial::setTotal(double total)
{
    this->total = total;
}

double Presencial::getTotal() const
{
    return total;
}

void Presencial::leerDatos(ifstream& archivo)
{
    Alumno::leerDatos(archivo);
    archivo >> recargo;
    archivo.get(); //fin de linea porque empiezo con una letra
}

void Presencial::actualiza(double precio)
{
    total = precio * (recargo / 100);
    Alumno::setTotal(precio + total);
}

void Presencial::mostrarDatos(ofstream& out)
{
    Alumno::mostrarDatos(out);
    out << right << " " << setw(24) << Alumno::getTotal() << endl;
}

