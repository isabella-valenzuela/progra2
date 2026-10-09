//
// Created by anaro on 13/05/2026.
//

#ifndef EJEMPLOUSOOPCONCLASES_VEHICULO_H
#define EJEMPLOUSOOPCONCLASES_VEHICULO_H
#include "Accesorio.h"

class Vehiculo
{
private:
    char* marca;
    char* modelo;
    char* color;
    int anno;
    double velocidadActual;
    class Accesorio listaAccesorios[20];
    int cantAccesorios;

public:
    Vehiculo();
    Vehiculo(const class Vehiculo&);
    void operator=(const Vehiculo&);
    ~Vehiculo();
    void inicializa();
    void setMarca(const char*);
    void setModelo(const char*);
    void setColor(const char*);
    void setAnno(const int);
    void setVelocidadActual(const double);
    double getVelocidadActual() const;
    int getAnno() const;
    void getMarca(char*) const;
    void getModelo(char*) const;
    void getColor(char*) const;

};

//Aqu'i estoy fuera de la clase Vehiculo
//void operator >> (ifstream& in, class Vehiculo & ve);
ifstream& operator >> (ifstream& in, class Vehiculo & ve);
ofstream& operator << (ofstream& out, const class Vehiculo & ve);
char* leeCadena(ifstream& in, char c);
#endif //EJEMPLOUSOOPCONCLASES_VEHICULO_H
