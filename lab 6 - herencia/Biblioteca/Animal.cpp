//
// Created by anaro on 27/05/2026.
//

#include <cstring>
#include <iostream>
#include <ostream>
using namespace std;
#include "Animal.h"

Animal::Animal()
{
    inicializa();
}

Animal::~Animal()
{
    if (nombre) delete[] nombre;
    cout << "Destruyendo a animal" << endl;
}

Animal::Animal(const char* nomb, int edad, double peso)
{
    inicializa();
    setNombre(nomb);
    this->edad = edad;
    this->peso = peso;
}

Animal::Animal(const Animal& ani)
{
    nombre = nullptr;
    *this = ani; //delegar la tarea al operador =
}

void Animal::operator=(const Animal& ani)
{
    /*Primera forma de setter un char* */
    char nomb[50];
    ani.getNombre(nomb);
    setNombre(nomb);

    /*Segunda forma de setter un char* */
    // if (ani.nombre != nullptr)
    //     setNombre(ani.nombre);

    edad = ani.edad;
    peso = ani.peso;
}

void Animal::inicializa()
{
    nombre = nullptr;
}

void Animal::setNombre(const char* nom)
{
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}

void Animal::getNombre(char* nom) const
{
    if (nombre == nullptr) nom[0] = 0;
    else strcpy(nom, nombre);
}

void Animal::setEdad(int edad)
{
    this->edad = edad;
}

int Animal::getEdad() const
{
    return edad;
}

void Animal::setPeso(double peso)
{
    this->peso = peso;
}

double Animal::getPeso() const
{
    return peso;
}

void Animal::mostrar() const
{
    cout << " ANIMAL " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " annos " << endl;
    cout << "Peso: " << peso << " kg. " << endl;
}

void Animal::hablar()
{
    
}





