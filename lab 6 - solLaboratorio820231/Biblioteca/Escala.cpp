//
// Created by anaro on 28/05/2026.
//
#include <fstream>
using namespace std;
#include "Escala.h"

Escala::Escala(){
    codigo = 0;  // muy importante para la lectura e impresión
    precio = 0;
}

void Escala::setPrecio(double precio){
    this->precio = precio;
}

void Escala::setCodigo(int codigo){
    this->codigo = codigo;
}

double Escala::getPrecio() const{
    return precio;
}

int Escala::getCodigo() const{
    return codigo;
}

void Escala::leeDatos(ifstream& in)
{
    in >> codigo;
    if (in.eof()) return;
    in.get();
    in >> precio; // fin de linea porque empiezo con un numero
}

void Escala::mostrar(ofstream& out)
{
    if (codigo)
        out << codigo << " " << precio << endl;
}



