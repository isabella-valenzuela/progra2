//
// Created by Isabella on 19/11/2026.
//

#ifndef LAB9_25_2_EMPRESA_H
#define LAB9_25_2_EMPRESA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include "Vehiculo.h"
#include "Multa.h"
using namespace std;

class Empresa {
private:
    int dni;
    string nombre;
    string distrito;
    map <string, class Vehiculo> vehiculos;
    vector <class Multa> multasRecibidas;
    void inicializar();
public:
    Empresa();
    ~Empresa();

    int getDni();
    string getNombre();
    string getDistrito();

    void setDni(int dni);
    void setNombre(string nombre);
    void setDistrito(string distrito);
    bool operator<(Empresa &orig);
    void cargarVehiculo(Vehiculo &vehiculo);

    bool operator==(Multa &multa);
    void agregarMulta(Multa &multa);
    void ordenarMultas();
    void eliminarMultasPagadas();
    void imprime(ofstream &arch);
};

void operator >>(ifstream &arch, Empresa &empresa);
void operator <<(ofstream &arch, Empresa &empresa);

#endif //LAB9_25_2_EMPRESA_H
