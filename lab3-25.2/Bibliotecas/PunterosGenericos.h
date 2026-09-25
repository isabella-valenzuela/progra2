//
// Created by Isabella on 22/09/2026.
//

#ifndef LAB3_25_2_PUNTEROSGENERICOS_H
#define LAB3_25_2_PUNTEROSGENERICOS_H
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream abrirIfstream(const char *nombArch) ;
char *leerCadenaExacta(ifstream &arch, char delim) ;
void cargaStreamers(void *&streamers) ;
void leerArchivoStreamers(ifstream &arch, void *&unStreamer) ;
void *llenaRegistroStreamers(char *cuenta, char *categoria, long long tiempoTotal, int promEspectadores, int seguidores) ;
void incrementarEspacios(void **&arreglo, int &nd, int &cap) ;
void leerArchivoComentarios(ifstream &arch, void *&unComentario) ;
void *llenaRegistroComentarios(char *codigo, char *texto, char *emisor, char * receptor) ;
void cargaComentarios(void *&comentarios) ;
ofstream abrirOfstream(const char *nombArch) ;
void imprimirReporteStreamers(void *streamers) ;
void imprimirReporteComentarios(void *&comentarios) ;
void actualizaComentarios(void *&streamers, void *&comentarios) ;
void incrementarEspaciosComentarios(void *&unStreamerComentarios, int &nd, int &cap) ;
void buscarComentarios(void **comentariosAux, char *cuentaStreamer, void **unStreamer, int &nd, int &cap);
void imprimirLinea(ofstream &arch, int tam, char c) ;
void imprimeStreamers(void *&streamers) ;
void imprimirComentariosEmitidos(ofstream &arch, void *unStreamerComentarios);
void incrementarEspaciosComentarios(void *&unStreamerComentarios, int &nd, int &cap) ;


#endif //LAB3_25_2_PUNTEROSGENERICOS_H