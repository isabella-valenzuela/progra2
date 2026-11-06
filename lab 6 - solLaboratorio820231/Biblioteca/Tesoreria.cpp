//
// Created by anaro on 28/05/2026.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Tesoreria.h"
#define INCREMENTO 5

Tesoreria::Tesoreria()
{
    lpresencial = nullptr;
    lvirtual = nullptr;
}

Tesoreria::~Tesoreria()
{
    if (lpresencial) delete [] lpresencial;
    if (lvirtual) delete [] lvirtual;
}

void Tesoreria::cargaEscalas(const char* nombArch)
{
    ifstream archivo(nombArch, ios::in);
    if (not archivo.is_open())
    {
        cout << "Error en el archivo de entrada" << endl;
        exit(1);
    }

    class Escala escala;
    while (true)
    {
        escala.leeDatos(archivo);
        if (archivo.eof()) break;
        lescala[escala.getCodigo()-1] = escala;
    }
}

//S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,30
void Tesoreria::cargaAlumnos(const char* nombArch)
{
    ifstream archivo(nombArch, ios::in);
    if (not archivo.is_open())
    {
        cout << "Error en el archivo de entrada" << endl;
        exit(1);
    }

    char tipo;
    class Presencial auxPresencial[100]{}; // para la memoria exacta
    lvirtual = nullptr;
    int numDat = 0, capacidad = 0;
    int cantPresencial = 0;
    int cantSemiPresencial = 0;

    while (true)
    {
        archivo >> tipo;
        if (archivo.eof()) break;
        archivo.get();
        switch (tipo)
        {
            case 'P':
                //usando buffer de memoria exacta
                auxPresencial[cantPresencial++].leerDatos(archivo);
                break;
            case 'S':
                //arreglo estatico
                lsemipresencial[cantSemiPresencial++].leerDatos(archivo);
                break;
            case 'V':
                 // memoria por incrementos
                 if (numDat == capacidad)
                     incrementarLosEspacios(lvirtual, numDat, capacidad);
                 lvirtual[numDat-1].leerDatos(archivo);
                 numDat++;
                break;
        }
    }
    lpresencial = new Presencial[cantPresencial+1];
    for (int i = 0; i < cantPresencial; i++)
        lpresencial[i] = auxPresencial[i];
}

void Tesoreria::incrementarLosEspacios(Virtual*& datos, int& numDatos, int& capacidad)
{
    Virtual * aux;
    capacidad += INCREMENTO;
    if (datos == nullptr)
    {
        datos = new Virtual[capacidad];
        numDatos = 1;
    }else
    {
        aux = new Virtual[capacidad];
        for (int i = 0; i < numDatos; i++)
            aux[i] = datos[i];
        delete [] datos;
        datos = aux;
    }
}

void Tesoreria::actualiza(double creditos)
{
    int esc;
    double precio;
    for (int i = 0; lpresencial[i].getCodigo(); i++)
    {
        esc = lpresencial[i].getEscala();
        precio = creditos * lescala[esc-1].getPrecio();
        lpresencial[i].actualiza(precio);
    }
    for (int i = 0; lsemipresencial[i].getCodigo(); i++)
    {
        esc = lsemipresencial[i].getEscala();
        precio = creditos * lescala[esc-1].getPrecio();
        lsemipresencial[i].actualiza(precio);
    }
    for (int i = 0; lvirtual[i].getCodigo(); i++)
    {
        esc = lvirtual[i].getEscala();
        precio = creditos * lescala[esc-1].getPrecio();
        lvirtual[i].actualiza(precio);
    }

}

void Tesoreria::imprime(const char* nombArch)
{
    ofstream archivo(nombArch, ios::out);
    if (not archivo.is_open())
    {
        cout << "Error en el archivo de salida" << endl;
        exit(1);
    }

    for (int i = 0; lescala[i].getCodigo(); i++)
        lescala[i].mostrar(archivo);

    archivo << left << setw(25) << "CODIGO" <<
        setw(25) << "NOMBRE" <<
        setw(10) << "ESCALA" <<
        setw(12) << "LICENCIA" <<
        setw(10) << "TOTAL" << endl;
    archivo.precision(2);
    archivo << fixed;
    archivo << "========PRESENCIAL=======" << endl;
    for (int i = 0; lpresencial[i].getCodigo(); i++)
        lpresencial[i].mostrarDatos(archivo);

    archivo << "======SEMIPRESENCIAL=====" << endl;
    for (int i = 0; lsemipresencial[i].getCodigo(); i++)
        lsemipresencial[i].mostrarDatos(archivo);

    archivo << "=========VIRTUAL=========" << endl;
    for (int i = 0; lvirtual[i].getCodigo(); i++)
        lvirtual[i].mostrarDatos(archivo);
}
