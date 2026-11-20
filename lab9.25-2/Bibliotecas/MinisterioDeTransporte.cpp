//
// Created by Isabella on 19/11/2026.
//

#include "MinisterioDeTransporte.h"

MinisterioDeTransporte::MinisterioDeTransporte() {
}
MinisterioDeTransporte::~MinisterioDeTransporte() {
}

void MinisterioDeTransporte::cargaDeInfracciones(const char *nombArch) {
    ifstream arch = abrirIfstream(nombArch);
    Infraccion infraccion;
    while (true) {
        arch>>infraccion;
        if (arch.eof()) break;
        tablaInfracciones.push_back(infraccion);
    }
    tablaInfracciones.sort();
}

void MinisterioDeTransporte::cargaEmpresas(const char *nombArch) {
    ifstream arch = abrirIfstream(nombArch);
    Empresa empresa;
    while (true) {
        arch>>empresa;
        if (arch.eof()) break;
        listaEmpresas.push_back(empresa);
    }
    listaEmpresas.sort();
}

void MinisterioDeTransporte::cargaVehiculos(const char *nombArch) {
    ifstream arch = abrirIfstream(nombArch);
    int dni;
    Vehiculo vehiculo;
    while (true) {
        arch>>dni;
        if (arch.eof()) break;
        arch.get();
        arch>>vehiculo;
        for (class Empresa &e : listaEmpresas) {
            if (e.getDni() == dni) {
                e.cargarVehiculo(vehiculo);
                break;
            }
        }
    }
}

void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *nombArch) {
    ifstream arch = abrirIfstream(nombArch);
    Multa multa;
    while (true) {
        arch>>multa;
        if (arch.eof()) break;
        for (class Infraccion &i : tablaInfracciones) {
            if (i.getCodigo() == multa.getCodMulta()) {
                multa.agregarMonto(i.getMulta());
                break;
            }
        }
        for (class Empresa &e : listaEmpresas) {
            if (e == multa) {
                e.agregarMulta(multa);
                break;
            }
        }
    }
    for (class Empresa &e : listaEmpresas)
        e.ordenarMultas();
}

void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char *nombArch) {
    ofstream arch = abrirOfstream(nombArch);
    arch << string(110, '=') << endl;
    arch << string(25, ' ') << "RELACIÓN DE EMPRESAS CON INFRACCIONES DE TRANSITO" << endl;
    arch << string(110, '-') << endl;
    for (class Empresa &e : listaEmpresas) {
        arch << e;                              // la impresión la hace Empresa
        arch << string(110, '-') << endl;
    }
    arch << string(110, '=') << endl;
}

void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
    for (class Empresa &e : listaEmpresas)      // & para modificar la original
        e.eliminarMultasPagadas();
}

ifstream MinisterioDeTransporte::abrirIfstream(const char *nombArch) {
    ifstream arch = ifstream(nombArch,ios::in);
    if (not arch.is_open()) {
        cout <<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    return arch;
}

ofstream MinisterioDeTransporte::abrirOfstream(const char *nombArch) {
    ofstream arch = ofstream(nombArch,ios::out);
    if (not arch.is_open()) {
        cout <<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    return arch;
}
