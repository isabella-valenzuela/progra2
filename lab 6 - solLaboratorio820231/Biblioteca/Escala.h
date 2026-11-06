//
// Created by anaro on 28/05/2026.
//

#ifndef SOLLABORATORIO820231_ESCALA_H
#define SOLLABORATORIO820231_ESCALA_H

class Escala
{
private:
    int codigo;
    double precio;
public:
    Escala();
    void setPrecio(double precio);
    void setCodigo(int codigo);
    double getPrecio() const;
    int getCodigo() const;
    void leeDatos(ifstream & in);
    void mostrar(ofstream & out);

};


#endif //SOLLABORATORIO820231_ESCALA_H
