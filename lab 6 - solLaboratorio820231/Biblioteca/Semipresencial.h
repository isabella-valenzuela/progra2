//
// Created by anaro on 28/05/2026.
//

#ifndef SOLLABORATORIO820231_SEMIPRESENCIAL_H
#define SOLLABORATORIO820231_SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial : public Alumno
{
private:
    double descuento;
    double total;

public:
    Semipresencial();
    void setDescuento(double descuento);
    void setTotal(double total);
    double getDescuento() const;
    double getTotal() const;
    void leerDatos(ifstream& in);
    void actualiza(double precio);
    void mostrarDatos(ofstream& out);
};

#endif //SOLLABORATORIO820231_SEMIPRESENCIAL_H
