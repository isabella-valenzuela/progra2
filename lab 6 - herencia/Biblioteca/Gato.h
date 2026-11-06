//
// Created by anaro on 27/05/2026.
//

#ifndef HERENCIA_GATO_H
#define HERENCIA_GATO_H
#include "Animal.h"

class Gato : public Animal
{
private:
    bool dentroCasa;
public:
    Gato();
    Gato(const char* nomb, int edad, double peso, bool dentroCasa);
    ~Gato();
    void setDentroCasa(bool dentro);
    bool getDentroCasa() const;
    void mostrar() const;
    void hablar() ;
};


#endif //HERENCIA_GATO_H
