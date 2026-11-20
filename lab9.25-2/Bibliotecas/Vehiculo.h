//
// Created by Isabella on 19/11/2026.
//

#ifndef LAB9_25_2_VEHICULO_H
#define LAB9_25_2_VEHICULO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
    void inicializar();
public:
    Vehiculo();
    ~Vehiculo();
    Vehiculo(const Vehiculo &orig);
    void operator=(const Vehiculo &orig);

    string getPlaca();
    string getMarca();
    string getModelo();

    void setPlaca(string placa);
    void setMarca(string marca);
    void setModelo(string modelo);
};

void operator >>(ifstream &arch, Vehiculo &veh);
void operator <<(ofstream &arch, Vehiculo &veh);

#endif //LAB9_25_2_VEHICULO_H
