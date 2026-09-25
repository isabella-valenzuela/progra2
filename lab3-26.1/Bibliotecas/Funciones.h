//
// Created by Isabella on 25/09/2026.
//

#ifndef LAB3_26_1_FUNCIONES_H
#define LAB3_26_1_FUNCIONES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
ifstream abrirIfstream(const char *nombArch) ;
ofstream abrirOfstream(const char *nombArch) ;
char *leerCadenaExacta(ifstream &arch, char delim) ;
void *rellenarPaciente(int id, char *nombre, int edad, char genero) ;
void cargarPacientes(const char *nombArch, void *&pacientes) ;
void leerArchivo(ifstream &arch, void *&paciente) ;
void incrementarEspacios(void **&pacientesAux, int& nd, int& cap) ;
void leeVisitas(ifstream &arch, void **pacientesAux, int *nd, int *cap) ;
void colocaVisita(void *unaVisita, void *unPaciente, double costoAtencion, int &nd, int &cap) ;
void *rellenarVisita(int fecha, int hora, double costoAtencion) ;
int buscarPaciente(int idBuscado, void **pacientesAux) ;
void cargarVisitas(const char *nombArch, void *&pacientes) ;
void incrementarEspacios(void *&campoVisitas, int &nd, int &cap) ;


#endif //LAB3_26_1_FUNCIONES_H