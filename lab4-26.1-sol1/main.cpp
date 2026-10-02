#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

//L


#include "Biblioteca/BibliotecaGenerica.h"
#include "Biblioteca/BibliotecaRegistros.h"
#include "Biblioteca/BibliotecaEnteros.h"
#define MAX 300

int main() {
    void *arreglo1[MAX]{}, *arreglo2[MAX]{};
    void *lista1,*lista2;
    procesaArreglo(arreglo1,leenum,"ArchivosIngreso/numeros1.txt");
    creaLista(arreglo1,lista1,comparanum);
    procesaArreglo(arreglo2,leenum,"ArchivosIngreso/numeros2.txt");
    creaLista(arreglo2,lista2,comparanum);
    //fusionaListas(lista1,lista2,verificaNum);
    imprimeLista(lista1,imprimenum,"ArchivosDeSalida/Repnum.txt");

    return 0;
}


