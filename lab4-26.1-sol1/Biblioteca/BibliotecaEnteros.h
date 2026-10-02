//
// Created by alulab14 on 8/05/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAENTEROS_H
#define LISTAGENERICA_BIBLIOTECAENTEROS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

void *leenum(ifstream &arch);
int comparanum(const void *dato1,const void *dato2);
void imprimenum(ofstream &arch,void *lista);
#endif //LISTAGENERICA_BIBLIOTECAENTEROS_H
