//
// Created by anaro on 28/05/2026.
//

#ifndef SOLLABORATORIO820231_VIRTUAL_H
#define SOLLABORATORIO820231_VIRTUAL_H
#include "Alumno.h"

class Virtual : public Alumno
{
private:
    char* licencia;
    double total;

public:
    Virtual();
    ~Virtual();
    Virtual(const Virtual& orig);
    void operator=(const Virtual& orig);
    void inicializa();
    void setLicencia(const char* licencia);
    void setTotal(double total);
    void getLicencia(char* lic) const;
    double getTotal() const;
    void leerDatos(ifstream& in);
    void actualiza(double precio);
    void mostrarDatos(ofstream& out);
};


#endif //SOLLABORATORIO820231_VIRTUAL_H
