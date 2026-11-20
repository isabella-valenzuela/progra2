//
// Created by Isabella on 19/11/2026.
//

#include "Empresa.h"

void Empresa::inicializar() {
    dni = 0;
    nombre = "";
    distrito = "";
}

Empresa::Empresa() {
    inicializar();
}

Empresa::~Empresa() {

}

int Empresa::getDni() {
    return dni;
}

string Empresa::getNombre() {
    return nombre;
}

string Empresa::getDistrito() {
    return distrito;
}

void Empresa::setDni(int dni) {
    this->dni = dni;
}

void Empresa::setNombre(string nombre) {
    this->nombre = nombre;
}

void Empresa::setDistrito(string distrito) {
    this->distrito = distrito;
}

void operator>>(ifstream &arch, Empresa &empresa) {
    int dni;
    arch >> dni;
    empresa.setDni(dni);
    arch.get();
    string buffer;
    getline(arch, buffer, ',');
    empresa.setNombre(buffer);
    getline(arch, buffer, '\n');
    empresa.setDistrito(buffer);
}

void Empresa::imprime(ofstream &arch) {
    arch << left << "DNI: " << setw(12) << dni << "NOMBRE: " << setw(45)
         << nombre << "DISTRITO: " << distrito << endl;
    arch << "VEHICULOS DE LA EMPRESA:" << endl;
    arch << left << setw(10) << "PLACA" << setw(15) << "MARCA" << "MODELO" << endl;
    for (auto &par : vehiculos)
        arch << par.second;
    arch << "MULTAS IMPUESTAS" << endl;
    arch << left << setw(12) << "PLACA" << setw(13) << "FECHA" << setw(14)
         << "COD. INFRAC." << right << setw(10) << "MULTA" << "   " << left
         << setw(8) << "PAGADA" << "FECHA DE PAGO" << endl;
    for (Multa &m : multasRecibidas)
        arch << m;
}

void operator<<(ofstream &arch, Empresa &empresa) {
    empresa.imprime(arch);
}

bool Empresa::operator<(Empresa &orig) {
    return (this->getDni() < orig.getDni());
}

void Empresa::cargarVehiculo(Vehiculo &vehiculo) {
    string placa = vehiculo.getPlaca();
    vehiculos[placa] = vehiculo;
}

bool Empresa::operator==(Multa &multa) {
    string placa = multa.getPlaca();
    auto it = vehiculos.find(placa);
    if (it != vehiculos.end())
        return true;
    else
        return false;
}

void Empresa::agregarMulta(Multa &multa) {
    multasRecibidas.push_back(multa);
}

void Empresa::ordenarMultas() {
    // Descendente por fecha (usa Multa::operator>)
    sort(multasRecibidas.begin(), multasRecibidas.end(), greater<Multa>());
}

void Empresa::eliminarMultasPagadas() {
    vector<Multa>::iterator it = multasRecibidas.begin();
    while (it != multasRecibidas.end()) {
        if (it->getPagada())
            it = multasRecibidas.erase(it);   // erase devuelve el siguiente
        else
            ++it;
    }
}