//
// Created by renat on 2/5/2026.
//

#ifndef LAB4_25_1_BIBLIOTECAGENERICA_HPP
#define LAB4_25_1_BIBLIOTECAGENERICA_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
enum Lista{PRIMERBLOQUE, SEGUNDOBLOQUE};
enum Nodo{DATO, SIGUIENTE};
void creaLista(void *& lista,void* (*lee)(ifstream &),int (*clasifica)(void *&)
    , const char* nomArch);
void generalista(void *&lista);
void *buscarAnterior(void *inicioRecorrido,int numBloque,int (*clasifica)(void *&));
void insertaLista(void *&lista,void *dato,int (*clasifica) (void *&));
void imprimeLista(void *lista,void (*imprime)(ofstream &, void *),const char* nomArch);
#endif //LAB4_25_1_BIBLIOTECAGENERICA_HPP