//
// Created by anaro on 28/05/2026.
//

#ifndef SOLLABORATORIO820231_TESORERIA_H
#define SOLLABORATORIO820231_TESORERIA_H
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Tesoreria
{
private:
    class Presencial * lpresencial;  //En caso sea un puntero
    class Semipresencial lsemipresencial[100];
    class Virtual * lvirtual; //memoria incrementos
    class Escala lescala[100];
public:
    Tesoreria();
    ~Tesoreria();
    void cargaEscalas(const char* nombArch);
    void cargaAlumnos(const char* nombArch);
    void incrementarLosEspacios(Virtual* & datos, int &numDatos, int &capacidad);
    void actualiza(double cred);
    void imprime(const char* nombArch);

};


#endif //SOLLABORATORIO820231_TESORERIA_H
