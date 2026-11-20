//
// Created by Isabella on 19/11/2026.
//

#include "Vehiculo.h"

void Vehiculo::inicializar() {
    placa ="";
    marca = "";
    modelo = "";
}

Vehiculo::Vehiculo() {
    inicializar();
}

Vehiculo::~Vehiculo() {
}

Vehiculo::Vehiculo(const Vehiculo &orig) {
    inicializar();
    *this = orig;
}

void Vehiculo::operator=(const  Vehiculo &orig) {
    placa = orig.placa;
    marca = orig.marca;
    modelo = orig.modelo;
}

string Vehiculo::getPlaca() {
    return placa;
}

string Vehiculo::getMarca() {
    return marca;
}

string Vehiculo::getModelo() {
    return modelo;
}

void Vehiculo::setPlaca(string placa) {
    this->placa = placa;
}

void Vehiculo::setMarca(string marca) {
    this->marca = marca;
}

void Vehiculo::setModelo(string modelo) {
    this->modelo = modelo;
}

void operator>>(ifstream &arch, Vehiculo &veh) {
    string buffer;
    getline(arch, buffer, ',');
    veh.setPlaca(buffer);
    arch >> ws;
    getline(arch, buffer, ',');
    veh.setMarca(buffer);
    getline(arch, buffer, '\n');
    veh.setModelo(buffer);
}

void operator<<(ofstream &arch, Vehiculo &veh) {
    arch << left << setw(10) << veh.getPlaca() <<
        setw(15) << veh.getMarca() << setw(10) << veh.getModelo() <<endl;
}


