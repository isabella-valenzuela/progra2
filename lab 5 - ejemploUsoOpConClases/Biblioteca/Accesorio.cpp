//
// Created by anaro on 13/05/2026.
//
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
#include "Accesorio.h"

Accesorio::Accesorio()
{
}

Accesorio::Accesorio(const class Accesorio& accesorio)
{
}

void Accesorio::operator=(const class Accesorio& accesorio)
{
}

Accesorio::~Accesorio()
{
}

void Accesorio::setNombre(const char*)
{
}

void Accesorio::getNombre(char*) const
{
}

TIPO Accesorio::getTipo() const
{
    return tipo;
}

void Accesorio::setTipo(const TIPO tipo)
{
    this->tipo = tipo;
}