//
// Created by Isabella on 22/09/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
enum camposStreamer {CUENTA, TIEMPOTOTAL,PROMESPECT, SEGUIDORES, CATEGORIA, COMENTARIOS};
enum camposComentario {CODIGO, TEXTO, EMISOR, RECEPTOR};
#define INCREMENTO5 5

void cargaStreamers(void *&streamers) {
    ifstream arch = abrirIfstream("ArchivosDeDatos/streamers.csv");
    void **streamersExacto = nullptr, *unStreamer;
    int nd= 0 , cap = 0;
    while (true) {
        leerArchivoStreamers(arch, unStreamer);
        if (arch.eof()) break;if (nd == cap) {
            incrementarEspacios(streamersExacto, nd, cap);
        }
        streamersExacto[nd] = unStreamer;
        nd++;
    }

    streamers = streamersExacto;
    imprimirReporteStreamers(streamers) ;

}

void cargaComentarios(void *&comentarios) {
    void **comentariosExacto=nullptr, *unComentario;
    int nd =0, cap= 0;
    ifstream arch = abrirIfstream("ArchivosDeDatos/comentarios.csv");
    while (true) {
        leerArchivoComentarios(arch, unComentario);
        if (arch.eof()) break;
        if (nd==cap) {
            incrementarEspacios(comentariosExacto, nd, cap);
        }
        comentariosExacto[nd] = unComentario;
        nd++;
    }
    comentarios = comentariosExacto;
    imprimirReporteComentarios(comentarios) ;
}

void actualizaComentarios(void *&streamers, void *&comentarios) {
    void **streamersAux = (void**)streamers;
    void **comentariosAux = (void**)comentarios;
    for (int i = 0; streamersAux[i]; i++) {
        void **unStreamer = (void**)streamersAux[i];
        char *cuentaStreamer = (char*)unStreamer[CUENTA];
        int nd = 0, cap = 0;
        buscarComentarios(comentariosAux, cuentaStreamer, unStreamer, nd, cap);
    }
}

void imprimeStreamers(void *&streamers) {
    ofstream arch = abrirOfstream("ArchivosDeReporte/reporteFinal.txt");
    void **streamersAux = (void**)streamers;
    for (int i = 0; streamersAux[i]; i++) {
        imprimirLinea(arch, 120, '=');
        void **unStreamer = (void**)streamersAux[i];
        arch<<left<<setw(20)<<"Cuenta"<<setw(20)<<"Seguidores"<<endl;
        arch<<left<<setw(20)<<(char *)unStreamer[CUENTA]<<setw(20)<<*(int *)unStreamer[SEGUIDORES]<<endl;
        imprimirLinea(arch, 120, '-');
        arch<<left<<"Comentarios emitidos: "<<endl;
        imprimirLinea(arch, 120, '-');
        arch<<left<<setw(20)<<"Receptor"<<setw(20)<<"Texto"<<endl;
        imprimirLinea(arch, 120, '-');
        imprimirComentariosEmitidos(arch, unStreamer[COMENTARIOS]);
    }
}

void imprimirComentariosEmitidos(ofstream &arch, void *unStreamerComentarios) {
    void **comentariosDeStreamer = (void**)unStreamerComentarios;
    if (unStreamerComentarios == nullptr) return;
    for (int i = 0; comentariosDeStreamer[i]; i++) {
        void **unComentario = (void**)comentariosDeStreamer[i];
        arch << left<<setw(30) << (char*)unComentario[RECEPTOR] <<setw(100)<<(char *)unComentario[TEXTO] << endl;
    }
}

void imprimirLinea(ofstream &arch, int tam, char c) {
    for (int i = 0; i < tam; i++) {
        arch << c;
    }
    arch << endl;
}

void buscarComentarios(void **comentariosAux, char *cuentaStreamer, void **unStreamer, int &nd, int &cap) {
    for (int j = 0; comentariosAux[j]; j++) {
        void **unComentario = (void**)comentariosAux[j];
        char *emisorComentario = (char*)unComentario[EMISOR];

        if (strcmp(cuentaStreamer, emisorComentario) == 0) {
            if (nd == cap)
                incrementarEspaciosComentarios(unStreamer[COMENTARIOS], nd, cap);
            void **comentariosStreamer = (void**)unStreamer[COMENTARIOS];
            comentariosStreamer[nd] = unComentario;
            nd++;
        }
    }
}

void incrementarEspaciosComentarios(void *&unStreamerComentarios, int &nd, int &cap) {
    void **comentariosStreamer = (void**)unStreamerComentarios;
    void **aux;
    cap += INCREMENTO5;
    if (comentariosStreamer == nullptr) {
        comentariosStreamer = new void*[cap]{};
    } else {
        aux = new void*[cap]{};
        for (int i = 0; i < nd; i++)
            aux[i] = comentariosStreamer[i];
        delete[] comentariosStreamer;
        comentariosStreamer = aux;
    }
    unStreamerComentarios = comentariosStreamer;
}

void imprimirReporteStreamers(void *streamers) {
    ofstream arch = abrirOfstream("ArchivosDeReporte/reporteStreamers.txt");
    void **auxStreamers = (void**)streamers;
    arch << setw(60)<<"VERIFICACION DE CORRECTA ASIGNACION DE DATOS EN ARREGLO STREAMERS"<<endl;
    arch<<"CUENTA"<<setw(20)<<"SEGUIDORES"<<setw(20)<<"CATEGORIA"<<endl;
    for (int j = 0; auxStreamers[j]; j++) {
        void **unStreamer = (void**)auxStreamers[j];
        arch <<left<< setw(17)<< (char*)unStreamer[CUENTA] << setw(21)<<*(int*)unStreamer[SEGUIDORES] <<
            setw(20)<<(char*)unStreamer[CATEGORIA] << endl;
    }
}
void imprimirReporteComentarios(void *&comentarios) {
    ofstream arch = abrirOfstream("ArchivosDeReporte/reporteComentarios.txt");
    void **auxComentarios = (void**)comentarios;
    arch << right<<setw(100)<<"VERIFICACION DE CORRECTA ASIGNACION DE DATOS EN ARREGLO COMENTARIOS"<<endl;
    arch<<right<<"CODIGO"<<setw(50)<<"TEXTO"<<setw(60)<<"EMISOR"<<setw(20)<<"RECEPTOR"<<endl;
    for (int j = 0; auxComentarios[j]; j++) {
        void **unComentario=(void**)auxComentarios[j];
        arch <<left<< setw(17)<< (char*)unComentario[CODIGO] << setw(90)<<(char*)unComentario[TEXTO] <<
            setw(20)<<(char*)unComentario[EMISOR] <<setw(20)<<(char*)unComentario[RECEPTOR] << endl;
    }
}
void leerArchivoComentarios(ifstream &arch, void *&unComentario) {
    char *codigo, *texto, *emisor, *receptor;
    codigo = leerCadenaExacta(arch, ',');
    if (arch.eof() or codigo == nullptr) return;
    texto = leerCadenaExacta(arch, '[');
    emisor = leerCadenaExacta(arch, ' ');
    receptor = leerCadenaExacta(arch, ']'); arch.get();
    unComentario = llenaRegistroComentarios(codigo, texto, emisor, receptor);
}
void *llenaRegistroComentarios(char *codigo, char *texto, char *emisor, char * receptor) {
    void **registro;
    registro = new void*[4];
    registro[CODIGO] = codigo;
    registro[TEXTO] = texto;
    registro[EMISOR] = emisor;
    registro[RECEPTOR] = receptor;
    return registro;
}
void incrementarEspacios(void **&arreglo, int &nd, int &cap) {
    void **aux;
    cap += INCREMENTO5;
    if (arreglo == nullptr) {
        arreglo = new void*[cap]{};
    } else {
        aux = new void*[cap]{};
        for (int i = 0; i < nd; i++)
            aux[i] = arreglo[i];
        delete[] arreglo;
        arreglo = aux;
    }
}
void leerArchivoStreamers(ifstream &arch, void *&unStreamer) {
    char *cuenta, *categoria, c;
    long long tiempoTotal;
    int promEspectadores, seguidores;
    cuenta = leerCadenaExacta(arch, ',');
    if (arch.eof() or cuenta == nullptr) return;
    arch>>tiempoTotal>>c>>promEspectadores>>c>>seguidores>>c;
    categoria = leerCadenaExacta(arch, '\n');
    unStreamer = llenaRegistroStreamers(cuenta, categoria, tiempoTotal, promEspectadores, seguidores);
}
void *llenaRegistroStreamers(char *cuenta, char *categoria, long long tiempoTotal, int promEspectadores, int seguidores) {
    void **registro;
    registro = new void*[6];
    registro[CUENTA]      = cuenta;
    registro[CATEGORIA]   = categoria;
    int *ptrPromEspectadores;
    ptrPromEspectadores = new int;
    *ptrPromEspectadores = promEspectadores;
    registro[PROMESPECT]      = ptrPromEspectadores;

    long long *ptrTiempoTotal = new long long;
    *ptrTiempoTotal = tiempoTotal;
    registro[TIEMPOTOTAL]  = ptrTiempoTotal;

    int *ptrSeguidores;
    ptrSeguidores = new int;
    *ptrSeguidores = seguidores;
    registro[SEGUIDORES]  = ptrSeguidores;

    registro[COMENTARIOS] = nullptr;
    return registro;
}
ifstream abrirIfstream(const char *nombArch) {
    ifstream arch = ifstream(nombArch, ios::in);
    if(not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    return arch;
}
ofstream abrirOfstream(const char *nombArch) {
    ofstream arch = ofstream(nombArch, ios::out);
    if(not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    return arch;
}
char *leerCadenaExacta(ifstream &arch, char delim) {
    char *ptr, buffer[100];
    arch.getline(buffer, 100, delim);
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buffer)+1];
    strcpy(ptr, buffer);
    return ptr;
}