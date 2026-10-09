//
// Created by anaro on 13/05/2026.
//

#ifndef EJEMPLOUSOOPCONCLASES_ACCESORIO_H
#define EJEMPLOUSOOPCONCLASES_ACCESORIO_H

enum TIPO{INTERIOR, EXTERIOR};

class Accesorio
{
    private:
    char* nombre;
    TIPO tipo;
public:
    Accesorio();
    Accesorio(const class Accesorio& accesorio);
    void operator=(const class Accesorio& accesorio);
    ~Accesorio();
    void setNombre(const char*);
    void getNombre(char*) const;
    TIPO getTipo() const;
    void setTipo(const TIPO tipo);
};


#endif //EJEMPLOUSOOPCONCLASES_ACCESORIO_H
