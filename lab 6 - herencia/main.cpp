/*
 * Archivo: main.cpp
 * Autor: Ana C. Roncal N.
 * Creado el 27 de 05 del 2026 a las 11:40 
 */

#include <cstring>
#include <iostream>
using namespace std;
#include "Biblioteca/Animal.h"
#include "Biblioteca/Gato.h"
#include "Biblioteca/Perro.h"

int main(int argc, char** argv)
{
    class Animal animal1, animal2;
    animal1 = animal2;
    animal1.setNombre("Firulais");
    animal1.setEdad(3);
    animal1.setPeso(5.5);

    animal1.mostrar();

    class Gato gato1, gato2;
    gato1.setNombre("Dali");
    gato1.setEdad(2);
    gato1.setPeso(4.5);
    gato1.mostrar();
    gato2 = gato1;
    gato2.setDentroCasa(true);
    gato2.mostrar();

    class Perro perro1, perro2;
    perro1.setNombre("Terry");
    perro1.setEdad(10);
    perro1.setPeso(15.2);
    perro1.mostrar();
    perro2 = perro1;
    perro2.setDomestico(true);
    perro2.mostrar();

    return 0;
}