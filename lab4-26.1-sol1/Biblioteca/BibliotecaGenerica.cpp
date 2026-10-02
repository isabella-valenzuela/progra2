//
// Created by alulab14 on 8/05/2026.
//

#include "BibliotecaGenerica.h"
void procesaArreglo (void **arr,void *(*lee)(ifstream &),const char *nombArch) {
    void *dato;
    ifstream archLectura (nombArch, ios::in);
    int i=0;
    while (true) {
        dato = lee(archLectura);
        if (archLectura.eof()) break;
        arr[i] = dato;
        i++;
    }
}

void creaLista(void **arr,void *&lista,int (*comparar)(const void *,const void *)) {

    int i=0;
    void *dato;
    //Saca numero de datos
    while (arr[i]!=nullptr) i++;
    qsort(arr,i,sizeof(void *),comparar);
    for (int i = 0; arr[i]!=nullptr; i++) {
        cout <<*(int*) arr[i] << endl;
    }
    generaLista(lista);
    int *longitudLista=new int;
    *longitudLista=i;
    //lista[LONGITUDLISTA]=longitudLista;
    int j=0;
    while (arr[j]!=nullptr) {
        dato = arr[j];
        insertaLista(lista,longitudLista,dato);
        j++;

    }


}

void generaLista(void *&lista) {
    void **listaAbierta=new void *[2]{};
    lista=listaAbierta;
}

void insertaLista(void *&lista,int *longitudLista,void *dato) {
    void **listaAbierta=(void**)lista;
    listaAbierta[LONGITUDLISTA]=longitudLista;
    void **nodo=new void *[2]{};
    nodo[DATO]=dato;
    if (listaAbierta[PRIMERNODO]==nullptr) {
        listaAbierta[PRIMERNODO]=nodo;
        nodo[SIGUIENTE]=nullptr;
    }else {
        void **ultimo=(void**)obtenerUltimoNodo(listaAbierta);
        ultimo[SIGUIENTE]=nodo;
        nodo[SIGUIENTE]=nullptr;
    }
    lista=listaAbierta;
}

void *obtenerUltimoNodo(void *lista) {
    void *ultimo;
    void **recorrido=(void **) lista;
    while (recorrido!=nullptr) {
        ultimo=recorrido;
        recorrido=(void**)recorrido[SIGUIENTE];
    }
    return ultimo;
}

void imprimeLista(void *&lista,void (*imprime)(ofstream&,void *),const char *nombArch) {
    ofstream archReporte(nombArch, ios::out);
    void **recorrido=(void**)lista;
    while (recorrido!=nullptr) {
        imprime(archReporte,recorrido[DATO]);
        recorrido=(void**) recorrido[SIGUIENTE];
    }
}