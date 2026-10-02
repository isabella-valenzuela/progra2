//
// Created by alulab14 on 8/05/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAGENERICA_H
#define LISTAGENERICA_BIBLIOTECAGENERICA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

enum lista{PRIMERNODO,LONGITUDLISTA};
enum nodoLista{DATO,SIGUIENTE};
void procesaArreglo (void **arr,void *(*lee)(ifstream &),const char *nombArch);
void creaLista(void **arr,void *&lista,int (*comparar)(const void *,const void *));
void generaLista(void *&lista);
void insertaLista(void *&lista,int *longitudLista,void *dato);
void *obtenerUltimoNodo(void *lista);
void imprimeLista(void *&lista,void (*imprime)(ofstream&,void *),const char *nombArch);
#endif //LISTAGENERICA_BIBLIOTECAGENERICA_H
