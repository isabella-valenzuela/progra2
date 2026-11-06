//
// Created by anaro on 27/05/2026.
//

#include <iostream>
#include <ostream>
using namespace std;
#include "Gato.h"

Gato::Gato(){
    dentroCasa = false;
}

Gato::~Gato(){
    cout << "destruyendo a gato " << endl;
}

Gato::Gato(const char* nombre, int edad, double peso, bool dentroCasa): Animal(nombre, edad, peso){
    this->dentroCasa = dentroCasa;
}

void Gato::setDentroCasa(bool dentro){
    this->dentroCasa = dentro;
}

bool Gato::getDentroCasa() const{
    return dentroCasa;
}

void Gato::mostrar() const{

    Animal::mostrar();
    cout << " GATOOO" << endl;
    cout << "Vive dentro de casa: "
         << (dentroCasa ? "Si" : "No") << endl;
}

void Gato::hablar()
{
    cout << "Hace: Miauu Miauu" << endl;
}


