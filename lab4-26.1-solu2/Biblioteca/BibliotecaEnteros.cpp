/*
 * BibliotecaEnteros.cpp
 * Funciones propias del archivo de números: es la única que sabe que el dato es un int.
 */
#include <fstream>
#include "BibliotecaEnteros.h"
using namespace std;

// Lee un entero y lo devuelve como void*. Devuelve nullptr al terminar el archivo.
void *leenum(ifstream &input) {
    int num;
    if (not (input >> num)) return nullptr;
    return new int(num);
}

// Para qsort: recibe la DIRECCIÓN de cada elemento del arreglo (un void *),
// por eso se desreferencia una vez antes de llegar al int.
int comparanum(const void *a, const void *b) {
    int *x = (int *) *(void **) a;
    int *y = (int *) *(void **) b;
    return *x - *y;
}

// Para fusionaListas: recibe directamente los datos (punteros a int).
int verificanum(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void imprimenum(ofstream &output, void *dato) {
    output << *(int *) dato << endl;
}
