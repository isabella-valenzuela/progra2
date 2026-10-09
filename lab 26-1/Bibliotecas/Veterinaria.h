//
// Created by Isabella on 8/10/2026.
//

#ifndef LAB_26_1_VETERINARIA_H
#define LAB_26_1_VETERINARIA_H
#include "Mascota.h"
class Veterinaria {
    private:
    Mascota *listaDeMascotas;
    int numMascotas;
    void redimensionar (int capacidad);
    void agregarMascota(const class Mascota &mascota, int &capacidad);
    ifstream abrirIfstream(const char *nombArch);
    int buscarMascota(int dniCliente, const char *nombre);
    public:
    Veterinaria();
    ~Veterinaria();
    void inicializar();
    void eliminar();
    void operator <=(const char *nombArch);
    void operator <<=(const char *nombArch);
};
#endif //LAB_26_1_VETERINARIA_H