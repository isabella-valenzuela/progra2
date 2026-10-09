/*
 * Archivo: main.cpp
 * Autor: Ana C. Roncal N.
 * Creado el 07 de 10 del 2026 a las 10:24
 */

#include <iostream>
using namespace std;
#include "Biblioteca/Sistema.h"

int main(int argc, char** argv)
{
    class Sistema sistema;
    sistema << "ArchivosDeDatos/vehiculos.csv";
    sistema >> "ArchivosDeReportes/ReportesVehiculos.txt";
    return 0;
}