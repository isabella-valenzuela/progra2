/*
 * Archivo: main.cpp
 * Autor: Ana C. Roncal N.
 * Creado el 23 de Octubre del 2026 a las 08:02 a.m.
 */

#include <iostream>
using namespace std;
#include "Biblioteca/Tesoreria.h"

int main(int argc, char** argv)
{
    class Tesoreria tesoreria;
    tesoreria.cargaEscalas("ArchivosDeDatos/escalas.csv");
    tesoreria.cargaAlumnos("ArchivosDeDatos/alumnos.csv");
    tesoreria.actualiza(19.5);
    tesoreria.imprime("ArchivosDeReporte/ReporteAlumnos.txt");
    return 0;
}