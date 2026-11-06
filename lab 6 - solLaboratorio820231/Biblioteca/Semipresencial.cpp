//
// Created by anaro on 28/05/2026.
//
#include <fstream>
#include <iomanip>
using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial()
{
    total = 0;
}

void Semipresencial::setDescuento(double descuento)
{
    this->descuento = descuento;
}

void Semipresencial::setTotal(double total)
{
    this->total = total;
}

double Semipresencial::getDescuento() const
{
    return descuento;
}

double Semipresencial::getTotal() const
{
    return total;
}

void Semipresencial::leerDatos(ifstream& in)
{
    Alumno::leerDatos(in);
    in >> descuento;
    in.get(); //fin de linea porque empiezo con una letra
}

void Semipresencial::actualiza(double precio)
{
    total = precio * (descuento / 100);
    Alumno::setTotal(precio - total);
}

void Semipresencial::mostrarDatos(ofstream& out)
{
    Alumno::mostrarDatos(out);
    out << right << " " << setw(24) << Alumno::getTotal() << endl;
}
