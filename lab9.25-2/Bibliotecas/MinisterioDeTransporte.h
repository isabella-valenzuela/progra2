//
// Created by Isabella on 19/11/2026.
//

#ifndef LAB9_25_2_MINISTERIODETRANSPORTE_H
#define LAB9_25_2_MINISTERIODETRANSPORTE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
#include "Infraccion.h"
#include "Empresa.h"
using namespace std;

class MinisterioDeTransporte {
private:
    list<class Infraccion> tablaInfracciones;
    list<class Empresa> listaEmpresas;
    ifstream abrirIfstream(const char* nombArch);
    ofstream abrirOfstream(const char* nombArch);
public:
    MinisterioDeTransporte();
    ~MinisterioDeTransporte();

    void cargaDeInfracciones(const char*nombArch);
    void cargaEmpresas(const char*nombArch);
    void cargaVehiculos(const char*nombArch);
    void cargaInfraccionesCometidas(const char*nombArch);
    void reporteDeEmpresasConInfracciones(const char*nombArch);
    void eliminaInfraccionesPagadas();

};

#endif //LAB9_25_2_MINISTERIODETRANSPORTE_H
