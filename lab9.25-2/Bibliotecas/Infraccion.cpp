//
// Created by Isabella on 19/11/2026.
//

#include "Infraccion.h"

void Infraccion::inicializar() {
    codigo = "";
    double multa;
    gravedad = "";
    descripcion = "";
}

Infraccion::Infraccion() {
    inicializar();

}

Infraccion::~Infraccion() {
}

Infraccion::Infraccion(const Infraccion &orig) {
    inicializar();
    *this = orig;
}

void Infraccion::operator=(const Infraccion &orig) {
    codigo = orig.codigo;
    gravedad = orig.gravedad;
    descripcion = orig.descripcion;
    multa = orig.multa;
}

string Infraccion::getCodigo() {
    return codigo;
}

double Infraccion::getMulta() {
    return multa;
}

string Infraccion::getGravedad() {
    return gravedad;
}


string Infraccion::getDescripcion() {
    return descripcion;
}

void Infraccion::setCodigo(string codigo) {
    this->codigo = codigo;
}

void Infraccion::setMulta(double multa) {
    this->multa = multa;
}

void Infraccion::setGravedad(string gravedad) {
    this->gravedad = gravedad;
}

void Infraccion::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void operator>>(ifstream &arch, Infraccion &inf) {
    string buffer;
    getline(arch, buffer, ',');
    inf.setCodigo(buffer);
    double multa;
    arch>>multa;
    inf.setMulta(multa);
    arch.get();
    getline(arch, buffer, ',');
    inf.setGravedad(buffer);
    getline(arch, buffer, '\n');
    inf.setDescripcion(buffer);
}

void operator<<(ofstream &arch, Infraccion &inf) {
    arch << left << setw(10) << inf.getCodigo() << fixed << setprecision (2)
<<     setw(10) << inf.getMulta() << endl;
}

bool Infraccion::operator<(Infraccion &infraccion) {
    return this->getCodigo() < infraccion.getCodigo();
}
