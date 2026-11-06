//
// Created by anaro on 28/05/2026.
//

#ifndef SOLLABORATORIO820231_PRESENCIAL_H
#define SOLLABORATORIO820231_PRESENCIAL_H
#include "Alumno.h"

class Presencial : public Alumno
{
private:
    double recargo;
    double total;

public:
    Presencial();
    void setRecargo(double recargo);
    double getRecargo() const;
    void setTotal(double total);
    double getTotal() const;
    void leerDatos(ifstream&);
    void actualiza(double precio);
    void mostrarDatos(ofstream& out);
};

#endif //SOLLABORATORIO820231_PRESENCIAL_H
