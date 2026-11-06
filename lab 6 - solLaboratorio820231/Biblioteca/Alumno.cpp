//
// Created by anaro on 28/05/2026.
//

#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Alumno.h"

Alumno::Alumno(){
    inicializa();
}

Alumno::~Alumno(){
    if (nombre) delete nombre;
}

void Alumno::inicializa()
{
    nombre = nullptr;
    total = 0;
    codigo = 0;
}

Alumno::Alumno(const Alumno& orig){
    inicializa();
    *this = orig;
}

void Alumno::operator=(const Alumno& orig){

    if (orig.nombre!=nullptr)
        setNombre(orig.nombre);
    codigo = orig.codigo;
    escala = orig.escala;
    total = orig.total;
}

void Alumno::setCodigo(int codigo){
    this->codigo = codigo;
}

void Alumno::setNombre(const char* nomb){
    if (nombre) delete  nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Alumno::setEscala(int escala){
    this->escala = escala;
}

void Alumno::setTotal(double total){
    this->total = total;
}

int Alumno::getCodigo() const{
    return codigo;
}

void Alumno::getNombre(char* nomb) const{
    if (nombre==nullptr) nomb[0]=0;
    else strcpy(nomb, nombre);
}

int Alumno::getEscala() const{
    return escala;
}

double Alumno::getTotal() const{
    return total;
}

void Alumno::leerDatos(ifstream& in)
{
    char nomb[60];
    in >> codigo;
    if (in.eof()) return;
    in.get();
    in.getline(nomb,60, ',');
    in >> escala;
    in.get();
    setNombre(nomb);
}

void Alumno::mostrarDatos(ofstream& out)
{
    out << left << setw(10) << codigo << setw(40)
        << nombre << right << setw(5) << escala ;

}


