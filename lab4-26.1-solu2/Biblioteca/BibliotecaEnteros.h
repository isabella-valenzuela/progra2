#ifndef BIBLIOTECAENTEROS_H
#define BIBLIOTECAENTEROS_H

#include <fstream>
using namespace std;

void *leenum(ifstream &input);
int comparanum(const void *a, const void *b);
int verificanum(const void *a, const void *b);
void imprimenum(ofstream &output, void *dato);

#endif
