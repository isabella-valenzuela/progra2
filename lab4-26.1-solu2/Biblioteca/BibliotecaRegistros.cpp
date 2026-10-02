/*
 * BibliotecaRegistros.cpp
 * Funciones propias del archivo de atenciones.
 * Registro = void ** con 9 posiciones (ver enum Atencion):
 *   CODIGO, FECHA (aaaammdd) y HORA (hhmm) apuntan a int; el resto a char *.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaRegistros.h"
using namespace std;

int leeFecha(ifstream &input);
int leeHora(ifstream &input);
char *leeCadena(ifstream &input, char delimitador);
int comparaAtenciones(void **a, void **b);
void imprimeEncabezado(ofstream &output);
void imprimeFecha(ofstream &output, int fecha);
void imprimeHora(ofstream &output, int hora);

// Formato: codigo,dd/mm/aaaa,motivo,hh:mm,estado,nombre,raza,color,especie
void *leeregistro(ifstream &input) {
    int codigo;
    if (not (input >> codigo)) return nullptr;       // fin de archivo
    input.get();                                      // coma después del código
    void **registro = new void *[NUMCAMPOS]{};
    registro[CODIGO] = new int(codigo);
    registro[FECHA] = new int(leeFecha(input));
    registro[MOTIVO] = leeCadena(input, ',');
    registro[HORA] = new int(leeHora(input));
    registro[ESTADO] = leeCadena(input, ',');
    registro[NOMBRE] = leeCadena(input, ',');
    registro[RAZA] = leeCadena(input, ',');
    registro[COLOR] = leeCadena(input, ',');
    registro[ESPECIE] = leeCadena(input, '\n');
    return registro;
}

// Para qsort: cada elemento del arreglo es un void * que apunta a un registro.
int comparareg(const void *a, const void *b) {
    void **ra = (void **) *(void **) a;
    void **rb = (void **) *(void **) b;
    return comparaAtenciones(ra, rb);
}

// Para fusionaListas: recibe directamente los registros.
int verificareg(const void *a, const void *b) {
    return comparaAtenciones((void **) a, (void **) b);
}

void imprimeregistro(ofstream &output, void *dato) {
    void **registro = (void **) dato;
    if (output.tellp() == streampos(0)) imprimeEncabezado(output);   // primer registro del archivo
    imprimeFecha(output, *(int *) registro[FECHA]);
    output << "  ";
    imprimeHora(output, *(int *) registro[HORA]);
    output << "  " << left << setw(8) << *(int *) registro[CODIGO]
           << setw(20) << (char *) registro[NOMBRE]
           << setw(18) << (char *) registro[RAZA]
           << (char *) registro[COLOR] << endl;
}

// ---------------------------- funciones auxiliares ----------------------------

// Lee dd/mm/aaaa (día y mes con 1 o 2 dígitos) y la coma siguiente. Devuelve aaaammdd.
int leeFecha(ifstream &input) {
    int dia, mes, anio;
    char c;
    input >> dia >> c >> mes >> c >> anio;
    input.get();
    return anio * 10000 + mes * 100 + dia;
}

// Lee hh:mm y la coma siguiente. Devuelve hhmm.
int leeHora(ifstream &input) {
    int hh, mm;
    char c;
    input >> hh >> c >> mm;
    input.get();
    return hh * 100 + mm;
}

// Lee hasta el delimitador (los textos pueden tener espacios) y los guarda en memoria exacta.
char *leeCadena(ifstream &input, char delimitador) {
    char buffer[100];
    input.getline(buffer, 100, delimitador);
    int n = strlen(buffer);
    if (n > 0 and buffer[n - 1] == '\r') buffer[--n] = '\0';   // salto de línea tipo Windows
    char *cadena = new char[n + 1];
    strcpy(cadena, buffer);
    return cadena;
}

// Ordena por fecha, luego por hora; el código solo desempata para que el orden sea estable.
int comparaAtenciones(void **a, void **b) {
    int fa = *(int *) a[FECHA], fb = *(int *) b[FECHA];
    if (fa != fb) return fa - fb;
    int ha = *(int *) a[HORA], hb = *(int *) b[HORA];
    if (ha != hb) return ha - hb;
    return *(int *) a[CODIGO] - *(int *) b[CODIGO];
}

void imprimeEncabezado(ofstream &output) {
    output << "Reporte" << endl << endl;
    output << left << setw(12) << "FECHA" << setw(7) << "HORA" << setw(8) << "CODIGO"
           << setw(20) << "NOMBRE" << setw(18) << "RAZA" << "COLOR" << endl;
    output << setfill('=') << setw(76) << "" << setfill(' ') << endl;
}

// "right" es necesario: el flujo trae "left" activo y el cero de relleno debe ir a la izquierda.
void imprimeFecha(ofstream &output, int fecha) {
    output << fecha / 10000 << '/' << right << setfill('0') << setw(2) << fecha / 100 % 100
           << '/' << setw(2) << fecha % 100 << setfill(' ');
}

void imprimeHora(ofstream &output, int hora) {
    output << right << setfill('0') << setw(2) << hora / 100 << ':' << setw(2) << hora % 100 << setfill(' ');
}
