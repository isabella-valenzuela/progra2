//
// Created by anaro on 27/05/2026.
//

#ifndef HERENCIA_PERRO_H
#define HERENCIA_PERRO_H
#include "Animal.h"

class Perro : public Animal
{
private:
    bool esDomestico;
public:
    Perro();
    Perro(const char* nomb, int edad, double peso, bool esDomestico);
    ~Perro();
    void setDomestico(bool domestico);
    bool getDomestico() const;
    void mostrar() const;
    void hablar();
};


#endif //HERENCIA_PERRO_H
