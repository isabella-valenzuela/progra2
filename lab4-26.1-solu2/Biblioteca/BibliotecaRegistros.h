#ifndef BIBLIOTECAREGISTROS_H
#define BIBLIOTECAREGISTROS_H

#include <fstream>
using namespace std;

// Campos de una atención. Un registro es un arreglo de NUMCAMPOS void*.
enum Atencion {CODIGO, FECHA, MOTIVO, HORA, ESTADO, NOMBRE, RAZA, COLOR, ESPECIE, NUMCAMPOS};

void *leeregistro(ifstream &input);
int comparareg(const void *a, const void *b);
int verificareg(const void *a, const void *b);
void imprimeregistro(ofstream &output, void *dato);

#endif
