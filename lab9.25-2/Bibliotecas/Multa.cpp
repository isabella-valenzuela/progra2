//
// Created by Isabella on 19/11/2026.
//

#include "Multa.h"

void Multa::inicializar() {
    fecha = 0;
    placa = "";
    codMulta ="";
    multa = 0.0;
    pagada = false;
    fechaDePago = 0;
}

Multa::Multa() {
    inicializar();
}

Multa::~Multa() {
}

Multa::Multa(const Multa &orig) {
    inicializar();
    *this = orig;
}

void Multa::operator=(const Multa &orig) {
    fecha = orig.fecha;
    placa = orig.placa;
    codMulta = orig.codMulta;
    multa = orig.multa;
    pagada = orig.pagada;
    fechaDePago = orig.fechaDePago;
}

int Multa::getFecha() {
    return fecha;
}

string Multa::getPlaca() {
    return placa;
}

string Multa::getCodMulta() {
    return codMulta;
}

double Multa::getMulta() {
    return multa;
}

bool Multa::getPagada() {
    return pagada;
}

int Multa::getFechaDePago() {
    return fechaDePago;
}

void Multa::setFecha(int fecha) {
    this->fecha = fecha;
}

void Multa::setPlaca(string placa) {
    this->placa = placa;
}

void Multa::setCodMulta(string codMulta) {
    this->codMulta = codMulta;
}

void Multa::setMulta(double multa) {
    this->multa = multa;
}

void Multa::setPagada(bool pagada) {
    this->pagada = pagada;
}

void Multa::setFechaDePago(int fecha) {
    this->fechaDePago = fecha;
}

void operator>>(ifstream &arch, Multa &mul) {
    int aa, mm, dd, fecha;
    char c;
    string buffer;
    arch>>dd>>c>>mm>>c>>aa>>c;
    fecha = dd + mm*100 + aa*10000;
    mul.setFecha(fecha);
    getline(arch, buffer, ',');
    mul.setPlaca(buffer);
    getline(arch, buffer, ',');
    mul.setCodMulta(buffer);
    arch>>c;
    mul.setPagada(c == 'P');
    if (c == 'P') {
        arch>>c;
        arch>>dd>>c>>mm>>c>>aa;
        fecha = dd + mm*100 + aa*10000;
        mul.setFechaDePago(fecha);
    }else {
        mul.setFechaDePago(0);
    }

}

void Multa::imprimeFecha(ofstream &arch, int fecha) {
    // fecha viene como aaaammdd -> imprime dd/mm/aaaa
    arch << right << setfill('0')
         << setw(2) << fecha % 100 << '/'
         << setw(2) << (fecha / 100) % 100 << '/'
         << setw(4) << fecha / 10000
         << setfill(' ') << left;
}

void Multa::imprime(ofstream &arch) {
    arch << fixed << setprecision(2) << left << setw(12) << placa;
    imprimeFecha(arch, fecha);
    arch << "   " << setw(14) << codMulta << right << setw(10) << multa
         << "   " << left << setw(8) << (pagada ? "SI" : "NO");
    if (pagada) imprimeFecha(arch, fechaDePago);
    arch << endl;
}

void operator<<(ofstream &arch, Multa &mul) {
    mul.imprime(arch);
}

bool Multa::operator<(const Multa &mul) const {
    return fecha < mul.fecha;
}

bool Multa::operator>(const Multa &mul) const {
    return fecha > mul.fecha;
}

void Multa::agregarMonto(double multa) {
    this->multa = multa;
}


