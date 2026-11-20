//
// Created by Isabella on 19/11/2026.
//

#ifndef LAB9_25_2_MULTA_H
#define LAB9_25_2_MULTA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "Vehiculo.h"
using namespace std;
class Multa {
private:
    int fecha;
    string placa;
    string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;
    void inicializar();
    void imprimeFecha(ofstream &arch, int fecha);
public:
    Multa();
    ~Multa();
    Multa(const Multa &orig);
    void operator=(const Multa &orig);

    int getFecha();
    string getPlaca();
    string getCodMulta();
    double getMulta();
    bool getPagada();
    int getFechaDePago();

    void setFecha(int fecha);
    void setPlaca(string placa);
    void setCodMulta(string codMulta);
    void setMulta(double multa);
    void setPagada(bool pagada);
    void setFechaDePago(int fecha);
    void agregarMonto(double multa);
    bool operator<(const Multa &mul) const;
    bool operator>(const Multa &mul) const;
    void imprime(ofstream &arch);
};

void operator >>(ifstream &arch, Multa &mul);
void operator <<(ofstream &arch, Multa &mul);

#endif //LAB9_25_2_MULTA_H
