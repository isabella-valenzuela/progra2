/*
 * BibliotecaGenerica.h
 * Lista genérica simplemente ligada (Figura 1 del enunciado).
 */
#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

enum Cabecera {INICIO, LONGITUD};   // posiciones de la cabecera de la lista
enum Nodo {DATO, SIGUIENTE};        // posiciones de un nodo

void procesaArreglo(void **arreglo, void *(*lee)(ifstream &), const char *nombArch);
void creaLista(void **arreglo, void *&lista, int (*compara)(const void *, const void *));
void generaLista(void *&lista);
void insertaLista(void *lista, void *dato);
void fusionaListas(void *lista1, void *lista2, int (*verifica)(const void *, const void *));
void imprimeLista(void *lista, void (*imprime)(ofstream &, void *), const char *nombArch);

#endif
