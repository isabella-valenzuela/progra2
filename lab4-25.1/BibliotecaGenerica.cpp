//
// Created by renat on 2/5/2026.
//

#include "BibliotecaGenerica.hpp"
void creaLista(void *& lista,void* (*lee)(ifstream &),int (*clasifica)(void *&)
    , const char* nomArch) {
    generalista(lista);
    ifstream input(nomArch, ios::in);
    while (true) {
        void *dato;
        dato = lee(input);
        if (input.eof()) break;
        insertaLista(lista, dato,clasifica);
    }
}
void generalista(void *&lista) {
    void **listaAbierta = new void *[2]{};
    void **bloque1 = new void *[2]{};
    void **bloque2 = new void *[2]{};
    listaAbierta[PRIMERBLOQUE] = bloque1;
    listaAbierta[SEGUNDOBLOQUE] = bloque2;
    bloque1[SIGUIENTE] = bloque2;
    lista = listaAbierta;
}
void insertaLista(void *&lista,void *dato,int (*clasifica) (void *&)) {
    void **listaAbierta = (void **) lista;
    int numBloque = clasifica(dato);
    void **nuevoNodo = new void *[2]{};
    nuevoNodo[DATO] = dato;
    if (numBloque == 1) nuevoNodo[SIGUIENTE] = listaAbierta[SEGUNDOBLOQUE];
    if (numBloque==1) {
        void **primerNodoBloque = (void **) listaAbierta[PRIMERBLOQUE];
        if (primerNodoBloque[DATO] ==nullptr) {
            listaAbierta[PRIMERBLOQUE] = nuevoNodo;
        }
        else {
            void **anterior = (void **) buscarAnterior(primerNodoBloque, numBloque, clasifica);
            anterior[SIGUIENTE] = nuevoNodo;
        }
    }
    else {
        void **primerNodoBloque2 = (void **) listaAbierta[SEGUNDOBLOQUE];
        if (primerNodoBloque2[DATO] ==nullptr) {
            listaAbierta[SEGUNDOBLOQUE] = nuevoNodo;
        }
        else {
            void **anterior = (void **) buscarAnterior(primerNodoBloque2, numBloque, clasifica);
            anterior[SIGUIENTE] = nuevoNodo;
        }
    }
}
void *buscarAnterior(void *inicioRecorrido,int numBloque,int (*clasifica)(void *&)) {
    void ** recorrido = (void **) inicioRecorrido;
    void * anterior = nullptr;
    while (recorrido != nullptr) {
        if (numBloque != clasifica(recorrido[DATO])) break;
        anterior = recorrido;
        recorrido = (void **) recorrido[SIGUIENTE];
    }
    return anterior;
}

void imprimeLista(void *lista,void (*imprime)(ofstream &, void *),const char* nomArch) {
    ofstream output(nomArch, ios::out);
    void **listaAbierta = (void **) lista;
    void **recorrido = (void **) listaAbierta[PRIMERBLOQUE];
    while (recorrido != nullptr) {
        imprime(output, recorrido[DATO]);
        recorrido = (void **) recorrido[SIGUIENTE];
    }
}










