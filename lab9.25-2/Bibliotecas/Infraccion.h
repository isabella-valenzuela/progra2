//
// Created by Isabella on 19/11/2026.
//

#ifndef LAB9_25_2_INFRACCION_H
#define LAB9_25_2_INFRACCION_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
class Infraccion {
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;
    void inicializar();
public:
    Infraccion();
    ~Infraccion();
    Infraccion(const Infraccion &orig);
    void operator=(const Infraccion &orig);

    string getCodigo();
    double getMulta();
    string getGravedad();
    string getDescripcion();

    void setCodigo(string codigo);
    void setMulta(double multa);
    void setGravedad(string gravedad);
    void setDescripcion(string descripcion);
    bool operator<(Infraccion &infraccion);

};

void operator >>(ifstream &arch, Infraccion &inf);
void operator <<(ofstream &arch, Infraccion &inf);

#endif //LAB9_25_2_INFRACCION_H
