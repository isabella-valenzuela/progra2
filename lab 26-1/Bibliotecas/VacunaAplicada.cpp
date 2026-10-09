//
// Created by Isabella on 8/10/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "VacunaAplicada.h"

//primero empezamos con los constructores, destructor y operador de asignacion
VacunaAplicada::VacunaAplicada(){
    inicializar();
}

VacunaAplicada::VacunaAplicada(const VacunaAplicada &orig) {
    inicializar();
    *this = orig;
}

VacunaAplicada::~VacunaAplicada() {
    eliminar();
}

void VacunaAplicada::inicializar() {
    nombre = nullptr;
    fecha = 0;
    dosis =0;
    colegiatura = nullptr;
}

void VacunaAplicada::eliminar() {
    if (nombre != nullptr) delete [] nombre;
    if (colegiatura != nullptr) delete [] colegiatura;
}
void VacunaAplicada::asignaCadena(char *&destino, const char *origen) {
    if (destino!= nullptr) delete [] destino;
    destino = nullptr;
    if (origen == nullptr) return;
    destino = new char[strlen(origen) + 1];
    strcpy(destino, origen);
}
void obtieneCadena(char *cadena,const char *origen) {
    if (origen == nullptr) cadena[0] =0;
    else strcpy(cadena,origen);
}
//ahora los getters (para imprimir) y setters (para leer)

void VacunaAplicada::getNombre(char *cadena) const {
    obtieneCadena(cadena, nombre);
}

void VacunaAplicada::setNombre(char *cadena) {
    asignaCadena(nombre, cadena);
}

int VacunaAplicada::getFecha() {
    return fecha;
}
void VacunaAplicada::setFecha(int fecha) {
    this->fecha = fecha;
}
double VacunaAplicada::getDosis() {
    return dosis;
}
void VacunaAplicada::setDosis(double dosis) {
    this->dosis = dosis;
}
void VacunaAplicada::getColegiatura(char *cadena) const {
    obtieneCadena(cadena, colegiatura);
}
void VacunaAplicada::setColegiatura(char *cadena) {
    asignaCadena(colegiatura, cadena);
}

void VacunaAplicada::leerDatos(ifstream &arch) {
    char buffer[100];
    arch.getline(buffer, 100, ',');
    setNombre(nombre);
    arch >> fecha;
    arch.get();
    arch >> dosis;
    arch.get();
    arch.getline(buffer, 100, ',');
    setColegiatura(colegiatura);
}

void VacunaAplicada::imprimirDatos(ofstream &arch) {
    arch << "- " <<left <<nombre<<" : "<<right << fecha << endl;
}

void operator<<(ofstream &arch, class VacunaAplicada &vacuna) {
    vacuna.imprimirDatos(arch);
}


void operator>>(ifstream &arch, class VacunaAplicada &vacuna) {
    vacuna.leerDatos(arch);
}
bool VacunaAplicada::esIgual(const VacunaAplicada &otra) const {
    return strcmp(nombre, otra.nombre) == 0 and fecha == otra.fecha and
           dosis == otra.dosis and strcmp(colegiatura, otra.colegiatura) == 0;
}