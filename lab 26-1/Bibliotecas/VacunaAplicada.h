//
// Created by Isabella on 8/10/2026.
//

#ifndef LAB_26_1_VACUNAAPLICADA_H
#define LAB_26_1_VACUNAAPLICADA_H

class VacunaAplicada {
    private:
        char* nombre;
        int fecha;
        double dosis;
        char* colegiatura;
    void asignaCadena(char *&destino, const char *origen);
    void obteneCadena(char *cadena, const char *nombre) const;
    public:
    VacunaAplicada();
    ~VacunaAplicada();
    VacunaAplicada(const VacunaAplicada &orig);
    void operator=(const VacunaAplicada &orig);
    void inicializar();
    void eliminar();
    void getNombre(char *cadena)const;
    void setNombre(char *cadena);
    int getFecha();
    void setFecha(int fecha);
    double getDosis();
    void setDosis(double dosis);
    void getColegiatura(char * cadena)const;
    void setColegiatura(char *colegiatura);
    void leerDatos(ifstream &arch);
    void imprimirDatos(ofstream &arch);
    bool esIgual(const VacunaAplicada &aComparar) const;
};
void operator>>(ifstream &arch, class VacunaAplicada &vacuna);
void operator<<(ofstream &arch, class VacunaAplicada &vacuna);


#endif //LAB_26_1_VACUNAAPLICADA_H