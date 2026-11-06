//
// Created by anaro on 27/05/2026.
//

#ifndef HERENCIA_ANIMAL_H
#define HERENCIA_ANIMAL_H

class Animal
{
private:
    char * nombre; //regla de los tres
    int edad;
    double peso;

public:
    Animal();
    ~Animal();
    Animal(const char * nombre, int edad, double peso);
    Animal(const Animal &ani);
    void operator=(const Animal &ani);

    void inicializa();
    void setNombre(const char * nom);
    void getNombre(char * nom) const;
    void setEdad(int edad);
    int getEdad() const;
    void setPeso(double peso);
    double getPeso() const;
    void mostrar() const;
    void hablar();
};


#endif //HERENCIA_ANIMAL_H
