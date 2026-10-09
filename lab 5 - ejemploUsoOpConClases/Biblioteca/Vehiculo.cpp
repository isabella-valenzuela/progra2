//
// Created by anaro on 13/05/2026.
//
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Vehiculo.h"

Vehiculo::Vehiculo()
{
    inicializa();
}

void Vehiculo::inicializa()
{
    marca = nullptr;
    modelo = nullptr;
    color = nullptr;
    anno = 0;
    velocidadActual = 0.0;
}

Vehiculo::Vehiculo(const class Vehiculo& velocidadActual)
{
    inicializa();
    *this = velocidadActual;
}

void Vehiculo::operator=(const Vehiculo& copia)
{
    setMarca(copia.marca);
    setModelo(copia.modelo);
    setColor(copia.color);
    anno = copia.anno;
    cantAccesorios = copia.cantAccesorios;
    velocidadActual = copia.velocidadActual;
    for (int i = 0; i < cantAccesorios; i++)
        listaAccesorios[i] = copia.listaAccesorios[i];
}

Vehiculo::~Vehiculo()
{
    if (marca) delete [] marca;
    if (modelo) delete [] modelo;
    if (color) delete [] color;
}

void Vehiculo::setMarca(const char* mar)
{
    if (marca) delete marca;
    marca = new char[strlen(mar) + 1];
    strcpy(marca, mar);
}

void Vehiculo::setModelo(const char* mod)
{
    if (modelo) delete modelo;
    modelo = new char[strlen(mod) + 1];
    strcpy(modelo, mod);
}

void Vehiculo::setColor(const char* col)
{
    if (color) delete color;
    color = new char[strlen(col) + 1];
    strcpy(color, col);
}

void Vehiculo::setAnno(const int anno)
{
    this->anno = anno;
}

void Vehiculo::setVelocidadActual(const double velocidadActual)
{
    this->velocidadActual = velocidadActual;
}

double Vehiculo::getVelocidadActual() const
{
    return velocidadActual;
}

int Vehiculo::getAnno() const
{
    return anno;
}

void Vehiculo::getMarca(char* mar) const
{
    if (marca == nullptr) mar[0] = 0;
    else strcpy(mar, marca);
}

void Vehiculo::getModelo(char* mod) const
{
    if (modelo == nullptr) mod[0] = 0;
    else strcpy(mod, modelo);
}

void Vehiculo::getColor(char* col) const
{
    if (color == nullptr) col[0] = 0;
    else strcpy(col, color);
}

char* leeCadena(ifstream& in, char tipo)
{
    char auxCadena[100];
    char* cadena;
    in.getline(auxCadena, 100, tipo);
    cadena = new char[strlen(auxCadena) + 1];
    strcpy(cadena, auxCadena);
    return cadena;
}

ifstream& operator>>(ifstream& in, class Vehiculo& ve)
{
    char *marca, *modelo, *color;
    int anno;
    double velocidadActual;
    marca = leeCadena(in, ',');
    if (in.eof()) return in;
    modelo = leeCadena(in, ',');
    in >> anno;
    in.get();
    in >> velocidadActual;
    in.get();
    color = leeCadena(in, '\n');

    ve.setMarca(marca);
    ve.setModelo(modelo);
    ve.setColor(color);
    ve.setVelocidadActual(velocidadActual);
    ve.setAnno(anno);
    return in;
}

ofstream& operator<<(ofstream& out, const class Vehiculo& ve)
{
    char marca[20], modelo[20], color[20];
    ve.getMarca(marca);
    ve.getModelo(modelo);
    ve.getColor(color);
    out << left << setw(20) << marca
                << setw(20) << modelo
                << setw(20) << color << endl;
    // ve.listarAccesorios(out);
    return out;
}
