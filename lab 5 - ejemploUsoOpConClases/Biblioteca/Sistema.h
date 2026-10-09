//
// Created by anaro on 13/05/2026.
//

#ifndef EJEMPLOUSOOPCONCLASES_SISTEMA_H
#define EJEMPLOUSOOPCONCLASES_SISTEMA_H
#include  "Vehiculo.h"
#include "Accesorio.h"

class Sistema
{
private:
    class Vehiculo* vehiculos;
    int numVehiculos;

public:
    Sistema();
    ~Sistema();
    void operator << (const char* nombArch);
    void operator >> (const char* nombArch);
};


#endif //EJEMPLOUSOOPCONCLASES_SISTEMA_H
