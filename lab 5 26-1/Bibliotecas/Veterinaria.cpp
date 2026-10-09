//
// Created by Isabella on 8/10/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <list>
using namespace std;
#include "Veterinaria.h"
#include "Mascota.h"
#define INCREMENTO 5
#define NOENCONTRADO -1
Veterinaria::Veterinaria() {
    inicializar();
}
void Veterinaria::inicializar() {
    listaDeMascotas = nullptr;
    numMascotas = 0;
}
Veterinaria::~Veterinaria() {
    eliminar();
}
void Veterinaria::eliminar() {
    listaDeMascotas = nullptr;
}
void Veterinaria::operator <=(const char *nombArch) {
    ifstream arch = abrirIfstream(nombArch);
    Mascota mascota;
    int capacidad = numMascotas;
    while (true) {
        arch >> mascota; // ya esta sobrecargado con leer datos en Mascota.h
        if (arch.eof())  break;
        agregarMascota(mascota, capacidad);
    }
    if (capacidad != numMascotas) redimensionar(numMascotas);
}

void Veterinaria::agregarMascota(const class Mascota &mascota, int &capacidad) {
    if (numMascotas == capacidad) {
        capacidad += INCREMENTO;
        redimensionar(capacidad);
    }
    listaDeMascotas[numMascotas] = mascota;
    numMascotas++;
}
void Veterinaria::redimensionar(int nuevaCapacidad) {
    class Mascota *nuevaLista = new class Mascota[nuevaCapacidad];
    for (int i = 0; i < numMascotas; i++)
        nuevaLista[i] = listaDeMascotas[i];
    eliminar();
    listaDeMascotas = nuevaLista;
}

void Veterinaria::operator<<=(const char *nombArch) {
    ifstream arch = abrirIfstream(nombArch);
    VacunaAplicada vacunaAplicada;
    char nombre[60];
    int dniCliente, pos;
    while (true) {
        arch.getline(nombre, 60, ',');
        if (arch.eof()) break;
        arch >> dniCliente;
        arch.get();
        arch >> vacunaAplicada;
        pos = buscarMascota(dniCliente, nombre);
        if (pos != NOENCONTRADO) {
            listaDeMascotas[pos]+=vacunaAplicada;
        }
    }

}
int Veterinaria::buscarMascota(int dniCliente, const char* nombre) {
    char nombMascota[60];
    for (int i = 0; i < numMascotas; i++)
        if (listaDeMascotas[i].getDni() == dniCliente) {
            listaDeMascotas[i].getNombre(nombMascota);
            if (strcmp(nombMascota, nombre) == 0) return i;
        }
    return NOENCONTRADO;
}
ifstream Veterinaria::abrirIfstream(const char *nombArch) {
    ifstream arch = ifstream(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch;
        exit(1);
    }
    return arch;
}
