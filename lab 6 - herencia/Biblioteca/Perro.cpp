//
// Created by anaro on 27/05/2026.
//
#include <iostream>
#include <ostream>
using namespace std;
#include "Perro.h"

Perro::Perro(){
    esDomestico = false;
}

Perro::Perro(const char* nombre, int edad, double peso, bool esDomestico) : Animal(nombre, edad, peso)
{
    this->esDomestico = esDomestico;
}

Perro::~Perro(){
    cout << "Destruyendo al perro" << endl;
}

void Perro::setDomestico(bool domestico){
    this->esDomestico = domestico;
}

bool Perro::getDomestico() const{
    return esDomestico;
}
void Perro::mostrar() const{

    Animal::mostrar();
    cout << " PERRO : "<< endl;
    cout << "Es domestico: "
         << (esDomestico ? "Si":"No") <<endl;
}

void Perro::hablar()
{
    cout << "Hace: Guauu Guauu" << endl;
}


