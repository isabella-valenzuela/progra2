//
// Created by anaro on 13/05/2026.
//
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
#include "Sistema.h"
#include "Accesorio.h"

Sistema::Sistema()
{
    vehiculos = nullptr;
    numVehiculos = 0;
}

Sistema::~Sistema()
{
    if (vehiculos) delete [] vehiculos;
}

void Sistema::operator<<(const char* nombArch)
{
    ifstream archivo(nombArch, ios::in);
    if (not archivo.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    Vehiculo buffVehiculos[25]{};
    int numDat = 0;
    while (true)
    {
        //leo un vehiculo
        archivo >> buffVehiculos[numDat];
        if (archivo.eof()) break;
        numDat++;
    }
    vehiculos = new Vehiculo[numDat]{};
    for (int i = 0; i < numDat; i++)
        vehiculos[i] = buffVehiculos[i];
    numVehiculos = numDat;
}

void Sistema::operator>>(const char* nombArch)
{
    ofstream archivo(nombArch, ios::out);
    if (not archivo.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }

    for (int i = 0; i < numVehiculos; i++)
        archivo << vehiculos[i];
}
