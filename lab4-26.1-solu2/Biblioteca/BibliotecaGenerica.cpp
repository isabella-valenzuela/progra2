/*
 * BibliotecaGenerica.cpp
 * No conoce el tipo de los datos: lo que depende del tipo (leer, comparar,
 * imprimir) llega por punteros a función.
 *
 * Estructuras (ambas son arreglos de 2 void*):
 *   cabecera de la lista: [INICIO]  -> primer nodo (nullptr si está vacía)
 *                         [LONGITUD]-> int con la cantidad de nodos
 *   nodo:                 [DATO]    -> el dato (void*)
 *                         [SIGUIENTE]-> siguiente nodo (nullptr si es el último)
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BibliotecaGenerica.h"
using namespace std;

int cuentaArreglo(void **arreglo);
void **buscaUltimo(void **nodo);
void avanzaHasta(void **&anterior, void **&actual, void *dato,
                 int (*verifica)(const void *, const void *));
void retiraPrimero(void **cabecera);
void **enlazaNodo(void **cabecera, void **anterior, void **nodo, void **siguiente);

// Lee el archivo con el puntero a función "lee" y guarda los datos en el arreglo.
// El arreglo llega lleno de nullptr, así que queda terminado en nullptr.
void procesaArreglo(void **arreglo, void *(*lee)(ifstream &), const char *nombArch) {
    ifstream input(nombArch, ios::in);
    if (not input.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int n = 0;
    void *dato;
    while (true) {
        dato = lee(input);
        if (dato == nullptr) break;      // lee devuelve nullptr al terminar el archivo
        arreglo[n++] = dato;
    }
}

// Ordena el arreglo con qsort y lo mueve a una lista nueva.
void creaLista(void **arreglo, void *&lista, int (*compara)(const void *, const void *)) {
    int n = cuentaArreglo(arreglo);
    qsort(arreglo, n, sizeof(void *), compara);   // ascendente según "compara"
    generaLista(lista);
    for (int i = 0; i < n; i++) {
        insertaLista(lista, arreglo[i]);          // inserta al final: conserva el orden
        arreglo[i] = nullptr;                      // el dato se MUEVE: el arreglo queda
    }                                              // libre para volver a usarse
}

// Crea la lista vacía de la Figura 2: inicio en nullptr y longitud en 0.
void generaLista(void *&lista) {
    void **cabecera = new void *[2]{};
    cabecera[INICIO] = nullptr;
    cabecera[LONGITUD] = new int{0};
    lista = cabecera;
}

// Inserta el dato al final de la lista y actualiza la longitud.
void insertaLista(void *lista, void *dato) {
    void **cabecera = (void **) lista;
    void **nuevo = new void *[2]{};
    nuevo[DATO] = dato;
    if (cabecera[INICIO] == nullptr)
        cabecera[INICIO] = nuevo;
    else
        buscaUltimo((void **) cabecera[INICIO])[SIGUIENTE] = nuevo;
    (*(int *) cabecera[LONGITUD])++;
}

// Mezcla lista2 dentro de lista1 sin crear nodos ni listas: solo se re-enlazan
// los nodos de lista2. Las dos longitudes se actualizan nodo a nodo.
// "verifica(a, b) <= 0" significa que a va antes (o es igual) que b.
void fusionaListas(void *lista1, void *lista2, int (*verifica)(const void *, const void *)) {
    void **cab1 = (void **) lista1, **cab2 = (void **) lista2;
    void **anterior = nullptr, **actual = (void **) cab1[INICIO];
    while (cab2[INICIO] != nullptr) {
        void **nodo = (void **) cab2[INICIO];           // primer nodo pendiente de lista2
        avanzaHasta(anterior, actual, nodo[DATO], verifica);
        retiraPrimero(cab2);                            // sale de lista2 (longitud - 1)
        anterior = enlazaNodo(cab1, anterior, nodo, actual);   // entra a lista1 (longitud + 1)
    }
}

void imprimeLista(void *lista, void (*imprime)(ofstream &, void *), const char *nombArch) {
    ofstream output(nombArch, ios::out);
    if (not output.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    void **cabecera = (void **) lista;
    for (void **nodo = (void **) cabecera[INICIO]; nodo != nullptr; nodo = (void **) nodo[SIGUIENTE])
        imprime(output, nodo[DATO]);
}

// ---------------------------- funciones auxiliares ----------------------------

int cuentaArreglo(void **arreglo) {
    int n = 0;
    while (arreglo[n] != nullptr) n++;
    return n;
}

void **buscaUltimo(void **nodo) {
    while (nodo[SIGUIENTE] != nullptr)
        nodo = (void **) nodo[SIGUIENTE];
    return nodo;
}

// Avanza en lista1 mientras su dato deba ir antes (o ser igual) que "dato".
// Los empates quedan con el dato de lista1 primero.
void avanzaHasta(void **&anterior, void **&actual, void *dato,
                 int (*verifica)(const void *, const void *)) {
    while (actual != nullptr and verifica(actual[DATO], dato) <= 0) {
        anterior = actual;
        actual = (void **) actual[SIGUIENTE];
    }
}

// Desconecta el primer nodo de la lista (el nodo NO se libera) y baja la longitud.
void retiraPrimero(void **cabecera) {
    void **primero = (void **) cabecera[INICIO];
    cabecera[INICIO] = primero[SIGUIENTE];
    (*(int *) cabecera[LONGITUD])--;
}

// Mete "nodo" entre "anterior" y "siguiente" y sube la longitud. Devuelve el nodo.
void **enlazaNodo(void **cabecera, void **anterior, void **nodo, void **siguiente) {
    nodo[SIGUIENTE] = siguiente;
    if (anterior == nullptr)
        cabecera[INICIO] = nodo;
    else
        anterior[SIGUIENTE] = nodo;
    (*(int *) cabecera[LONGITUD])++;
    return nodo;
}
