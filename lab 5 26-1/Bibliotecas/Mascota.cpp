//
// Created by Isabella on 8/10/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Mascota.h"
#define MAXVACUNAS 20
//constructor por defecto
Mascota::Mascota() {
    inicializar();
}

//constructor con parametro
Mascota::Mascota(const Mascota &orig) {
    inicializar();
    *this = orig;
}

//destructor
Mascota::~Mascota() {
    eliminar();
}

//operador de asignacion
void Mascota::operator=(const Mascota &orig) {
    if (this == &orig) return;
    dni = orig.dni;
    setNombre(orig.nombre);
    setEspecie(orig.especie);
    edad = orig.edad;
    peso = orig.peso;
    setColegiatura(orig.colegiatura);
    numVacunas = orig.numVacunas;
    for (int i = 0; i < numVacunas; i++)
        listaVacunas[i] = orig.listaVacunas[i];
}
//inicializa cada atributo de mascota
void Mascota::inicializar() {
    dni = 0;
    nombre = nullptr;
    especie = nullptr;
    edad = 0;
    peso = 0;
    colegiatura = nullptr;
    numVacunas = 0;
}
//elimina los punteros de mascota
void Mascota::eliminar() {
    if (nombre != nullptr) delete [] nombre;
    if (especie != nullptr) delete [] especie;
    if (colegiatura != nullptr) delete [] colegiatura;
}

void Mascota::asignaCadena(char *&destino, const char *origen) {
    if (destino != nullptr) delete [] destino;
    destino = nullptr;
    if (origen == nullptr) return;
    destino = new char[strlen(origen)+1];
    strcpy(destino, origen);
}

void Mascota::obtenerCadena(char *cad, const char *origen) const {
    if (origen == nullptr) cad[0] = 0;
    else strcpy(cad, origen);
}

//ahora con los getters y setters

int Mascota::getDni() const {
    return dni;
}
void Mascota::setDni(int dni) {
    this->dni = dni;
}

void Mascota::getNombre(char* cadena) const {
    obtenerCadena(cadena, nombre);
}
void Mascota::setNombre(char* cadena) {
    asignaCadena(nombre, cadena);
}
void Mascota::getEspecie(char* cadena) const {
    obtenerCadena(cadena, especie);
}
void Mascota::setEspecie(char* cadena) {
    asignaCadena(especie, cadena);
}
double Mascota::getPeso() const {
    return peso;
}
void Mascota::setPeso(double peso) {
    this->peso = peso;
}

void Mascota::getColegiatura(char* cadena) const {
    obtenerCadena(cadena, colegiatura);
}
void Mascota::setColegiatura(char* cadena) {
    asignaCadena(colegiatura, cadena);
}
int Mascota::getNumVacunas()const {
    return numVacunas;
}
void Mascota::leerDatos(ifstream &arch) {
    char buffer [100];
    arch>>dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(buffer,100, ',');
    setNombre(buffer);
    arch.getline(buffer,100, ',');
    setEspecie(buffer);
    arch>>edad;
    arch.get();
    arch>>peso;
    arch.get();
    arch.getline(buffer,100, '\n');
    setColegiatura(buffer);
}

void Mascota::imprimirDatos(ofstream &arch) {
    char nomb[60], esp[20], anios[8];
    getNombre(nomb);
    getEspecie(esp);
    strcat(esp, ",");
    if (edad == 1)
        strcpy(anios, "año,");
    else
        strcpy(anios, "años,");
    arch.precision(2);
    arch<<fixed;
    arch<<"Mascota : "<<left<<setw(10)<<nomb<<" ("<<setw(8)<<esp
        <<right<<setw(2)<<edad<<' '<<left<<setw(6)<<anios
        <<right<<setw(6)<<peso<<" kg)"<<endl;

}

//guanira pide hacer la lectura de datos y la sobrecarga como funciones separadas,
//realmente numeros se pueden leer directamente y no se usan los setters pero por
//que el enunciado lo pide es que lo ponemos igual, podriamos usarlo pero es agregar lineas
//de mas que se pueden ahorrar guardandolo directamente

void operator>>(ifstream &arch, class Mascota &orig) {
    orig.leerDatos(arch);
}

void operator<<(ofstream &arch, class Mascota &orig) {
    orig.imprimirDatos(arch);
}

void Mascota::operator+=(class VacunaAplicada &vacuna) {
    if (numVacunas < MAXVACUNAS) {
        listaVacunas[numVacunas] = vacuna;
        numVacunas++;
    }
}
bool Mascota::operator~() {
        for (int i = 0; i < numVacunas - 1; i++)
            for (int j = i + 1; j < numVacunas; j++)
                if (listaVacunas[i].esIgual(listaVacunas[j])) return true;
        return false;
    }