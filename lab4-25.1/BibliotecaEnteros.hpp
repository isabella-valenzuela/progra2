//
// Created by renat on 2/5/2026.
//

#ifndef LAB4_25_1_BIBLIOTECAENTEROS_HPP
#define LAB4_25_1_BIBLIOTECAENTEROS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
void * leenum(ifstream &input);
int clasificaEntero(void *&dato);
void imprimenum(ofstream &output, void *dato);
#endif //LAB4_25_1_BIBLIOTECAENTEROS_HPP