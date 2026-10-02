//
// Created by renat on 2/5/2026.
//

#include "BibliotecaRegistros.hpp"
//27864822,T9U-338,16/01/2019,318,FIGUEROA MEDINA MADELEINE
void * leereg(ifstream &input) {
    int *licencia = new int[1]{},*fecha = new int[1]{}, *codigo = new int[1]{};
    char *placa, *nombre, ignorar;
    input>>*licencia>>ignorar;
    if (input.eof()) return nullptr;
    placa = LeerConDelimitador(input, ',');
    *fecha = LeerFecha(input);
    input>>*codigo>>ignorar;
    nombre = LeerConDelimitador(input, '\n');
    void **registro = new void*[5]{};
    registro[0] = licencia;
    registro[1] = placa;
    registro[2] = fecha;
    registro[3] = codigo;
    registro[4] = nombre;
    return registro;
}
int clasificaRegistro(void *&dato) {
    if (dato == nullptr) return -1;
    void **registro = (void **) dato;
    int num_bloq = (*(int *)registro[3])/100;
    if (num_bloq == 1) return 1;
    return 2;
}
void imprimereg(ofstream &output, void *dato) {
    if (dato == nullptr) return;
    void **registro = (void **) dato;
    char *nombre = (char *) registro[4];
    ImprimirFecha(output, *(int *)registro[2]);
    output<<setw(10)<<*(int *)registro[0]<<setw(10)
    <<" "<<nombre<<setw(70-strlen(nombre))<<*(int *)registro[3]<<endl;
}
char *LeerConDelimitador(ifstream &input, char delimitador) {
    char * cadena, cad[200]{};
    input.getline(cad, 200, delimitador);
    cadena = new char[strlen(cad) + 1]{};
    strcpy(cadena, cad);
    return cadena;
}
int LeerFecha(ifstream &input) {
    int anio, mes, dia;
    char ignorar;
    input>>dia>>ignorar>>mes>>ignorar>>anio>>ignorar;
    return dia +  mes*100 + anio * 10000;
}
void ImprimirFecha(ofstream &output, int fecha) {
    int anio, mes, dia;
    anio = fecha / 10000;
    mes = (fecha % 10000) / 100;
    dia = (fecha % 10000) % 100;
    output<<anio<<"/"<<setfill('0')<<setw(2)<<mes<<"/"<<setw(2)<<dia<<setfill(' ');
}