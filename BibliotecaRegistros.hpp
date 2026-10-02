//
// Created by renat on 2/5/2026.
//

#ifndef LAB4_25_1_BIBLIOTECAREGISTROS_HPP
#define LAB4_25_1_BIBLIOTECAREGISTROS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
void * leereg(ifstream &input);
char *LeerConDelimitador(ifstream &input, char delimitador);
int LeerFecha(ifstream &input);
int clasificaRegistro(void *&dato);
void ImprimirFecha(ofstream &output, int fecha);
void imprimereg(ofstream &output, void *dato);
#endif //LAB4_25_1_BIBLIOTECAREGISTROS_HPP