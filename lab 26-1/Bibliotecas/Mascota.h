//
// Created by Isabella on 8/10/2026.
//

#ifndef LAB_26_1_MASCOTA_H
#define LAB_26_1_MASCOTA_H
#include "VacunaAplicada.h"
class Mascota {
    private:
        int dni;
        char* nombre;
        char *especie;
        int edad;
        double peso;
        char* colegiatura;
        VacunaAplicada listaVacunas[20];
        int numVacunas;
        void asignaCadena(char *&destino, const char *origen); // para set de punteros,libera la cadena anterior y guarda una copia de la nueva
        void obtenerCadena(char *cad, const char *origen) const; // para get de punteros, obtiene cadena

    public:
        Mascota(); //constructor
        Mascota(const Mascota &orig); //constructor copia (const Clase &orig)
        void operator=(const Mascota &orig); //operador de asignacion tamnbien con (const Clase &orig)
        ~Mascota(); //destructor
        void inicializar(); //para el constructor (desarrollo)
        void eliminar(); // para el destructor (desarrollo)
        int getDni() const;
        void setDni(int dni);
        void getNombre(char* cadena) const;
        void setNombre(char* nombre);
        void getEspecie(char* cadena) const;
        void setEspecie(char* especie);
        double getPeso() const;
        void setPeso(double peso);
        void getColegiatura(char* cadena) const;
        void setColegiatura(char* colegiatura);
        int getNumVacunas() const;
        void leerDatos(ifstream &arch);
        void imprimirDatos(ofstream &arch);
        void operator +=(class VacunaAplicada &vacuna);
        bool operator~();
};

void operator>>(ifstream &arch, class Mascota &mascota);
void operator<<(ofstream &arch, class Mascota &mascota);
#endif //LAB_26_1_MASCOTA_H