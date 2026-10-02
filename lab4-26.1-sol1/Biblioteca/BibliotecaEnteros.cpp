//
// Created by alulab14 on 8/05/2026.
//

#include "BibliotecaEnteros.h"

void *leenum(ifstream &arch) {
    int *dato= new int;
    arch>>*dato;
    if (arch.eof()) return nullptr;
    return dato;
}


int comparanum(const void *dato1,const void *dato2) {
    void **comparar1= (void **) dato1;
    void **comparar11= (void **) comparar1[0];
    void **comparar2= (void **) dato2;
    void **comparar22= (void **) comparar2[0];
    return *(int*)comparar11 - *(int*)comparar22;
}

void imprimenum(ofstream &arch,void *lista) {
    void **dato= (void **) lista;
    int num= *(int *)dato;
    arch<<num<<endl;
}