//
// Created by anaro on 28/05/2026.
//

#ifndef SOLLABORATORIO820231_ALUMNO_H
#define SOLLABORATORIO820231_ALUMNO_H

class Alumno
{private:
    int codigo;
    char* nombre;
    int escala;
    double total;
public:
    Alumno();
    ~Alumno();
    Alumno(const Alumno& orig);
    void operator=(const class Alumno& orig);
    void inicializa();

    void setCodigo(int codigo);
    void setNombre(const char* nombre);
    void setEscala(int escala);
    void setTotal(double total);

    int getCodigo() const;
    void getNombre(char* nomb) const;
    int getEscala() const;
    double getTotal() const;
    void leerDatos(ifstream & in);
    void mostrarDatos(ofstream & out);

};


#endif //SOLLABORATORIO820231_ALUMNO_H
